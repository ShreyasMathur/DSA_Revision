#include <bits/stdc++.h>
#include "utils/timer.h"
#include "include/sorting/merge_sort.h"

using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    Timer t;
    t.startTimer();

    long long ops = mergeSort(arr, 0, arr.size()-1);

    double timeTaken = t.stopTimer();

    cout << "Sorted Array: ";
    for(int x: arr) cout << x << " ";

    cout << "\nOperations: " << ops;
    cout << "\nTime Taken: " << timeTaken << " sec\n";

    return 0;
}