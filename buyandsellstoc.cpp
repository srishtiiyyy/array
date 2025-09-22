/*
Question: Best Time to Buy and Sell Stock (Leetcode 121)

You are given an array `prices` where `prices[i]` is the price of a stock on day `i`.

- You want to maximize your profit by choosing:
   1. A day to buy the stock (buy day),
   2. A future day to sell the stock (sell day).

Return the maximum profit you can achieve. If you cannot make any profit, return 0.

---

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:
Buy on day 1 (price=1), sell on day 4 (price=6), profit = 6-1=5.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation:
No profit possible because stock prices keep decreasing.

---

Approach (Greedy):
- Track the minimum stock price seen so far (`mini`).
- For each day, calculate the profit if sold today = `prices[i] - mini`.
- Keep updating `maxprofit` with the best profit seen.
- Update `mini` if today’s price is smaller than the current minimum.

Time Complexity: O(n)  
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];   // track the minimum price so far
        int n = prices.size();
        int maxprofit = 0;      // best profit so far

        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mini;          // profit if sold today
            maxprofit = max(maxprofit, cost);     // update max profit
            mini = min(mini, prices[i]);          // update min price
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
