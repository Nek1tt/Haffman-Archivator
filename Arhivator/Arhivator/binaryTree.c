#include "myArchivator.h"

int32_t size = 0;
Node** queue = NULL;

Node* newNode(char letter, int32_t freq)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("\n");
        printf("\n");
        printf("===================================================================================================================\n");
        printf("||  Memory management error: Cannot locate memory when creating a newNode. Check binaryTree.c for more details.  ||\n");
        printf("===================================================================================================================\n");
        exit(1);
    }
    temp->letter = letter;
    temp->freq = freq;
    temp->right = temp->left = NULL;
    return temp;
}

void addElement(Node* item)
{
    if (queue == NULL)
    {
        queue = (Node**)malloc(count * sizeof(Node*));
        if (queue == NULL)
        {
            printf("\n");
            printf("\n");
            printf("============================================================================================================== ==\n");
            printf("||  Memory management error: Cannot locate memory when add a new element. Check binaryTree.c for more details  ||\n");
            printf("=================================================================================================================\n");
            exit(1);
        }
        for (int32_t i = 0; i < count; i++)
        {
            queue[i] = NULL;
        }
    }
    queue[size] = item;
    size++;
    insertSort();
}

Node* delElement()
{
    Node* del = queue[0];
    for (int32_t i = 1; i < size; i++)
    {
        queue[i - 1] = queue[i];
    }
    queue[size - 1] = NULL;
    size--;
    return del;
}

void freeQueue()
{
    free(queue[0]);
    free(queue);
}


