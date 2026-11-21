// 118
#include <stdio.h>

#define MAX 50

struct Patient
{
    int patientID;
    char arrivalTime[20];
};

struct Patient queue[MAX];

int front = -1;
int rear = -1;

// a. Add patient to queue
void addPatient(int patientID, char arrivalTime[])
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;

    queue[rear].patientID = patientID;

    int i = 0;
    while (arrivalTime[i] != '\0')
    {
        queue[rear].arrivalTime[i] = arrivalTime[i];
        i++;
    }
    queue[rear].arrivalTime[i] = '\0';

    printf("Patient %d added successfully.\n", patientID);
}

// b. Attend patient
void attendPatient()
{
    if (front == -1 || front > rear)
    {
        printf("No patients waiting.\n");
        return;
    }

    printf("Attending Patient ID: %d\n", queue[front].patientID);
    printf("Arrival Time: %s\n", queue[front].arrivalTime);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// c. View all waiting patients
void viewPatients()
{
    int i;

    if (front == -1)
    {
        printf("No patients waiting.\n");
        return;
    }

    printf("\nPatients currently waiting:\n");

    for (i = front; i <= rear; i++)
    {
        printf("Patient ID: %d | Arrival Time: %s\n",
               queue[i].patientID,
               queue[i].arrivalTime);
    }
}

// d. Check if queue is empty
void isQueueEmpty()
{
    if (front == -1)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

int main()
{
    int choice;
    int patientID;
    char arrivalTime[20];

    do
    {
        printf("\n===== HOSPITAL PATIENT QUEUE =====\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &patientID);

                printf("Enter Arrival Time: ");
                scanf("%s", arrivalTime);

                addPatient(patientID, arrivalTime);
                break;

            case 2:
                attendPatient();
                break;

            case 3:
                viewPatients();
                break;

            case 4:
                isQueueEmpty();
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

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: 1
   Enter Patient ID: 22
   Enter Arrival Time: 12 00
   Patient 22 added successfully.

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: Invalid choice!

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: 3

Patients currently waiting:
Patient ID: 22 | Arrival Time: 12

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: 2
   Attending Patient ID: 22
   Arrival Time: 12

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: 4
   Queue is empty.

===== HOSPITAL PATIENT QUEUE =====

1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit
   Enter your choice: 5
   Exiting...


