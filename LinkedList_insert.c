#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void push(struct Node* *head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(struct Node* *head_ref, int new_data){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void insert_pos(struct Node* *head_ref, int new_data, int position){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    struct Node* temp1 = *head_ref;
    int count = 0;
    while (temp1->next != NULL)
    {
        count++;
        temp1 = temp1->next;
    }
    new_node->data = new_data;
    if(position == 1){
        new_node->next = temp;
        *head_ref = new_node;
        printf("Inserted %d at position %d..\n", new_data, position);
        return;
    }
    if(position > 1 && position <=count){
        for (int i = 1; i < position - 1; i++){
        temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        printf("Inserted %d at position %d..\n", new_data, position);
    }
    else{
        printf("Invalid position..\n");
    }
    
}

void printList(struct Node *node){
    while (node != NULL)
    {
        printf("%d ->", node->data);
        node = node->next;
    }
}
int main(){
    struct Node *head = NULL;
    int choice, num, pos;
    do{
        printf("1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT AT POSITION\n4.DISPLAY\n5.EXIT : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the no. to insert: ");
            scanf("%d", &num);
            push(&head, num);
            printf("Inserted %d at the beginning..\n",num);
            break;
        case 2:
            printf("Enter the no. to insert: ");
            scanf("%d", &num);
            append(&head, num);
            printf("Inserted %d at the end..\n",num);
            break;
        case 3:
            printf("Enter the no. to insert: ");
            scanf("%d", &num);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insert_pos(&head, num, pos);
            break;
        case 4:
            printf("Created linked list is: ");
            printList(head);
            printf("NULL\n");
            break;
        case 5:
            break;
        default:
            printf("Invalid input! Try again...\n");
            break;
        }        
    } while (choice != 5);
    return 0;
}
