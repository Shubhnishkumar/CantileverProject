#ifndef SOCIALNETWORK_H
#define SOCIALNETWORK_H

#include <unordered_map>
#include <string>
#include <fstream>
#include "User.h"

class SocialNetwork {
private:
    std::unordered_map<std::string, User> users;

public:
    void createUser(const std::string& username) {
        users[username] = User(username);
    }

    User* getUser(const std::string& username) {
        auto it = users.find(username);
        if (it != users.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    void addFriend(const std::string& username, const std::string& friendUsername) {
        User* user = getUser(username);
        User* friendUser = getUser(friendUsername);
        if (user && friendUser) {
            user->addFriend(friendUsername);
            friendUser->addFriend(username);
        } else {
            std::cerr << "User not found." << std::endl;
        }
    }

    void postMessage(const std::string& username, const std::string& message) {
        User* user = getUser(username);
        if (user) {
            user->postMessage(message);
        } else {
            std::cerr << "User not found." << std::endl;
        }
    }

    void displayUserProfile(const std::string& username) {
        User* user = getUser(username);
        if (user) {
            user->displayProfile();
        } else {
            std::cerr << "User not found." << std::endl;
        }
    }

    void saveData(const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& pair : users) {
            file << pair.first << std::endl;
            for (const auto& friendUsername : pair.second.getFriends()) {
                file << "F " << friendUsername << std::endl;
            }
            for (const auto& message : pair.second.getMessages()) {
                file << "M " << message << std::endl;
            }
        }
    }

    void loadData(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        std::string currentUser;
        while (std::getline(file, line)) {
            if (line.empty()) {
                continue;
            }
            if (line[0] != 'F' && line[0] != 'M') {
                currentUser = line;
                createUser(currentUser);
            } else if (line[0] == 'F') {
                addFriend(currentUser, line.substr(2));
            } else if (line[0] == 'M') {
                postMessage(currentUser, line.substr(2));
            }
        }
    }
};

#endif // SOCIALNETWORK_H
