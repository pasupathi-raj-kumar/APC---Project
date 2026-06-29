#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head, Dlist **tail)
{
	
    if (*head1 == NULL || *head2 == NULL)
        return dl_insert_first(head, tail, 0);

    Dlist *temp2 = *tail2; 
    Dlist *res2Head = NULL; 
    Dlist *res2Tail = NULL;
    Dlist *res3Head = NULL; 
    Dlist *res3Tail = NULL;

    int shift = 0; 

    while (temp2 != NULL)
    {
        int num2 = temp2->data; 
        Dlist *temp1 = *tail1;    
        Dlist *res1Head = NULL;   
        Dlist *res1Tail = NULL;
        int carry = 0;


        for (int i = 0; i < shift; i++)
        {
            if (dl_insert_first(&res1Head, &res1Tail, 0) == FAILURE)
                return FAILURE;
        }

        
        while (temp1 != NULL || carry != 0)
        {
            int num1; 
	    if (temp1 != NULL) 
	    {
		   num1 = temp1->data;
	    }
	    else
	    {
		    num1 = 0;
	    }

            int product = num1 * num2 + carry; 
            int result = product % 10;     
            carry = product / 10;                

       
            if (dl_insert_first(&res1Head, &res1Tail, result) == FAILURE)
                return FAILURE;

            if (temp1 != NULL)
                temp1 = temp1->prev;
        }

        
        
        addition(&res1Tail, &res2Tail, &res3Head,&res3Tail);

        
        temp2 = temp2->prev;

        
        if (temp2 == NULL)
        {
            *head = res3Head;
            *tail = res3Tail;
            break;
        }

        
        if (copy_list(&res3Head, &res3Tail, &res2Head, &res2Tail) == FAILURE)
            return FAILURE;

        
        res3Head = NULL;
        res3Tail = NULL;

        
        shift++;
    }

    while ((*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *to_delete = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(to_delete);
    }

    return SUCCESS;
}


int copy_list(Dlist **sourceHead, Dlist **sourceTail, Dlist **destHead, Dlist **destTail)
{
    
    if (*sourceHead == NULL)
    {
        *destHead = NULL;
        *destTail = NULL;
        return SUCCESS;
    }

    
    *destHead = NULL;
    *destTail = NULL;

    Dlist *temp = *sourceHead; 

   
    while (temp != NULL)
    {
    
        if (dl_insert_last(destHead, destTail, temp->data) == FAILURE)
        {
            return FAILURE; 
        }

        
        temp = temp->next;
    }

    return SUCCESS;
}

