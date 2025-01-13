#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Empty");
    }
    else
    {
        printf("popped element is %d", temp->data);
        front = temp->link;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Empty");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d", temp->data);
            temp = temp->link;
        }
    }
}
int main()
{
    int choice;
    int value;
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to add\n");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}