#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root, *parent, *current;

void insert(int data)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;

    if (root == NULL)
    {
        root = tempNode;
        return;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            if (data < parent->data)
            {
                current = current->left;
                if (current == NULL)
                {
                    parent->left = tempNode;
                    return;
                }
            }
            else if (data > parent->data)
            {
                current = current->right;
                if (current == NULL)
                {
                    parent->right = tempNode;
                    return;
                }
            }
        }
    }
}

struct Node *search(int data)
{
    struct Node *current;

    current = root;

    while (current->data != data)
    {
        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }

        if (current == NULL)
        {
            return NULL;
        }
    }

    return current;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("Data : %d \n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("Data : %d \n", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("Data : %d \n", root->data);
    }
}

struct Node *find_min(struct Node *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    else if (tree->left == NULL)
    {
        return tree;
    }

    return find_min(tree->left);
}

struct Node *removeNode(struct Node *tree, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    int cmp = data - tree->data;

    if (cmp < 0)
    {
        temp = removeNode(tree->left, data);
        tree->left = temp;
    }
    else if (cmp > 0)
    {
        temp = removeNode(tree->right, data);
        tree->right = temp;
    }
    else if (tree->left != NULL && tree->right != NULL)
    {
        struct Node *min = find_min(tree->right);
        tree->data = min->data;
        temp = removeNode(tree->right, min->data);
        tree->right = temp;
    }
    else
    {
        struct Node *nodeToDelete = tree;
        if (tree->left == NULL)
        {
            tree = tree->right;
        }
        else if (tree->right == NULL)
        {
            tree = tree->left;
        }
        else
        {
            tree = NULL;
        }
        free(nodeToDelete);
    }

    return tree;
}

int main()
{
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};

    for (i = 0; i < 7; i++)
        insert(array[i]);

    i = 31;
    struct Node *temp = search(i);

    if (temp != NULL)
    {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }
    else
    {
        printf("[ x ] Element not found (%d).\n", i);
    }

    i = 15;
    temp = search(i);

    if (temp != NULL)
    {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }
    else
    {
        printf("[ x ] Element not found (%d).\n", i);
    }

    printf("\nPreorder traversal: ");
    preOrder(root);

    printf("\nInorder traversal: ");
    inOrder(root);

    printf("\nPost order traversal: ");
    postOrder(root);

    struct Node *delNode = removeNode(root, 19);

    printf("\nPreorder traversal: ");
    preOrder(root);

    return 0;
}