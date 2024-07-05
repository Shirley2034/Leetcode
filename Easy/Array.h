//
// Created by shirleyz on 2024/7/5.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#include "vector"
#include "random"

class Array {
public:
    class Case {
    public:
        static void case1(std::vector<int> &nums1, const int m, std::vector<int> &nums2, const int n) {
            std::srand(1);
            int ans = std::rand() % 50;
            for (int i = 0; i < m; i++) {
                nums1.push_back(ans);
                ans += std::rand() % 50;
            }
            ans = std::rand() % 50;
            for (int i = 0; i < n; i++) {
                nums2.push_back(ans);
                ans += std::rand() % 50;
                nums1.push_back(0);
            }
        }
    };

    class Lc88 {
    public:
        class Solution {
        public:
            void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                constexpr int m = 6;
                constexpr int n = 8;
                std::vector<int> nums1, nums2;
                Case::case1(nums1, m, nums2, n);
                std::cout << "nums1 is ";
                for (const int &num: nums1) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                std::cout << "nums2 is ";
                for (const int &num: nums2) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
                solution.merge(nums1, m, nums2, n);
                std::cout << "merge result is ";
                for (const int &num: nums1) {
                    std::cout << num << " ";
                }
            }
        };
    };
};


#endif //ARRAY_H
