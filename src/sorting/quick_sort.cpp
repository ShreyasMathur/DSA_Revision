#include "../../include/sorting/quick_sort.h"
using namespace std;

int partition(vector<int>& arr, int l, int r, long long &ops) {
    int pivot = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++) {
        ops++;
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

long long quickSort(vector<int>& arr, int l, int r) {
    long long ops = 0;
    if(l < r) {
        int pi = partition(arr, l, r, ops);
        ops += quickSort(arr, l, pi-1);
        ops += quickSort(arr, pi+1, r);
    }
    return ops;
}