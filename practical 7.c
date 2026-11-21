
//118

#include <stdio.h>

int adj[100][100];
int visited[100];
int n;

// Add connection between users
void addConnection(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;

    printf("Connection added between %d and %d\n", u, v);
}

// Breadth First Search
void BFS(int start)
{
    int queue[100];
    int front = 0, rear = 0;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    printf("\n");
}

// Depth First Search
void DFS(int start)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int v = 0; v < n; v++)
    {
        if (adj[start][v] == 1 && visited[v] == 0)
        {
            DFS(v);
        }
    }
}

int main()
{
    int choice, u, v, start;

    printf("Enter number of users: ");
    scanf("%d", &n);

    do
    {
        printf("\n--- Social Network Menu ---\n");
        printf("1. Add Connection\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter two users: ");
                scanf("%d %d", &u, &v);

                if (u >= 0 && u < n && v >= 0 && v < n)
                    addConnection(u, v);
                else
                    printf("Invalid user ID!\n");

                break;

            case 2:
                printf("Enter starting user: ");
                scanf("%d", &start);

                if (start >= 0 && start < n)
                    BFS(start);
                else
                    printf("Invalid user ID!\n");

                break;

            case 3:
                printf("Enter starting user: ");
                scanf("%d", &start);

                if (start >= 0 && start < n)
                {
                    for (int i = 0; i < n; i++)
                        visited[i] = 0;

                    printf("DFS Traversal: ");
                    DFS(start);
                    printf("\n");
                }
                else
                    printf("Invalid user ID!\n");

                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
Enter number of users: 5

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 1
Enter two users: 0 1
Connection added between 0 and 1

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 1
Enter two users: 0 2
Connection added between 0 and 2

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 1
Enter two users: 1 3
Connection added between 1 and 3

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 1
Enter two users: 2 4
Connection added between 2 and 4

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 2
Enter starting user: 0 2
BFS Traversal: 0 1 2 3 4 

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: Enter starting user: 3
BFS Traversal: 3 1 0 2 4 

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 3
Enter starting user: 2
DFS Traversal: 2 0 1 3 4 

--- Social Network Menu ---
1. Add Connection
2. BFS Traversal
3. DFS Traversal
4. Exit
Enter your choice: 4
Exiting program...

