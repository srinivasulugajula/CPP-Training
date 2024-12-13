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

class CircularLinkedList {
private:
	Node* head;

public:
	CircularLinkedList() {
		head = nullptr;
	}

	~CircularLinkedList() {
		if (head) {
			Node* temp = head;
			do {
				Node* nextNode = temp->next;
				delete temp;
				temp = nextNode;
			} while (temp != head);
		}
	}

	void insert(int value) {
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			newNode->next = head;
			cout << "Inserted " << value << " as the first node." << endl;
			return;
		}

		Node* temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
		cout << "Inserted " << value << " into the circular linked list." << endl;
	}

	void deleteNode(int value) {
		if (!head) {
			cout << "List is empty." << endl;
			return;
		}

		Node* temp = head;
		Node* prev = nullptr;

		do {
			if (temp->data == value) {
				if (temp == head && temp->next == head) {
					delete temp;
					head = nullptr;
					cout << "Deleted the only node in the circular list." << endl;
					return;
				}

				if (temp == head) {
					Node* lastNode = head;
					while (lastNode->next != head) {
						lastNode = lastNode->next;
					}
					lastNode->next = head->next;
					head = head->next;
				} else {
					prev->next = temp->next;
				}

				delete temp;
				cout << "Deleted node with value: " << value << endl;
				return;
			}

			prev = temp;
			temp = temp->next;
		} while (temp != head);

		cout << "Value not found in the circular linked list." << endl;
	}

	void display() {
		if (!head) {
			cout << "List is empty." << endl;
			return;
		}

		Node* temp = head;
		cout << "Circular Linked List: ";
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl;
	}
};

int main() {
	CircularLinkedList cll;

	cll.insert(10);
	cll.insert(20);
	cll.insert(30);
	cll.insert(40);

	cll.display();

	cll.deleteNode(30);
	cll.display();

	cll.deleteNode(10);
	cll.display();

	return 0;
}
