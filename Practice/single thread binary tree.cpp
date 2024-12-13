#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    bool rightThread; // This flag indicates whether the right pointer is a thread

    Node(int value) {
        data = value;
        left = right = nullptr;
        rightThread = false;
    }
};

// Function to insert a new node in the single-threaded BST
Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);

    if (root == nullptr) {
        return newNode; // If the tree is empty, return the new node as root
    }

    Node* parent = nullptr;
    Node* current = root;

    
    while (current != nullptr) {
        parent = current;
        if (value < current->data) {
            // Move to left subtree
            if (current->left == nullptr || current->left->rightThread) {
                break;
            }
            current = current->left;
        } else {
            // Move to right subtree
            if (current->right == nullptr || current->rightThread) {
                break;
            }
            current = current->right;
        }
    }

    if (value < parent->data) {
        // Insert as the left child
        parent->left = newNode;
        newNode->right = parent;
        newNode->rightThread = true; // Threading the right child to the parent
    } else {
        // Insert as the right child
        parent->right = newNode;
        parent->rightThread = false;
        newNode->left = nullptr;
        newNode->right = nullptr;
    }

    return root;
}

// In-order traversal of the single-threaded BST without recursion
void inorderTraversal(Node* root) {
    if (root == nullptr) return;

    // Find the leftmost node
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    // Traverse the tree
    while (current != nullptr) {
        cout << current->data << " ";

        // If the node has a thread (rightThread is true), move to the in-order successor
        if (current->rightThread) {
            current = current->right; // Follow the thread
        } else {
            // Otherwise, move to the right child and continue to the leftmost node
            current = current->right;
            while (current != nullptr && current->left != nullptr) {
                current = current->left;
            }
        }
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Perform in-order traversal
    cout << "In-order traversal of the single-threaded binary search tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
