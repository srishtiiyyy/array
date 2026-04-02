/*
=====================================================================
ROTATE ARRAY BY ONE (LEFT ROTATION)
=====================================================================

Problem:
--------
Given an array, rotate it to the left by one position.

---------------------------------------------------------------------

Example:
--------
Input:
nums = [1,2,3,4,5]

Output:
[2,3,4,5,1]

---------------------------------------------------------------------

Company Tags:
-------------
Walmart, MongoDB, Roche, Roblox, Seagate Technology,
Bungie, Goldman Sachs, Deloitte, OYO Rooms, Byju's,
Rakuten, Visa, Texas Instruments, Etsy, HCL Technologies,
Epic Systems, NVIDIA, Reddit, DoorDash, Teladoc Health,
PayPal, Red Hat, Zoho, Robinhood, Micron Technology,
TCS, Cognizant, Accenture, Infosys, Capgemini, Wipro

=====================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
=====================================================================
APPROACH (IN-PLACE SHIFT)
=====================================================================

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

*/
void rotateByOne(vector<int> &nums)
{
    int n = nums.size();

    // Store first element
    int temp = nums[0];

    // Shift all elements left
    for (int i = 1; i < n; i++)
    {
        nums[i - 1] = nums[i];
    }

    // Place first element at end
    nums[n - 1] = temp;
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

    rotateByOne(nums);

    cout << "\nRotated Array:\n";
    for (int x : nums)
        cout << x << " ";

    return 0;
}