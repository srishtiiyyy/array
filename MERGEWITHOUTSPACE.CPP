/*
------------------------------------------------------------
💡 Problem: Merge Sorted Array (LeetCode 88)
------------------------------------------------------------
You are given two sorted integer arrays nums1 and nums2, and two integers m and n,
representing the number of initialized elements in nums1 and nums2 respectively.

nums1 has a size of m + n, where the last n elements are 0 
and should be ignored. Merge nums2 into nums1 so that it becomes
a single sorted array.

------------------------------------------------------------
Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output:
nums1 = [1,2,2,3,5,6]

------------------------------------------------------------
🔹 Approach: Swap + Sort
------------------------------------------------------------
1️⃣ Start two pointers:
     - left = m-1 (last valid element in nums1)
     - right = 0 (first element in nums2)
2️⃣ Swap elements if nums1[left] > nums2[right].
3️⃣ Decrement left, increment right.
4️⃣ After all possible swaps:
     - Sort the first m elements of nums1
     - Sort all elements of nums2
5️⃣ Copy nums2 back into the last n positions of nums1.
------------------------------------------------------------
Time Complexity: O((m + n) * log(m + n))
Space Complexity: O(1)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m - 1;
    int right = 0;

    // Step 1: Swap larger elements from nums1 with smaller ones from nums2
    while (left >= 0 && right < n) {
        if (nums1[left] > nums2[right]) {
            swap(nums1[left], nums2[right]);
            left--;
            right++;
        } else {
            break; // already in correct order
        }
    }

    // Step 2: Sort both arrays
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());

    // Step 3: Merge nums2 elements into nums1
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    cout << "\n🔹 Merge Sorted Array (Swap + Sort Approach)\n";
    cout << "--------------------------------------------\n";

    mergeSortedArrays(nums1, m, nums2, n);

    cout << "Merged Sorted Array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    return 0;
}
