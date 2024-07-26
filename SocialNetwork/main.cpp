#include <iostream>
#include "SocialNetwork.h"

void displayMenu() {
    std::cout << "1. Create User" << std::endl;
    std::cout << "2. Add Friend" << std::endl;
    std::cout << "3. Post Message" << std::endl;
    std::cout << "4. Display Profile" << std::endl;
    std::cout << "5. Save Data" << std::endl;
    std::cout << "6. Load Data" << std::endl;
    std::cout << "7. Exit" << std::endl;
}

int main() {
    SocialNetwork network;
    int choice;
    std::string username, friendUsername, message, filename;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                network.createUser(username);
                break;
            case 2:
                std::cout << "Enter your username: ";
                std::cin >> username;
                std::cout << "Enter friend's username: ";
                std::cin >> friendUsername;
                network.addFriend(username, friendUsername);
                break;
            case 3:
                std::cout << "Enter your username: ";
                std::cin >> username;
                std::cout << "Enter your message: ";
                std::cin.ignore();
                std::getline(std::cin, message);
                network.postMessage(username, message);
                break;
            case 4:
                std::cout << "Enter username: ";
                std::cin >> username;
                network.displayUserProfile(username);
                break;
            case 5:
                std::cout << "Enter filename to save: ";
                std::cin >> filename;
                network.saveData(filename);
                break;
            case 6:
                std::cout << "Enter filename to load: ";
                std::cin >> filename;
                network.loadData(filename);
                break;
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
    return 0;
}
