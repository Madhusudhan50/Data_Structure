//Madhusudhan

#include<stdio.h>
#include<stdlib.h>

struct Node     // Structre Defination
{
    int data;
    struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertFirst(PPNODE Head, int no){

    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(Head==NULL){
        *Head=newn;
    }else{
        newn->next=*Head;
        *Head=newn;
    }

}

void InsertIntoLast(PPNODE Head, int no){

    PNODE newn=NULL;
    PNODE temp=*Head;
   
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=no;
    newn->next=NULL;

    if(Head==NULL){
        *Head=newn;
    }
    else
    {
        while (temp->next!=NULL)
        {
            temp=temp->next;

        }
            temp->next=newn;
    }
}

void Display(PNODE Head){

    while (Head!=NULL)
    {
        printf("| %d | -> ",Head->data);
        Head=Head->next;
    }
       printf("NULL \n");
       
}
int Count(NODE* Head){

    int count=0;
    
    while (Head!=NULL)
    {
        count++;
        Head=Head->next;
    }
    return count;
}


void InsertAtPos(PPNODE Head, int no,int pos){
    int i=0,size=0;
    PNODE temp=*Head;
    PNODE newn=NULL;
    size=Count(*Head);
    
    if((pos<1) || pos>(size+1)){
        return;
    }

    else if(pos==1)
    {
        InsertFirst(Head, no);
    }
    else if(pos==size+1)
    {
        InsertIntoLast(Head,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;

        for(i=1; i<pos-1; i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void DeleteFirst(PPNODE Head){
    PNODE temp=*Head;

    if(*Head!=NULL){
        *Head=(*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head){
    PNODE temp=*Head;
    if(*Head==NULL){
        return;
    }
    else if ((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {   
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;

    }
    
}

void DeleteAtPos(PPNODE Head, int pos){
    int size = 0,i = 0;
    size = Count(*Head);
    PNODE temp, temp2;
    if((pos < 1) || (pos > size))
    {
        return;
    }
    if(pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(pos == size)
    {
        DeleteLast(Head);
    }
    else
    {
        temp = *Head;
        for(i = 1; i< pos-1; i++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }

}

int main()
{
    int iRet = 0;
    int isum = 0;
    
    PNODE First = NULL;    
    
        printf("----------------------------------------\n");
        printf("Welcome To The linked list Application\n");
        printf("----------------------------------------\n");
    
    int choice=1;
    int num=0;
    int pos=0;

    while (choice)
    {
    printf("\t Enter the Choice\n 2: For Add First Position \n 3: For Add Last Position :\n 4: For Add given Position :\n 5: For Delete First Position :\n 6: For Delete Last Position :\n 7: For Delete given Position :\n 8: For Display:\n 9: For Count:\n 10: For Sum:\n 0: For Exit");
    scanf("%d",&choice); 
         
    switch (choice)
    {
    case 2:
        printf("Enter Number you wnat to add");
        scanf("%d",&num);
        InsertFirst(&First, num);      
        
        break;
    case 3:
        printf("Enter Number you wnat to add");
        scanf("%d",&num);
        InsertIntoLast(&First, num);      
        break;
    case 4:
        printf("Enter Number you wnat to add");
        scanf("%d",&num);
        printf("Enter Position");
        scanf("%d",&pos);
        InsertAtPos(&First,num,pos);      
        break;
    case 5:
        DeleteFirst(&First);      
        break;
    case 6:
        DeleteLast(&First);      
        break;
    case 7:
        printf("Enter Position");
        scanf("%d",&pos);
        DeleteAtPos(&First, pos);      
        break;                
    case 8:
        Display(First);                 // Display(100);
        break;
    case 9:
        iRet=Count(First);
        printf("\nNumber of Elements is %d ",iRet);
        iRet=0;
        break;
    case 0:
    printf("\nThanks For Using Application Bye....");
        break;
    }
}  
  printf("\n");
  
     return 0;
}
