#include<stdio.h>

void push();
void pop();
void traverse();

struct node
{
    int data;
    struct node* link;
};
struct node* top=NULL;

int main()
{
    int ch;
    char c;
    printf("Stack Operations\n");
    do
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Traverse\n");
        printf("Enter your choice:  ");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        default :
            printf("Invalid operation\n");
        }
        printf("Do you want to continue(y/n) : ");
        scanf("%c",&c);
    }while(c!='n');
}

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data : ");
    scanf("%d",&temp->data);
    getchar();
    temp->link=NULL;
    temp->link=top;
    top=temp;
}

void pop()
{
    struct node* temp;
    temp=top;
    if(temp==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        top=temp->link;
        temp->link=NULL;
        printf("Pop element : %d\n",temp->data);
        free(temp);
    }
}

void traverse()
{
    struct node* temp;
    temp=top;
    if(temp==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
