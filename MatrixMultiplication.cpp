#include <iostream>
using namespace std;
int main() {
    int row1, col1, row2, col2;
    // Get dimensions of the first matrix from the user
    cout << "Enter the number of rows for the first matrix: ";
    cin >> row1;
    cout << "Enter the number of columns for the first matrix: ";
    cin >> col1;
    // Get dimensions of the second matrix from the user
    cout << "Enter the number of rows for the second matrix: ";
    cin >> row2;
    cout << "Enter the number of columns for the second matrix: ";
    cin >> col2;
    // Check if matrix multiplication is possible
    if (col1 != row2) {
        cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1; // Exit with an error code
    }
    // Declare matrices
    int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];
    // Input elements of the first matrix from the user
    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col1;j++) {
            cout << "Enter element at position (" << i  << "," << j  << "): ";
            cin >> matrix1[i][j];
        }
    }
    // Input elements of the second matrix from the user
    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < row2;i++) {
        for (int j = 0; j < col2;j++) {
            cout << "Enter element at position (" << i  << "," << j  << "): ";
            cin >> matrix2[i][j];
        }
    }
    // Initialize the result matrix with zeros
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col2;j++) {
            result[i][j] = 0;
        }
    }
    // Perform matrix multiplication
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col2;j++) {
            for (int k = 0; k < col1;k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    // Display the result matrix
    cout << "Resultant matrix after multiplication:" << endl;
    for (int i = 0; i < row1;i++) {
        for (int j = 0; j < col2;j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0; // Exit with success
}