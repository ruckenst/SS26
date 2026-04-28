#include <iostream>
#include <string>

struct User {
    int id;
    std::string name;
};

User* getUserById(int userId){
    // Load from DB/API/...
    //return nullptr;
    return new User(1, "Seppl");
}

void saveUser(User* user) {
    // Save User in DB/API/...
    throw std::out_of_range("DB Access not possible");
}

bool updateUsername(int userId, std::string newName) {
    User* user = getUserById(userId);
    if(user == nullptr) {
        throw std::invalid_argument("User not found");
    }

    user->name = newName;

    saveUser(user);

    // SOMETHING ELSE
    // SOMETHING ELSE
    // SOMETHING ELSE
    // SOMETHING ELSE
    // SOMETHING ELSE
    // SOMETHING ELSE
}

int main() {
    try {
        updateUsername(83, "Anna");
    } catch(const std::out_of_range& ex) {
        std::cout << "Save not successful! Reason: " << ex.what() << std::endl;
        return -3;
    } catch(const std::invalid_argument& ex) {
        std::cout << "Update not successful! Reason: " << ex.what() << std::endl;
        return -2;
    } catch(...) {
        std::cout << "Unknown error occurred!" << std::endl;
        return -1;
    }

    return 0;
}