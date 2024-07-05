//
// Created by shirleyz on 2024/7/5.
//

#include "STRING.h"
#include "map"

std::string STRING::Lc415::Solution::addStrings(std::string num1, std::string num2) {
    std::map<char, int> StrToInt = {
        {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
        {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
    };
    int c_in = 0;
    std::string res;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 && j >= 0) {
        int ans = StrToInt[num1[i]] + StrToInt[num2[j]] + c_in;
        int a = ans % 10;
        c_in = ans / 10;
        res = std::to_string(a) + res;
        i--;
        j--;
    }
    while (i >= 0) {
        int ans = StrToInt[num1[i]] + c_in;
        int a = ans % 10;
        c_in = ans / 10;
        res = std::to_string(a) + res;
        i--;
    }
    while (j >= 0) {
        int ans = StrToInt[num2[j]] + c_in;
        int a = ans % 10;
        c_in = ans / 10;
        res = std::to_string(a) + res;
        j--;
    }
    if (c_in > 0) {
        res = std::to_string(c_in) + res;
    }
    return res;
}
