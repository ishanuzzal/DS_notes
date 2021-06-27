#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

Nodes *create()
{
    int i,n,data;
    Nodes *node,*temp;

    printf("How many nodes you want to create\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter node %d data: ",i);
        scanf("%d",&data);

        node = (Nodes *)malloc(sizeof(Nodes));
        node->data = data;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;
            temp = head;
        }
        else
        {
            temp->next = node;
            temp = node;
        }
    }
    return head;

}

void read()
{
    Nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
}

void insertFirst()
{
    int n,data,count=1;
    Nodes *node;
    printf("\nEnter 1st node data\n");
    scanf("%d",&data);

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    node->next = head;
    head = node;
}

void insertLast()
{
    Nodes *temp, *node;

    temp = head;

    int data;
    printf("\nEnter last node data\n");
    scanf("%d",&data);

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = node;

}


int main()
{

    create();
    read();
    insertFirst();
    insertLast();
    read();
    return 0;

}
