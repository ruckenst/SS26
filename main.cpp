#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <vector>

struct File {
    std::string name;
    int size;
};

void downloadFile(File file, std::mutex& mutex){
    int currentCount = 0;
    int previousPercentage = 0;

    while(currentCount < file.size) {
        int currentPercentage = currentCount / (double)file.size * 100;

        if(currentPercentage != previousPercentage) {
            std::lock_guard<std::mutex> guard(mutex);
            std::cout << "File: '" << file.name << "' (" << currentPercentage << "/100)" << std::endl;
            previousPercentage = currentPercentage;
        }

        currentCount++;
    }

    std::lock_guard<std::mutex> guard(mutex);
    std::cout << "### File: '" << file.name << "' finished!" << std::endl;
}

int main() {
    std::mutex mutex;

    std::vector<File> files = {
            File("File_A.pdf", 918242),
            File("File_B.pdf", 6123),
            File("File_C.pdf", 456732),
            File("File_D.pdf", 612361),
            File("File_E.pdf", 4564),
            File("File_F.pdf", 43),
            File("File_G.pdf", 6343)
    };

    std::vector<std::thread> threads;

    for(const auto& file : files) {
        threads.push_back(std::thread(downloadFile, file, std::ref(mutex)));
    }

    for(auto& thread : threads) {
        thread.join();
    }

    std::cout << "All files downloaded successfully!" << std::endl;

    return 0;
}