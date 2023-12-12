#include <stdio.h>
#include "binheap.h"  

ElementType FindKthLargest(int k, ElementType arr[], int n) {
    PriorityQueue minHeap = Initialize(k);
    for (int i = 0; i < k; ++i) {
        Insert(arr[i], minHeap);
    }
    for (int i = k; i < n; ++i) {
        if (arr[i] > FindMin(minHeap)) {
            DeleteMin(minHeap);
            Insert(arr[i], minHeap);
        }
    }
    ElementType kthLargest = FindMin(minHeap);
    Destroy(minHeap);

    return kthLargest;
}

int main() {
    int k = 7;
    ElementType arr[] = {10, 4, 8, 2, 6, 7, 1, 9, 5, 3};  
    int n = sizeof(arr) / sizeof(arr[0]);
    ElementType kthLargest = FindKthLargest(k, arr, n);
    printf("The %dth largest element is: %d\n", k, kthLargest);
    return 0;
}
