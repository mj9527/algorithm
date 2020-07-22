//
// Created by mjzheng on 2020/6/25.
//

#ifndef ALGORITHM_ROTATEMATRIX_H
#define ALGORITHM_ROTATEMATRIX_H


class RotateMatrix {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n/2; i++) {
            std::cout << "circle" << std::endl;
            int start = i; // 当前环的起始下标（横纵均相等）
            int end = n - i - 1; // 当前环的终点下标（横纵均相等）
            for (int j = 0; j < end - start; j++) {
                int temp = matrix[start][start + j];
                matrix[start][start + j] = matrix[end - j][start];
                matrix[end - j][start] = matrix[end][end - j];
                matrix[end][end - j] = matrix[start + j][end];
                matrix[start + j][end] = temp;
            }
        }
    }

    void PrintMatix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << endl;
        }

    }
};

void TestMatrix() {
    vector<vector<int>> matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    RotateMatrix s;
    s.PrintMatix(matrix);
    s.rotate(matrix);
    s.PrintMatix(matrix);
}


#endif //ALGORITHM_ROTATEMATRIX_H
