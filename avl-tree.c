#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key, data, height;
    struct Node *left, *right;
};

struct Node* newNode(int key, int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(struct Node* p)
{
    return p ? p -> height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void recalc(struct Node* p)
{
    p->height = 1 + max(height(p->left),height(p->right)); 
}

struct Node* rotate_right(struct Node* p)
{
    struct Node* q = p->left;

    p->left = q->right;
    q->right = p;

    recalc(p);
    recalc(q);

    return q;
}

struct Node* rotate_left(struct Node* p)
{
    struct Node* q = p->right;

    p->right = q->left;
    q->left = p;

    recalc(p);
    recalc(q);

    return q;
}

struct Node* balance(struct Node* p)
{
    recalc(p);

    if(height(p->left) - height(p->right) == 2)
    {
        if(height(p->left->right) > height(p->left->left))
           p->left =  rotate_left(p->left);
        return rotate_right(p);
    }
    else if(height(p->right) - height(p->left) == 2)
    {
        if(height(p->right->left) > height(p->right->right))
            p->right =rotate_right(p->right);
        return rotate_left(p);
    }
    
    return p;
}

struct Node* insert(struct Node* p, int key, int data)
{
    if(!p)
        return newNode(key,data);

    if(p->key > key)
        p->left = insert(p->left, key, data);
    else if (p->key < key)
        p->right =  insert(p->right, key, data);
    else 
        p->data = data;

    return balance(p);
}

struct Node* search(struct Node* p, int key)
{    
    if(!p)
        return NULL;

    if(p->key > key)
        return search(p->left, key);
    else if(p->key < key)
        return search(p->right, key);
    else
        return p;
}

struct Node* find_min(struct Node* p)
{
    if(p->left != NULL)
        find_min(p->left);
    else
        return p;
}

struct Node* remove_min(struct Node* p)
{
    if(p->left == NULL)
        return p->right;

    p->left = remove_min(p->left);

    return balance(p); 
}

struct Node* remove_item(struct Node* p, int key)
{
    if(!p)
    {
        printf("NOTHING TO DELETE \n");
        return NULL;
    }
    if(p->key < key)
        p->right = remove_item(p->right, key);
    else if(p->key > key)
        p->left = remove_item(p->left, key);

    else
    {
        struct Node* l = p->left;
        struct Node* r = p->right;

        free(p);

        if( r == NULL)
            return l;

        struct Node* m = find_min(r);
        m->right = remove_min(r);
        m->left = l;

        return balance(m);
    }
    
    return balance(p);
}

void free_tree(struct Node* p)
{
    if ( !p )
        return;

    free_tree(p -> left);
    free_tree(p -> right);
    free(p);
}

int main(){
    struct Node* root = NULL;

    char c;
    int k, d;
    printf("Enter 'A' to Add Values \n 'S' to SEarch Value \n OR \n 'D' to delte values \n\n 'F' to exit \n");
    while ( scanf("%c", &c) && c != 'F' )
    {
        if ( c == 'A' )
        {
            printf("Insert VALUES \n");
            scanf("%d %d", &k, &d);
            root = insert(root, k, d);
        }
        else if ( c == 'S' )
        {
            printf("Search VALUES \n");
            scanf("%d", &k);
            struct Node* n = search(root, k);
            if ( n ) 
                printf("%d %d\n", n -> key, n -> data);
        }
        else if ( c == 'D' )
        {
            printf("Delete VALUES \n");
            scanf("%d", &k); 
            root = remove_item(root, k);
        }
        printf("1- Enter 'A' to Add Values \n 2- 'S' to SEarch Value \n OR \n 3- 'D' to delte values \n\n 4- 'F' to exit \n");
    }

    free_tree(root);

    return 0;
}