#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> result(numRows);
    for(int i=0; i<numRows; i++){
        result[i] = vector<int>(i+1, 1);
        for(int j=1; j<i; j++){
            result[i][j] = result[i-1][j] + result[i-1][j-1];
        }
    }
    return result;
}

int main(){
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;

    vector<vector<int>> triangle = generatePascal(numRows);

    cout << "Pascal's Triangle up to " << numRows << " rows:\n";
    for(auto &row : triangle){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
