#include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i;
    float remaining_capacity = capacity;

    for(i = 0; i < n; i++)
        x[i] = 0.0;

    for(i = 0; i < n; i++)
    {
        if(weight[i] <= remaining_capacity)
        {
            x[i] = 1.0;

            tp = tp + profit[i];

            remaining_capacity =
                remaining_capacity - weight[i];

            printf("Item %d taken fully\n", i + 1);
            printf("Remaining Capacity = %.0f\n",
                   remaining_capacity);
            printf("Current Profit = %.2f\n\n", tp);
        }
        else
        {
            break;
        }
    }

    // Fractional part
    if(i < n)
    {
        x[i] = remaining_capacity / weight[i];

        tp = tp + (x[i] * profit[i]);

        printf("Item %d taken fractionally\n", i + 1);
        printf("Fraction Taken = %.2f\n", x[i]);

        remaining_capacity = 0;

        printf("Remaining Capacity = %.0f\n",
               remaining_capacity);
        printf("Current Profit = %.2f\n\n", tp);
    }

    printf("Maximum Profit = %.2f\n", tp);
}

int main()
{
    float weight[20] = {5, 10, 15, 22, 25, 30, 35};
    float profit[20] = {30, 40, 45, 77, 90, 120, 140};

    float ratio[20], temp;
    float capacity = 60;

    int num = 7;
    int i, j;

    // Calculate ratio
    for(i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort according to ratio
    for(i = 0; i < num; i++)
    {
        for(j = i + 1; j < num; j++)
        {
            if(ratio[i] < ratio[j])
            {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);

    return 0;
}