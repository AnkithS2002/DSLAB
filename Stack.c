//stacks implemented using arrays only.
#include <stdio.h>
#define MAX 5

int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main(){

    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
		printf("\n 1.PUSH  2.POP  3.PEEK  4.DISPLAY  5.EXIT");		
        printf("\n Enter your option: ");		
        scanf("%d", &option);
        switch (option){
        case 1: 
            printf("\nEnter the number to be pushed on the stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        
        case 2:
            val = pop(st);
            if(val != -1)
                printf("\nThe value popped out of the stack is: %d\n", val);
            break;

        case 3:
            val = peek(st);
            if(val != -1)
                printf("\nThe value on top of the stack is: %d\n", val);
            break;
        
        case 4:
            display(st);
            break;
        case 5:
            printf("\nProgram ended!\n");
            break;
        default:
            printf("Invalid input! Try again!");
            break;
        }
    } while (option != 5);

    return 0;
}

void push(int st[], int val){
    if(top == MAX-1)
        printf("\nStack overflow!\n");
    else{
        top++;
        st[top] = val;
    }
}

int pop(int st[]){
    int val;
    if(top == -1){
        printf("\nStack underflow\n");
        return -1;
    }
    else{
        val = st[top];
        top--;
        return val;
    }
}

int peek(int st[]){
    if(top == -1){
        printf("\nStack is empty!\n");
        return -1;
    }    
    else
        return st[top];
}

void display(int st[]){
    if(top == -1)
        printf("\nStack is empty!\n");
    else{
        for (int i = top; i >= 0; i--)
        {
            printf("\n %d", st[i]);
            printf("\n");
        }
    }
}