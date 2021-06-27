#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
} Nodes;

Nodes *head = NULL;

void create()
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

void searchIndexValue(){
    Nodes *temp;
    temp = head;
    int index, count=1;

    printf("\nEnter which index value you want to find\n");
    scanf("%d",&index);

    while(count!=index){
        temp = temp->next;
        count++;
    }
    printf("%d index value is %d",index, temp->data);
}



int main()
{

    create();
    read();
    searchIndexValue();
    return 0;

}
