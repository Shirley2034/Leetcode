//
// Created by shirleyz on 2024/7/5.
//

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <map>
#include <set>

#include "string"
#include "random"

class STRING {
public:
    class Cases {
    public:
        std::vector<std::string> case1() {
            std::vector<std::string> case1 = {"flower", "flow", "flight"};
            std::cout << "strings are as follows: " << std::endl;
            for (std::string &str: case1) {
                std::cout << str << " ";
            }
            std::cout << std::endl;
            return case1;
        }

        std::vector<std::string> case2() {
            std::vector<std::string> case1 = {"ra", "racecar", "car"};
            std::cout << "strings are as follows: " << std::endl;
            for (std::string &str: case1) {
                std::cout << str << " ";
            }
            std::cout << std::endl;
            return case1;
        }
    };

    class Lc3 {
    public:
        class Solution {
        public:
            int lengthOfLongestSubstring(std::string s) {
                int left = 0;
                int right = 0;
                int res = 0;
                std::set<char> charSet;
                while (right < s.size()) {
                    if (charSet.find(s[right]) != charSet.end()) {
                        res = std::max(res, right - left);
                        while (s[left] != s[right] && left < right) {
                            charSet.erase(s[left]);
                            left++;
                        }
                        charSet.erase(s[left]);
                        left++;
                    }
                    charSet.insert(s[right]);
                    right++;
                }
                if (left <= right) {
                    res = std::max(res, right - left);
                }
                return res;
            }
        };
    };

    class Lc14 {
    public:
        class Solution {
        public:
            std::string longestCommonPrefix(std::vector<std::string> &strs);

            void test1() {
                Cases cases;
                std::vector<std::string> s1 = cases.case2();
                std::string res = longestCommonPrefix(s1);
                std::cout << "The longest common prefix is " << res << std::endl;
            }
        };
    };

    class Lc415 {
    public:
        class Solution {
        public:
            std::string addStrings(std::string num1, std::string num2);
        };

        class Test {
        public:
            static void test1() {
                Solution solution;
                int a = std::rand() % 100 + 1;
                int b = std::rand() % 100 + 1;
                std::string num1 = std::to_string(a);
                std::string num2 = std::to_string(b);
                std::cout << "num1 is " << num1 << std::endl;
                std::cout << "num2 is " << num2 << std::endl;
                std::cout << "result is " << solution.addStrings(num1, num2) << std::endl;
            }
        };
    };
};


#endif //STRING_H
