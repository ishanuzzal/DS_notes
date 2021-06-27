#include <stdio.h>
#include <stdlib.h>

typedef struct Nodelist
{
    int data;
    struct Nodelist *next;
}queue;

queue *top = NULL;
queue *rear = NULL;

int isEmpty(){
    return top == NULL;
}

void enqueue(int data){
    queue *node = (queue *)malloc(sizeof(queue));
    node->data = data;
    node->next = NULL;
    if(top == NULL){
        top = node;
        rear = node;
    }
    else{
         rear->next = node;
         rear = node;
    }
}

void dequeue(){
    queue *temp;
    if(isEmpty()){
        printf("Nothing to delete\n");
        return;
    }
    printf("\n%d deleted from queue\n",top->data);
    temp = top;
    top = top->next;
    free(temp);
}

void display(){
    queue *temp = top;
    while(temp!=NULL){
        printf(" %d",temp->data);
        temp=temp->next;
    }
}

int main()
{
   enqueue(2);
   enqueue(3);
   enqueue(4);
   dequeue();
   display();


    return 0;

}

