// program to implement travelling salesperson problem

#include <stdio.h>
#include <stdlib.h>
#define max_cities 10

int num_cities;
int distance[max_cities][max_cities];
int visited[max_cities];
int min_distance = 999999; // Initialize min_distance with a large value
int min_path[max_cities];

void tsp(int current_city, int visited_count, int total_distance, int path[max_cities]) {
    int i;
    if (visited_count == num_cities) {
        if (total_distance + distance[current_city][0] < min_distance) {
            min_distance = total_distance + distance[current_city][0];
            for (i = 0; i < num_cities; i++)
                min_path[i] = path[i];
        }
        return;
    }

    visited[current_city] = 1;
    for (i = 0; i < num_cities; i++) {
        if (!visited[i] && distance[current_city][i] != 0) {
            path[visited_count] = i;
            tsp(i, visited_count + 1, total_distance + distance[current_city][i], path);
        }
    }
    visited[current_city] = 0;
}

int main() {
    int i, j;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the distance matrix: \n");
    for (i = 0; i < num_cities; i++)
        for (j = 0; j < num_cities; j++)
            scanf("%d", &distance[i][j]);

    int path[max_cities];
    path[0] = 0;

    tsp(0, 1, 0, path);

    printf("Minimum distance: %d\n", min_distance);
    printf("Minimum path: ");
    for (i = 0; i < num_cities; i++)
        printf("%d ", min_path[i]);
    printf("\n");

    return 0;
}
