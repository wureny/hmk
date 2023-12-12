#include <stdio.h>
#include "binheap.h"

ElementType FindTheKthSmallest(int k, ElementType arr[], int n) {
    PriorityQueue minHeap = Initialize(n);
    for (int i = 0; i < n; ++i) {
        Insert(arr[i], minHeap);
    }

    for (int i = 0; i < k - 1; ++i) {
        DeleteMin(minHeap);
    }

    ElementType kthSmallest = DeleteMin(minHeap);

    Destroy(minHeap);

    return kthSmallest;
}

int main() {
    int k = 5;  
    ElementType arr[] = {10, 4, 8, 2, 6, 7, 1, 9, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ElementType kthSmallest = FindTheKthSmallest(k, arr, n);
    printf("The %dth smallest element is: %d\n", k, kthSmallest);
    return 0;
}
