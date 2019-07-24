#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user_list.h"

struct user_list_fun list_fun;

PNode list;


/*
brief:create a NUll list
*/
static PNode create_list(void) 
{
    PNode PHead = (PNode)malloc(sizeof(Node));   
    if (PHead == NULL)   
    {
        printf("no memory \n");
        return NULL; //no memory       
    }

    PHead->Next = NULL;    
    return PHead;    
}

static int traverse_list(PNode List) 
{
    int num = 0;
    if(List == NULL)return -1;
    PNode P = List->Next;    
    if (P == NULL)
      {  
        printf("[info]no nodes in this list \n");
      }
    while (P != NULL)    
    {
	printf("%s\n",P->Element.thingname);
        P = P->Next;
        num++;
    }
    printf("[info]node num:%d \n",num);
    return num; // return list nodes number
}


static PNode find_list(PNode List,ElementType item) 
{
    PNode P = List->Next;   

    if(item.thingname== NULL)return NULL;

    while (P != NULL) 
    {
        if(strncmp(P->Element.thingname,item.thingname,strlen(item.thingname)) == 0) 
            
        {
         break;
        }
        P = P->Next;

    }
    return P;// if not found ,will return NULL
}

static PNode find_list_by_unicast(PNode List,ElementType item) 
{
    PNode P = List->Next;   

    if(item.thingname== NULL)return NULL;

    while (P != NULL) 
    {
        if(memcmp(P->Element.unicast,item.unicast,sizeof(item.unicast)) == 0) 
            
        {
         break;
        }
        P = P->Next;

    }
    return P;// if not found ,will return NULL
}


//always insert to the tail
static void insert_to_list_tail(PNode List,ElementType item)  
{
    PNode P = List;   
    while (P != NULL)
    {
        if( P->Next == NULL)break;//found the tail
        P = P->Next;
        
    }
    if(P->Next != NULL)
    {
      printf("list tail not found \n");//impossible run to here
     return; 
    }

    PNode PNew = (PNode)malloc(sizeof(Node));
    memset(PNew,0,sizeof(Node));
    if (PNew == NULL) 
    {
       printf("[error]no memory \n");
       return ;//no memory 
    }
    memcpy(&(PNew->Element),&item,sizeof(item));
    P->Next = PNew;    
    PNew->Next = NULL;        
}
/*
brief:modify a list node
param: 
--item:  the target value
--pnode:  must use FindList() function to return  a pnode and delete it
*/

static void list_node_modify(PNode pnode, ElementType item) 
{
    if(pnode == NULL)return;
    memset(&(pnode->Element),0,sizeof(pnode->Element));
    memcpy(&(pnode->Element),&item,sizeof(item));
    return;
}

/*
brief:delete a list node
param: 
--List:  the list head
--node:  must use FindList() function to return  a pnode and delete it
*/

static void delete_list(PNode List, PNode pnode) 
{
    if(pnode == NULL)return;
    PNode P = List;
    while (P != NULL) 
    {
        if(P->Next == pnode)break;// find the target pnode
        P = P->Next;
    }
    
    P->Next = pnode->Next;
    free(pnode);

    return;
}



static void delete_the_list(PNode List) 
{
    if(List == NULL)return;
    PNode P, Tmp;
    P = List->Next;    
    List->Next = NULL;
    while (P != NULL) 
    {
        Tmp = P->Next;        
        free(P);    
        P = Tmp;    
    }
    printf("[info]list deleted!! \n");

}

void user_list_init(void)
{
     list_fun.create_list = create_list;
     list_fun.traverse_list= traverse_list;
     list_fun.find_list= find_list;
     list_fun.insert_to_list_tail= insert_to_list_tail;
     list_fun.list_node_modify = list_node_modify;
     list_fun.delete_list= delete_list;
     list_fun.delete_the_list= delete_the_list;
     list_fun.find_list_by_unicast = find_list_by_unicast;
     
     list = list_fun.create_list();   
     
}
