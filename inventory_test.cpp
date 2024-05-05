#include <deepstate/DeepState.hpp>
#include "inventory.cpp"

using namespace deepstate;

#define MAX_ITEMS 100

TEST(InventoryManagement, AddItem) {
    Item inventory[MAX_ITEMS];
    int size = 0;
    initializeInventory(inventory, MAX_ITEMS);

    char name[] = "TestItem";
    int quantity = 10;
    double price = 5.99;

    addItem(inventory, size, name, quantity, price);

    ASSERT_EQ(size, 1);
    ASSERT_EQ(strcmp(inventory[0].name, name), 0);
    ASSERT_EQ(inventory[0].quantity, quantity);
    ASSERT_EQ(inventory[0].price, price);
}

TEST(InventoryManagement, RemoveItem) {
    Item inventory[MAX_ITEMS];
    int size = 0;
    initializeInventory(inventory, MAX_ITEMS);

    char name[] = "TestItem";
    int quantity = 10;
    double price = 5.99;

    addItem(inventory, size, name, quantity, price);
    removeItem(inventory, size, name);

    ASSERT_EQ(size, 0);
}

// int main(int argc, char** argv) {
//     DeepState_InitOptions(argc, argv);
//     DeepState_Run();
//     return 0;
// }
