#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;  
        int right = 0;    

        // Swap elements if nums1[left] > nums2[right]
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--; 
                right++;
            } else {
                break;
            }
        }

        // Sort both parts
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());

        // Copy nums2 into nums1’s extra space
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }
    }
};

int main() {
    int m, n;
    cout << "Enter number of elements in nums1 (excluding extra 0s): ";
    cin >> m;
    cout << "Enter number of elements in nums2: ";
    cin >> n;

    vector<int> nums1(m + n), nums2(n);

    cout << "Enter elements of nums1 (first " << m << " elements sorted, rest 0s): ";
    for (int i = 0; i < m; i++) cin >> nums1[i];

    cout << "Enter elements of nums2 (sorted): ";
    for (int i = 0; i < n; i++) cin >> nums2[i];

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    return 0;
}
