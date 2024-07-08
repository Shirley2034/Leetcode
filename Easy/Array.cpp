//
// Created by shirleyz on 2024/7/5.
//

#include "Array.h"

void Array::Lc88::Solution::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, k = n + m - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0) {
        nums1[j] = nums2[j];
        j--;
    }
}

int Array::Lc704::Solution::search(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (nums[left] == target) {
        return left;
    } else {
        return -1;
    }
}
