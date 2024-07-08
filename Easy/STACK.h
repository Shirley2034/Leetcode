//
// Created by shirleyz on 2024/7/5.
//

#ifndef STOCK_H
#define STOCK_H

#include <iostream>

#include "vector"
#include "random"
#include "stack"

class STACK {
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

    class Lc155 {
    public:
        class MinStack {
        private:
            int minVal = pow(2, 31) - 1;
            std::stack<int> currentStack;
            std::stack<int> minStack;

        public:
            MinStack() {}

            void push(int val) {
                currentStack.push(val);
                if (val <= minVal) {
                    minVal = val;
                }
                minStack.push(minVal);
            }

            void pop() {
                currentStack.pop();
                minStack.pop();
                if (minStack.empty()) {
                    minVal = pow(2, 31) - 1;
                } else {
                    minVal = minStack.top();
                }
            }

            int top() { return currentStack.top(); }

            int getMin() { return minStack.top(); }
        };

    };

    class Lc232 {
    public:
        class MyQueue {
        private:
            std::stack<int> stack1;
            std::stack<int> stack2;
        public:
            MyQueue() {}

            void push(int x) {
                stack1.push(x);
            }

            int pop() {
                int x;
                if (stack2.empty()) {
                    x = peek();
                } else {
                    x = stack2.top();
                }
                stack2.pop();
                return x;
            }

            int peek() {
                if (stack2.empty()) {
                    while (!stack1.empty()) {
                        int x = stack1.top();
                        stack2.push(x);
                        stack1.pop();
                    }
                }
                return stack2.top();
            }

            bool empty() {
                return stack1.empty() && stack2.empty();
            }
        };
    };
};


#endif //STOCK_H
