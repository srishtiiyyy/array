#include <bits/stdc++.h>
using namespace std;
//brute
vector<int> leadersBrute(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) { // If any right element is bigger
                flag = false;
                break;
            }
        }
        if (flag) ans.push_back(arr[i]);
    }
    return ans;
}
//optimal
//check if one right the maximum right is smaller than the current
vector<int> leadersoptimal(vector<int>&arr)
{// we begin from the last element and then checkkk iff the current is greater than maximum on the right add it to ans
    //thn reverse to get it fromstarting
    //o(nlogn)
    int maxi=INT_MIN;
    vector<int>ans;
    for(int i=arr.size()-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
            maxi=arr[i];
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = leadersoptimal(arr);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
