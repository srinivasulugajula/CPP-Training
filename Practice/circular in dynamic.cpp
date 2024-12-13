#include<bits/stdc++.h>
using namespace std;

class carr {
    int *arr;  // Dynamic array
    int size;
    int front, rear;

public:
    carr() {
        cout << "Enter the array size: ";
        cin >> size;
        arr = new int[size];  
        front = rear = -1;
    }

    ~carr() {
        delete[] arr;  
    }

    void add(int val) {
        if (front == -1 && rear == -1) {
            front = rear = 0;  
            arr[rear] = val;
        } else {
            int next_rear = (rear + 1) % size;
            if (next_rear == front) {
                cout << "Queue is full!" << endl;
                return;
            }

            rear = next_rear;
            arr[rear] = val;
        }
    }

    void del() {
        if (front == -1) {
            cout << "Array is empty!" << endl;
            return;
        }

        if (front == rear) {
           
            front = rear = -1;
        } else {
            cout<<"value deleted in the array is:"<<arr[front]<<endl;
            front = (front + 1) % size;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    void peek() {
        if (isEmpty()) {
            cout << "No elements present in the array" << endl;
        } else {
            cout << "The peek element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No elements present in the array" << endl;
        } else {
            cout << "The values in the array are: ";
            int i = front;
            while (i != rear) {
                cout << arr[i] << " ";
                i = (i + 1) % size;
            }
            cout << arr[rear] << endl;  
        }
    }
};

int main() {
    carr arr1;
    arr1.add(10);
    arr1.add(20);
    arr1.add(30);
    arr1.add(40);
    arr1.add(50);
    arr1.add(60);
    arr1.display();
    arr1.del();
    arr1.peek();
    arr1.display();
}
