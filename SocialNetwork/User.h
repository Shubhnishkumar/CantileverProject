#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>

class User {
private:
    std::string username;
    std::vector<std::string> friends;
    std::vector<std::string> messages;

public:
    User() {}  // Default constructor
    User(const std::string& username) : username(username) {}

    std::string getUsername() const {
        return username;
    }

    void addFriend(const std::string& friendUsername) {
        friends.push_back(friendUsername);
    }

    void postMessage(const std::string& message) {
        messages.push_back(message);
    }

    void displayProfile() const {
        std::cout << "Username: " << username << std::endl;
        std::cout << "Friends: ";
        for (const auto& friendUsername : friends) {
            std::cout << friendUsername << " ";
        }
        std::cout << std::endl;
        std::cout << "Messages: " << std::endl;
        for (const auto& message : messages) {
            std::cout << message << std::endl;
        }
    }

    const std::vector<std::string>& getFriends() const {
        return friends;
    }

    const std::vector<std::string>& getMessages() const {
        return messages;
    }
};

#endif // USER_H
