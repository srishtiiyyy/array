#include <bits/stdc++.h>
using namespace std;

int largestele(vector<int> &arr, int n) {
    int largeste = arr[0];
    for (int i = 1; i < n; i++) { 
        if (arr[i] > largeste) {
            largeste = arr[i];
        }
    }
    return largeste;
}

int main() {
    int n;
    cout << "ENTER NUMBER OF ELEMENTS: ";
    cin >> n;

    vector<int> arr(n); // ✅ Give size to avoid out-of-bounds

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Largest element is " << largestele(arr, n) << endl;
    return 0;
}
