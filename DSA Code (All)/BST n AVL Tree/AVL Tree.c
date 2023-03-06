#include<stdio.h>
#include<stdlib.h>

struct root{
    int data;
    struct root *left, *right;
    int height;
};

struct root * newNode(int key);
struct root * insert_avl(struct root *node, int key);
void inorder(struct root *node);
struct root * deleteNode(struct root *node, int key);
int max(int a, int b);
int heightOfNode(struct root *node);
int balanceFactor(struct root *node);
struct root * leftRotate(struct root *node);
struct root * rightRotate(struct root *node);

int main()
{
    struct root *t = NULL;

    t = insert_avl(t,34);
    t = insert_avl(t,30);
    t = insert_avl(t,32);
    t = insert_avl(t,15);
    t = insert_avl(t,13);
    t = insert_avl(t,20);
    t = insert_avl(t,31);
    t = insert_avl(t,25);
    t = insert_avl(t,28);

    printf("Inorder traversal: ");
    inorder(t);

    t = deleteNode(t,40);
    printf("\nInorder traversal: ");
    inorder(t);
}

struct root * newNode(int key)
{
    struct root *temp = (struct root *)malloc(sizeof(struct root));
    temp->data = key;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

struct root * insert_avl(struct root *node, int key)
{
    if(node == NULL){
        return newNode(key);
    }
    else if(node->data > key){
        node->left = insert_avl(node->left,key);
    }
    else if(node->data < key){
        node->right = insert_avl(node->right,key);
    }
    else
        return node;

    if(node == NULL)
        node->height = 0;
    else
        node->height = max(heightOfNode(node->left) , heightOfNode(node->right))+1;
    
    int bf = balanceFactor(node);
    if(bf>1 && key<(node->left->data)){
        return rightRotate(node);
    }
    else if(bf>1 && key>(node->left->data)){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if(bf<-1 && key<(node->right->data)){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    else if(bf<-1 && key>(node->right->data)){
        return leftRotate(node);
    }

    return node;
}

int heightOfNode(struct root *node)
{
    if(node == NULL)
        return 0;
    else
        return node->height;
}

int max(int a, int b)
{
    return a>b?a:b;
}

void inorder(struct root *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("--> %d ",node->data);
        inorder(node->right);
    }
}

struct root * deleteNode(struct root *node, int key)
{
    if(node == NULL)
        return NULL;
    else if(key > (node->data))
        node->right = deleteNode(node->right, key);
    else if(key < (node->data))
        node->left = deleteNode(node->left, key);
    else
    {
        if(node->left == NULL && node->right == NULL)
        {
            free(node);
            return NULL;
        }
        else if(node->left == NULL)
        {
            struct root * temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == NULL)
        {
            struct root * temp = node->left;
            free(node);
            return temp;
        }
        else
        {
            struct root * temp = node->right;
            while(temp->left != NULL)
                temp = temp->left;
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }
    return node;
}

int balanceFactor(struct root *node)
{
    if(node == NULL)
        return 0;
    int bf = heightOfNode(node->left) - heightOfNode(node->right);
    return bf;
}

struct root * leftRotate(struct root *node)
{
    struct root *nn,*nnl;
    nn = node->right;
    nnl = node->right->left;

    nn->left = node;
    node->right = nnl;

    node->height = max(heightOfNode(node->left), heightOfNode(node->right))+1;
    nn->height = max(heightOfNode(nn->left), heightOfNode(nn->right))+1;

    return nn;
}

struct root * rightRotate(struct root *node)
{
    struct root *nn,*nnl;
    nn = node->left;
    nnl = node->left->right;

    nn->right = node;
    node->left = nnl;

    node->height = max(heightOfNode(node->left), heightOfNode(node->right))+1;
    nn->height = max(heightOfNode(nn->left), heightOfNode(nn->right))+1;

    return nn;
}

