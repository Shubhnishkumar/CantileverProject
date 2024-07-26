#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // include this for std::remove_if

class Item {
public:
    std::string name;
    int quantity;
    double price;

    Item(std::string n, int q, double p) : name(n), quantity(q), price(p) {}
};

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const std::string& name, int quantity, double price) {
        for (auto& item : items) {
            if (item.name == name) {
                item.quantity += quantity;
                std::cout << "Updated " << name << " quantity to " << item.quantity << std::endl;
                return;
            }
        }
        items.push_back(Item(name, quantity, price));
        std::cout << "Added new item: " << name << std::endl;
    }

    void displayItems() const {
        if (items.empty()) {
            std::cout << "Inventory is empty." << std::endl;
            return;
        }
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : items) {
            std::cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: " << item.price << std::endl;
        }
    }

    void removeItem(const std::string& name, int quantity) {
        for (auto& item : items) {
            if (item.name == name) {
                if (item.quantity >= quantity) {
                    item.quantity -= quantity;
                    std::cout << "Removed " << quantity << " of " << name << std::endl;
                    if (item.quantity == 0) {
                        items.erase(std::remove_if(items.begin(), items.end(), [&](const Item& i) {
                            return i.name == name;
                        }), items.end());
                        std::cout << "Removed " << name << " from inventory as quantity is zero" << std::endl;
                    }
                } else {
                    std::cout << "Not enough quantity to remove." << std::endl;
                }
                return;
            }
        }
        std::cout << "Item not found in inventory." << std::endl;
    }
};

void displayMenu() {
    std::cout << "\nInventory Management System" << std::endl;
    std::cout << "1. Add Item" << std::endl;
    std::cout << "2. Display Items" << std::endl;
    std::cout << "3. Remove Item" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;
    std::string name;
    int quantity;
    double price;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                std::cout << "Enter price: ";
                std::cin >> price;
                inventory.addItem(name, quantity, price);
                break;

            case 2:
                inventory.displayItems();
                break;

            case 3:
                std::cout << "Enter item name: ";
                std::cin >> name;
                std::cout << "Enter quantity to remove: ";
                std::cin >> quantity;
                inventory.removeItem(name, quantity);
                break;

            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
