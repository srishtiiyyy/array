#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "enter number of elements";
    cin >> n;

    vector<int> arr(n);
    int sum = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    int leftsum = 0;
    for(int i = 0; i < n; i++){
        if(leftsum == sum - leftsum - arr[i]){
            cout << i;
            return 0;  // <-- use return 0 instead of return;
        } else {
            leftsum += arr[i];
        }
    }

    cout << -1;
    return 0;
}
