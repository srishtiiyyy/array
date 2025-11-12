//agr ek element bhi 1 hai to sab one hojayengee
//n-1 operations lgenge tab
//generic form=n-(number of 1's)
//if no one is there then we need to convert any one element to 1
/*
------------------------------------------------------------------------------
🧾 Problem: Minimum Number of Operations to Make All Array Elements Equal to 1
(LeetCode #2654)
------------------------------------------------------------------------------
You are given an integer array `nums`.  
You can perform the following operation on the array **any number of times**:

- Choose any adjacent pair of elements and replace one of them with their GCD.

Return the minimum number of operations required to make **all the elements 1**.  
If it’s not possible, return -1.

------------------------------------------------------------------------------
Example 1:
Input: nums = [2,6,3,4]
Output: 4
Explanation:
- gcd(2,6)=2, gcd(6,3)=3, gcd(3,4)=1
- It takes 1 operation to get a 1, then (n - 1) = 3 more to spread it.

Example 2:
Input: nums = [2,10,6,14]
Output: -1
Explanation:
No subarray has gcd equal to 1.

------------------------------------------------------------------------------
Constraints:
- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 10^9
------------------------------------------------------------------------------
💡 Approach:
1. If there is already at least one `1` in the array →  
   It takes `(n - count(1))` operations to make all 1s.
2. Otherwise, find the **shortest subarray** whose GCD = 1.
   - Because that’s where we can first generate a `1`.
3. Once we create one `1`, it takes `(n - 1)` additional operations to spread it to all.
4. If no subarray has GCD = 1 → return `-1`.

Time Complexity: O(n²)
Space Complexity: O(1)
------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to calculate minimum operations
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int count1 = 0;

    // Step 1: Count existing 1s
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) count1++;
    }

    // If already contains 1s → Only need to convert others
    if (count1 > 0) {
        return n - count1;
    }

    // Step 2: Find shortest subarray with gcd == 1
    int minLength = INT_MAX;
    for (int i = 0; i < n; i++) {
        int currentGCD = nums[i];
        for (int j = i + 1; j < n; j++) {
            currentGCD = gcd(currentGCD, nums[j]);
            if (currentGCD == 1) {
                minLength = min(minLength, j - i);
                break; // No need to go further; subarray found
            }
        }
    }

    // Step 3: If no gcd == 1 found, return -1
    if (minLength == INT_MAX) return -1;

    // Step 4: Total operations = minLength (to create 1) + (n - 1) to spread it
    return minLength + (n - 1);
}

// Main function for user input
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minOperations(nums);

    if (result == -1)
        cout << "It is not possible to make all elements equal to 1.\n";
    else
        cout << "Minimum number of operations to make all elements 1: " << result << endl;

    return 0;
}
