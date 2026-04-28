#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

void printSomething(bool comparisonFunction(int, int)) {
    if(comparisonFunction(20, 83)) {
        std::cout << "Text A" << std::endl;
    } else {
        std::cout << "Text B" << std::endl;
    }
}

bool testFunction(int a, int b) {
    return a > b;
}

struct File {
    std::string name;
    int size;
};

void downloadFile(File file, std::mutex& mutex) {
    int currentSize = 0;

    while(currentSize < file.size) {
        if(currentSize % 10000 == 0) {
            double currentPercentage = currentSize / (double)file.size * 100;

            std::lock_guard<std::mutex> guard(mutex);
            std::cout << "File '" << file.name << "' (" << currentPercentage << "/100)" << std::endl;
        }

        currentSize++;
    }

    std::lock_guard<std::mutex> guard(mutex);
    std::cout << "### File '" << file.name << "' Finished!" << std::endl;
}

int main() {
    printSomething(testFunction);
    printSomething([](int a, int b) {
        return a < b;
    });

    std::vector<File> files = {
            File("File_A.pdf", 892374),
            File("File_B.pdf", 5231),
            File("File_C.pdf", 962),
            File("File_D.pdf", 5682352),
            File("File_E.pdf", 28235),
            File("File_F.pdf", 28346),
            File("File_G.pdf", 6827)
    };

    std::vector<std::thread> threads;
    std::mutex mutex;

    for(const auto& file : files) {
        threads.push_back(std::thread(downloadFile, file, std::ref(mutex)));
    }

    for(auto& thread : threads) {
        thread.join();
    }

    std::cout << "All files downloaded successfully!" << std::endl;

    return 0;
}