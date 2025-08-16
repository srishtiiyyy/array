#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(){
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter matrix elements:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "Matrix after 90 degree rotation:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
