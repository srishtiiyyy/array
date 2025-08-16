#include<bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>>& matrix){
    int n=matrix.size();//rowsize
    int m=matrix[0].size();//columnsize
    int top=0;//for row
    int left=0;//for column
    int right=m-1;//for column
    int bottom=n-1;//for row
    vector<int>ans;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;
    cout << "Enter number of columns: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the elements of the matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiral(matrix);

    cout << "Spiral order: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
