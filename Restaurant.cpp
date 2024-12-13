#include <bits/stdc++.h>
using namespace std;


class resturent {
public:
    string resname;
    string streetname;
    map<string, int> items;
    resturent* next;
    resturent() {
        next = nullptr;
    }
};

class Node {
public:
    string username;
    int phonenum;
    string address;
    Node* next;
    Node() {
        next = nullptr;
    }
};

resturent *head = nullptr;
resturent *tail = nullptr;
Node *head1 = nullptr;
Node *tail1 = nullptr;

bool check(string ordername, string res, vector<int>& prices);
void logindetails(bool &login, string &address);

class swiggy {
private:
    map<string, int> cart;
    vector<int> prices;
    bool login = false;
    string address;

public:
    swiggy() {
        if (head != nullptr) {
            resturent* temp = head;
            cout << "Restaurants present in our application:" << endl;
            while (temp != nullptr) {
                cout << temp->resname << " " << temp->streetname << endl;
                temp = temp->next;
            }
        } else {
            cout << "No Restaurants are available right now:" << endl;
        }
    }

    void displayrestrunts() {
        if (head != nullptr) {
            resturent* temp = head;
            cout << "Restaurants present in our application:" << endl;
            while (temp != nullptr) {
                cout << temp->resname << " " << temp->streetname << endl;
                temp = temp->next;
            }
        } else {
            cout << "No restaurants available." << endl;
        }
    }

    void selectrestrunt(string res) {
        bool flag = false;
        resturent* temp = head;
        while (temp != nullptr) {
            if (temp->resname == res) {
                flag = true;
                cout << "Welcome to " << res << endl;
                for (auto it : temp->items) {
                    cout << it.first << " " << it.second << endl;
                }
            }
            temp = temp->next;
        }

        if (flag) {
            int search;
            do {
                cout << "1: Do you want to add to cart?" << endl;
                cout << "2: Do you want to search another restaurant?" << endl;
                cout << "Please enter 1 or 2" << endl;
                cin >> search;
                string ordername;  // Declare this variable outside the switch
                switch (search) {
                    case 1: {
                        cout << "Enter the order name: " << endl;
                        cin >> ordername;
                        if (check(ordername, res, prices)) {
                            if (login) {
                                cout << "Enter quantity: " << endl;
                                int quantity;
                                cin >> quantity;
                                cart[ordername] = quantity;
                                cout << "Your order is successfully added to your cart" << endl;
                                displayitemsincart();
                            } else {
                                cout << "You are not logged in. Please login." << endl;
                                logindetails(login, address);
                                cout << "Enter quantity: " << endl;
                                int quantity;
                                cin >> quantity;
                                cart[ordername] = quantity;
                                cout << "Your order is successfully added to your cart" << endl;
                                displayitemsincart();
                            }
                        } else {
                            cout << "Your order is not available in this restaurant" << endl;
                        }
                        break;
                    }
                    case 2:
                        displayrestrunts();
                        cout << "Enter restaurant name to search: ";
                        cin >> res;
                        selectrestrunt(res);
                        break;
                    default:
                        cout << "Invalid option!" << endl;
                }
            } while (search != 2);
        }
    }

    void orderitems() {
        cout << "Your cart has:" << endl;
        displayitemsincart();
        cout << "1: Do you want to change quantity of items?" << endl;
        cout << "2: Do you want to add anything to the cart?" << endl;
        
        int change;
        string res; 
        cin >> change;
        switch (change) {
            case 1: {
                cout << "Enter the dish name and quantity:" << endl;
                string dish;
                int quant;
                cin >> dish >> quant;
                cart[dish] = quant;
                orderitems();
                break;
            }
            case 2:
                displayrestrunts();
                cout << "Enter restaurant name to select: ";
                cin >> res;
                selectrestrunt(res);
                orderitems();
                break;
           
            default:
                cout << "Invalid option!" << endl;
        }
    }

