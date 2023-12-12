#include <stdio.h>
#include <stdbool.h>

#define NUMOFVERTEX 6
#define NOTAVERTEX 0

int findnewvertexindegreeZero(bool visit[], int inDegree[]) {
    for (int v = 0; v < NUMOFVERTEX; v++) {
        if (!visit[v] && inDegree[v] == 0) {
            return v;
        }
    }
    return NOTAVERTEX;
}
void Topsort(int graph[NUMOFVERTEX][NUMOFVERTEX]) {
    int counter = 0;
    int top_num[NUMOFVERTEX] = {0};
    int inDegree[NUMOFVERTEX] = {0};
    bool visit[NUMOFVERTEX] = {false};
    for (int i = 0; i < NUMOFVERTEX; i++) {
        for (int j = 0; j < NUMOFVERTEX; j++) {
            if (graph[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }
    for (counter = 0; counter < NUMOFVERTEX; counter++) {
        int v = findnewvertexindegreeZero(visit, inDegree);
        if (v == NOTAVERTEX) {
            break;
        }
        top_num[v] = counter;
        visit[v] = true;

        for (int w = 0; w < NUMOFVERTEX; w++) {
            if (graph[v][w] == 1) {
                inDegree[w]--;
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
}


