#include<stdio.h>
struct node {
    int data ;
    struct node *next ;
};
struct node *temp,*head,*newnode;

void push(){
    temp = head ;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the element to be pushed : ");
    scanf("%d",&newnode->data);
    if(head == NULL)
    {
        newnode->next = NULL ;
        head = newnode ;
        n++;
    }
    else{
        newnode->next = head ;//previous head
        head = newnode ;

    }
}
void pop()
{
   temp = head;
   head = temp->next;
   temp->next = NULL;
   free(temp);


}
void display()
{
    printf("NULL");
    temp = head;
    while(temp != NULL){
        printf(" <- %d ",temp->data);
        temp = temp->next;
    }

}

void main()
{
     int choice , ch ;
    do{
   printf("\n\t\t\tLinked Stack\n");
   printf("1. Push\n2. Pop\n3. Display\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   switch(choice){
   case 1 :
       {
           push();
           break;
       }
       case 2 :
       {
           pop();
           break;
       }
       case 3 :
       {
           display();
           break;
       }
       default :
        {
            printf("Invalid Choice \n");
        }
   }
    printf("\nEnter 1 to Continue or 0 to Exit\n");
    scanf("%d",&ch);
}while(ch == 1);
}
