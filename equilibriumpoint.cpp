#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find Equilibrium Index of an Array
-------------------------------------------
An equilibrium index is an index such that the sum of elements
on its left = sum of elements on its right.

Example:
Input: arr = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: 
At index 3 → left sum = (-7+1+5) = -1
             right sum = (-4+3+0) = -1
So index 3 is the equilibrium point.
*/

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    int sum = 0;

    // Read elements and compute total sum
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int leftsum = 0;
    for(int i = 0; i < n; i++){
        // Check if current index is equilibrium
        if(leftsum == sum - leftsum - arr[i]){
            cout << "Equilibrium index: " << i << endl;
            return 0;   // ✅ terminate program correctly
        }
        // Update left sum
        leftsum += arr[i];
    }

    // If no equilibrium index found
    cout << -1 << endl;
    return 0;
}
