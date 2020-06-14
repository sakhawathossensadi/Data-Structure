#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;

void insertAtEnd();
void insertAtBeginning();
void insertAfter();
void deleteNode();
void printList();
int listLength();
void listNodeUpdate();
bool listSearch(int x);
void listReverse();

int main()
{
    int ch,length,x;
    char c;
    bool found;
    printf("Singly Linked List Operations\n\n");
    do
    {
        printf("1.Insert At End\n");
        printf("2.Insert At Beginning\n");
        printf("3.Insert After\n");
        printf("4.Delete\n");
        printf("5.Print List\n");
        printf("6.Length\n");
        printf("7.Update\n");
        printf("8.Search\n");
        printf("9.Reverse\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        getchar();
        switch(ch)
        {
        case 1:
            insertAtEnd();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAfter();
            break;
        case 4:
            deleteNode();
            break;
        case 5:
            printList();
            break;
        case 6:
            length=listLength();
            if(length==0)
            {
                printf("List is empty\n");
            }
            else
            {
                printf("List Length : %d\n",length);
            }
            break;
        case 7:
            listNodeUpdate();
            break;
        case 8:
            printf("Enter search data : ");
            scanf("%d",&x);
            getchar();
            found=listSearch(x);
            if(found==true)
            {
                printf("Data Found\n");
            }
            else
            {
                printf("Not found\n");
            }
            break;
        case 9:
            listReverse();
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

void insertAtEnd()
{
    int data;
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data : ");
    scanf("%d",&data);
    getchar();
    temp->data=data;
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

void insertAtBeginning()
{
    int data;
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data : ");
    scanf("%d",&data);
    getchar();
    temp->data=data;
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

void insertAfter()
{
    int loc,data;
    struct node *temp,*p;
    printf("Enter node location : ");
    scanf("%d",&loc);
    getchar();
    if(loc>listLength())
    {
        printf("Invalid location\n");
    }
    else
    {
        int i=1;
        p=root;
        while(i<loc)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter Node Data : ");
        scanf("%d",&data);
        getchar();
        temp->data=data;
        temp->link=NULL;
        temp->link=p->link;
        p->link=temp;
    }
}

void deleteNode()
{
    int loc;
    struct node* temp;
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Enter location : ");
        scanf("%d",&loc);
        getchar();
        if(loc>listLength() || loc<=0)
        {
            printf("Invalid location\n");
        }
        else if(loc==1)
        {
            temp=root;
            root=temp->link;
            temp->link=NULL;
            free(temp);
        }
        else
        {
            struct node *p,*q;
            p=root;
            int i=1;
            while(i<loc-1)
            {
                p=p->link;
                i++;
            }
            q=p->link;
            p->link=q->link;
            q->link=NULL;
            free(q);
        }
    }
}

void printList()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->link!=NULL)
            {
                printf("%d-->",temp->data);
            }
            else
            {
                printf("%d",temp->data);
            }
            temp=temp->link;
        }
        printf("\n");
    }
}

int listLength()
{
    int count=0;
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        return count;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->link;
        }
    }
    return count;
}

void listNodeUpdate()
{
    struct node *temp;
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int pre,update,flag=0;
        printf("Enter which node data you want to update : ");
        scanf("%d",&pre);
        printf("Enter new node data : ");
        scanf("%d",&update);
        getchar();
        temp=root;
        while(temp!=NULL)
        {
            if(temp->data==pre)
            {
                flag=1;
                break;
            }
            else
            {
                temp=temp->link;
            }
        }
        if(flag==0)
        {
            printf("Node data not found\n");
        }
        else
        {
            temp->data=update;
        }
    }
}

bool listSearch(int x)
{
    int flag=0;
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->data==x)
            {
                flag=1;
                break;
            }
            temp=temp->link;
        }
    }
    if(flag==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void listReverse()
{
    if(root==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node* prev=NULL;
        struct node* next;
        struct node* current=root;
        while(current!=NULL)
        {
            next=current->link;
            current->link=prev;
            prev=current;
            current=next;
        }
        root=prev;
    }
}
