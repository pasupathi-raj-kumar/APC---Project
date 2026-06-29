#include "header.h"

void addition(Dlist **tail1, Dlist **tail2, Dlist **head, Dlist **tail)
{
   Dlist *temp1, *temp2;
    Dlist *temp3;
    temp1 = *tail1;
    temp2 = *tail2;
    temp3 = *head;
    int val, carry = 0;

    while ((temp1 != NULL) || (temp2 != NULL))
    {
        if (temp1 == NULL)
        {
            val = add(0, temp2->data, carry);
        }
        else if (temp2 == NULL)
        {
            val = add(temp1->data, 0, carry);
        }
        else
        {
            val = add(temp1->data, temp2->data, carry);
        }
        if (val > 9)
        {
            dl_insert_first(head, tail, val % 10);
            carry = val / 10;
        }
        else
        {
            dl_insert_first(head, tail, val);
            carry = 0;
        }
        // traverse
        if(temp1)
        temp1 = temp1->prev;
        if(temp2)
        temp2 = temp2->prev;
    }
    if (carry)
        dl_insert_first(head,tail, 1);
    
}

int add(int num1, int num2, int carry)
{
    return num1 + num2 + carry;
}