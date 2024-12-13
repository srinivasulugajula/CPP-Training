#include <iostream>
using namespace std;

struct Node {
    int data;         // Data stored at the node
    Node* left;       // Pointer to left subtree
    Node* right;      // Pointer to right subtree
    int height;       // Height of the node

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1; // New node has initial height as 1 or 0
    }
};

class AVLTree {
private:
    Node* root;

    // Helper function to get the height of a node
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    // Helper function to get balance factor of a node
    int getBalanceFactor(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Right rotate
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // Update the heights
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotate
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update the heights
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Recursive function to insert a value into the AVL tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        // Perform normal BST insert
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node; // Duplicates are not allowed
        }

        // Update the height of the current node
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        // Get the balance factor to check if this node is now unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node; // Return the unchanged node
    }

    // Recursive function to delete a node from the AVL tree
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            cout << "Value not found in tree." << endl;
            return nullptr;
        }

        // Perform normal BST delete
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node to be deleted found
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    delete node;
                    return nullptr;
                } else { // One child case
                    delete node;
                    return temp;
                }
            } else {
                // Node with two children, get the in-order successor
                Node* temp = node->right;
                while (temp->left) {
                    temp = temp->left;
                }

                // Copy the successor's data to this node
                node->data = temp->data;

                // Delete the successor recursively
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // Update the height after deletion
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        // Get the balance factor to check if this node is now unbalanced
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // Left Right Case
        if (balance > 1 && getBalanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Right Left Case
        if (balance < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Recursive function to perform in-order traversal
    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

public:
    AVLTree() {
        root = nullptr; // Initialize an empty AVL tree
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    void display() {
        cout << "In-order Traversal of AVL Tree: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(15);
    avl.insert(25);
    avl.insert(5);
    avl.insert(1);

    avl.display();

    cout << "Deleting 15" << endl;
    avl.deleteValue(15);
    avl.display();

    cout << "Deleting 20" << endl;
    avl.deleteValue(20);
    avl.display();

    return 0;
}
