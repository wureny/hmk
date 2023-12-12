#include <stdio.h>
#include "binheap.h"  

void heapSort(int arr[], int n) {
    PriorityQueue minHeap = Initialize(n);
    for (int i = 0; i < n; ++i) {
        Insert(arr[i], minHeap);
    }
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = DeleteMin(minHeap);
    }
    Destroy(minHeap);
}
int main() {
    int arr[] = {10, 4, 8, 2, 6, 7, 1, 9, 3, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
