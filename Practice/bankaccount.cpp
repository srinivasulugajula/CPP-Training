#include<bits/stdc++.h>
using namespace std;

class SavingsAccount;  // Forward declaration

class BankAccount {
protected:
    string accountholder;
    int balance;

public:
    BankAccount(string name, int bal) {  // Constructor to initialize account holder and balance
        accountholder = name;
        balance = bal;
    }

    string getaccountholder() const {
        return accountholder;
    }

    int getbalance() const {
        return balance;
    }

    virtual void deposit(int amount) {//virtual function
        if (amount > 0) {
            balance += amount;
            cout << "Deposited amount is: " << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    virtual void withdraw(int amount) {//virtual function
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn amount is: " << amount << endl;
        } else {
            cout << "Insufficient Funds" << endl;
        }
    }

    void checkbalance() const {
        cout << "Balance: " << balance << endl;  
    }

    void displayaccountdetails() const {
        cout << "Account Holder: " << accountholder << endl;
        cout << "Balance: " << balance << endl;  
    }

    friend class SavingsAccount; 
};

class SavingsAccount : public BankAccount {
private:
    double interstapplied;  // Fixed spelling of 'interest'

public:
    SavingsAccount(string name, int balance, double interest)
        : BankAccount(name, balance), interstapplied(interest) {  // Corrected constructor initialization
    }

    void displayaccountdetails() const {
        BankAccount::displayaccountdetails();
        cout << "Interest Applied: " << interstapplied << "%" << endl;
    }

    void addInterest() {
        double interest = balance * (interstapplied / 100);  
        balance += interest;
        cout << "Interest added: " << interest << ", New balance: " << balance << endl;
    }

    void withdraw(int amount) { 
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn: " << amount << endl; 
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    void deposit(int amount) { 
        if (amount > 0) {
            balance += amount;
            cout << "Deposited amount is: " << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }
};

int main() {
    BankAccount p1("Srinivas", 10000);
    cout << p1.getaccountholder() << " " << p1.getbalance() << endl;
    p1.deposit(15000);
    p1.withdraw(12000);
    p1.checkbalance();
//Add objects of persons into bacnkAccount vector.
    vector<BankAccount*> account;
    account.push_back(new BankAccount("Srinivas", 10000)); 
    account.push_back(new BankAccount("Naveen", 12000)); 
    account.push_back(new BankAccount("Manoj", 13000));  

    // Display account details
    for (auto acc : account) {
        acc->displayaccountdetails();  // Corrected line: Accessing method using pointer
    }

    //free the memory allocated using 'new' to avoid memory leaks
    for (auto acc : account) {
        delete acc;  
    }

    return 0;
}
