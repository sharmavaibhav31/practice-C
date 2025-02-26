/*Question 3: Optimizing Instagram’s Content Delivery Network (CDN) Using Dijkstra’s Algorithm
Problem Statement:
Optimize Instagram’s content delivery network (CDN) by 
finding the shortest path from 5 data centers (CDN nodes) 
to 10 different user locations using Dijkstra’s algorithm.*/

#include <stdio.h>
#include <limits.h>

#define V 5 // Number of data centers (CDN nodes)

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX, sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Content Delivery Network (CDN) Optimization - Shortest Path:\n");
    for (int i = 0; i < V; i++) {
        printf("Data Center %d -> User Location %d: %d ms\n", src, i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 20, 30, 0, 0},
        {20, 0, 10, 25, 0},
        {30, 10, 0, 35, 40},
        {0, 25, 35, 0, 15},
        {0, 0, 40, 15, 0}
    };

    int startCDN = 0;
    printf("Computing shortest delivery routes from Data Center %d...\n", startCDN);
    dijkstra(graph, startCDN);

    return 0;
}

