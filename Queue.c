#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE], f = -1, r = -1;

int isEmpty(){
    if(f == r) return 1;
    else return 0;
}
int isFull(){
    if(r == SIZE-1) return 1;
    else return 0;
}

void Enqueue(){
    int num;
    if(isEmpty()){
        f =0; r =0;
        printf("\nEnter the number to insert into the queue: ");
        scanf("%d", &num);
         queue[r] = num;
        r++;
    }
    else if(isFull() == 1){
        printf("\nStack is full!");
    }
    else{
        printf("\nEnter the number to insert into the queue: ");
        scanf("%d", &num);
        queue[r] = num;
        r++;
    }
}

void Dequeue(){
    if (isEmpty() == 1){
        printf("\nQueue is empty");
        f = -1;
        r = -1;
    }
    else{
        printf("%d has been removed from Queue", queue[f++]);
    }
}
void Display(){
    int choice;
    printf("1.Entire Queue  2.Front  3.Rear");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        for (int i = f; i <= r; i++){
            printf("%d ", queue[i]);
        }  
        break;
    case 2:
        printf("The first element in the queue is: %d", queue[f]);
        break;
    case 3:
        printf("The last element in the queue is: %d", queue[r]);
        break;
    }
}

int main(){
    int choice;
    do{
    printf("1.Enqueue\t2.Dequeue3.Display\t4.EXIT  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Enqueue();
        break;
    case 2:
        Dequeue();
        break;
    case 3:
        Display();
        break;
    case 4:
        printf("\n********Program ended********");
        break;
    default:
        printf("Enter a valid input!");
        break;
    }}while (choice != 4);
    return 0;
}