#include <stdio.h>
#define SIZE 3

int cq[SIZE], f = -1, r = -1;

int isFull(){
  if((f == r + 1) || (f == 0 && r == SIZE-1)) return 1;
  else return 0;
}

int isEmpty(){
  if(f == -1) return 1;
  return 0;
}

void enQueue(){
  int val;
  printf("Enter the value to insert into the queue: ");
  scanf("%d", &val);
  if(isFull()) printf("The queue is full!\n");
  else{
    if(f == -1) f = 0;
    r = (r+1)%SIZE;
    cq[r] = val;
    printf("Inserted: %d\n", val);
  }
}

int deQueue(){
  int val;
  if(isEmpty()){
    printf("\nQueue is empty!\n");
    return (-1);
  }
  else{
    val = cq[f];
    if(f == r){
      f = -1;
      r = -1;
    }
    else{
      f = (f+1)%SIZE;
    }
    printf("\nDeleted element: %d", val);
    return(val);
  }
}

void display(){
  int i;
  if(isEmpty())
    printf("\nQueue is empty");
  else{
    printf("\nFront: %d", f);
    printf("\nItems:");
    for (i = f; i != r; i = (i+1)%SIZE) {
      printf("%d ", cq[i]);
    }
    printf("%d ", cq[i]);
    printf("\nRear: %d\n", r);
  }
}

int main(){
  int choice;
  do{
    printf("\n1.EnQueue  2.DeQueue  3.Display  4.Exit  : ");
    scanf("%d", &choice);
    switch(choice){
      case 1: enQueue();
              break;
      case 2: deQueue();
              break;
      case 3: display();
              break;
      case 4: printf("\n*PROGRAM ENDED**");
              break;
      default: printf("Please Enter a valid input!");
                break;
    }
  }while(choice != 4);
  return 0;
}
