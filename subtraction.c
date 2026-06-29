#include "header.h"

void subtraction(Dlist **tail1, Dlist **tail2, Dlist **head, Dlist **tail)
{
    Dlist *temp1, *temp2;
    Dlist *temp3;

    temp3 = *head;

    temp1 = *tail1;
    temp2 = *tail2;

    int res, num1, num2;

    while ((temp1 != NULL))
    {

        if (temp2 == NULL)
        {
            if (temp1->data < 0) {
                res = temp1->data + 10;
                temp1->prev->data -= 1;
            } else {
                res = temp1->data;
            }
        }
        else
        {

            num1 = temp1->data;
            num2 = temp2->data;
            if (num1 >= num2)
            {

                res = num1 - num2;
            }
            else
            {

                res = (num1 + 10) - num2;
                temp1->prev->data -= 1;
            }
        }
        // insert_at_first(head, res);
        dl_insert_first(head, tail, res);

        // traverse

        temp1 = temp1->prev;
        if (temp2 != NULL)
            temp2 = temp2->prev;
    }
    while ((*head)->data == 0 && (*head)->next != NULL)
    {

        Dlist *to_delete = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(to_delete);
    }
}