#include <bits/stdc++.h>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    vector<int> ans;
    int i = 0, j = 0;

    // Find intersection
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            i++;
        }
        else if (nums1[i] > nums2[j]) {
            j++;
        }
        else {
            // Avoid duplicates in result
            if (ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }

    cout << "Intersection of arrays: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
