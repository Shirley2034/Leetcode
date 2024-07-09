//
// Created by shirleyz on 2024/7/9.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <vector>


class MATRIX {
public:
    class Lc54 {
    public:
        class Solution {
        public:
            std::vector<int> spiralOrder(std::vector<std::vector<int> > &matrix) {
                std::vector<int> res;
                int rowFirst = 0;
                int rowLast = matrix.size() - 1;
                int colFirst = 0, colLast = matrix[0].size() - 1;
                while (true) {
                    for (int colIndex = colFirst; colIndex <= colLast; ++colIndex) {
                        res.push_back(matrix[rowFirst][colIndex]);
                    } //遍历上面的元素
                    if (++rowFirst > rowLast) { break; }
                    for (int rowIndex = rowFirst; rowIndex <= rowLast; ++rowIndex) {
                        res.push_back(matrix[rowIndex][colLast]);
                    } //遍历右边的元素
                    if (--colLast < colFirst) { break; }
                    for (int colIndex = colLast; colIndex >= colFirst; --colIndex) {
                        res.push_back(matrix[rowLast][colIndex]);
                    }
                    if (--rowLast < rowFirst) { break; }
                    for (int rowIndex = rowLast; rowIndex >= rowFirst; --rowIndex) {
                        res.push_back(matrix[rowIndex][colFirst]);
                    }
                    if (++colFirst > colLast) { break; }
                }
                return res;
            }
        };
    };
};


#endif //MATRIX_H
