#include "header.h"
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head, Dlist **tail)
{ 
  
    int count = 0;
    int flag = 0;
    while ((count_list(head1)) >= (count_list(head2)))
    {
        if((count_list(head1)) == (count_list(head2)))
        {
            Dlist *temp1 = *head1;
            Dlist *temp2 = *head2;
            flag = 0;
            
            while(temp1 != NULL)
            {
                if((temp1 -> data ) < (temp2 -> data))
                {
                    flag = 1;
                    break;
                }
                else if ((temp1 -> data) > (temp2 -> data))
                {
                    break;
                }
                else
                {
                    temp1 = temp1 -> next;
                    temp2 = temp2 -> next;
                }
            }
        }
        if(flag == 1)
        break;

        //printf(" count = %d\n", count);
        subtraction(tail1, tail2, head, tail);
        /*
        if ( count <= 10)
        print_list(*head);
        else 
        break;
        */
        dl_delete_list(head1, tail1);
        *head1 = *head;
        *tail1 = *tail;
        (*head) = (*tail) = NULL;
        count++;
       
    }
    
    int digit;
    if (count == 0) {
        dl_insert_first(head, tail, 0);
    } else {
        while(count != 0)
        {
            digit = count % 10;
            dl_insert_first(head, tail, digit);
            count = count / 10;
        }
    }
    return SUCCESS;
}
