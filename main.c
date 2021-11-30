#include <stdio.h>
#define SIZE 5

int arr[SIZE], top = -1, front = 0; 

void enQueue();
int deQueue();
int peek();
void display();

int main() {
	int choice, val;
	do{
		printf("1.ENQUEUE  2.DEQUEUE  3.PEEK  4.DISPLAY  5.EXIT\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: enQueue();
					break;
			case 2: val = deQueue();
					if(val != -1) printf("The value removed from the queue: %d\n", val);
					break;
			case 3: val = peek();
					if(val != -1) printf("The value on top of the queue is: %d\n", val);
					break;
			case 4: display();
					break;
			case 5: printf("\n****PROGRAM OVER****\n");
					break;
			default: printf("Please enter a valid input!\n");
					break;
		}
	}while(choice != 5);

	return 0;
}

void enQueue(){
	int val;
	if(top == SIZE-1) printf("Queue is full!");
	else{
		printf("Enter the value to insert: ");
		scanf("%d", &val);
		if(top == -1) arr[++top] = val;
		else{
		    int i = top;
			while(i>=0){
				if(val > arr[i]){
					arr[i+1] = arr[i];
				}
				else{
					arr[i+1] = val;
					top++;
				}
				i--;
			}
			
		}
	}
}

int deQueue(){
	if(top == -1){
		printf("Queue is empty\n!");
		return -1;
	} 
	else{
		return arr[front++];
	}
}

int peek(){
	if(top == -1){
		printf("Queue is empty!\n");
		return -1;
	} 
	else{
		return arr[front];
	}
}

void display(){
    if(top == -1){
		printf("Queue is empty!\n");
	}
	else{
    	for(int i =top; i>=front; i--){
    		printf("%d ", arr[i]);
    	}
    	printf("\n");
	}
}