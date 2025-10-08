/*
------------------------------------------------------------
💡 Problem: Remove Duplicates from Sorted Array (LeetCode 26)
------------------------------------------------------------
Given a sorted integer array nums, remove the duplicates in-place 
such that each element appears only once and returns the new length.

The relative order of the elements should be kept the same.

------------------------------------------------------------
Example:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5
Modified nums = [0,1,2,3,4,_,_,_,_,_]

------------------------------------------------------------
🔹 Approach: Two Pointers
------------------------------------------------------------
1️⃣ Use two pointers i and j:
    - i points to the last unique element's position.
    - j traverses the array.
2️⃣ If nums[i] != nums[j], increment i and update nums[i] = nums[j].
3️⃣ Return i+1 as the new length.

Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    cout << "\n🔹 Remove Duplicates from Sorted Array\n";
    cout << "--------------------------------------------\n";

    int newLength = removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
