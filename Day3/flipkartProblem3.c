/*Question 3: Logistics and Supply Chain Optimization
Problem Statement:
Optimize the logistics and supply chain of Flipkart’s platform 
using Dijkstra’s algorithm to find the shortest path between 5 warehouses and 10 delivery locations.*/

#include <stdio.h>
#include <limits.h>

#define V 5 // Number of warehouses

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

    printf("Warehouse to Delivery Location Shortest Distance:\n");
    for (int i = 0; i < V; i++) {
        printf("Warehouse %d -> Delivery %d: %d km\n", src, i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 20, 0, 0},
        {10, 0, 5, 15, 0},
        {20, 5, 0, 25, 30},
        {0, 15, 25, 0, 10},
        {0, 0, 30, 10, 0}
    };

    int startWarehouse = 0;
    printf("Computing shortest delivery routes from Warehouse %d...\n", startWarehouse);
    dijkstra(graph, startWarehouse);

    return 0;
}
