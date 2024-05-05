#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "header.h"
#include <iomanip>

void initializeInventory(Item inventory[], int size) {
    for (int i = 0; i < size; i++) {
        inventory[i].name[0] = '\0';
        inventory[i].quantity = 0;
        inventory[i].price = 0.0;
    }
}

void addItem(Item inventory[], int &size, const char* name, int quantity, double price) {
    strcpy(inventory[size].name, name);
    inventory[size].quantity = quantity;
    inventory[size].price = price;
    size++;
}

void removeItem(Item inventory[], int &size, const char* itemName) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            for (int j = i; j < size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            size--;
            std::cout << "Item removed successfully.\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

void updateItem(Item inventory[], int size, const char* itemName, int newQuantity, double newPrice) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            inventory[i].quantity = newQuantity;
            inventory[i].price = newPrice;
            std::cout << "Item updated successfully.\n";
            return;
        }
    }
    std::cout << "Item not found.\n";
}

bool searchItem(Item inventory[], int size, const char* itemName) { // Adjust return type to bool
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            std::cout << "Item found:\n";
            std::cout << "Name: " << inventory[i].name << "\nQuantity: " << inventory[i].quantity << "\nPrice: " << inventory[i].price << std::endl;
            return true; // Return true if item is found
        }
    }
    std::cout << "Item not found.\n";
    return false; // Return false if item is not found
}
void sortInventory(Item inventory[], int size) {
    std::sort(inventory, inventory + size, [](const Item &a, const Item &b) {
        return strcmp(a.name, b.name) < 0;
    });
    std::cout << "Inventory sorted by item name.\n";
}

void saveInventory(Item inventory[], int size, const char *filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error opening file for writing.\n";
        return;
    }
    file.write(reinterpret_cast<char *>(inventory), size * sizeof(Item));
    file.close();
    std::cout << "Inventory saved to file.\n";
}

void loadInventory(Item inventory[], int &size, const char *filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Error opening file for reading.\n";
        return;
    }
    file.read(reinterpret_cast<char *>(inventory), size * sizeof(Item));
    size = file.gcount() / sizeof(Item);
    file.close();
    std::cout << "Inventory loaded from file.\n";
}

void displayInventory(Item inventory[], int size) {
    std::cout << "Inventory:\n";
    std::cout << std::left << std::setw(20) << "Name" << std::setw(10) << "Quantity" << std::setw(10) << "Price" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << std::left << std::setw(20) << inventory[i].name << std::setw(10) << inventory[i].quantity << std::setw(10) << std::fixed << std::setprecision(2) << inventory[i].price << std::endl;
    }
}

#define MAX_ITEMS 100

// int main() {
//     Item inventory[MAX_ITEMS];
//     int size = 0;
//     int choice;

//     initializeInventory(inventory, MAX_ITEMS);

//     do {
//         std::cout << "\nInventory Management System\n";
//         std::cout << "1. Add Item\n";
//         std::cout << "2. Remove Item\n";
//         std::cout << "3. Update Item\n";
//         std::cout << "4. Search Item\n";
//         std::cout << "5. Sort Inventory\n";
//         std::cout << "6. Save Inventory\n";
//         std::cout << "7. Load Inventory\n";
//         std::cout << "8. Display Inventory\n";
//         std::cout << "9. Exit\n";
//         std::cout << "Enter your choice: ";
//         std::cin >> choice;

//         switch (choice) {
//             case 1: {
//                 char name[50];
//                 int quantity;
//                 double price;
//                 std::cout << "Enter item name: ";
//                 std::cin >> name;
//                 std::cout << "Enter quantity: ";
//                 std::cin >> quantity;
//                 std::cout << "Enter price: ";
//                 std::cin >> price;
//                 addItem(inventory, size, name, quantity, price);
//                 break;
//             }
//             case 2: {
//                 char itemName[50];
//                 std::cout << "Enter the name of the item to remove: ";
//                 std::cin >> itemName;
//                 removeItem(inventory, size, itemName);
//                 break;
//             }
//             case 3: {
//                 char itemName[50];
//                 int newQuantity;
//                 double newPrice;
//                 std::cout << "Enter the name of the item to update: ";
//                 std::cin >> itemName;
//                 std::cout << "Enter new quantity: ";
//                 std::cin >> newQuantity;
//                 std::cout << "Enter new price: ";
//                 std::cin >> newPrice;
//                 updateItem(inventory, size, itemName, newQuantity, newPrice);
//                 break;
//             }
//             case 4: {
//                 char itemName[50];
//                 std::cout << "Enter the name of the item to search: ";
//                 std::cin >> itemName;
//                 searchItem(inventory, size, itemName);
//                 break;
//             }
//             case 5:
//                 sortInventory(inventory, size);
//                 break;
//             case 6:
//                 saveInventory(inventory, size, "inventory.dat");
//                 break;
//             case 7:
//                 loadInventory(inventory, size, "inventory.dat");
//                 break;
//             case 8:
//                 displayInventory(inventory, size);
//                 break;
//             case 9:
//                 std::cout << "Exiting...\n";
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
//         }
//     } while (choice != 9);

//     return 0;
// }
