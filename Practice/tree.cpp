#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int val) {
        left = nullptr;
        data = val;
        right = nullptr;
    }
};

class Btree {
private:
    Node *root;
    
public:
    Btree() {
        root = nullptr;
    }

    Node* insert(Node *root) {
        int value;
        cout << "Enter the value of node (-1 to stop): ";
        cin >> value;
        if(value == -1) return nullptr;
        Node* newnode = new Node(value);
        cout << "Enter the left child of " << value << endl;
        newnode->left = insert(newnode->left);
        cout << "Enter the right child of " << value << endl;
        newnode->right = insert(newnode->right);
        return newnode;
    }

    void insert() {
        root = insert(root);
    }

    Node* retrnroot() {
        return root;
    }

    void inorder(Node *root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }

    // Function to add a new node at the end (rightmost position) of the tree
    void addNodeAtEnd(int value) {
        if (root == nullptr) {
            cout<<"Node value with "<<value<< "is added"<<endl;
            root = new Node(value); // If tree is empty, new node is the root.
            return;
        }

        Node* current = root;
        while (current != nullptr) {
            // If the current node doesn't have a left or right child, insert a node here.
            if (current->left == nullptr) {
                cout<<"Node value with "<<value<< "is added at left"<<endl;

                current->left = new Node(value);
                return;
            } else if (current->right == nullptr) {
                cout<<"Node value with "<<value<< "is added at right"<<endl;

                current->right = new Node(value);
                return;
            }

            // Otherwise, go to the left or right child.
            // You can choose which child to visit depending on how you want to traverse.
            if (current->left) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
};

int main() {
    Btree tree;
    tree.insert(); // Insert initial nodes

    // Print inorder traversal before adding a new node at the end.
    cout << "Inorder Traversal of the tree: ";
    tree.printInorder();

    // Add a new node at the end of the tree.
    tree.addNodeAtEnd(100); // Adding the value '100' at the end.

    // Print inorder traversal after adding the new node.
    cout << "Inorder Traversal of the tree after adding node at the end: ";
    tree.printInorder();
    
    return 0;
}

