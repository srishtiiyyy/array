#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pascalTriangleI(int r, int c) {
        return ncr(r-1,c-1);
    }
private:
    int ncr(int n,int r){
        if(r>n-r) r=n-r;    // Use smaller r
        if(r==1) return n;  // Base case: nC1 = n
        int res=1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return res;
    }
};

int main(){
    int r, c;
    cout << "Enter row and column: ";
    cin >> r >> c;

    Solution obj;
    int val = obj.pascalTriangleI(r, c);

    cout << "Element at row " << r << ", column " << c << " is: " << val << endl;

    return 0;
}
