#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();

struct node
{
    int data;
    struct node* next;
};
struct node *temp,*front,*rear;

int main()
{
    int ch,qdata;
    char c;
    printf("Queue Operations\n\n");
    do
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default :
            printf("Invalid operation\n");
        }
        printf("Do you want to continue(y/n) : ");
        scanf("%c",&c);
    }
    while(c!='n');
    return 0;
}

void enqueue()
{
    int ele;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter queue data : ");
    scanf("%d",&ele);
    getchar();
    temp->data=ele;
    temp->next=NULL;
    if(rear==NULL)
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else if(front->next==NULL)
    {
        temp=front;
        temp->next=NULL;
        front=front->next;
        rear=NULL;
        printf("Dequeue value : %d\n",temp->data);
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        temp->next=NULL;
        printf("Dequeue value : %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    temp=front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                printf("%d<--",temp->data);
            }
            else
            {
                printf("%d",temp->data);
            }
            temp=temp->next;
        }
        printf("\n");
    }
}
