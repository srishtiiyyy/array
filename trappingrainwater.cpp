#include <bits/stdc++.h>
using namespace std;

/*
Problem: Trapping Rain Water
- Given an array 'height' representing elevation map
- Find how much water can be trapped after raining.
- Idea: For each bar, water trapped = min(max height to left, max height to right) - height[i]
*/

vector<int> leftmax(vector<int>& height) {
    int n = height.size();
    vector<int> left(n);
    left[0] = height[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(height[i], left[i - 1]);
    }
    return left;
}

vector<int> rightmax(vector<int>& height) {
    int n = height.size();
    vector<int> right(n);
    right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(height[i], right[i + 1]);
    }
    return right;
}

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    // Precompute left max and right max for all bars
    vector<int> left = leftmax(height);
    vector<int> right = rightmax(height);

    int water = 0;
    for (int i = 0; i < n; i++) {
        water += max(0, min(left[i], right[i]) - height[i]);
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << trap(height) << endl; // Output: 6
    return 0;
}
