#include "../../include/sorting/merge_sort.h"
using namespace std;

long long merge(vector<int>& arr, int l, int m, int r) {
    long long ops = 0;

    vector<int> L(arr.begin()+l, arr.begin()+m+1);
    vector<int> R(arr.begin()+m+1, arr.begin()+r+1);

    int i=0,j=0,k=l;

    while(i<L.size() && j<R.size()){
        ops++;
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }

    while(i<L.size()) arr[k++]=L[i++], ops++;
    while(j<R.size()) arr[k++]=R[j++], ops++;

    return ops;
}

long long mergeSort(vector<int>& arr, int l, int r) {
    long long ops = 0;
    if(l<r){
        int m=(l+r)/2;
        ops += mergeSort(arr,l,m);
        ops += mergeSort(arr,m+1,r);
        ops += merge(arr,l,m,r);
    }
    return ops;
}