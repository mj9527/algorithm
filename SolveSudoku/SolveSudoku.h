//
// Created by mjzheng on 2021/3/4.
//

#ifndef ALGORITHM_SOLVESUDOKU_H
#define ALGORITHM_SOLVESUDOKU_H


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        searchRes(board);
    }

    bool searchRes(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') {
                    continue;
                }
                for (char num = '1'; num <= '9'; num++) {//尝试
                    if (!isValid(board, i, j, num)) {
                        continue;
                    }
                    board[i][j] = num;
                    if (searchRes(board)) {
                        return true;
                    } else {
                        board[i][j] = '.';//回退之前的状态,本轮搜索失败,回退的时候也是递归的
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int i, int j, char num) {
        // 行有相同的,说明尝试错误.
        for (int row = 0; row < 9; row++) {
            if (board[row][j] == num) {
                return false;
            }
        }
        // 列有相同的,说明尝试错误.
        for (int col = 0; col < 9; col++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        // 9宫格中有相同的,说明尝试错误.
        for (int row = i / 3 * 3; row < i / 3 * 3 + 3; row++) {
            for (int col = j / 3 * 3; col < j / 3 * 3 + 3; col++) {
                if (board[row][col] == num) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif //ALGORITHM_SOLVESUDOKU_H
