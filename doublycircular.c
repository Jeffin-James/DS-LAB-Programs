#include<stdio.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;

};
struct node *temp,*head,*newnode;

int n;

int isEmpty(struct node *list){
    if(list == NULL)
        return 1;
    else
        return 0;

}

void create(){

    if(isEmpty(head)){
    printf("Enter number od elements to be inserted: ");
    scanf("%d",&n);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data #1: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    temp = newnode;
    head = newnode;

    for(int  i = 1; i < n ; i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data #%d: ",i+1);
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
    }

    else{
        printf("\nList already exist");
    }

}

void insert(){
    int position;
    printf("\nEnter position to insert: ");
    scanf("%d",&position);
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to be inserted: : ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    position = position -1;

    temp = head;

    if(isEmpty(head)){
        printf("List is empty!!");
    }
    else {
            struct node *p;
            p = head;//previous head

        if(position == 0){

            newnode->next = temp;
            temp->prev = newnode;
            head = newnode;


            do{
                temp = temp->next;
            }while(temp->next != p);

            temp->next = head;
            n++;
        }
        else if(position > 0 && position < n -1 ){

            for(int i = 0 ; i < position -1; i++){

                temp = temp->next;
            }

            newnode->next = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next->prev = newnode;
            n++;

        }
        else{
            do{
                temp = temp->next;
            }while(temp->next != p);
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = head;
            n++;
        }
    }
}
void search(){
    int x,position = 0;
    printf("\nEnter element to be search: ");
    scanf("%d",&x);

    temp = head;

    if(head == NULL){
        printf("Empty list!!");
    }
    else {
       do
        {
            if(temp->data == x){
                position++;
                printf("Element is found at %d",position);
                break;
            }
            position++;
            temp = temp->next;
        }while(temp != head);
    }

}
void delete(){
    int x,position = 0;
    printf("Enter element to be deleted: ");
    scanf("%d",&x);
    if(isEmpty(head)){
        printf("Elemet cannot be deleted since the list is empty!! ");
    }else{

    temp = head;
    do{
        if(temp->data == x){
            position ++;
            break;
        }
        position ++;

        temp = temp->next;
    }while(temp != head);

    position = position -1;
    temp = head;

    if(position == 0){
        struct node *p;
        p = head;
        temp->next->prev = NULL;
        head = temp->next;


        do{
            temp = temp->next;
        }while(temp->next != p);

        temp->next = head;
        n--;

    }else if( position > 0 && position <  n - 1){
        for(int i =0 ; i < position - 1; i++ ){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = temp;
        n--;
    }
    else{
        for(int i = 0 ; i < n - 2; i++){
            temp = temp->next;
        }
        temp->next = head;
    }
}
}




void display(){
    printf("\n");
    temp = head;
    printf("NULL");

    do{
        printf(" <- %d -> ",temp->data);
        temp= temp->next;
    }while(temp != head);

    printf("CONTINUE");

}

void main(){
    int choice , ch ;
    do{
   printf("\n\t\t\tDoubly Circular List\n");
   printf("1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n");
   printf("Enter your choice : ");
   scanf("%d",&choice);
   switch(choice){
   case 1 :
       {
           create();
           break;
       }
       case 2 :
       {
           display();
           break;
       }
       case 3 :
       {
           insert();
           break;
       }
       case 4 :
       {
           delete();
           break;
       }
       case 5 :
       {
           search();
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





