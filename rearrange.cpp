#include <bits/stdc++.h>
using namespace std;

vector<int> arrange(vector<int>& arr) {
    int n = arr.size();
    vector<int> pos, neg, ans(n);
    
    // Separate positives and negatives
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    // Fill ans alternately (assuming equal count of pos & neg)
    for (int i = 0; i < n / 2; i++) {
        ans[2 * i] = pos[i];
        ans[2 * i + 1] = neg[i];
    }

    return ans;
}
  vector<int> rearrangeArray(vector<int>& nums) {
                int n=nums.size();
                vector<int>ans(n);
                        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;
    }
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = arrange(arr);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
