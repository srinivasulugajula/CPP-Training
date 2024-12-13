#include <bits/stdc++.h>
using namespace std;

// Ecommerce class
class Ecommerce {
protected:
    string customer;
    string order;
    int quantity;
    int price;
    map<string, int> cart;

public:
    Ecommerce(string name, string ordered, int inventory, int cost) {
        customer = name;
        order = ordered;
        quantity = inventory;
        cart[order] = quantity;
        price = cost * quantity;
    }
    void returnprice()const{
        cout<<price<<endl;
    }
    void clearcart(){
        cart.clear();
        cout<<"cart is empty"<<endl;
    }

    virtual void addorder(string name, int inventory, int cost) {
        cart[name]++;
        quantity += inventory;
        price += inventory * cost;
        cout << "Your Order " << name << " added to the cart" << endl;
    }

    virtual void removeorder(string name, int inventory, int cost) {
        if (cart[name] > inventory) {
            cart[name] -= inventory;
            price -= inventory * cost;
            quantity -= inventory;
        } else {
            cout << "You don't have the item in your cart OR you are removing more than they exist" << endl;
        }
    }

    virtual void addquantity(string name, int inventory, int cost) {
        cart[name] += inventory;
        price += inventory * cost;
        quantity += inventory;
        cout << "Your Order " << name << " has " << cart[name] << " in the cart" << endl;
    }

    virtual void displaycart() {
        if (!cart.empty()) {
            for (auto it : cart) {
                cout << it.first << " " << it.second << endl;
            }
        } else {
            cout << "Cart is empty! Add products to the cart." << endl;
        }

        if (!cart.empty()) {
            cout << "In your cart, there are " << cart.size() << " products and total quantity: " << quantity << endl;
            cout << "Amount you have to pay: " << price << endl;
        }
    }
};

class Electronics : public Ecommerce {
public:
    
    Electronics(string name, string ordered, int inventory, int cost)
        : Ecommerce(name, ordered, inventory, cost) {}

    void addorder(string name, int inventory, int cost) override {
        cart[name]++;
        quantity += inventory;
        price += inventory * cost;
        cout << "Your Order " << name << " added to the cart" << endl;
    }

    void removeorder(string name, int inventory, int cost) override {
        if (cart[name] > inventory) {
            cart[name] -= inventory;
            price -= inventory * cost;
            quantity -= inventory;
        } else {
            cout << "You don't have the item in your cart OR you are removing more than they exist" << endl;
        }
    }

    void addquantity(string name, int inventory, int cost) override {
        cart[name] += inventory;
        price += inventory * cost;
        quantity += inventory;
        cout << "Your Order " << name << " has " << cart[name] << " in the cart" << endl;
    }

    void displaycart() override {
        Ecommerce::displaycart();  
    }
};


class Clothes : public Ecommerce {
public:

    Clothes(string name, string ordered, int inventory, int cost)
        : Ecommerce(name, ordered, inventory, cost) {}

    void addorder(string name, int inventory, int cost) override {
        cart[name]++;
        quantity += inventory;
        price += inventory * cost;
        cout << "Your Order " << name << " added to the cart" << endl;
    }

    void removeorder(string name, int inventory, int cost) override {
        if (cart[name] > inventory) {
            cart[name] -= inventory;
            price -= inventory * cost;
            quantity -= inventory;
        } else {
            cout << "You don't have the item in your cart OR you are removing more than they exist" << endl;
        }
    }

    void addquantity(string name, int inventory, int cost) override {
        cart[name] += inventory;
        price += inventory * cost;
        quantity += inventory;
        cout << "Your Order " << name << " has " << cart[name] << " in the cart" << endl;
    }

    void displaycart()  {
        Ecommerce::displaycart(); 
    }
};

class Payment {
public:
     void processPayment(int card_number, int pin, int amount,Ecommerce *order) {
         order->displaycart();
         cout<<"amount payable is";
         order->returnprice();
         cout<<endl;
        cout << "The amount paid through debit/credit card is: " << amount << endl;
        cout << "Amount paid successfully" << endl;
        cout << "Your order will be delivered in 2 days" << endl;
        order->clearcart();
        cout<<"\n"<<endl;
    }

     void processPayment(int upi, int amount,Ecommerce *order) {
         order->displaycart();
         cout<<"amount payable is";
         order->returnprice();
         cout<<endl;
         
         
        cout << "The amount paid through UPI number " << upi << " is: " << amount << endl;
        cout << "Amount paid successfully" << endl;
        cout << "Your order will be delivered in 2 days" << endl;
        order->clearcart();
        cout<<"\n"<<endl;

    }

     void processPayment(string Cod, int amount,Ecommerce *order) {
         order->displaycart();
         cout<<"amount payable is";
         order->returnprice();
         cout<<endl;
         
         
        cout << "You have chosen Cash on Delivery (COD)" << endl;
        cout << "The amount is to be paid upon delivery" << endl;
        cout << "Your order will be delivered in 4 days" << endl;
        order->clearcart();
        cout<<"\n"<<endl;

    }
};


int main() {
    Ecommerce* order1 = new Electronics("srinivas", "Laptop", 1, 50000);
    order1->addorder("Mobile", 2, 20000);
    order1->displaycart();
    Payment pay;
    pay.processPayment(12345678, 1234, 70000,order1); 

    Ecommerce* order2 = new Clothes("naveen", "T-shirt", 2, 1000);
    order2->addorder("Jeans", 3, 2000);
    order2->displaycart();
    pay.processPayment("COD", 7000,order2);

    delete order1;
    delete order2;

    return 0;
}
