//ELEMENT OCCURS MORE THAN N/2 TIMES
//BRUTE--ITERATE
//BETTER-HASHING
//OPTIMAL-MOORE'S VOTING ALGO
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();

    // Moore’s Voting Algorithm
    int cnt = 0;
    int el;

    // Step 1: Find candidate
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            el = nums[i];
            cnt = 1;
        } else if (nums[i] == el) {
            cnt++;
        } else {
            cnt--;
        }
    }

    // Step 2: Verify if candidate is majority
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == el) cnt1++;
    }

    if (cnt1 > n / 2) return el;
    return -1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int ans = majorityElement(nums);

    if (ans != -1)
        cout << "Majority Element: " << ans << endl;
    else
        cout << "No Majority Element found" << endl;

    return 0;
}
