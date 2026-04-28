#include <iostream>
#include <string>

struct User {
    int id;
    std::string name;
};

User* getUser(int userId) {
    // LOADS THE USER
    return new User(userId, "Seppl");
}

void saveUser(User* user) {
    // SAVE THE USER
    int status = 500;
    if(status != 200 || status != 201) {
        throw std::out_of_range("Status out of range during saving");
    }
}

void updateUserName(int userId, std::string name) {
    auto user = getUser(userId);
    if(user == nullptr) {
        // NOT FOUND
        throw std::invalid_argument("User with id was not found");
    }

    user->name = name;

    saveUser(user);
}

int main() {
    try{
        updateUserName(1, "Anna");
    } catch(const std::invalid_argument& ex) {
        std::cout << "The user was not found!" << std::endl;
        return -3;
    } catch(const std::out_of_range& ex) {
        std::cout << "Error during saving the updated user!" << std::endl;
        return -2;
    } catch(...) {
        std::cout << "Error while updating the user!" << std::endl;
        return -1;
    }

    std::cout << "User updated successfully!" << std::endl;

    return 0;
}