//118
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
    struct Contact *next;
};

struct Contact *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct Contact *newNode;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", newNode->phone);

    newNode->next = head;
    head = newNode;

    printf("Contact inserted at beginning.\n");
}

// Insert at end
void insertEnd()
{
    struct Contact *newNode, *temp;

    newNode = (struct Contact *)malloc(sizeof(struct Contact));

    printf("Enter name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", newNode->phone);

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Contact inserted at end.\n");
}

// Delete contact using name
void deleteContact()
{
    char name[50];
    struct Contact *temp, *prev;

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    temp = head;
    prev = NULL;

    while(temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    if(prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Contact deleted successfully.\n");
}

// Search contact
void searchContact()
{
    char name[50];
    struct Contact *temp;

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            printf("\nContact Found!\n");
            printf("Name  : %s\n", temp->name);
            printf("Phone : %s\n", temp->phone);
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found.\n");
}

// Display all contacts
void displayContacts()
{
    struct Contact *temp;

    if(head == NULL)
    {
        printf("Contact list is empty.\n");
        return;
    }

    temp = head;

    printf("\n------ Contact List ------\n");

    while(temp != NULL)
    {
        printf("Name  : %s\n", temp->name);
        printf("Phone : %s\n", temp->phone);
        printf("--------------------------\n");

        temp = temp->next;
    }
}

// Free all allocated memory
void freeMemory()
{
    struct Contact *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteContact();
                break;

            case 4:
                searchContact();
                break;

            case 5:
                displayContacts();
                break;

            case 6:
                freeMemory();
                printf("All memory deallocated. Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 1
Enter name: Sakshi
Enter phone number: 9922110077
Contact inserted at beginning.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 2
Enter name: Nikita
Enter phone number: 664489
Contact inserted at end.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 4
Enter name to search: Nikita

Contact Found!
Name  : Nikita
Phone : 664489

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 4
Enter name to search: Suraj
Contact not found.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 5

------ Contact List ------
Name  : Sakshi
Phone : 9922110077
--------------------------
Name  : Nikita
Phone : 664489
--------------------------

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 3
Enter name to delete: Nikita
Contact deleted successfully.

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 5

------ Contact List ------
Name  : Sakshi
Phone : 9922110077
--------------------------

===== CONTACT MANAGEMENT SYSTEM =====
1. Insert at Beginning
2. Insert at End
3. Delete Contact
4. Search Contact
5. Display Contacts
6. Exit
Enter your choice: 6
All memory deallocated. Exiting...


=== Code Execution Successful ===
