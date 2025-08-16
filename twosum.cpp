#include<bits/stdc++.h>
using namespace std;

vector<int> twosumbrute(vector<int> &arr,int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ // start from i+1
            if(arr[i]+arr[j] == target){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

vector<int> twosumoptimal(vector<int>& arr,int target){
    int n = arr.size();
    unordered_map<int,int> mp; // value -> index
    for(int i=0; i<n; i++){
        int remaining = target - arr[i];
        if(mp.find(remaining) != mp.end()){
            return {mp[remaining], i};
        }
        mp[arr[i]] = i;
    }
    return {-1, -1};
}

int main(){
    int n, target;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    // Brute Force
    vector<int> ans1 = twosumbrute(arr, target);
    cout << "Brute Force Result: " << ans1[0] << " " << ans1[1] << endl;

    // Optimal
    vector<int> ans2 = twosumoptimal(arr, target);
    cout << "Optimal Result: " << ans2[0] << " " << ans2[1] << endl;

    return 0;
}
