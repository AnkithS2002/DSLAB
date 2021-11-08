//Basic postfix expression evaluation program
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int st[MAX], top = -1;
void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int evaluate(char exp[]);

int main()
{
    int val;
    char exp[100];
    printf("Enter the expression: ");
    gets(exp);
    val = evaluate(exp);
    printf("The value of the postfix expression is: %d\n", val);
    return 0;
}

int evaluate(char exp[])
{
    int i = 0;
    int op1, op2, value;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (int)exp[i] - 48);
            printf("\nThe stack is:\n");
            display(st);
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;

            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;

            case '/':
                value = op1 / op2;
                break;
            }
            push(st, value);
            printf("\nThe stack is:\n");
            display(st);
        }
        i++;
    }
    return (pop(st));
}

void push(int st[], int val)
{
    st[++top] = val;
}

int pop(int st[])
{
    return st[top--];
}

int peek(int st[])
{
    return st[top];
}

void display(int st[])
{
    for (int i = top; i >= 0; i--)
    {
        printf("\n %d", st[i]);
        printf("\n");
    }
}