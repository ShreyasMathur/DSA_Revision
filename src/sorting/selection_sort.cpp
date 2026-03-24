// include/sorting/selection_sort.h
#include <vector>

long long selectionSort(std::vector<int>& arr) {
    long long ops = 0;
    int n = arr.size();

    for(int i = 0; i < n-1; i++) {
        int minIdx = i;

        for(int j = i+1; j < n; j++) {
            ops++;
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }

        if(minIdx != i)
            std::swap(arr[i], arr[minIdx]);
    }

    return ops;
}