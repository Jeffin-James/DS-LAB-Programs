#include <stdio.h>
#include<stdlib.h>

struct node
{
    int coff;
    int expo;
    struct node *link;
};
int main(){
    struct node *p,*q,*r;
    p = (struct node*)malloc(sizeof(struct node));
    q = (struct node*)malloc(sizeof(struct node));
    r = (struct node*)malloc(sizeof(struct node));
    printf("Enter polinomial p\n");
    addpoly(p);
    printf("\nEnter polinomial q\n");
    addpoly(q);
    printf("polynomial p: ");
    traverse(p);
    printf("polynomial q: ");
    traverse(q);
    subtraction(p, q, r);
    printf("\naddition polynomial r: ");
    traverse(r);
}
void addpoly(struct node *head){
    struct node *p, *temp;
    head->link = NULL;
    int ch;
    do{
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter polynomial coefficient value: ");
        scanf("%d", &temp->coff);
        printf("Enter polynomial exponential value: ");
        scanf("%d", &temp->expo);
        temp->link = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while(p->link != NULL)
            {
                p = p->link;
            }
            p->link = temp;
        }
        printf("\n1. create.\n2. exit. \nDo you want to create a node:");
        scanf("%d", &ch);
    }while(ch == 1);
}
void traverse(struct node *head)
{
    struct node *d;
    d = head->link;
    while(d != NULL)
    {
        printf("%dx^%d ", d->coff, d->expo);
        d = d->link;
    }
    printf("\n");
}
void subtraction(struct node *p, struct node *q, struct node *r){
    struct node *result, *d;
    r->link = NULL;
    p = p->link;
    q = q->link;
    while((p!=NULL) && (q!=NULL)){
        result = (struct node*)malloc(sizeof(struct node));
        result->link = NULL;
        if(p->expo > q->expo){
            result->coff = p->coff;
            result->expo = p->expo;
            p = p->link;
        }
        else if(p->expo < q->expo){
            result->coff = q->coff;
            result->expo = q->expo;
            q = q->link;
        }
        else{
            result->coff = p->coff + q->coff;
            result->expo = p->expo;
            p = p->link;
            q = q->link;
        }
        if(r->link == NULL)
        {
            r->link = result;
        }
        else
        {
            d = r->link;
            while(d->link != NULL)
            {
                d = d->link;
            }
            d->link = result;
        }
    }
    while(p != NULL){
        result = (struct node*)malloc(sizeof(struct node));
        result->coff = p->coff;
        result->expo = p->expo;
        d = r->link;
        while(d->link != NULL)
        {
            d = d->link;
        }
        d->link = result;
        p = p->link;
    }
    while(q != NULL){
        result = (struct node*)malloc(sizeof(struct node));
        result->coff = q->coff;
        result->expo = q->expo;
        d = r->link;
        while(d->link != NULL)
        {
            d = d->link;
        }
        d->link = result;
        q = q->link;
    }
}
