#include <bits/stdc++.h>
#include "utils/timer.h"

#include "include/sorting/merge_sort.h"
#include "include/sorting/quick_sort.h"
#include "include/sorting/selection_sort.h"
#include "include/sorting/insertion_sort.h"
#include "include/sorting/bubble_sort.h"
#include "include/sorting/binary_search.h"

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

void testSimple(string name, vector<int> arr,
                long long (*sortFunc)(vector<int>&)) {

    cout << "\n--- " << name << " ---\n";

    cout << "Input: ";
    printArray(arr);

    Timer t;
    t.startTimer();

    long long ops = sortFunc(arr);

    double time = t.stopTimer();

    cout << "Output: ";
    printArray(arr);

    cout << "Operations: " << ops << "\n";
    cout << "Time: " << time << " sec\n";
}

void testBinarySearch(vector<int> arr, int target) {
    cout << "\n--- Binary Search (Recursive) ---\n";

    sort(arr.begin(), arr.end());

    cout << "Sorted Input: ";
    printArray(arr);

    long long ops = 0;

    int index = binarySearchRec(arr, 0, arr.size()-1, target, ops);

    cout << "Target: " << target << "\n";
    cout << "Index: " << index << "\n";
    cout << "Operations: " << ops << "\n";
}

int main() {

    vector<int> input = {5, 2, 9, 1, 5, 6};

    cout << "===== SORTING TESTS =====\n";

    test("Merge Sort", input, mergeSort);
    test("Quick Sort", input, quickSort);

    testSimple("Selection Sort", input, selectionSort);
    testSimple("Insertion Sort", input, insertionSort);
    testSimple("Bubble Sort", input, bubbleSort);

    cout << "\n===== SEARCHING TEST =====\n";

    testBinarySearch(input, 5);

    return 0;
}