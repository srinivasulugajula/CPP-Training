using  namespace std;
#include<iostream>
  
class bank{
    public:
    void add(){
        cout<<"base";
    }
};
class saving:virtual public bank{
    public:
    void sav(){
        cout<<"derived 1"<<endl;
    }
};
class current:virtual  public bank{
    public:
    void curr(){
        cout<<"derived 2"<<endl;
    }
};
class dimond:public saving,    current{
    public:
    void dimonds() {
        cout<<"dimond"<<endl;
    }
};

int main(){
    dimond d;
    d.add();
}