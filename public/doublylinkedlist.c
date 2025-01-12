#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head;
void enqueue()
{
    struct node *newnode;
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d", &newnode->data);
    newnode->right = 0;
    newnode->left = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->right = newnode;
        newnode->left = temp;
        temp = newnode;
    }
}
void delete()
{
    struct node *temp;
    if (head == 0)
    {
        printf("Empty");
    }
    else
    {
        temp = head;
        head = head->right;
        head->left = 0;
        printf("popped element is %d", temp->data);
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == 0)
    {
        printf("Empty");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d", temp->data);
            temp = temp->right;
        }
    }
}
int main()
{
    int choice;
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
            enqueue();
            break;
        case 2:
            delete ();
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