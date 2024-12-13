#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int data){
        val=data;
        next=nullptr;
    }
};
class Linkedlist{
    Node* head;
    Node* tail;
    Node*temp;
    int count;
    int list=0;
    public:
    Linkedlist(){
        head=nullptr;
        count=0;
    }
    void add(int val){
        Node *newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
            count++;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            count++;
        }
    }
    void del() {
    if (head == nullptr) {
        cout << "No Node Present in the linked list" << endl;
    } else {
        temp = head;
        while (temp->next->next) { // Corrected condition
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        count--;
    }
}
void numnodes(){
    cout<<"the number of nodes present in the linkedlist is:"<<count<<endl;
}

void display() {
    if (!head) {
        cout << "No Node Present in the linked list to display" << endl;
    } else {
        temp = head;
        while (temp != nullptr) { // Corrected condition
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void deletebyvalue(int value) {
    if (!head) {
        cout << "No Node Present in the linked list to delete" << endl;
    } else if (head->val == value) {
        head = head->next;
        count--;
    } else {
        temp = head;
        Node* temp1 = nullptr;  // Corrected variable declaration
        while (temp != nullptr) { // Corrected condition
            if (temp->val == value) {
                cout << "The value " << value << " is deleted from the list" << endl;
                temp1->next = temp->next;
                count=count-1;
                delete temp;
                return;
            }
            temp1 = temp;
            temp = temp->next;
        }
        cout << "No node is present with the value: " << value << " in the linked list" << endl;
    }
}

void insertbyposition(int position, int value) {
    if (position > count || position <= 0 || !head) { // Corrected condition
        cout << "Position is out of range or no nodes present in the linked list" << endl;
    } else {
        temp = head;
        int acc = 1;  // Corrected starting value of acc
        while (temp != nullptr) { // Corrected condition
            if (acc == position - 1) {
                Node* newnode = new Node(value);  // Corrected variable name
                Node* temp1 = temp->next;
                temp->next = newnode;
                newnode->next = temp1;
                count++;
                cout<<"The element :"<<value<<" is added in the "<<position<<" position in the linked list"<<endl;
                break;
            }
            temp = temp->next;
            acc++;
        }
    }
}

void reverse() {
    temp = head;
    Node* previous = nullptr;
    Node* current = head;
    Node* nextnode = nullptr;
    while (current != nullptr) { 
        nextnode = current->next;
        current->next = previous;
        previous = current;
        current = nextnode;
    }
    cout<<"The elements are reversed in the linked list"<<endl;
    head = previous;  
}
Node* reversethenumpositions(Node* head ,int k){
    if(!head)
    return nullptr;
    Node* current=head;
    Node* prev=nullptr;
    Node* nextnode=nullptr;
    int value=0;
    while(current!=nullptr && value<k){
        nextnode=current->next;
        current->next=prev;
        prev=current;
        current=nextnode;
        value++;
        list++;
    }
    if(nextnode!=nullptr && (count-list)>k){
        head->next=reversethenumpositions(nextnode,k);
    }
    else{
        head->next=current;
    }
    return prev;
}
    
    void reverseingroups(int k){
        head=reversethenumpositions(head,k);
    }
  void swaptwonodes(int value1, int value2) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    Node *prev1 = nullptr, *prev2 = nullptr;
    Node *temp1 = head, *temp2 = head;
    bool flag1 = false, flag2 = false;

    while (temp1 != nullptr) {
        if (temp1->val == value1) {
            flag1 = true;
            break;
        }
        prev1 = temp1;
        temp1 = temp1->next;
    }

    while (temp2 != nullptr) {
        if (temp2->val == value2) {
            flag2 = true;
            break;
        }
        prev2 = temp2;
        temp2 = temp2->next;
    }

    if (!flag1 || !flag2) {
        cout << "One or both of the values (" << value1 << " and " << value2 << ") are not present in the linked list." << endl;
        return;
    }

    if (temp1 == temp2) {
        cout << "Both values are the same. No swap needed." << endl;
        return;
    }

    if (prev1 != nullptr) {
        prev1->next = temp2;
    } else {
        head = temp2;
    }

    if (prev2 != nullptr) {
        prev2->next = temp1;
    } else {
        head = temp1;
    }

    Node *tempNext = temp1->next;
    temp1->next = temp2->next;
    temp2->next = tempNext;

    cout << "Swapped " << value1 << " and " << value2 << " in the linked list." << endl;
}




};

int main(){
    Linkedlist list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);
    list.add(60);
    list.display();
    list.reverseingroups(2);
    list.display();
    list.swaptwonodes(20,50);
    list.display();
    list.swaptwonodes(30,40);
    list.display();

    
    


    
}