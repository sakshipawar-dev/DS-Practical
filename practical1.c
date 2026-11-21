//118
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable declaration
    int marks[20], n = 0, i, choice, pos, key;
    int low, high, mid, found, temp;

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Insert
                printf("\nEnter the size of array: ");
                scanf("%d", &n);

                if(n > 20 || n <= 0)
                {
                    printf("Invalid size! Enter size between 1 and 20.\n");
                    n = 0;
                    break;
                }

                printf("Enter the marks:\n");

                for(i = 0; i < n; i++)
                {
                    scanf("%d", &marks[i]);
                }

                printf("Elements inserted successfully.\n");
                break;


            case 2:
                // Delete
                if(n == 0)
                {
                    printf("\nArray is empty.\n");
                    break;
                }

                printf("\nEnter position to delete: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid position!\n");
                    break;
                }

                for(i = pos - 1; i < n - 1; i++)
                {
                    marks[i] = marks[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;


            case 3:
                // Display
                if(n == 0)
                {
                    printf("\nArray is empty.\n");
                    break;
                }

                printf("\nThe elements of array are:\n");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", marks[i]);
                }

                printf("\n");
                break;


            case 4:
                // Linear Search
                if(n == 0)
                {
                    printf("\nArray is empty.\n");
                    break;
                }

                printf("\nEnter element to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(marks[i] == key)
                    {
                        printf("Element %d found at position %d.\n",
                               key, i + 1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Element %d not found.\n", key);
                }

                break;


            case 5:
                // Binary Search
                if(n == 0)
                {
                    printf("\nArray is empty.\n");
                    break;
                }

                // Sorting array before binary search
                for(i = 0; i < n - 1; i++)
                {
                    for(int j = i + 1; j < n; j++)
                    {
                        if(marks[i] > marks[j])
                        {
                            temp = marks[i];
                            marks[i] = marks[j];
                            marks[j] = temp;
                        }
                    }
                }

                printf("\nSorted array:\n");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", marks[i]);
                }

                printf("\n");

                printf("Enter element to search: ");
                scanf("%d", &key);

                low = 0;
                high = n - 1;
                found = 0;

                while(low <= high)
                {
                    mid = (low + high) / 2;

                    if(marks[mid] == key)
                    {
                        printf("Element %d found at position %d "
                               "in sorted array.\n",
                               key, mid + 1);
                        found = 1;
                        break;
                    }
                    else if(marks[mid] < key)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if(found == 0)
                {
                    printf("Element %d not found.\n", key);
                }

                break;


            case 6:
                // Exit
                printf("\nExit...\n");
                break;


            default:
                printf("\nEnter a valid choice!\n");
        }

    } while(choice != 6);

    return 0;
}


========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 1

Enter the size of array: 5
Enter the marks:
20 10 50 60 80
Elements inserted successfully.

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 3

The elements of array are:
20 10 50 60 80 

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 4

Enter element to search: 60
Element 60 found at position 4.

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 5

Sorted array:
10 20 50 60 80 
Enter element to search: 4
Element 4 not found.

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 2

Enter position to delete: 3
Element deleted successfully.

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 3

The elements of array are:
10 20 60 80 

========== MENU ==========
1. Insert Element
2. Delete Element
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your choice: 6

Exit...

