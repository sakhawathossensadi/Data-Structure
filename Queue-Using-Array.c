#include<stdio.h>
#define CAPACITY 5

int queue[CAPACITY];
int front=0;
int rear=0;

void enqueue();
void dequeue();
void display();

int main()
{
    int ch,peekdata;
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
    int qdata;
    if(rear==CAPACITY)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter queue data : ");
        scanf("%d",&qdata);
        getchar();
        queue[rear]=qdata;
        rear++;
    }
}

void dequeue()
{
    if(front==rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int dequeuevalue,i;
        dequeuevalue=queue[front];
        printf("Dequeue value : %d\n",dequeuevalue);
        for(i=0; i<rear-1; i++)
        {
            queue[i]=queue[i+1];
        }
        rear--;
    }
}

void display()
{
    int i;
    if(front==rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=0; i<rear; i++)
        {
            if(i!=rear-1)
            {
                printf("%d<--",queue[i]);
            }
            else
            {
                printf("%d",queue[i]);
            }
        }
        printf("\n");
    }
}
