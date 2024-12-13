#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *prev;
    int val;
    Node *next;
    Node(int value){
        prev=nullptr;
        val=value;
        next=nullptr;
    }

};
class doublelinkedlist{
    private:
    Node *head=nullptr;
    Node *tail=nullptr;
    Node *newnode=nullptr;
    Node *temp;
    public:
    void append(int value){
        newnode=new Node(value);
        if(head==nullptr){
            cout<<"created a linkedlist"<<endl;
            head=newnode;
            tail=head;
        }
        else{
            cout<<"new node "<<value<< " is added to the linkedlist"<<endl;
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            
        }
    }
    void prepend(int value){
        newnode=new Node(value);
        if(head==nullptr){
            head=newnode;
            tail=head;
        }
        else{
            cout<<"a node is prepend to the linked list"<<endl;
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
        }
    }
    void deleteatend(){
        if(head!=nullptr){
            cout<<" Node with "<<tail->val<< " is deleted in the list"<<endl;
            temp=tail->prev;
            temp->next=nullptr;
            delete tail;
            tail=temp;
        }
        else{
            cout<<"no linked list is present"<<endl;
        }
    }
    void deletewithvalue(int value){
        temp=head;
        if(temp!=nullptr){
        while(temp!=nullptr){
            if(temp->val==value){
                cout<<"Value with "<<value<<" is deleted in the linked list"<<endl;
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
                break;
            }
            temp=temp->next;
        }
        }
        else{
            cout<<"list is empty"<<endl;
        }
    }
    void display(){
        temp=head;
        cout<<"displaying the values"<<endl;
        if(temp!=nullptr){
            while(temp!=nullptr){
                cout<<temp->val<<"<->";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
       
    }
    void reverse(){
        temp=tail;
       if(head!=nullptr){
           while(temp!=head){
               cout<<temp->val<<"<->";
               temp=temp->prev;
           }
           cout<<head->val<<endl;
       }
    }
    
};
int main(){
    doublelinkedlist list;
    list.append(10);
    list.append(20);
    list.prepend(30);
    list.prepend(40);
    list.deletewithvalue(30);
    list.display();
    list.reverse();
}