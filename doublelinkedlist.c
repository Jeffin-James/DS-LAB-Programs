#include<stdio.h>
struct node {
    int data ;
    struct node *next ;
    struct node *prev;
};
struct node *head,*temp,*newnode;
int n;

void create(){
    printf("Enter number of elements to be inserted: ");
    scanf("%d",&n);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("Enter data #1: ");
    scanf("%d",&newnode->data);

    head = newnode;
    temp = head;

    for(int i = 1 ; i < n; i ++){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data #%d: ",i+1);
        scanf("%d",&newnode->data);
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = NULL;
        temp= newnode;

    }
}


void insert(){
    int position;
    printf("Enter position to be inserted: ");
    scanf("%d",&position);
    position = position - 1;

    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to be inserted: ");
    scanf("%d",&newnode->data);
    newnode->prev = NULL;
    newnode->next  = NULL;

    temp  = head;

    if(position == 0){
        temp->prev = newnode;
        newnode->next  = temp;
        head = newnode;
        n++;
    }
    else if(position > 0 && position < n-1){
        for(int i = 0 ; i < position - 1; i++){
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;

    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void delete(){
    int x;
    printf("Enter data to be deleted: ");
    scanf("%d",&x);
    temp = head;
    int position= -1;

    for(int i = 0; i < n ; i++){
        if(temp->data == x){
            position ++;
            break;
        }
        position ++;
        temp = temp->next;
    }
    printf("%d ",position);

    if(position  == 0){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        free(temp);
        n--;
    }

    else if(position > 0 && position < n - 1){//last element before
        for(int i = 0; i < position - 1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        temp->next->prev = NULL;
        temp->next->next->prev = temp;
        temp->next->next = NULL;
        free(temp);

    }
}



void display(){

    temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
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
