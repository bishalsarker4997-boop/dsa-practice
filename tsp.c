#include <stdio.h>

#define N 4

int cost[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[N];
int minCost = 9999;

void tsp(int city, int count, int totalCost)
{
    int i;

    if(count == N)
    {
        totalCost += cost[city][0];

        if(totalCost < minCost)
            minCost = totalCost;

        return;
    }

    for(i = 0; i < N; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;

            tsp(i, count + 1,
                totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main()
{
    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Minimum Cost = %d", minCost);

    return 0;
}