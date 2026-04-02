/*
=====================================================================
ROTATE ARRAY BY K POSITIONS (LEFT ROTATION)
=====================================================================

Problem:
--------
Given an array, rotate it to the left by k positions.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,2,3,4,5,6], k = 2

Output:
[3,4,5,6,1,2]

---------------------------------------------------------------------

Company Tags:
-------------
TCS, Infosys, Wipro, HCLTech, Tech Mahindra, Accenture

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
1️⃣ BRUTE FORCE (USING EXTRA ARRAY)
=====================================================================

Time Complexity: O(n)
Space Complexity: O(k)

*/
void rotateBrute(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    vector<int> temp;

    // Store first k elements
    for (int i = 0; i < k; i++)
        temp.push_back(nums[i]);

    // Shift remaining elements
    for (int i = k; i < n; i++)
        nums[i - k] = nums[i];

    // Put temp elements at end
    for (int i = 0; i < k; i++)
        nums[n - k + i] = temp[i];
}

/*
=====================================================================
2️⃣ OPTIMAL (REVERSAL ALGORITHM)
=====================================================================

Time Complexity: O(n)
Space Complexity: O(1)

Steps:
------
1. Reverse first k elements
2. Reverse remaining n-k elements
3. Reverse whole array

*/

// Reverse helper
void reverseArray(vector<int> &nums, int start, int end)
{
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotateOptimal(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    reverseArray(nums, 0, k - 1);
    reverseArray(nums, k, n - 1);
    reverseArray(nums, 0, n - 1);
}

/*
=====================================================================
MAIN FUNCTION
=====================================================================
*/

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cout << "Enter k: ";
    cin >> k;

    vector<int> nums1 = nums;
    vector<int> nums2 = nums;

    rotateBrute(nums1, k);
    rotateOptimal(nums2, k);

    cout << "\nBrute Rotation:\n";
    for (int x : nums1)
        cout << x << " ";

    cout << "\nOptimal Rotation:\n";
    for (int x : nums2)
        cout << x << " ";

    return 0;
}