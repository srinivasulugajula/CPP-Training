#include<bits/stdc++.h>

using namespace std;

class InventorySystem {
private:
    int rows, cols;
    string storeName;
    vector<string> items;
    vector<vector<vector<int>>> inventory;
    int quantity;

public:
    
    InventorySystem(int r, int c, const string& name) : rows(r), cols(c), storeName(name) {}

    void displayStoreName() {
        cout << "Welcome to store: " << storeName << "\n";
    }

    void addItem(string item, int quantity, int row, int col) {
        auto it = find(items.begin(), items.end(), item);
        if (it == items.end()) {
            items.push_back(item);
            inventory.push_back(vector<vector<int>>(rows, vector<int>(cols, 0)));
        }
        int itemId = distance(items.begin(), it);
        if (quantity > 0) {
            inventory[itemId][row][col] += quantity;
            cout << "Added " << quantity << " of " << item << " to location (" << row << ", " << col << ").\n";
        }
    }

    void removeItem(string item, int quantity, int row, int col) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            int itemId = distance(items.begin(), it);
            if (inventory[itemId][row][col] >= quantity) {
                inventory[itemId][row][col] -= quantity;
                cout << "Removed " << quantity << " of " << item << " from location (" << row << ", " << col << ").\n";
            } else {
                cout << "Not enough stock to remove.\n";
            }
        } else {
            cout << "Item not found.\n";
        }
    }

    void checkStock(string item, int row, int col) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            int itemId = distance(items.begin(), it);
            cout << "Stock of " << item << " at (" << row << ", " << col << ") is " << inventory[itemId][row][col] << ".\n";
        } else {
            cout << "Item not found.\n";
        }
    }

    void displayInventory() {
        for (size_t i = 0; i < items.size(); ++i) {
            cout << items[i] << ":\n";
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (inventory[i][r][c] > 0) {
                        cout << "Location (" << r << ", " << c << "): " << inventory[i][r][c] << "\n";
                    }
                }
            }
        }
    }

    void transferItem(string item, int quantity, int fromRow, int fromCol, int toRow, int toCol) {
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            int itemId = distance(items.begin(), it);
            if (inventory[itemId][fromRow][fromCol] >= quantity) {
                inventory[itemId][fromRow][fromCol] -= quantity;
                addItem(item, quantity, toRow, toCol);
                cout << "Transferred " << quantity << " of " << item << " from (" << fromRow << ", " << fromCol << ") to (" << toRow << ", " << toCol << ").\n";
            } else {
                cout << "Not enough stock to transfer.\n";
            }
        } else {
            cout << "Item not found.\n";
        }
    }

    void lowStockAlert(int threshold) {
        for (size_t i = 0; i < items.size(); ++i) {
            for (int r = 0; r < rows; ++r) {
                for (int c = 0; c < cols; ++c) {
                    if (inventory[i][r][c] < threshold) {
                        cout << "Low stock for " << items[i] << " at location (" << r << ", " << c << "). Stock: " << inventory[i][r][c] << "\n";
                    }
                }
            }
        }
    }
};

class StoreManager {
private:
    unordered_map<string, InventorySystem> stores;

public:
    void createStore(const string& storeName, int rows, int cols) {
        // Emplace directly using the parameters of the constructor for InventorySystem
        stores.emplace(storeName, InventorySystem(rows, cols, storeName));
    }

    InventorySystem& getStore(const string& storeName) {
        auto it = stores.find(storeName);
        if (it != stores.end()) {
            return it->second;
        } else {
            // Handle the case where the store is not found
            cout<<"Store is not found!"<<endl;
        }
    }

    bool storeExists(const string& storeName) {
        return stores.find(storeName) != stores.end();
    }
};

int main() {
    StoreManager manager;
    int rows = 5, cols = 5;

    while (true) {
        cout << "\n1. Create Store\n2. Select Store\n3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        string storeName;
        switch (choice) {
        case 1:
            cout << "Enter store name: ";
            cin >> storeName;
            if (!manager.storeExists(storeName)) {
                manager.createStore(storeName, rows, cols);
                cout << "Store '" << storeName << "' created.\n";
            } else {
                cout << "Store already exists.\n";
            }
            break;

        case 2:
            cout << "Enter store name: ";
            cin >> storeName;
            if (manager.storeExists(storeName)) {
                InventorySystem& store = manager.getStore(storeName);
                store.displayStoreName();

                bool exitStoreMenu = false;
                while (!exitStoreMenu) {
                    cout << "\n1. Add Item\n2. Remove Item\n3. Check Stock\n4. Display Inventory\n5. Transfer Item\n6. Low Stock Alerts\n7. Exit to Main Menu\n";
                    cout << "Enter your choice: ";
                    int choice;
                    cin >> choice;

                    string item;
                    int quantity, row, col, fromRow, fromCol, toRow, toCol, threshold;

                    switch (choice) {
                    case 1:
                        cout << "Enter item name: ";
                        cin >> item;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        cout << "Enter row and column: ";
                        cin >> row >> col;
                        store.addItem(item, quantity, row, col);
                        break;

                    case 2:
                        cout << "Enter item name: ";
                        cin >> item;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        cout << "Enter row and column: ";
                        cin >> row >> col;
                        store.removeItem(item, quantity, row, col);
                        break;

                    case 3:
                        cout << "Enter item name: ";
                        cin >> item;
                        cout << "Enter row and column: ";
                        cin >> row >> col;
                        store.checkStock(item, row, col);
                        break;

                    case 4:
                        store.displayInventory();
                        break;

                    case 5:
                        cout << "Enter item name: ";
                        cin >> item;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        cout << "Enter from row and column: ";
                        cin >> fromRow >> fromCol;
                        cout << "Enter to row and column: ";
                        cin >> toRow >> toCol;
                        store.transferItem(item, quantity, fromRow, fromCol, toRow, toCol);
                        break;

                    case 6:
                        cout << "Enter threshold: ";
                        cin >> threshold;
                        store.lowStockAlert(threshold);
                        break;

                    case 7:
                        exitStoreMenu = true;
                        break;

                    default:
                        cout << "Invalid choice.\n";
                    }
                }
            } else {
                cout << "Store does not exist.\n";
            }
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
