//118
#include <stdio.h>

int main()
{
    int roll[50], n, i, j, temp;

    // Accept number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Accept roll numbers
    printf("Enter %d roll numbers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &roll[i]);
    }

    // Bubble Sort
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(roll[j] > roll[j + 1])
            {
                // Swap
                temp = roll[j];
                roll[j] = roll[j + 1];
                roll[j + 1] = temp;
            }
        }

        // Display intermediate pass
        printf("Pass %d: ", i + 1);
        for(j = 0; j < n; j++)
        {
            printf("%d ", roll[j]);
        }
        printf("\n");
    }

    // Display sorted roll numbers
    printf("\nSorted Roll Numbers: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", roll[i]);
    }

    return 0;
}

Enter number of students: 20 
Enter 20 roll numbers:
3 5 4 2 6 8 9 6 1 12 13 15 17 16 11 14 19 18 17 10
Pass 1: 3 4 2 5 6 8 6 1 9 12 13 15 16 11 14 17 18 17 10 19 
Pass 2: 3 2 4 5 6 6 1 8 9 12 13 15 11 14 16 17 17 10 18 19 
Pass 3: 2 3 4 5 6 1 6 8 9 12 13 11 14 15 16 17 10 17 18 19 
Pass 4: 2 3 4 5 1 6 6 8 9 12 11 13 14 15 16 10 17 17 18 19 
Pass 5: 2 3 4 1 5 6 6 8 9 11 12 13 14 15 10 16 17 17 18 19 
Pass 6: 2 3 1 4 5 6 6 8 9 11 12 13 14 10 15 16 17 17 18 19 
Pass 7: 2 1 3 4 5 6 6 8 9 11 12 13 10 14 15 16 17 17 18 19 
Pass 8: 1 2 3 4 5 6 6 8 9 11 12 10 13 14 15 16 17 17 18 19 
Pass 9: 1 2 3 4 5 6 6 8 9 11 10 12 13 14 15 16 17 17 18 19 
Pass 10: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 11: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 12: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 13: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 14: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 15: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 16: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 17: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 18: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 
Pass 19: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 

Sorted Roll Numbers: 1 2 3 4 5 6 6 8 9 10 11 12 13 14 15 16 17 17 18 19 

=== Code Execution Successful ===


