#include<stdio.h>
#include<stdlib.h>

/*Node*/
struct Node{
    int data;

    struct Node *next;
}*node;

/*Head*/
struct Head{
    int count;
    struct Node *front;
    struct Node *rear;
}*head;

/*Create Head*/
void create_head(){
    head = (struct Head*)malloc(sizeof(struct Head));
    head->count = 0;
    head->front = NULL;
    head->rear = NULL;
}

/*Create Node*/
void create_node(){
    node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data: ");
    scanf("%d", &node->data);
    node->next = NULL;
}

/*Enqueue*/
void enqueue(){
    if(head->count == 0){
        create_node();
        head->front = node;
        head->rear = node;
    }
    else{
        create_node();
        head->rear->next = node;
        head->rear = node;
    }
    head->count++;
}

/*Dequeue*/
void dequeue(){
    struct Node *temp;
    if(head->count > 0){
        temp = head->front;
        head->front = temp->next;
        head->count--;
        free(temp);
    }
    else{
        printf("\nQueue is empty.\n");
    }
}

/*Display*/
void display(){
    if(head->front == 0){
        printf("\nQueue is empty.\n");
    }
    else{
        struct Node *temp;
        temp = head->front;
        printf("\n\nDisplay:\n");
        while(temp != NULL){
            printf("Data: %d\n",temp->data);
            temp = temp->next;
        }
    }
}

/*Show Top*/
void show_top(){
    if(head->count == 0){
        printf("\nQueue is empty.\n");
    }
    else{
        printf("\nTop data: %d\n", head->front->data);
    }
}

/*Show Rear*/
void show_rear(){
    if(head->count == 0){
        printf("Queue is empty.\n");
    }
    else{
        printf("\nRear data: %d\n", head->rear->data);
    }
}

int main(){
    create_head();
    printf("Queue\n");
    int n;
    while(1){
        printf("\n");
        printf("Press 1 for Enqueue.\n");
        printf("Press 2 for Dequeue.\n");
        printf("Press 3 for Display.\n");
        printf("Press 4 for Show Top.\n");
        printf("Press 5 for Show Rear.\n");
        printf("Press 0 for Close Program.\n");
        printf("Your Option: ");
        scanf("%d", &n);
        printf("\n");

        if(n == 1){
            enqueue();
        }
        else if(n == 2){
            dequeue();
        }
        else if(n == 3){
            display();
        }
        else if(n == 4){
            show_top();
        }
        else if(n == 5){
            show_rear();
        }
        else if(n == 0){
            printf("Thank You.\n");
            break;
        }
        else{
            printf("Invalid Input!\n");
            printf("Try again.\n");
        }
    }
return 0;
}