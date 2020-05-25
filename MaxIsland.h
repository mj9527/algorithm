//
// Created by mjzheng on 2020/5/25.
//

#ifndef ALGORITHM_MAXISLAND_H
#define ALGORITHM_MAXISLAND_H

#include <vector>
#include <iostream>

using namespace std;

class MaxIsland {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int columns = grid[0].size();
        int** visited = getVisitedArray(n, columns);
        int max = 0;
        int current = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<columns; j++) {
                if (grid[i][j]==1 && visited[i][j] == 0 ) {
                    current = DFS(grid, i, j, n, columns, visited);
                    std::cout << "currrent " << i << " " << j << current << " "  << std::endl;
                    if (current > max) {
                        max = current;
                    }
                }
            }
        }
        return max;
    }

    int DFS(vector<vector<int>>& grid, int i, int j, int n, int c, int** visited) {
        visited[i][j] = 1;
        if (grid[i][j] == 0) {
            return 0;
        }
        int total = 1;
        if (j+1<c && grid[i][j+1]==1&&visited[i][j+1]==0) {
            total += DFS(grid, i, j+1, n, c, visited);
        }

        if (j-1>0 && grid[i][j-1]==1&&visited[i][j-1]==0) {
            total += DFS(grid, i, j-1, n, c, visited);
        }

        if (i+1<n && grid[i+1][j]==1&&visited[i+1][j]==0) {
            total += DFS(grid, i+1, j, n, c, visited);
        }

        if (i-1>0 && grid[i-1][j]==1&&visited[i-1][j]==0) {
            total += DFS(grid, i-1, j, n, c, visited);
        }

        return total;
    }

    int** getVisitedArray(int n, int columns) {
        int** visited = new int*[n];
        for (int i=0; i<n; i++) {
            visited[i] = new int[columns];
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<columns; j++) {
                visited[i][j] = 0;
            }
        }
        return visited;
    }
};

void TestIsland() {
    vector<vector<int>> grid = {
//            {1,1,0,0,0},
//            {1,1,0,0,0},
//            {0,0,0,1,1},
//            {0,0,0,1,1}
            {0, 1},
            {1, 1}
    };

    MaxIsland m;
    int max = m.maxAreaOfIsland(grid);
    std::cout << max << std::endl;
}


#endif //ALGORITHM_MAXISLAND_H
