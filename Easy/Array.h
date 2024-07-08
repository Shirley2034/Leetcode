//
// Created by shirleyz on 2024/7/5.
//

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <queue>

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

    class Lc34 {
    public:
        class Solution {
        private:
            int searchLocation(std::vector<int> &nums, int target, int left, int right, bool &found) {
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (target == nums[mid]) {
                        found = true;
                        return mid;
                    } else if (target > nums[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                return left;
            }

        public:
            std::vector<int> searchRange(std::vector<int> &nums, int target) {
                bool found = false;
                int location = searchLocation(nums, target, 0, nums.size() - 1, found);
                if (!found) {
                    return {-1, -1};
                }
                int left = location, right = location;
                location = searchLocation(nums, target - 1, 0, left - 1, found);
                if (location != -1) {
                    left = location;
                }

                location = 0;
                while (location != -1) {
                    location = searchLocation(nums, target, right + 1, nums.size() - 1, found);
                    if (location != -1) {
                        right = location;
                    }
                }
                return {left, right};
            }
        };
    };

    class Lc35 {
    public:
        class Solution {
        public:
            int searchInsert(std::vector<int> &nums, int target) {
                int left = 0;
                int right = nums.size() - 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (target == nums[mid]) {
                        return mid;
                    } else if (target > nums[mid]) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                return left;
            }
        };
    };

    class Lc74 {
    public:
        class Solution {
        public:
            bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
                int rowFirst = 0;
                int rowEnd = matrix.size() - 1;
                while (rowFirst <= rowEnd) {
                    int rowMid = (rowFirst + rowEnd) / 2;
                    int colFirst = 0;
                    int colEnd = matrix[0].size() - 1;
                    while (colFirst <= colEnd) {
                        int colMid = (colFirst + colEnd) / 2;
                        if (matrix[rowMid][colMid] == target) {
                            return true;
                        } else {
                            if (matrix[rowMid][colMid] > target) {
                                colEnd = colMid - 1;
                            } else {
                                colFirst = colMid + 1;
                            }
                        }
                    }
                    if (colFirst == 0) {
                        rowEnd = rowMid - 1;
                    } else {
                        rowFirst = rowMid + 1;
                    }
                }
                return false;
            }
        };
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

    class Lc704 {
    public:
        class Solution {
        public:
            int search(std::vector<int> &nums, int target);
        };

        class Test {
        public:
            static void test1() {
                std::srand(4);
                std::vector<int> nums;
                int length = std::rand() % 20 + 5;
                int ans = std::rand() % 10 + 1;
                std::cout << "The numbers are ";
                for (int i = 0; i < length; i++) {
                    std::cout << ans << " ";
                    nums.push_back(ans);
                    ans += std::rand() % 10 + 1;
                }
                std::cout << std::endl;
                int target = std::rand() % 20;
                std::cout << "The target number is " << target << std::endl;
                Solution solution;
                int res = solution.search(nums, target);
                std::cout << "The result is " << res << std::endl;
            }
        };
    };

    class Lc100336 {
    public:
        class Solution {
        public:
            int numberOfAlternatingGroups(std::vector<int> &colors) {
                int first = colors[0], second = colors[1], third;
                int res = 0;
                for (int i = 2; i < colors.size(); i++) {
                    third = colors[i];
                    if (first != second && third != second) {
                        res++;
                    }
                    first = second;
                    second = third;
                }
                third = colors[0];
                if (first != second && third != second) {
                    res++;
                }
                first = second;
                second = third;
                third = colors[1];
                if (first != second && third != second) {
                    res++;
                }
                return res;
            }
        };
    };

    class Lc100351 {
    public:
        class Solution {
        public:
            int numberOfAlternatingGroups(std::vector<int> &colors, int k) {
                int left = 0;
                int right = k - 1;
                int res = 0;
                bool lastIsAlternatingGroups = false;
                while (right < colors.size()) {
                    bool isAlternatingGroups = true;
                    if (lastIsAlternatingGroups) {
                        if (colors[right] != colors[right - 1]) {
                            res++;
                        } else {
                            isAlternatingGroups = false;
                        }
                    } else {
                        for (int i = left + 1; i < right; i++) {
                            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                                continue;
                            } else {
                                isAlternatingGroups = false;
                                break;
                            }
                        }
                        if (isAlternatingGroups) {
                            res++;
                        }
                    }
                    lastIsAlternatingGroups = isAlternatingGroups;
                    right++;
                    left++;
                }
                right = 0;
                while (right < k - 1) {
                    bool isAlternatingGroups = true;
                    if (lastIsAlternatingGroups) {
                        if ((right > 0 && colors[right] != colors[right - 1]) ||
                            (right == 0 && colors[right] != colors[colors.size() - 1])) {
                            res++;
                        } else {
                            isAlternatingGroups = false;
                        }
                    } else {
                        for (int i = left + 1; i < colors.size() - 1; i++) {
                            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                                continue;
                            } else {
                                isAlternatingGroups = false;
                                break;
                            }
                        }
                        if (!isAlternatingGroups) {
                            lastIsAlternatingGroups = isAlternatingGroups;
                            right++;
                            left++;
                            continue;
                        }
                        if (left != colors.size() - 1) {
                            if (colors[colors.size() - 1] == colors[colors.size() - 2] ||
                                colors[colors.size() - 1] == colors[0]) {
                                isAlternatingGroups = false;
                            }
                        }
                        if (!isAlternatingGroups) {
                            lastIsAlternatingGroups = isAlternatingGroups;
                            right++;
                            left++;
                            continue;
                        }
                        for (int i = 0; i < right; i++) {
                            if (i == 0) {
                                if (colors[i] != colors[colors.size() - 1] && colors[i] != colors[i + 1]) {
                                    continue;
                                } else {
                                    isAlternatingGroups = false;
                                    break;
                                }
                            }
                            if (colors[i] != colors[i - 1] && colors[i] != colors[i + 1]) {
                                continue;
                            } else {
                                isAlternatingGroups = false;
                                break;
                            }
                        }
                        if (isAlternatingGroups) {
                            res++;
                        }
                    }
                    lastIsAlternatingGroups = isAlternatingGroups;
                    right++;
                    left++;
                }
                return res;
            }
        };
    };
};


#endif //ARRAY_H
