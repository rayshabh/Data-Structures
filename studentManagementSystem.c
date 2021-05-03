#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME 30
#define CONTACT 15
#define GENDER 10

/*
Implementation of Student Management System for a classroom.
A simple implemetation using Linked List.
The details stored are such as roll no, student name, contact, gender and blood group.
*/
struct Student
{
    int rollNo;
    char studentName[NAME];
    char contact[CONTACT];
    char gender[GENDER];
    char bloodGroup;
    struct Student *nextLink;
} * head;

struct Student *createNode() //function to create nodes dynamically using malloc and returns the node
{
    struct Student *node = (struct Student *)malloc(sizeof(struct Student));

    if (node == NULL)
        printf("\nMemory allocation unsuccessful!\n");
    else
        return node;
}

void addDetails(int rollNo, char *studentName, char *contact, char *gender, char bloodGroup)
{
    struct Student *add = createNode();
    add->rollNo = rollNo;
    strcpy(add->studentName, studentName);
    strcpy(add->contact, contact);
    strcpy(add->gender, gender);
    add->bloodGroup = bloodGroup;
    add->nextLink = NULL;

    if (head == NULL) //checking if head points to any existing node or not
    {
        head = add; //if not, point the head to 'add'
    }
    else //if not, then traverse using a temporary pointer to the last node and append the 'add' node.
    {
        struct Student *ptr = head;
        while (ptr->nextLink != NULL)
        {
            ptr = ptr->nextLink;
        }
        ptr->nextLink = add;
    }
    //return;
}

void updateDetails(int rollNo)
{
    struct Student *update = head;
    while (update != NULL)
    {
        if (update->rollNo == rollNo)
        {
            printf("\nRoll No. %d found in records!\n", rollNo);
            printf("\nEnter new name: ");
            gets(update->studentName);
            printf("\nEnter new contact details: ");
            gets(update->contact);
            printf("\nEnter Gender: ");
            gets(update->gender);
            printf("\nEnter the Blood Group: ");
            scanf("%c", &update->bloodGroup);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            //return;
        }
        update = update->nextLink;
    }
    printf("\nRoll No. %d not found in the records!\n", rollNo);
}

void searchDetails(int rollNo)
{
    struct Student *search = head;
    while (search != NULL)
    {
        if (search->rollNo == rollNo)
        {
            printf("\nSearch Found in the records!\n");
            printf("Roll No.: %d\n", search->rollNo);
            printf("Name: %s\n", search->studentName);
            printf("Contact: %s\n", search->contact);
            printf("Gender: %s\n", search->gender);
            printf("Blood Group: %c\n", search->bloodGroup);
            //return;
        }
        search = search->nextLink;
    }
    printf("\nRoll No. %d not found in the records!\n", rollNo);
}

void deleteDetails(int rollNo)
{
    struct Student *delete = head;
    struct Student *previous = head;

    while (delete != NULL)
    {
        if (delete->rollNo == rollNo)
        {
            printf("Roll No. %d found in the records!\n", rollNo);

            if (delete == previous) //if the request is to delete the first node of the list
            {
                head = head->nextLink; //move the head pointer to the next node
                free(delete);
            }
            else
            {
                previous->nextLink = delete->nextLink; //if request is to delete the node from middle
                free(delete);                          //link the previous node of the requested node(i.e node which you want to remove) and link it with the next node of the requested node
            }
            printf("\nRecord successfully deleted!\n");
            //return;
        }
        previous = delete;
        delete = delete->nextLink; //increment the delete pointer
    }
}

void viewDetails()
{
    struct Student *view = head;
    if (view == NULL)
    {
        printf("\nRecords Empty!\n");
    }
    else
    {
        printf("\n\t\t\t\tRecord Details\n");
        printf("\nRoll No.\tName\t\t\tContact\t\tGender\t\tBloodGroup\n");
        while (view != NULL)
        {
            printf("\nRoll No.: %d\n", view->rollNo);
            printf("Name: %s\n", view->studentName);
            printf("Contact: %s\n", view->contact);
            printf("Gender: %s\n", view->gender);
            printf("Blood Group: %c\n", view->bloodGroup);
            printf("\n");
            view = view->nextLink;
        }
    }
    //return;
}

int main()
{
    int choice = 0, rollNo;
    char studentName[NAME], contact[CONTACT], gender[GENDER], bloodGroup;
    head = NULL; //initially head is assigned 'NULL' value.
    printf("\n\t\t\t\t\tWELCOME TO STUDENT MANAGEMENT SYSTEM PROGRAM!\n");
    do
    {
        printf("\nPlease select a choice. Press '0' to exit!\n\n1)Add a new entry\n2)Update an entry\n3)Search an entry\n4)Delete an entry\n5)View the records\n\nChoice: ");
        scanf("%d", &choice);
        while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
            ;

        switch (choice)
        {
        case 0: //to quit the program
            printf("\nQuitting the program....!\n");
            break;
        case 1: //to add the new entry
            printf("\nEnter student's details:\n");
            printf("\nEnter the roll number: ");
            scanf("%d", &rollNo);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            printf("\nEnter the name: ");
            gets(studentName);
            printf("\nEnter the contact details: ");
            gets(contact);
            printf("\nEnter the Gender: ");
            gets(gender);
            printf("\nEnter the Blood Group: ");
            scanf("%c", &bloodGroup);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            addDetails(rollNo, studentName, contact, gender, bloodGroup);
            break;
        case 2: //to update an existing entry
            printf("\nEnter the roll no. to update the details!\n\nRoll No: ");
            scanf("%d", &rollNo);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            updateDetails(rollNo);
            break;
        case 3: //to search an entry
            printf("\nEnter the roll no. to search the details!\n\nRoll No: ");
            scanf("%d", &rollNo);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            searchDetails(rollNo);
            break;
        case 4: //to delete an existing entry
            printf("\nEnter the roll no. to delete the details!\n\nRoll No: ");
            scanf("%d", &rollNo);
            while ((getchar()) != '\n') //To avoid Input Buffer Misbehaviour
                ;
            deleteDetails(rollNo);
            break;
        case 5: //to view the existing entries in record
            viewDetails();
            break;
        default: //for invalid choices
            printf("\nPlease enter a valid choice!\n");
            break;
        }
    } while (choice);
    system("pause");
    return 0;
}