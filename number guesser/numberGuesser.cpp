#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame(int lowerBound, int upperBound) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int targetNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;
    int guess;
    int attempts = 0;

    std::cout << "Guess the number between " << lowerBound << " and " << upperBound << ":\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > targetNumber) {
            std::cout << "Too high!\n";
        } else if (guess < targetNumber) {
            std::cout << "Too low!\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }
    } while (guess != targetNumber);
}

void displayMenu() {
    std::cout << "\nNumber Guesser Game\n";
    std::cout << "1. Play Game\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    int choice;
    int lowerBound = 1;
    int upperBound = 100;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                playGame(lowerBound, upperBound);
                break;
            case 2:
                std::cout << "Exiting the game. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
