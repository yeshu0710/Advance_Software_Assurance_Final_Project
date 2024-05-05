#ifndef INVENTORY_H
#define INVENTORY_H

// Define structure for each item in the inventory
struct Item {
    char name[50];
    int quantity;
    double price; // Changed float to double for better precision
};

// Function prototypes
void initializeInventory(Item inventory[], int size);
void addItem(Item inventory[], int &size, const char* name, int quantity, double price);
void removeItem(Item inventory[], int &size, const char* itemName); 
void updateItem(Item inventory[], int size, const char* itemName, int newQuantity, double newPrice); 
bool searchItem(Item inventory[], int size, const char* itemName);
void sortInventory(Item inventory[], int size);
void saveInventory(Item inventory[], int size, const char *filename);
void loadInventory(Item inventory[], int &size, const char *filename);
void displayInventory(Item inventory[], int size);

#endif
