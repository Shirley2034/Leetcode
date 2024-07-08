//
// Created by shirleyz on 2024/7/5.
//

#include "STACK.h"

int STACK::Lc121::Solution::maxProfit(std::vector<int> &prices) {
    int res = 0;
    if (prices.empty()) {
        return res;
    }
    int minPrice = prices[0];
    for (const int &price: prices) {
        int currentProfit = price - minPrice;
        res = std::max(res, currentProfit);
        if (currentProfit < 0) {
            minPrice = price;
        }
    }
    return res;
}

int STACK::Lc122::Solution::maxProfit(const std::vector<int> &prices) {
    int res = 0;
    if (prices.empty()) {
        return res;
    }
    std::vector<std::vector<int> > dp = {{0, -prices[0]}};
    for (int i = 1; i < prices.size(); ++i) {
        int a = std::max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
        int b = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp.push_back({a, b});
        res = std::max(std::max(a, b), res);
    }
    return res;
}
