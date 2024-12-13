#include<bits/stdc++.h>
using namespace std;
int main(){
    int row=3;
    int col=4;
    int **arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=i*col+j;
            cout<<arr[i][j]<<" ";
            }
            cout<<endl;
    }
    for(int i=0;i<row;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
// #include <iostream>
// using namespace std;

// int main() {
//     int x = 3, y = 4, z = 5;  // Dimensions of the 3D array

//     // Step 1: Declare a pointer to a pointer to a pointer
//     int ***arr;

//     // Step 2: Allocate memory for 'x' 2D arrays (pointers)
//     arr = new int**[x];

//     // Step 3: Allocate memory for each 2D array (pointers to rows)
//     for (int i = 0; i < x; ++i) {
//         arr[i] = new int*[y];
//     }

//     // Step 4: Allocate memory for each row (actual integer data)
//     for (int i = 0; i < x; ++i) {
//         for (int j = 0; j < y; ++j) {
//             arr[i][j] = new int[z];
//         }
//     }

//     // Step 5: Use the 3D array (example: filling it with values)
//     for (int i = 0; i < x; ++i) {
//         for (int j = 0; j < y; ++j) {
//             for (int k = 0; k < z; ++k) {
//                 arr[i][j][k] = i + j + k;  // Assigning values for demonstration
//             }
//         }
//     }

//     // Step 6: Print the 3D array
//     for (int i = 0; i < x; ++i) {
//         for (int j = 0; j < y; ++j) {
//             for (int k = 0; k < z; ++k) {
//                 cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
//             }
//         }
//     }

//     // Step 7: Deallocate the memory to avoid memory leaks
//     for (int i = 0; i < x; ++i) {
//         for (int j = 0; j < y; ++j) {
//             delete[] arr[i][j];  // Delete each row
//         }
//         delete[] arr[i];  // Delete each 2D array
//     }
//     delete[] arr;  // Delete the pointer to the array of pointers

//     return 0;
// }
