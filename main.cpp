#include <bits/stdc++.h>
#include "utils/timer.h"

#include "include/sorting/merge_sort.h"
#include "include/sorting/quick_sort.h"

using namespace std;

void printArray(const vector<int>& arr) {
    for(int x : arr) cout << x << " ";
    cout << "\n";
}

void test(string name, vector<int> arr,
          long long (*sortFunc)(vector<int>&, int, int)) {

    cout << "\n--- " << name << " ---\n";

    cout << "Input: ";
    printArray(arr);

    Timer t;
    t.startTimer();

    long long ops = sortFunc(arr, 0, arr.size()-1);

    double time = t.stopTimer();

    cout << "Output: ";
    printArray(arr);

    cout << "Operations: " << ops << "\n";
    cout << "Time: " << time << " sec\n";
}

int main() {
    vector<int> input = {5, 2, 9, 1, 5, 6};

    test("Merge Sort", input, mergeSort);
    test("Quick Sort", input, quickSort);

    return 0;
}