#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "\n";
}

// Utility function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> temp(n); // Temporary array to store boundary elements

        int i, tempNum, c;
        int scol = 0, ecol = n - 1, srow = 0, erow = n - 1;

        while (srow < erow) {

            c = 1;
            // Store left boundary in temp (bottom to top)
            for (i = erow-1; i >=srow; i--) {
                temp[c] = matrix[i][scol];
                c++;
            }

            printVector(temp);

            c = 1;
            // Top boundary (left to right)
            for (i = scol+1; i <= ecol; i++) {
                tempNum = temp[c];
                temp[c] = matrix[srow][i];
                matrix[srow][i] = tempNum;
                c++;
            }

            printVector(temp);
            c = 1;
            // Right boundary (top to bottom)
            for (i = srow+1; i <= erow; i++) {
                tempNum = temp[c];
                temp[c] = matrix[i][ecol];
                matrix[i][ecol] = tempNum;
                c++;
            }

            printVector(temp);
            c = 1;
            // Bottom boundary (right to left)
            for (i = ecol-1; i >= scol; i--) {
                tempNum = temp[c];
                temp[c] = matrix[erow][i];
                matrix[erow][i] = tempNum;
                c++;
            }

            printVector(temp);
            c = 1;
            // Left boundary (bottom to top again)
            for (i = erow-1; i >= srow; i--) {
                tempNum = temp[c];
                temp[c] = matrix[i][scol];
                matrix[i][scol] = tempNum;
                c++;
            }

            printVector(temp);
             cout<<"\n MATRIX IS "<<endl;
            // Move inward to next layer
            printMatrix(matrix);
            cout<<endl;
            srow++;
            erow--;
            scol++;
            ecol--;
        }
    }
};

// Utility function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }
}


int main() {
    vector<vector<int>> matrix = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    Solution obj;
    obj.rotate(matrix);

    cout << "Matrix after rotation:\n";
    printMatrix(matrix);

    return 0;
}
