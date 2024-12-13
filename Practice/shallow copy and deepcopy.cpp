#include<iostream>
using namespace std;
class A{
    private:
    int a;
    int b;
    int *c;
    public:
    A(int val){
        a=10;
        b=20;
        c=new int;
        *c=val;
    }
    A(A const &obj){
        a=obj.a;
        b=obj.b;
        c=new int;
        *c=*(obj.c);
    }
    void display(){
        cout<<a<<" "<<b<<" "<<c<<" "<<*c<<"\n";
    }
    
    
};
int main(){
    A obj(30);
    obj.display();
    A obj2=obj;
    obj2.display();

}


