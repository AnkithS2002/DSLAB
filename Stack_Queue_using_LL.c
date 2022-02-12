
#include<stdio.h>   
#include<stdlib.h>  
struct node   
{  
    int val;   
    struct node *next;  
}; 
 
struct node *head;  
   
struct node *front;  
struct node *rear;   
void insert();  
void remove();  
void display_queue();  

void push();  
void pop();  
void display_stack();

void main ()  
{  
	int type;
	printf("Want to create 1:Stack or 2:Queue: ");
	scanf("%d", &type);
	switch(type){
		case 1: {
			int choice = 0; 
			printf("\n*********Queue operations using linked list*********\n");  
			while(choice != 4)   
			{       
				printf("\n1.insert  2.Delete  3.Display  4.Exit");  
				printf("\nEnter your choice: ");  
				scanf("%d",& choice);  
				switch(choice)  
				{  
					case 1:  
					insert();  
					break;  
					case 2:  
					remove();  
					break;  
					case 3:  
					display();  
					break;  
					case 4:  
					exit(0);  
					break;  
					default:   
					printf("\nEnter valid choice!\n");  
				}  
			}
		}
		case 2: {
			int choice=0;     
			printf("\n*********Stack operations using linked list*********\n");
			while(choice != 4)  
			{  
				printf("\n1.Push  2.Pop  3.Show  4.Exit");  
				printf("\nEnter your choice: ");        
				scanf("%d",&choice);  
				switch(choice)  
				{  
					case 1:  
					{   
						push();  
						break;  
					}  
					case 2:  
					{  
						pop();  
						break;
					}  
					case 3:  
					{  
						display_stack();  
						break;  
					}  
					case 4:   
					{  
						printf("***PROGRAM OVER***");  
						break;   
					}  
					default:  
					{  
						printf("Please Enter valid choice..");  
					}   
				}  
			}  
		}
		default:	printf("Please choose either 1 or 2..\n");
					break;
	}
}  
void insert()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    else  
    {   
        printf("\nEnter value: ");  
        scanf("%d",&item);  
        ptr -> val = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }
        printf("Item added to the queue\n");  
    }  
}     
void remove ()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next; 
        printf("Item removed from Queue\n"); 
        free(ptr);  
    }  
}  
void display_queue()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nThe elements in the Queue are:\n");  
        while(ptr != NULL)   
        {  
            printf("%d\n",ptr -> val);  
            ptr = ptr -> next;  
        }  
    }  
} 
  
void push ()  
{  
    int val;  
    struct node *ptr = (struct node*)malloc(sizeof(struct node));   
    if(ptr == NULL)  
    {  
        printf("not able to push the element");   
    }  
    else   
    {  
        printf("Enter the value: ");  
        scanf("%d",&val);  
        if(head==NULL)  
        {         
            ptr->val = val;  
            ptr -> next = NULL;  
            head=ptr;  
        }   
        else   
        {  
            ptr->val = val;  
            ptr->next = head;  
            head=ptr;  
               
        }  
        printf("Item pushed");  
          
    }  
}  
  
void pop()  
{  
    int item;  
    struct node *ptr;  
    if (head == NULL)  
    {  
        printf("There is no element to pop out!\n");  
    }  
    else  
    {  
        item = head->val;  
        ptr = head;  
        head = head->next;  
        free(ptr);  
        printf("Item popped\n");  
          
    }  
}  
void display_stack()  
{  
    int i;  
    struct node *ptr;  
    ptr=head;  
    if(ptr == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {  
        printf("The Stack elements are: \n");  
        while(ptr!=NULL)  
        {  
            printf("%d\n",ptr->val);  
            ptr = ptr->next;  
        }  
    }  
}  
