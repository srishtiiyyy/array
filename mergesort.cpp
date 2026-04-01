/*
===============================================================
MERGE SORT (Divide and Conquer)
===============================================================

Problem:
--------
Given an array of integers, sort the array using the Merge Sort
algorithm.

Merge Sort follows the Divide and Conquer approach:
1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the sorted halves.

---------------------------------------------------------------
Company Tags:
---------------------------------------------------------------
Mastercard, Stripe, Pinterest, ARM, Snowflake, Rockstar Games,
Cerner, Splunk, Medtronic, Oracle, Broadcom, Uber, DoorDash,
GE Healthcare, Nutanix, Electronic Arts, Docker, Epic Systems,
Alibaba, HCL Technologies, Goldman Sachs, Red Hat,
Seagate Technology, Optum, Airbnb, TCS, Cognizant,
Accenture, Infosys, Capgemini, Wipro, Amazon, Google

---------------------------------------------------------------
Time Complexity:
---------------------------------------------------------------
Best Case    : O(n log n)
Average Case : O(n log n)
Worst Case   : O(n log n)

---------------------------------------------------------------
Space Complexity:
---------------------------------------------------------------
O(n)  (Auxiliary array used during merging)

---------------------------------------------------------------
Stable Sort:
---------------------------------------------------------------
Yes

---------------------------------------------------------------
Approach:
---------------------------------------------------------------
1. Divide array until single element remains.
2. Merge sorted halves.
3. Maintain sorted order while merging.
===============================================================
*/

#include <iostream>
#include <vector>
using namespace std;

/*
---------------------------------------------------------------
Function: merge
Purpose : Merge two sorted halves of the array
---------------------------------------------------------------
Parameters:
arr  -> input array
low  -> starting index
mid  -> middle index
high -> ending index
---------------------------------------------------------------
*/
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;     // temporary array
    int left = low;
    int right = mid + 1;

    // Merge the two halves in sorted order
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining elements from left half
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining elements from right half
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/*
---------------------------------------------------------------
Function: mergeSortHelper
Purpose : Recursive merge sort implementation
---------------------------------------------------------------
*/
void mergeSortHelper(vector<int> &arr, int low, int high)
{
    // Base condition
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    // Sort left half
    mergeSortHelper(arr, low, mid);

    // Sort right half
    mergeSortHelper(arr, mid + 1, high);

    // Merge sorted halves
    merge(arr, low, mid, high);
}

/*
---------------------------------------------------------------
Function: mergeSort
Purpose : Public function to start merge sort
---------------------------------------------------------------
*/
vector<int> mergeSort(vector<int> &nums)
{
    int n = nums.size();
    mergeSortHelper(nums, 0, n - 1);
    return nums;
}

/*
===============================================================
MAIN FUNCTION
===============================================================
*/
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Perform Merge Sort
    vector<int> sorted = mergeSort(arr);

    cout << "\nSorted Array:\n";
    for (int x : sorted)
        cout << x << " ";

    cout << endl;

    return 0;
}