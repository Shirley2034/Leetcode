//
// Created by shirleyz on 2024/7/5.
//

#ifndef STOCK_H
#define STOCK_H

#include <iostream>

#include "vector"
#include "random"

class Stock {
private:
    static std::vector<int> case1() {
        std::srand(1);
        std::vector<int> res;
        for (int i = 0; i < 5; i++) {
            int r = std::rand() % 100 + 1;
            res.push_back(r);
        }
        return res;
    }

public:
    class Lc121 {
    public:
        class Solution {
        public:
            int maxProfit(std::vector<int> &prices);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                std::vector<int> c1 = case1();
                std::cout << "the stock price is ";
                for (const int &price: c1) {
                    std::cout << price << ",";
                }
                std::cout << " max profit is " << solution.maxProfit(c1);
            }
        };
    };

    class Lc122 {
    public:
        class Solution {
        public:
            static int maxProfit(const std::vector<int> &prices);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                const std::vector<int> c1 = case1();
                std::cout << "the stock price is ";
                for (const int &price: c1) {
                    std::cout << price << ",";
                }
                std::cout << " max profit is " << solution.maxProfit(c1);
            }
        };
    };
};


#endif //STOCK_H
