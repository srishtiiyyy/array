#include <bits/stdc++.h>
using namespace std;

/*
Problem: 4-Sum
--------------
Given an array nums of n integers and a target value,
find all unique quadruplets (a, b, c, d) such that:
    a + b + c + d = target

Constraints:
- No duplicate quadruplets
- Order inside quadruplet doesn’t matter
*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());  // sort to handle duplicates easily
    vector<vector<int>> ans;

    // Fix the first two numbers (i and j)
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // avoid duplicate i

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // avoid duplicate j

            // Two-pointer approach for remaining two numbers
            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // skip duplicates for k and l
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum > target) {
                    l--; // need smaller sum
                }
                else {
                    k++; // need larger sum
                }
            }
        }
    }
    return ans;
}

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets with sum " << target << " are:\n";
    for (auto &quad : result) {
        for (int x : quad) cout << x << " ";
        cout << endl;
    }

    return 0;
}
