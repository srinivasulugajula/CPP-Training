#include <iostream>
using namespace std;

// A function that takes a function pointer as a parameter
void performOperation(int x, int y, int (*operation)(int, int)) {
    // Call the function passed as the callback
    cout << "Result: " << operation(x, y) << endl;
}

// A simple function to add two integers
int add(int a, int b) {
    return a + b;
}

// A simple function to multiply two integers
int multiply(int a, int b) {
    return a * b;
}

int main() {
    int x = 5, y = 3;

    // Using function pointer callback to perform addition
    performOperation(x, y, add);  // Result: 8

    // Using function pointer callback to perform multiplication
    performOperation(x, y, multiply);  // Result: 15

    return 0;
}

