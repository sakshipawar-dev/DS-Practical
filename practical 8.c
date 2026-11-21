//118

#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

// Hash function
int hashFunction(int key)
{
    return key % SIZE;
}

// Insert book ID using linear probing
void insert(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash table is full!\n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Book ID %d inserted successfully.\n", key);
}

// Search for book ID
void search(int key)
{
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("Book ID %d found at index %d.\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    printf("Book ID %d not found.\n", key);
}

// Display hash table
void display()
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice, id;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }

    do
    {
        printf("\n--- Library Book Indexing ---\n");
        printf("1. Insert Book ID\n");
        printf("2. Search Book ID\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                insert(id);
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                search(id);
                break;

            case 3:
                display();
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
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 25
Book ID 25 inserted successfully.

--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 35
Book ID 35 inserted successfully.

--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 45
Book ID 45 inserted successfully.

--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 2
Enter Book ID to search: 25
Book ID 25 found at index 5.

--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 3

Hash Table:
Index 0 : -1
Index 1 : -1
Index 2 : -1
Index 3 : -1
Index 4 : -1
Index 5 : 25
Index 6 : 35
Index 7 : 45
Index 8 : -1
Index 9 : -1

--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 4
Exiting program...

