#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];     
        int n = prices.size();
        int maxprofit = 0;

        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mini;     
            maxprofit = max(maxprofit, cost);
            mini = min(mini, prices[i]);    
        }
        return maxprofit;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) cin >> prices[i];

    Solution sol;
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;

    return 0;
}
