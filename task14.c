#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
}nodes;

nodes *head = NULL;
int size = 0;
int create()
{
    int i,n,data;
    nodes *node,*temp;
    printf("How many nodes you want to create\n");
    scanf("%d",&n);

    size = n;

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

void insertIndex(int data,int index){
    nodes *node, *temp, *temp2;
    temp = head;
    int count =1;
    node = (nodes *)malloc(sizeof(nodes));
    node->data = data;
    node->next = NULL;

    if(index>size+1 || index<=0){

    }
    //insert in 1st index
    if(index == 1){
        node->next = head->next;
        head = node;
    }
    //insert in other index
    else {
        while(count<index-1){
            temp = temp->next;
            count++;
        }
        node->next = temp->next;
        temp->next  = node;
    }

}





int main()
{
    int data;
     create();
    read();
    insertIndex(15,5);
    read();
    return 0;

}
