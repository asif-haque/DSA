#include <stdio.h>

int i, j;
typedef struct job
{
    char id[20];
    float profit;
    int deadline;
} job;

void jobSequencingWithDeadline(int n, job jobs[n])
{
    int dmax = 0;
    // Determining max deadline
    for (i = 0; i < n; i++)
    {
        if (jobs[i].deadline > dmax)
        {
            dmax = jobs[i].deadline;
        }
    }

    int timeSlot[dmax], filledSlot;
    filledSlot = 0;
    // Inserting -1 in timeSlot; -1 represents empty
    for (i = 0; i < n; i++)
    {
        timeSlot[i] = -1;
    }

    // Job Sequencing
    for (i = 0; i < n; i++)
    {
        int k = jobs[i].deadline - 1; // as array indexing starts from 0

        while (k >= 0) // condition check for the else part
        {
            if (timeSlot[k] == -1)
            {
                timeSlot[k] = i;
                filledSlot++;
                break;
            }
            else
            {
                k--; // inserting and checking from right to left
            }
        }
        if (filledSlot == dmax) // running the loop until timeSlot array gets filled
        {
            break;
        }
    }

    // Printing the job sequence
    printf("\nJob sequnce is : ");
    for (i = 0; i < dmax; i++)
    {
        printf("%s\t", jobs[timeSlot[i]].id);
    }
    // Max Profit
    float tp = 0;
    for (i = 0; i < dmax; i++)
    {
        tp = tp + jobs[timeSlot[i]].profit;
    }
    printf("\nMax profit : %f", tp);
}

int main()
{
    int n;
    printf("\nEnter no. of jobs : ");
    scanf("%d", &n);

    // Taking the input for jobs and their corresponding profits and deadlines
    job jobs[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Job name : ");
        scanf("%s", &jobs[i].id);
        printf("\nEnter profit : ");
        scanf("%f", &jobs[i].profit);
        printf("\nEnter deadline : ");
        scanf("%d", &jobs[i].deadline);
    }

    // Sort the array in non-increasing order of profit [Insertion Sort]
    for (i = 0; i <= n - 2; i++)
    {
        for (j = i + 1; j > 0; j--)
        {
            if (jobs[j - 1].profit < jobs[j].profit)
            {
                job temp = jobs[j - 1];
                jobs[j - 1] = jobs[j];
                jobs[j] = temp;
            }
            else
            {
                break;
            }
        }
    }

    // Print the sorted array to check
    for (i = 0; i < n; i++)
    {
        printf("\n%s\t", jobs[i].id);
        printf("%f\t", jobs[i].profit);
        printf("%d\n", jobs[i].deadline);
    }

    jobSequencingWithDeadline(n, jobs);
}