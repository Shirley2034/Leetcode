//
// Created by 昭会 on 2024/7/5.
//

#include "MATH.h"

int MATH::Solution::mySqrt(int x) {
    int left = 0;
    int right = x;
    while (left < right) {
        int mid = (left + right) / 2;
        long long ans = (long long) mid * mid;
        if (x == ans) {
            return mid;
        } else if (x > ans) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (left * left <= x) {
        return left;
    }
    return left - 1;
}