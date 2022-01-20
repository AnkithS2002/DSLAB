#include <stdio.h>
#include <stdlib.h>
struct node{
    char name[20];
    int mob_no;
    int likes;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;

void insert_begin()
{
  struct node *newnode = (struct node *) malloc (sizeof (struct node));
  printf ("\nEnter the friend name: ");
  scanf("%s",newnode->name);
  printf("Enter mobile number: ");
  scanf("%d",&newnode->mob_no);
  printf("Enter number of likes: ");
  scanf("%d",&newnode->likes);
  if (head == NULL)
    {
      newnode->next = NULL;
      newnode->prev = NULL;
      head = newnode;
    }
  else
    {
      newnode->prev = NULL;
      newnode->next = head;
      head->prev = newnode;
      head = newnode;
    }
    printf("\nFriend added to the list..\n");

}

void display()
{
  printf ("\nYour friends are as follows:\n");
  printf("Name\tPhone no.\tNo. of likes\n");
  struct node *temp = head;
  while (temp != NULL)
    {
      printf ("%s\t",temp->name);
      printf ("%d\t\t",temp->mob_no);
      printf ("%d",temp->likes);
      printf("\n");
      temp = temp->next;
    }
}
void display_max()
{
    struct node *temp = head;
    int max = 0;
    int flag = 0;
    max = head->likes;
    printf ("\nDetails of friend with most likes: \n");
    printf("Name\tPhone no.\tNo. of likes\n");
    temp = temp->next;
    while (temp != NULL)
    {
      if(temp->likes >= max)
      {
      max = temp->likes;
      }
      else
      {
      flag = 1;
      }
      temp = temp->next;
    }
    temp = head;
    while (temp != NULL && temp->likes!=max)
    {
        temp = temp->next;
    }
    printf ("%s\t",temp->name);
    printf ("%d\t\t",temp->mob_no);
    printf ("%d",temp->likes);
}
int main()
{
    int choice = 0;
    printf("Facebook friends list\n");
    while(choice!=4)
    {
        printf("\n\n1.Add a friend to list\n2.Display friend list\n3.Display friend with max likes\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert_begin();
                break;
            case 2:
                display();
                break;
            case 3:
                display_max();
                break;
            case 4:
                printf("\n*****Program ended*****\n");
                break;
            default:
                printf("\nIncorrect number entered. Please try again\n");
                break;
        }
    }
    return 0;
}