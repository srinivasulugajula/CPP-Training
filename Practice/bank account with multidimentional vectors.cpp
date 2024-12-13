#include<bits/stdc++.h>
using namespace std;
class BankAccount{
    protected:
    int accnumber;
    string accholder;
    int balance;
    public:
    BankAccount(int num,string holder,int bal):accnumber(num),accholder(holder),balance(bal){}
    void deposit(int amount){
        if(amount>=1000){
            cout<<"The amount deposited to your bank account is :"<<amount<<endl;
            balance+=amount;
            cout<<"total balance in your account is:"<<balance<<endl;
        }
        else{
            cout<<"amount should depost above 1000 "<<endl;
        }
        
    }
    void withdraw(int amount){
        if(amount<balance){
            cout<<"amount withdrawn from the account is:"<<amount<<endl;
            balance-=amount;
            
        }
        else if(amount>balance){
            cout<<"Insufficient funds in the bank account"<<endl;
        }
        else{
            cout<<"withdrawl amount should be positive"<<endl;
        }
    }
    void displayall()const{
        cout<<"ACCOUNT HOLDER:"<<accholder<<endl;
        cout<<"ACCOUNT NUMBER:"<<accnumber<<endl;
        cout<<"BALANCE:"<<balance<<endl;
    }
    int getaccountnumber()const{
        return accnumber;
    }
};
class Bankbranch{
    private:
    string bankbranch;
    string bankaddress;
    vector<BankAccount>accounts;
    public:
    Bankbranch(string bbranch,string baddress):bankbranch(bbranch),bankaddress(baddress){}
    
    void addbankaccount(int number,string name,int bal){
        BankAccount acc1(number,name,bal);
        accounts.push_back(acc1);
        cout<<"New Account is created for"<<name<<" with "<<number<<endl;
    }
    BankAccount* findaccount(int number){
        for(auto &it:accounts){
            if(it.getaccountnumber()==number){
                return &it;
            }
        }
        cout<<"account number "<<number<<" not found "<<endl;
        return nullptr;
    }
    void displayallacounts()const{
        for(auto it:accounts){
            it.displayall();
            cout<<endl;
        }
    }
    string getbranchname()const{
        return bankbranch;
    }
};
class Banksystem{
    private:
    vector<vector<BankAccount>>branches;
    public:
    Banksystem(int noofbranches){
        branches.reserve(noofbranches);
    }
    
    void addaccounttobranch(int index,BankAccount account){
        if(index>branches.capacity()){
            cout<<"index is outof range"<<endl;
        }
        else{
            cout<<"your account is added to your branch"<<endl;
            branches[index].push_back(account);
        }
    }
    void deposittoaccount(int index,int num,int amount){
        if(index<branches.capacity()){
            
             for(auto it:branches[index]){
                 if(it.getaccountnumber()==num){
                     it.deposit(amount);
                     
                 }
                 }
             } 
             
            
            else{
                cout<<"index is outof range"<<endl;
            }
        }
    void withdrawinaccount(int index,int num,int amount){
        if(index<branches.capacity()){
            for(auto it:branches[index]){
                if(it.getaccountnumber()==num){
                    it.withdraw(amount);
                    return;
                }
            }
            cout<<"account not found "<<endl;
        }
        else{
            cout<<"index is out of range"<<endl;
        }
    }
    void displayallbranches()const{
        for(int i=0;i<branches.capacity();i++){
            for(auto it:branches[i]){
                it.displayall();
            }
        }
        }
    };
int main(){
    BankAccount acc1(10001,"srinivas",10000);
    Banksystem bank(2);
    bank.addaccounttobranch(0,acc1);
    bank.deposittoaccount(0,10001,20000);
    bank.displayallbranches();
}