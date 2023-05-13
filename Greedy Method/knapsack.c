#include <stdio.h>

void swap(float arr[], int a, int b)
{
    float temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void print(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%f\t", arr[i]);
    }
    printf("\n");
}

void knapsack(int n, float capacity, float profit[], float weight[])
{
    float u, tp, x[n]; // u = remaining knapsack capacity ; tp = total profit gained ; x = solution vector
    u = capacity;
    tp = 0.0;
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    // knapsack code
    for (i = 0; i < n; i++)
    {
        if (u > weight[i]) // remaining capacity greater than weight, then fill it
        {
            u = u - weight[i];
            x[i] = 1; // helping me to get the total profit
            tp = tp + profit[i];
        }
        else
        {
            break;
        }
    }

    if (i < n) // 2 reasons for loop break: i > n OR the else statement; here we're taking the else statement
    {
        x[i] = u / weight[i];
        tp = tp + profit[i] * x[i];
    }

    // answer
    printf("\nSolution vector is: ");
    print(x,n);
    printf("\nTotal profit gained : %f", tp);
}

int main()
{
    int n, i, j;

    // input for number of objects
    printf("\nEnter the number of objects : ");
    scanf("%d", &n);

    float capacity, profit[n], weight[n], ratio[n];

    // input for capacity
    printf("\nEnter knapsack capacity : ");
    scanf("%f", &capacity);

    // input for weight and profit of objects
    for (i = 0; i < n; i++)
    {
        printf("\nEnter weight of object %d : ", i + 1);
        scanf("%f", &weight[i]);

        printf("\nEnter profit of object %d : ", i + 1);
        scanf("%f", &profit[i]);
    }

    // getting the profit/weight ratio list
    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    // sorting array in decreasing order of ratio [Most probably, this is selection sort. But insertion sort >>>>>>]
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                swap(ratio, i, j);
                swap(weight, i, j);
                swap(profit, i, j);
            }
        }
    }

    knapsack(n, capacity, profit, weight);
}
