#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *rlink;
    struct tree *llink;
};

typedef struct tree *treeptr;

void insert(treeptr *root, int item) {
    if (!(*root)) {
        *root = (treeptr)malloc(sizeof(struct tree));
        if (!*root) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        (*root)->data = item;
        (*root)->llink = NULL;
        (*root)->rlink = NULL;
        return;
    } else if ((*root)->data > item) {
        insert(&(*root)->llink, item);
    } else if ((*root)->data < item) {
        insert(&(*root)->rlink, item);
    }
}

void inorder(treeptr root) {
    if (root) {
        inorder(root->llink);
        printf("%d\t", root->data);
        inorder(root->rlink);
    }
}

void preorder(treeptr root) {
    if (root) {
        printf("%d\t", root->data);
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(treeptr root) {
    if (root) {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\t", root->data);
    }
}

void search(treeptr root, int item) {
    if (root == NULL) {
        printf("\nNot found\n");
        return;
    } else if (root->data == item) {
        printf("\nFound\n");
        return;
    } else if (root->data > item) {
        search(root->llink, item);
    } else {
        search(root->rlink, item);
    }
}

int main() {
    int ch, item;
    treeptr root = NULL;

    while (1) {
        printf("\n1. Insert\n2. In-order\n3. Pre-order\n4. Post-order\n5. Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &item);
                insert(&root, item);
                break;

            case 2:
                printf("\nIn-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("\nPre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("\nPost-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("\nEnter element to be searched: ");
                scanf("%d", &item);
                search(root, item);
                break;

            case 6:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}
