// include/sorting/insertion_sort.h
#include <vector>

long long insertionSort(std::vector<int>& arr) {
    long long ops = 0;
    int n = arr.size();

    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            ops++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    return ops;
}