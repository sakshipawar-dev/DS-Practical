//118
#include <stdio.h>
#include <string.h>

#define MAX 50
#define SIZE 100

char backStack[MAX][SIZE];
char forwardStack[MAX][SIZE];

int backTop = -1;
int forwardTop = -1;

char currentPage[SIZE] = "Home";

void visitPage()
{
    char page[SIZE];

    printf("Enter new page: ");
    scanf("%s", page);

    // Push current page into back stack
    if (backTop < MAX - 1)
    {
        backTop++;
        strcpy(backStack[backTop], currentPage);
    }

    // Set new page as current
    strcpy(currentPage, page);

    // Clear forward stack
    forwardTop = -1;

    printf("Visited: %s\n", currentPage);
}

void goBack()
{
    if (backTop == -1)
    {
        printf("No previous page available.\n");
        return;
    }

    // Push current page into forward stack
    forwardTop++;
    strcpy(forwardStack[forwardTop], currentPage);

    // Pop page from back stack
    strcpy(currentPage, backStack[backTop]);
    backTop--;

    printf("Back to: %s\n", currentPage);
}

void goForward()
{
    if (forwardTop == -1)
    {
        printf("No forward page available.\n");
        return;
    }

    // Push current page into back stack
    backTop++;
    strcpy(backStack[backTop], currentPage);

    // Pop page from forward stack
    strcpy(currentPage, forwardStack[forwardTop]);
    forwardTop--;

    printf("Forward to: %s\n", currentPage);
}

void displayPage()
{
    printf("Current Page: %s\n", currentPage);
}

int main()
{
    int choice;

    do
    {
        printf("\n===== BROWSER NAVIGATION =====\n");
        printf("1. Visit New Page\n");
        printf("2. Back Navigation\n");
        printf("3. Forward Navigation\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                visitPage();
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                displayPage();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

===== BROWSER NAVIGATION =====
1. Visit New Page
2. Back Navigation
3. Forward Navigation
4. Display Current Page
5. Exit
Enter your choice: 1
Enter new page: xyz
Visited: xyz

===== BROWSER NAVIGATION =====
1. Visit New Page
2. Back Navigation
3. Forward Navigation
4. Display Current Page
5. Exit
Enter your choice: 2
Back to: Home

===== BROWSER NAVIGATION =====
1. Visit New Page
2. Back Navigation
3. Forward Navigation
4. Display Current Page
5. Exit
Enter your choice: 3
Forward to: xyz

===== BROWSER NAVIGATION =====
1. Visit New Page
2. Back Navigation
3. Forward Navigation
4. Display Current Page
5. Exit
Enter your choice: 4
Current Page: xyz

===== BROWSER NAVIGATION =====
1. Visit New Page
2. Back Navigation
3. Forward Navigation
4. Display Current Page
5. Exit
Enter your choice: 5
Exiting...


