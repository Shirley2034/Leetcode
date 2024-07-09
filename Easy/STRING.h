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

    class Lc93 {
    public:
        class Solution {
        public:
            std::vector<std::string> restoreIpAddresses(std::string s) {
                //s的长度必须在4和12之间
                std::vector<std::string> res;
                int maxIndex = s.size() - 1;
                if (maxIndex < 3 || maxIndex > 11) {
                    return res;
                }
                for (int first = 0; first < 3; first++) {
                    //确保索引没有超出
                    if (first + 3 > maxIndex) {
                        break;
                    }
                    std::string first_sub_string = s.substr(0, first + 1);
                    //确保整数没有前导0并且位于0到255之间
                    if ((first > 0 && s[0] == '0') || std::stoi(first_sub_string) > 255) {
                        break;
                    }
                    for (int second = first + 1; second < first + 4; second++) {
                        if (second + 2 > maxIndex) {
                            break;
                        }
                        std::string second_sub_string = s.substr(first + 1, second - first);
                        //确保整数没有前导0并且位于0到255之间
                        if ((second - first > 1 && s[first + 1] == '0') || std::stoi(second_sub_string) > 255) {
                            break;
                        }
                        for (int third = second + 1; third < second + 4; third++) {
                            if (third + 1 > maxIndex) {
                                break;
                            }
                            std::string third_sub_string = s.substr(second + 1, third - second);
                            std::string fourth_sub_string = s.substr(third + 1, maxIndex - third);
                            //确保整数没有前导0并且位于0到255之间
                            if ((third - second > 1 && s[second + 1] == '0') || std::stoi(third_sub_string) > 255) {
                                break;
                            }
                            if ((maxIndex - third > 1 && s[third + 1] == '0') || std::stoi(fourth_sub_string) > 255) {
                                continue;
                            }
                            std::string ipAddress = first_sub_string + ".";
                            ipAddress += second_sub_string + ".";
                            ipAddress += third_sub_string + ".";
                            ipAddress += fourth_sub_string;
                            res.push_back(ipAddress);
                        }
                    }
                }
                return res;
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

    class Lc1143 {
    public:
        class Solution {
        public:
            /*
             * dp[i][j]表示text1.substr(0,i+1)与text2.substr(0,j+1)的最长公共子序列数
             * if(text1[i+1]==text2[j+1]){dp[i+1][j+1]=dp[i][j]+1}
             * else{
             * dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1])}
             * 边界情况：
             * if(text1[0]==text2[j]){dp[0][j]=1}否则为0
             * if(text1[i]==text2[0]){dp[i][0]=1}
             * 从dp的左上角开始遍历，最长公共子序列数记为res=0
             * row=0;
             * for(int col=0;col<maxCol;col++)
             * if(dp[row][col]==1){//等价于test1[i]==test[j]
             * res++;
             * }
             * 下一次遍历的col应该大于本次的col,row也要大于
             */
            int longestCommonSubsequence(std::string text1, std::string text2) {
                int n = text1.size();
                int m = text2.size();
                std::vector dp(n + 1, std::vector(m + 1, 0));
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) {
                        if (text1[i - 1] == text2[j - 1]) {
                            dp[i][j] = dp[i - 1][j - 1] + 1;
                        } else {
                            dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                        }
                    }
                }
                return dp[n][m];
            }
        };
    };
};


#endif //STRING_H
