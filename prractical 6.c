//118
#include <stdio.h>
#include <stdlib.h>

/* Structure for a BST node */
struct Node
{
    int rollNo;
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(int rollNo)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->rollNo = rollNo;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* a. Add a new student */
struct Node* insert(struct Node *root, int rollNo)
{
    if (root == NULL)
    {
        return createNode(rollNo);
    }

    if (rollNo < root->rollNo)
    {
        root->left = insert(root->left, rollNo);
    }
    else if (rollNo > root->rollNo)
    {
        root->right = insert(root->right, rollNo);
    }
    else
    {
        printf("Roll number already exists!\n");
    }

    return root;
}

/* Find the smallest node */
struct Node* findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

/* b. Remove a student */
struct Node* deleteNode(struct Node *root, int rollNo)
{
    struct Node *temp;

    if (root == NULL)
    {
        printf("Student with roll number %d not found.\n", rollNo);
        return root;
    }

    if (rollNo < root->rollNo)
    {
        root->left = deleteNode(root->left, rollNo);
    }
    else if (rollNo > root->rollNo)
    {
        root->right = deleteNode(root->right, rollNo);
    }
    else
    {
        /* Node with no child */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        /* Node with only right child */
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        /* Node with only left child */
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children */
        temp = findMin(root->right);
        root->rollNo = temp->rollNo;
        root->right = deleteNode(root->right, temp->rollNo);
    }

    return root;
}

/* c. Search for a student */
struct Node* search(struct Node *root, int rollNo)
{
    if (root == NULL || root->rollNo == rollNo)
    {
        return root;
    }

    if (rollNo < root->rollNo)
    {
        return search(root->left, rollNo);
    }

    return search(root->right, rollNo);
}

/* Inorder traversal */
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->rollNo);
        inorder(root->right);
    }
}

/* Preorder traversal */
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->rollNo);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder traversal */
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->rollNo);
    }
}

/* Main function */
int main()
{
    struct Node *root = NULL;
    struct Node *result;

    int choice;
    int rollNo;

    do
    {
        printf("\n===== STUDENT BST =====\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter student roll number: ");
                scanf("%d", &rollNo);

                root = insert(root, rollNo);
                printf("Student added successfully.\n");
                break;

            case 2:
                printf("Enter roll number to remove: ");
                scanf("%d", &rollNo);

                result = search(root, rollNo);

                if (result != NULL)
                {
                    root = deleteNode(root, rollNo);
                    printf("Student removed successfully.\n");
                }
                else
                {
                    printf("Student not found.\n");
                }
                break;

            case 3:
                printf("Enter roll number to search: ");
                scanf("%d", &rollNo);

                result = search(root, rollNo);

                if (result != NULL)
                {
                    printf("Student with roll number %d found.\n", rollNo);
                }
                else
                {
                    printf("Student with roll number %d not found.\n", rollNo);
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 1
Enter student roll number: 44
Student added successfully.

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 1
Enter student roll number: 56
Student added successfully.

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 3
Enter roll number to search: 44
Student with roll number 44 found.

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 4
Inorder Traversal: 44 56 

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 5
Preorder Traversal: 44 56 

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 6
Postorder Traversal: 56 44 

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 2
Enter roll number to remove: 44
Student removed successfully.

===== STUDENT BST =====
1. Add Student
2. Remove Student
3. Search Student
4. Inorder Traversal
5. Preorder Traversal
6. Postorder Traversal
7. Exit
Enter your choice: 7
Exiting...
