#include<bits/stdc++.h>
using namespace std;
//bruteforce----
//1. GENERATE ALL SORTED 2. LINEAR SEARCH 3. NEXT PERMUATION CAN BE ACHIEVED VIA RECURISON THE TIME COMPLEXITY WILL BE VERY HIGH
//AS MINIMUM OF N FACTORIAL WAYS ARE NEEDED
//BETTER----
//USE STL IN CPP- next_permutation(arr.begin(),arr.end())
//OPTIMAL--
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = -1;

    // Step 1: Find the first decreasing element from the right
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            idx = i;
            break;
        }
    }

    // If no such index, the array is the highest permutation → reverse it
    if (idx == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find the just larger element on right side and swap
    for (int i = n - 1; i > idx; i--) {
        if (nums[i] > nums[idx]) {
            swap(nums[i], nums[idx]);
            break;
        }
    }

    // Step 3: Reverse the part after idx
    reverse(nums.begin() + idx + 1, nums.end());
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
