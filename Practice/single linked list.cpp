#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            cout << "Inserted " << value << " as the first node." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at the end." << endl;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "The list is already empty." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Deleted the only node in the list." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Deleted the last node." << endl;
    }

    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);

        if (position < 0) {
            cout << "Invalid position." << endl;
            delete newNode;
            return;
        }

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << value << " at the beginning." << endl;
            return;
        }

        Node* temp = head;
        int index = 0;

        while (temp && index < position - 1) {
            temp = temp->next;
            index++;
        }

        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << "." << endl;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (position < 0) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted the node at position " << position << "." << endl;
            return;
        }

        Node* temp = head;
        int index = 0;

        while (temp->next && index < position - 1) {
            temp = temp->next;
            index++;
        }

        if (temp->next == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Deleted the node at position " << position << "." << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "Linked list reversed." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display();

    list.insertAtPosition(15, 1);
    list.display();

    list.deleteAtPosition(2);
    list.display();

    list.deleteFromEnd();
    list.display();

    list.reverse();
    list.display();

    return 0;
}
