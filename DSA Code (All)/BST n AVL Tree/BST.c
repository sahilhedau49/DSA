#include<stdio.h>
#include<stdlib.h>

struct root{
    int data;
    struct root * left;
    struct root * right;
};

struct root *newNode(int key);
struct root * insert_bst(struct root *node, int key);
void inorder(struct root * node);
void postorder(struct root * node);
void preorder(struct root * node);
struct root *deleteNode(struct root *node, int key);
int heightOfTree(struct root *node);
int countNodes(struct root *node);
void print_level(struct root *node, int level);
void print_levelOrder(struct root *node);
int max(int a, int b);

int main()
{
    struct root *tr = NULL;
    
    tr = insert_bst(tr,1);
    tr = insert_bst(tr,2);
    tr = insert_bst(tr,3);
    tr = insert_bst(tr,4);
    tr = insert_bst(tr,5);
    tr = insert_bst(tr,6);
    tr = insert_bst(tr,7);
    tr = insert_bst(tr,8);

    printf("\nInorder traversal: ");
    inorder(tr);
    printf("\nPreorder traversal: ");
    preorder(tr);
    printf("\nPostorder traversal: ");
    postorder(tr);
    printf("\nThe Current Height of the Tree is : %d", heightOfTree(tr));

    struct root *t = NULL;

    t = insert_bst(t,30);
    t = insert_bst(t,5);
    t = insert_bst(t,3);
    t = insert_bst(t,40);
    t = insert_bst(t,35);
    t = insert_bst(t,32);
    t = insert_bst(t,50);

    printf("\n\n\nInorder traversal: ");
    inorder(t);
    printf("\nPreorder traversal: ");
    preorder(t);
    printf("\nPostorder traversal: ");
    postorder(t);
    printf("\nThe Current Height of the Tree is : %d", heightOfTree(t));
    printf("\nThe current number of nodes in tree are : %d", countNodes(t));
    print_levelOrder(t);

    t = deleteNode(t,3);
    printf("\nInorder traversal: ");
    inorder(t);

    t = deleteNode(t,35);
    printf("\nInorder traversal: ");
    inorder(t);

    t = deleteNode(t,30);
    printf("\nInorder traversal: ");
    inorder(t);
    printf("\nThe Current Height of the Tree is : %d", heightOfTree(t));

    return 0;
}

struct root *newNode(int key)
{
    struct root *temp = (struct root *)malloc(sizeof(struct root));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

struct root * insert_bst(struct root *node, int key)
{
    if(node == NULL){
        return newNode(key);
    }
    else if((node->data) > key){
        node->left = insert_bst(node->left,key);
    }
    else if((node->data) < key){
        node->right = insert_bst(node->right,key);
    }
    return node;
}

void inorder(struct root * node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("-> %d ",node->data);
        inorder(node->right);
    }
}

void preorder(struct root * node)
{
    if(node != NULL)
    {
        printf("-> %d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct root * node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("-> %d ",node->data);
    }
}

struct root *deleteNode(struct root *node, int key)
{
    if (node == NULL)
        return NULL;
    else if (key < (node->data))
        node->left = deleteNode(node->left, key);
    else if (key > (node->data))
        node->right = deleteNode(node->right, key);
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            printf("\n\nDeleted Node with value: %d.",key);
            return NULL;
        }
        else if (node->left == NULL)
        {
            struct root *temp = node->right;
            printf("\n\nDeleted Node with value: %d.",key);
            free(node);
            return (temp);
        }
        else if (node->right == NULL)
        {
            struct root *temp = node->left;
            printf("\n\nDeleted Node with value: %d.",key);
            free(node);
            return (temp);
        }
        else
        {
            struct root *temp = node->right;
            while (temp->left != NULL)
                temp = temp->left;

            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

int heightOfTree(struct root *node)
{
    // if (node == NULL)
    //     return 0;
    // else
    // {
    //     int lh = heightOfTree(node->left);
    //     int rh = heightOfTree(node->right);

    //     if (lh < rh)
    //         return (rh + 1);
    //     else
    //         return (lh + 1);
    // }

    if (node == NULL)
        return 0;
    else
        return max(heightOfTree(node->left), heightOfTree(node->right)) + 1;
}

int max(int a, int b){
    return a>b?a:b;
}

int countNodes(struct root *node)       // leaf node
{
    if (node == NULL)
        return 0;
    else{
        if(node->left == NULL && node->right == NULL)
            return countNodes(node->left) + countNodes(node->right) + 1;
        else
            return countNodes(node->left) + countNodes(node->right);
    }
}

void print_level(struct root *node, int level)
{
    if (node == NULL)
        return;
    else if (level == 1)
        printf("-> %d ", node->data);
    else if (level > 1)
    {
        print_level(node->left, level - 1);
        print_level(node->right, level - 1);
    }
}

void print_levelOrder(struct root *node)
{
    printf("\nLevel order traversal: ");
    int h = heightOfTree(node);
    for (int i = 1; i <= h; i++)
        print_level(node, i);
}