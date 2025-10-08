/*
------------------------------------------------------------
💡 Problem: Remove Element (LeetCode 27)
------------------------------------------------------------
Given an integer array nums and an integer val, remove all occurrences of val in nums 
in-place. The relative order of the elements may be changed.

Return the new length of the array after removal.

------------------------------------------------------------
Example:
Input: nums = [3,2,2,3,4], val = 3
Output: 3
Modified nums = [2,2,4,_,_]

------------------------------------------------------------
🔹 Approach: Two Pointers
------------------------------------------------------------
1️⃣ Use a pointer 'index' to track position to insert non-val elements.
2️⃣ Traverse the array:
     - If nums[i] != val, place it at nums[index] and increment index.
3️⃣ Return index as the new length.

Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main() {
    vector<int> nums = {3, 2, 2, 3, 4};
    int val = 3;

    cout << "\n🔹 Remove Element Problem\n";
    cout << "--------------------------------------------\n";

    int newLength = removeElement(nums, val);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
