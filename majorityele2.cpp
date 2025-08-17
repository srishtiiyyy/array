#include<bits/stdc++.h>
using namespace std;
//BRUTE-ITERATION
//BETTER---
  vector<int> majorityElement(vector<int>& nums) {
        vector<int>list;
        map<int,int>mpp;
        int n=nums.size();
        int mini=(int)(n/3)+1;

        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>=mini){
                list.push_back(it.first);
            }
            if(list.size()==2)break;
        }
        sort(list.begin(),list.end());
        return list;
    }
    
vector<int> majorityElement1(vector<int>& nums) {
    int n = nums.size(); 
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // 1st pass: find candidates
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && el2 != nums[i]) {
            cnt1 = 1;
            el1 = nums[i]; 
        }
        else if (cnt2 == 0 && el1 != nums[i]) {
            cnt2 = 1;
            el2 = nums[i]; 
        } 
        else if (nums[i] == el1) {
            cnt1++;
        } 
        else if (nums[i] == el2) {
            cnt2++; 
        } 
        else {
            cnt1--; 
            cnt2--;
        }
    }

    // 2nd pass: verify counts
    cnt1 = 0, cnt2 = 0; 
    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++; 
        if (nums[i] == el2) cnt2++;
    }

    int mini = n / 3 + 1;
    vector<int> result; 
    if (cnt1 >= mini) result.push_back(el1);
    if (cnt2 >= mini && el1 != el2) result.push_back(el2);

    sort(result.begin(), result.end()); 
    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> ans = majorityElement1(nums);

    cout << "Majority elements (> n/3 times): ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}