#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist{
    int data;
    struct Nodelist *next;
}Nodes;

Nodes *head = NULL;

Nodes  *create(){
    int i,n,data;
    Nodes *node,*temp;

    printf("How many nodes you want to create\n");
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        printf("Enter node %d data: ",i);
        scanf("%d",&data);

        node = (Nodes *)malloc(sizeof(Nodes));
        node->data = data;
        node->next = NULL;

        if(head == NULL){
            head = node;
            temp = head;
        }
        else{
            temp->next = node;
            temp = node;
                    }
    }

}

void read(){
    Nodes *temp;
    temp = head;
    printf("\nRead linked list data");
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp = temp->next;
    }
}

void insert(){
    int n,data,count=1;
    Nodes *temp, *node;
    temp = head;
    printf("\nInsert index where you want to insert node\n");
    scanf("%d",&n);
    printf("Enter the data\n");
    scanf("%d",&data);

    node = (Nodes *)malloc(sizeof(Nodes));
    node->data = data;
    node->next = NULL;

    if(n==1){
        node->next = head;
        head = node;
    }
    else{
        while(count<n-1){
            temp = temp->next;
            count++;
        }
        node->next = temp->next;
        temp->next = node;
    }
}




int main(){

 create();
 read();
 insert();
 read();
 return 0;
}
