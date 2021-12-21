#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

void del_beg(){

}
void del_end(){

}
void del_pos(){

}
void display(){

}
int main(){
    int choice, val;
    do{
        printf("1.DELETE AT BEGINNING  2.DELETE AT END  3.DELETE AT POSITION  4.DISPLAY  5.EXIT : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            del_beg();
            break;
        case 2:
            del_end();
            break;
        case 3:
            del_pos();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n***PROGRAM ENDED**\n*");
            break;
        default:
            printf("Invalid input! try again..\n");
            break;
        }
    }while (choice != 4);
    return 0;
}