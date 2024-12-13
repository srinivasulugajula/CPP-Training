#include <iostream>
#include <vector>
using namespace std;
class SparseMatrixCSR {
public:
     vector<int> values;          // Non-zero values
     vector<int> col_indices;     // Column indices of non-zero values
     vector<int> row_ptr;         // Row pointer (start of each row in values)

    // Constructor to initialize a sparse matrix of size rows x cols
    SparseMatrixCSR(int rows, int cols) {
        row_ptr.resize(rows + 1, 0);
    }
    

    // Insert a non-zero element in the sparse matrix at (row, col)
    void insert(int row, int col, int value) {
        values.push_back(value);
        col_indices.push_back(col);
        row_ptr[row + 1]++;
    }

    // Convert row_ptr into correct cumulative values (prefix sum)
    void finalize() {
        for (int i = 1; i < row_ptr.size(); ++i) {
            row_ptr[i] += row_ptr[i - 1];
        }
    }

    // Get the value at (row, col), or return 0 if the element is not set
    int get(int row, int col) {
        for (int i = row_ptr[row]; i < row_ptr[row + 1]; ++i) {
            if (col_indices[i] == col) {
                return values[i];
            }
        }
        return 0; // Default value if element is not present
    }

    // Print the matrix in its sparse form
    void print() {
         cout << "Values: ";
        for (int val : values) {
             cout << val << " ";
        }
         cout <<  endl;

         cout << "Column Indices: ";
        for (int col : col_indices) {
             cout << col << " ";
        }
         cout <<  endl;

         cout << "Row Pointers: ";
        for (int ptr : row_ptr) {
             cout << ptr << " ";
        }
         cout <<  endl;
    }
};

int main() {
    // Create a sparse matrix of size 3x4 (3 rows, 4 columns)
    SparseMatrixCSR matrix(3, 4);

    // Insert some non-zero elements
    matrix.insert(0, 2, 3);
    matrix.insert(1, 0, 4);
    matrix.insert(2, 1, 5);
    matrix.insert(2, 3, 6);

    // Finalize the row_ptr array (cumulative sum)
    matrix.finalize();

    // Print the sparse matrix
    matrix.print();

    // Access some elements
     cout << "Element at (2, 1): " << matrix.get(2, 1) <<  endl; // Output: 5
     cout << "Element at (0, 0): " << matrix.get(0, 0) <<  endl; // Output: 0

    return 0;
}
