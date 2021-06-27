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

void delIndex(){
    Nodes *temp,*temp2;
    temp = head;
    int n,count=1;

    printf("\nEnter which index you want to delete\n");
    scanf("%d",&n);
    if(n==1){
        head = head->next;
        free(temp);
    }
    else{
        while(count<n-1){
            temp = temp->next;
            count++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;

        free(temp2);
    }
}



int main()
{

    create();
    read();
    delIndex();
    read();
    return 0;

}
