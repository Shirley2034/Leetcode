//
// Created by shirleyz on 2024/7/5.
//

#ifndef STRING_H
#define STRING_H

#include <iostream>

#include "string"
#include "random"

class STRING {
public:
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
