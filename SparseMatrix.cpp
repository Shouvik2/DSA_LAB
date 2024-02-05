#include <iostream>
#include <vector>
using namespace std;

bool isSparseMatrix(const vector<vector<int>>& matrix) {
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    int zeroCount = 0;
    int nonZeroCount = 0;
    for (int i = 0; i < rowCount;i++) {
        for (int j = 0; j < colCount;j++) {
            if (matrix[i][j] == 0) zeroCount++;
            else nonZeroCount++;
        }
    }
    // Adjust the threshold based on your criteria for sparsity
    return zeroCount > nonZeroCount;
}
int main() {
    int rowCount, colCount;
    cout << "Enter the number of rows: ";
    cin >> rowCount;
    cout << "Enter the number of columns: ";
    cin >> colCount;
    vector<vector<int>> matrix(rowCount, vector<int>(colCount));
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rowCount;i++) {
        for (int j = 0; j < colCount;j++) {
            cout << "Enter element at position (" << i << ", " << j  << "): ";
            cin >> matrix[i][j];
        }
    }
    if (isSparseMatrix(matrix)) cout << "The matrix is sparse.\n";
    else cout << "The matrix is not sparse.\n";
}