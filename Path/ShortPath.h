//
// Created by mjzheng on 2020/5/28.
//

#ifndef ALGORITHM_SHORTPATH_H
#define ALGORITHM_SHORTPATH_H

#include <vector>

using namespace std;

struct Dist {
    int path;
    bool visited;
    Dist() {
        path = INT_MAX;
        visited = false;
    }
};

class ShortPath {
public:
    Dist* getShortPaht(vector<vector<int>>&g, int n, int from) {
        Dist* dist = new Dist[n];
        for (int i=0; i<n; i++) {
            if (i == from) {
                dist[i].path = 0;
                dist[i].visited = true;
            } else if (g[from][i] != 0) {
                dist[i].path = g[from][i];
                dist[i].visited = false;
            } else {
                dist[i].path = INT_MAX;
                dist[i].visited = false;
            }
        }

        PrintDist(dist, n);

        for (int i=1; i<n; i++) {
            int index = getMin(dist, n);
            if (index == -1) {
                break;
            }
            dist[index].visited = true;
            for (int j=0; j<n; j++) {
                if (g[index][j] != 0) {
                    if (dist[index].path + g[index][j] < dist[j].path) {
                        dist[j].path = dist[index].path + g[index][j];
                    }
                }
            }
            PrintDist(dist, n);
        }

        //PrintDist(dist, n);
        return dist;
    }

    int getMin(Dist* dist, int n) {
        int min = INT_MAX;
        int index = -1;
        for (int i=0; i<n; i++) {
            if (!dist[i].visited && dist[i].path < min) {
                min = dist[i].path;
                index = i;
            }
        }
        return index;
    }

    void PrintDist(Dist* dist, int n) {
        for (int i=0; i<n; i++) {
            std::cout << dist[i].path << " ";
        }
        std::cout << std::endl;
    }

};

void TestShortPath() {
    vector<vector<int>> g = {
            {0, 0, 10, 0, 30, 100},
            {0, 0, 5, 0, 0, 0},
            {0, 0, 0, 50, 0, 0},
            {0, 0, 0, 0, 0, 10},
            {0, 0, 0, 20, 0, 60},
            {0, 0, 0, 0, 0, 0},
    };

    ShortPath p;
    p.getShortPaht(g, g.size(), 4);
}

#endif //ALGORITHM_SHORTPATH_H
