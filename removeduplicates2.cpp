/*
------------------------------------------------------------
💡 Problem 1: Remove Duplicates from Sorted Array I (LeetCode 26)
💡 Problem 2: Remove Duplicates from Sorted Array II (LeetCode 80)
------------------------------------------------------------
1️⃣ Problem I: Remove all duplicates (each element appears once)
2️⃣ Problem II: Allow each element to appear at most twice
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Problem I: Remove all duplicates (each element appears once)
    int removeDuplicatesOnce(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        int i = 0; 
        for(int j = 1; j < n; j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    // Problem II: Remove duplicates allowing at most twice
    int removeDuplicatesAtMostTwice(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; 

        int count = 1; 
        int index = 1; 

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1; 
            }

            if (count <= 2) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index; 
    }
};

int main() {
    vector<int> nums1 = {1,1,2,2,3,3,3};
    vector<int> nums2 = {0,0,1,1,1,1,2,3,3};

    Solution sol;

    // Test Problem I
    int len1 = sol.removeDuplicatesOnce(nums1);
    cout << "Problem I - New Length: " << len1 << "\nModified Array: ";
    for(int i = 0; i < len1; i++) cout << nums1[i] << " ";
    cout << "\n\n";

    // Test Problem II
    int len2 = sol.removeDuplicatesAtMostTwice(nums2);
    cout << "Problem II - New Length: " << len2 << "\nModified Array: ";
    for(int i = 0; i < len2; i++) cout << nums2[i] << " ";
    cout << "\n";

    return 0;
}
