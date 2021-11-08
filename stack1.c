// Stacks implemented using Arrays, structures and pointers
#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};
struct stack *s; 

int isEmpty(struct stack *ptr){
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack *ptr){
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr){
    int val;
    if (isFull(ptr) == 1)
        printf("\nStack overflow!");
    else{
        printf("\nEnter the number to be pushed: ");
        scanf("%d", &val);
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr){
    int val;
    if (isEmpty(ptr) == 1){
        printf("Stack is empty");
        return 0;
    }
    else{
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr){
    if (isEmpty(ptr) == 1){
        printf("Stack is empty");
        return 0;
    }
    else{
        return ptr->arr[ptr->top];
    }
}

void display(struct stack *ptr){
    if (isEmpty == 1) printf("Stack is empty");
    else{
        for (int i = ptr->top; i >= 0; i--){
            printf("\t%d\n", ptr->arr[i]);
        }
    }
    
}

int main(){
    int choice, value;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    do{
        printf("\n1.push  2.pop  3.peek  4.display  5.exit\n");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push(s);
            break;

        case 2:
            value = pop(s);
            if (value != 0)
                printf("Value popped out of the stack is %d", value);
            break;

        case 3:
            value = peek(s);
            if (value != 0)
                printf("Topmost element of the stack is %d", value);
            break;

        case 4:
            display(s);
            break;

        case 5:
            printf("\nProgram ended!\n");
            break;

        default:
            printf("\nPlease enter a valid input..");
            break;
        }
    }while (choice != 5);

    return 0;
}