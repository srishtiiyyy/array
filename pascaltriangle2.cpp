#include <bits/stdc++.h>
using namespace std;

vector<int> pascalTriangleII(int r) {
    vector<int> ans(r);
    ans[0] = 1;
    for(int i=1; i<r; i++){
        ans[i] = (ans[i-1] * (r-i)) / i;
    }
    return ans;
}

int main() {
    int r;
    cout << "Enter row number: ";
    cin >> r;

    vector<int> row = pascalTriangleII(r);

    cout << "Pascal Triangle Row " << r << ": ";
    for(int x : row){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