    void displayitemsincart() {
        int total = 0;
        for (auto it : cart) {
            for (auto it1 : prices) {
                total += it1 * it.second;
                cout << it.first << " " << it.second << " " << it1 * it.second << endl;
            }
        }
        cout << "Total: " << total << endl;
    }

    void displayaddress() {
        cout << "Your address: " << address << endl;
    }
};

bool check(string ordername, string res, vector<int>& prices) {
    resturent* temp = head;
    while (temp != nullptr) {
        if (temp->resname == res) {
            for (auto it : temp->items) {
                if (it.first == ordername) {
                    prices.push_back(it.second);
                    return true;
                }
            }
        }
        temp = temp->next;
    }
    return false;
}
class manager{
    
public:
void addrestaurent() {
    string resname;
    string streetname;
    map<string, int> items;
    cout << "Enter the restaurant name: ";
    getline(cin, resname);
    cout << "Enter the street name: ";
    getline(cin,streetname);

    char s = 'y';
    while (s != 'n') {
        string itemname;
        int price;
        cout << "Enter price: ";
        cin>>price;
        cout << "Enter item name: ";
         cin.ignore();
        getline(cin, itemname);
        items[itemname] = price;

        cout << "Enter 'y' to continue and 'n' to stop: ";
        cin >> s;

        
        
    }

    resturent* newnode = new resturent;
    newnode->resname = resname;
    newnode->streetname = streetname;
    newnode->items = items;

    if (head == nullptr) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}
};


void logindetails(bool &login, string &address) {
    Node* newnode1 = new Node;
    cout << "Enter username: ";
    cin >> newnode1->username;
    cout << "Enter phone number: ";
    cin >> newnode1->phonenum;
    cout << "Enter your address: ";
    getline(cin,newnode1->address);
    address = newnode1->address;
    if (head1 == nullptr) {
        head1 = newnode1;
        tail1 = newnode1;
    } else {
        tail1->next = newnode1;
        tail1 = newnode1;
    }
    login = true;
}

class Payment {
public:
    Payment(swiggy &obj) {
        cout << "1: UPI Payment" << endl;
        cout << "2: Card Payment" << endl;
        cout << "3: Cash on Delivery" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                string upi_id;
                cout << "Enter UPI ID: ";
                cin >> upi_id;
                UPI_Payment(upi_id, obj);
                break;
            }
            case 2: {
                int cardnumber;
                cout << "Enter Card Number: ";
                cin >> cardnumber;
                card_payment(cardnumber, obj);
                break;
            }
            case 3:
                cashondelivery(obj);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    void UPI_Payment(string upi_id, swiggy &obj) {
        obj.displayitemsincart();
        cout << "Amount successfully paid through UPI ID: " << upi_id << endl;
        cout << "Your order will be delivered at: ";
        obj.displayaddress();
    }

    void card_payment(int cardnumber, swiggy &obj) {
        obj.displayitemsincart();
        cout << "Amount successfully paid through card number: " << cardnumber << endl;
        cout << "Your order will be delivered at: ";
        obj.displayaddress();
    }

    void cashondelivery(swiggy &obj) {
        obj.displayitemsincart();
        cout << "Amount will be paid on COD" << endl;
        cout << "Your order will be delivered at: ";
        obj.displayaddress();
    }
};

int main() {
    swiggy acc1;
    manager mg;
    int choice;
    while (true) {
        cout << "\nWelcome to Swiggy Application!" << endl;
        cout << "1. Add Restaurant" << endl;
        cout << "2. Display Restaurants" << endl;
        cout << "3. Select Restaurant and Order" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                mg.addrestaurent();
                break;
            case 2:
                acc1.displayrestrunts();
                break;
            case 3: {
                string res;
                cout << "Enter the restaurant name to select: ";
                cin >> res;
                acc1.selectrestrunt(res);
                acc1.orderitems();
                break;
            }
            case 4:
                cout << "Thank you for using Swiggy! Have a good day." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
