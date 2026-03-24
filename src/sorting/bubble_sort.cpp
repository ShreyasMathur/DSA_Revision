// include/sorting/bubble_sort.h
#include <vector>

long long bubbleSort(std::vector<int>& arr) {
    long long ops = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            ops++;
            if(arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }

    return ops;
}