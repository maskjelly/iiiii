#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top = 0;
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}
void pop()
{
    struct node *temp;
    temp = top;
    if (temp == 0)
    {
        printf("Underflow");
    }
    else
    {
        printf("Popped element is %d", temp->data);
        top = temp->link;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = top;
    if (temp == 0)
    {
        printf("Underflow");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d\t", temp->data);
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
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}