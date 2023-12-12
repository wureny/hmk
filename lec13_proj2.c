#include <stdio.h>
#include <stdbool.h>

#define NUMOFVERTEX 6
#define NOTAVERTEX 0

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;



bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (queue->size == queue->capacity)
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

void topsort(int graph[NUMOFVERTEX][NUMOFVERTEX]) {
    Queue* Q = createQueue(NUMOFVERTEX);
    unsigned int counter = 0;
    int top_num[NUMOFVERTEX] = {0};
    int inDegree[NUMOFVERTEX] = {0};

    for (int i = 0; i < NUMOFVERTEX; i++) {
        for (int j = 0; j < NUMOFVERTEX; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    for (int v = 0; v < NUMOFVERTEX; v++) {
        if (inDegree[v] == 0) {
            enqueue(Q, v);
        }
    }

    while (!isEmpty(Q)) {
        int v = dequeue(Q);
        top_num[v] = ++counter;

        for (int w = 0; w < NUMOFVERTEX; w++) {
            if (graph[v][w] == 1) {
                inDegree[w]--;
                if (inDegree[w] == 0) {
                    enqueue(Q, w);
                }
            }
        }
    }

    for (int i = 0; i < NUMOFVERTEX; i++) {
        int vertex = -1;
        for (int j = 0; j < NUMOFVERTEX; j++) {
            if (top_num[j] == i) {
                vertex = j;
                break;
            }
        }
        printf("%d ", vertex);
    }
    printf("\n");
}
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return NOTAVERTEX;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}