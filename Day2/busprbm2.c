/*Route Optimization System
Develop a C program to optimize bus routes with the following features:

-> Accept route details (source, destination, and intermediate stops).
-> Calculate the shortest route using an algorithm such as Dijkstra's or Floyd-Warshall.
-> Display the optimized route and estimated travel time.
-> Handle changes in route details and re-optimize accordingly.*/
#include <stdio.h>
#include <limits.h>

#define MAX_STOPS 10  // Maximum number of bus stops
#define INF 9999      // Represents infinity (no direct path)

// Function to find the vertex with the minimum distance value
int findMinDistance(int distance[], int visited[], int stops) {
    int min = INF, minIndex = -1;
    for (int i = 0; i < stops; i++) {
        if (!visited[i] && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra's Algorithm to find the shortest route
void dijkstra(int graph[MAX_STOPS][MAX_STOPS], int stops, int source, int destination) {
    int distance[MAX_STOPS], visited[MAX_STOPS], parent[MAX_STOPS];

    // Initialize all distances as INF and visited as 0 (false)
    for (int i = 0; i < stops; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;  // No parent initially
    }

    distance[source] = 0;  // Distance from source to itself is 0

    for (int count = 0; count < stops - 1; count++) {
        int u = findMinDistance(distance, visited, stops);
        if (u == -1) break;  // No unvisited nodes left

        visited[u] = 1;

        for (int v = 0; v < stops; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;  // Store path
            }
        }
    }

    // Display the shortest path
    if (distance[destination] == INF) {
        printf("No path found between selected stops!\n");
        return;
    }

    printf("\nShortest route distance: %d km\n", distance[destination]);

    // Print the optimized path
    printf("Optimized Route: ");
    int path[MAX_STOPS], pathIndex = 0;
    for (int v = destination; v != -1; v = parent[v])
        path[pathIndex++] = v;

    for (int i = pathIndex - 1; i >= 0; i--)
        printf("%d%s", path[i] + 1, (i == 0) ? "\n" : " → ");

    // Estimated travel time assuming an average speed of 40 km/h
    printf("Estimated Travel Time: %.2f hours\n", (float)distance[destination] / 40);
}

// Function to accept route details and create the adjacency matrix
void initializeGraph(int graph[MAX_STOPS][MAX_STOPS], int stops) {
    printf("\nEnter distances between stops (Enter 0 if no direct path exists):\n");
    for (int i = 0; i < stops; i++) {
        for (int j = 0; j < stops; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                printf("Distance from stop %d to stop %d: ", i + 1, j + 1);
                scanf("%d", &graph[i][j]);
                if (graph[i][j] == 0) graph[i][j] = INF;  // No direct route
            }
        }
    }
}

int main() {
    int stops, source, destination;
    int graph[MAX_STOPS][MAX_STOPS];

    printf("Enter the number of stops (Max %d): ", MAX_STOPS);
    scanf("%d", &stops);
    if (stops > MAX_STOPS) stops = MAX_STOPS;

    initializeGraph(graph, stops);

    while (1) {
        printf("\n--- Route Optimization System ---\n");
        printf("1. Find Shortest Route\n");
        printf("2. Update Route Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Source Stop (1-%d): ", stops);
                scanf("%d", &source);
                printf("Enter Destination Stop (1-%d): ", stops);
                scanf("%d", &destination);

                if (source < 1 || source > stops || destination < 1 || destination > stops) {
                    printf("Invalid stop numbers!\n");
                } else {
                    dijkstra(graph, stops, source - 1, destination - 1);
                }
                break;

            case 2:
                initializeGraph(graph, stops);
                printf("Route details updated successfully!\n");
                break;

            case 3:
                printf("Exiting... Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
