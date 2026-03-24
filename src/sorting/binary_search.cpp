// include/searching/binary_search.h
#include <vector>

int binarySearchRec(std::vector<int>& arr, int l, int r, int target, long long &ops) {
    if(l > r) return -1;

    ops++;
    int mid = (l + r) / 2;

    if(arr[mid] == target) return mid;
    else if(arr[mid] > target)
        return binarySearchRec(arr, l, mid-1, target, ops);
    else
        return binarySearchRec(arr, mid+1, r, target, ops);
}