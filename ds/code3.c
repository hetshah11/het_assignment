/*Print all nodes of a perfect binary tree in a specific order.
Given a perfect binary tree, print the values of alternating left and right nodes for each level in a top-
down and bottom-up manner.
For example, there are two ways to print the following tree:
Variation 1: Print Top-Down
(1, 2, 3, 4, 7, 5, 6, 8, 15, 9, 14, 10, 13, 11, 12)

Variation 2: Print Bottom-Up
(8, 15, 9, 14, 10, 13, 11, 12, 4, 7, 5, 6, 2, 3, 1)*/

//Edited by: Het Shah





#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node

struct node
{
    int data;
    struct node *left, *right;
};

//insert node into queue
int enqueue(struct node arr[], int *front, int *rear, struct node *node, int n)
{
    if (*rear >= n)
    {
        // printf("Queue overflow\n");
        return 0;
    }
    else
    {
        *rear = *rear + 1;
        arr[*rear] = *node;
    }
    if (*front == 0)
        *front = *front + 1;
}

//delete a node from queue
struct node* dequeue(struct node arr[], int *front, int *rear, int n)
{
    if (*front == 0 && *rear == 0)
    {
        // printf("Queue underflow\n");
        // return NULL;
    }

    struct node *nod = &arr[*front];
    
    if (*front == *rear != 0)
    {
        *front = *rear = 0;
        // printf("%c deleted successfully\n", y);
    }
    else
    {
        *front = *front + 1;
        // printf("%c deleted successfully\n", y);
    }

    return nod;
}

//checking that queue is empty or not
int empty(struct node arr[], int *front, int *rear)
{
    if (*front == *rear == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//This function returns front node of queue
struct node* fron(struct node arr[], int *front, int *rear)
{
    return &arr[*front];
}

//print preOrder traversal of given tree
void preOrder(struct node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    if (node->left != NULL)
        preOrder(node->left);
    if (node->right != NULL)
        preOrder(node->right);
}

// Function to print all nodes of a given binary tree in a specific
// order from top to bottom
void topDowntraversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    // print root data first
    printf("%d ", root->data);

    if (root->left != NULL && root->right != NULL)
    {
        printf("%d %d ", root->left->data, root->right->data);
    }

    if (root->left->left == NULL)
        return;

    if (root->right->right == NULL)
        return;

    int n = 20;
    int front = 0, rear = 0;
    struct node queue[n];

    enqueue(queue, &front, &rear, root -> left, n);
    enqueue(queue, &front, &rear, root -> right, n);

    struct node *first = NULL;
    struct node *second = NULL;

    while(empty(queue, &front, &rear))
    {
        first = fron(queue, &front, &rear);
        dequeue(queue, &front, &rear, n);
        second = fron(queue, &front, &rear);
        dequeue(queue, &front, &rear, n);

        // Print children of first and second in reverse order
        printf("%d %d ", first -> left -> data, second -> right -> data);
        printf("%d %d ", first -> right -> data, second -> left -> data);

        // If first and second have grandchildren, enqueue them
        // in reverse order
        if (first->left->left != NULL)
        {
           enqueue(queue, &front, &rear,first->left, n);
           enqueue(queue, &front, &rear,second->right, n);
        //    enqueue(queue, &front, &rear, first->right, n);
        //    enqueue(queue, &front, &rear,second->left, n);
        }
    }
    
}
// struct node* newNode(int data)
// {
// 	struct node *node = (struct node*)malloc(sizeof(struct node));
// 	node->data = data;
// 	node->right = node->left = NULL;
// 	return node;
// }

int main()
{
    // struct node *root = newNode(1);
    struct node *root;  //creating root node
    root = (struct node *)malloc(sizeof(struct node));  //allocated memory for root node

    // root->left	 = newNode(2);
	// root->right	 = newNode(3);

	// root->left->left = newNode(4);
	// root->left->right = newNode(5);
	// root->right->left = newNode(6);
	// root->right->right = newNode(7);

	// root->left->left->left = newNode(8);
	// root->left->left->right = newNode(9);
	// root->left->right->left = newNode(10);
	// root->left->right->right = newNode(11);
	// root->right->left->left = newNode(12);
	// root->right->left->right = newNode(13);
	// root->right->right->left = newNode(14);
	// root->right->right->right = newNode(15);
    
    struct node *two = (struct node *)malloc(sizeof(struct node));
    struct node *three = (struct node *)malloc(sizeof(struct node));
    struct node *four = (struct node *)malloc(sizeof(struct node));
    struct node *seven = (struct node *)malloc(sizeof(struct node));
    struct node *five = (struct node *)malloc(sizeof(struct node));
    struct node *six = (struct node *)malloc(sizeof(struct node));
    struct node *eight = (struct node *)malloc(sizeof(struct node));
    struct node *nine = (struct node *)malloc(sizeof(struct node));
    struct node *ten = (struct node *)malloc(sizeof(struct node));
    struct node *eleven = (struct node *)malloc(sizeof(struct node));
    struct node *twelve = (struct node *)malloc(sizeof(struct node));
    struct node *thirteen = (struct node *)malloc(sizeof(struct node));
    struct node *fourteen = (struct node *)malloc(sizeof(struct node));
    struct node *fifthteen = (struct node *)malloc(sizeof(struct node));

    root->data = 1;
    root->left = two;
    root->right = three;

    two->data = 2;
    two->left = four;
    two->right = five;

    three->data = 3;
    three->left = six;
    three->right = seven;

    four->data = 4;
    four->left = eight;
    four->right = nine;

    five->data = 5;
    five->left = ten;
    five->right = eleven;

    six->data = 6;
    six->left = twelve;
    six->right = thirteen;

    seven->data = 7;
    seven->left = fourteen;
    seven->right = fifthteen;

    eight->data = 8;
    eight->left = NULL;
    eight->right = NULL;

    nine->data = 9;
    nine->left = NULL;
    nine->right = NULL;

    ten->data = 10;
    ten->left = NULL;
    ten->right = NULL;

    eleven->data = 11;
    eleven->left = NULL;
    eleven->right = NULL;

    twelve->data = 12;
    twelve->left = NULL;
    twelve->right = NULL;

    thirteen->data = 13;
    thirteen->left = NULL;
    thirteen->right = NULL;

    fourteen->data = 14;
    fourteen->left = NULL;
    fourteen->right = NULL;

    fifthteen->data = 15;
    fifthteen->left = NULL;
    fifthteen->right = NULL;

    printf("Preorder traversal: \n");
    preOrder(root);
    printf("\nGiven top down traversal: \n");
    topDowntraversal(root);
    printf("\n");
}
