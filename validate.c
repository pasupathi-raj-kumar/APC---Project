#include "header.h"

int validate(char *str1)
{
    int i = 0;
    while(str1[i])
    {
        if(str1[i] >= '0' && str1[i] <= '9')
        {
            i++;
        }
        else
        {
            
            return FAILURE;
        }
        
    }
    return SUCCESS;
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
   
   Dlist *new = malloc(sizeof(Dlist));
   if(new == NULL)
   {
       return FAILURE;
   }
   new -> data = data;
   new -> next = NULL;
   new -> prev = NULL;
   if(*head == NULL)
   {
       *head = *tail = new;
       return SUCCESS;
   }
   (*tail)-> next  = new;
   new -> prev = *tail;
   *tail = new;
   return SUCCESS;
}

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
   Dlist *new = malloc(sizeof(Dlist));
   if(new == NULL)
   {
       return FAILURE;
   }
   new -> data = data;
   new -> next = NULL;
   new -> prev = NULL;
   if(*head == NULL)
   {
       *head = *tail = new;
       return SUCCESS;
   }
   (*head)-> prev = new;
   new -> next = *head;
   *head = new;
   return SUCCESS;
}
int print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
		return FAILURE;
	}
	
	/* Assigning the temp value as head */
	Dlist *temp = head;	
	
	while (temp)		
	{
		/* Printing the list */
		printf("%d", temp -> data);

		/* Travering in forward direction */
		temp = temp -> next;
		
		    
	}

	return SUCCESS;
}


int count_list(Dlist **head)
{
    int count = 0;
	Dlist *temp = *head;
	while (temp != NULL)
	{
		temp = temp->next;
        count++;
	}
    return count;

}


int dl_delete_list(Dlist **head, Dlist **tail)
{
    
     if(*head == NULL)
     {
         return FAILURE;
     }
     if((*head)->next == NULL)
     {
         free(*head);
         *head = *tail = NULL;
         return SUCCESS;
         
     }
     Dlist *temp;
     Dlist *temp1 = *tail;
     *tail = NULL;
     while(temp1 != NULL)
     {
        temp = temp1;
        temp1 = temp1 -> prev;
        free(temp);
     }
     (*head) = NULL;
     return SUCCESS;
}