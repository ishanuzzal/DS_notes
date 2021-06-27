#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
}nodes;

nodes *head = NULL;

nodes create()
{
    int i,n,data;
    nodes *node,*temp;

    printf("How many nodes you want to create\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter node %d data: ",i);
        scanf("%d",&data);

        node = (nodes *)malloc(sizeof(nodes));
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

}

void read()
{
    nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
}

void findIndex(int data){
    nodes *temp;
    int index=1;
    temp = head;

    while(temp!=NULL){
        if(temp->data==data){
            printf("%d is in %d index\n",data,index);
            return;
        }
        index++;
        temp = temp->next;

    }
    printf("No value found\n");
}


int main()
{
    int data;
    create();
    read();
    printf("\nEnter which data you want to find\n");
    scanf("%d",&data);

    findIndex(data);
    return 0;

}

