#include <stdio.h>

# define max 6
int queue[max];
int front=-1;
int rear=-1;

void enqueue(int element)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)%max==front)
    {
        printf("Queue is overflow..");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=element;
    }
}


int dequeue()
{
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue is underflow..");
    }
 else if(front==rear)
{
   printf("\nThe dequeued element is %d", queue[front]);
   front=-1;
   rear=-1;
}
else
{
    printf("\nThe dequeued element is %d", queue[front]);
   front=(front+1)%max;
}
}

void display()
{
    int i=front;
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while(i<=rear)
        {
            printf("%d,", queue[i]);
            i=(i+1)%max;
        }
    }
}
int main()
{
    int choice , ch , x ;
    do{
        printf("\n\t\tCircular Queue\n");
        printf("\t\tArray Implementation\n");
        printf("\n1. Insert\n2. Delete\n3. Display\n");
        printf("\nEnter your choice : \n");
        scanf("%d", &choice);
        switch(choice)
        {

        case 1:
            {
                printf("\nEnter the element which is to be inserted : \n");
                scanf("%d", &x);
                enqueue(x);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        default :
            {
                printf("Invalid Choice \n");
                break;
            }
        }
    printf("\nEnter 1 to Continue or 0 to Exit\n");
    scanf("%d",&ch);
    }while(ch == 1);
}
