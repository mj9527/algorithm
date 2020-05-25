//
// Created by mjzheng on 2020/5/21.
//

#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <iostream>


class QuickSort {
public:
    void sort(int*p, int len){
        std::cout << len << std::endl;
        sort(p, 0, len-1);
        PrintArray(p, len);
    }

    void sort(int*p, int low, int high){
        if (low < high) {
            int pivot = partition(p, low, high);
            sort(p, low, pivot-1);
            sort(p, pivot+1, high);
        }
    }

    int partition(int*p, int low, int high) {
        int pivot = p[low];
        while (low < high) {
            while (low <high && p[high] > pivot) {
                high--;
            }
            std::swap(p[high], p[low]);
            while (low < high && p[low] < pivot) {
                low++;
            }
            std::swap(p[low], p[high]);
        }
        return low;
    }

    void PrintArray(int* p, int len) {
        for (int i=0; i<len; i++) {
            std::cout << p[i] << " ";
        }
        std::cout << std::endl;
    }
};



void TestQuickSort() {
    int a[] = {50,10,90,30,70,40,80,60,20};

    QuickSort q;
    q.sort(a, sizeof(a)/sizeof(int));

}


#endif //ALGORITHM_QUICKSORT_H
