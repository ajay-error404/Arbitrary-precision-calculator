#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int Substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    *resh = NULL;
    *rest = NULL;

    (void)head1;
    (void)head2;

    int borrow = 0;
    int dif = 0;
    while(temp1 || temp2)
    {
        if(temp1 && temp2)
        {
            if((temp1->data < 0) || ((temp1->data) < (temp2->data)))
            {
                borrow = 1;
                temp1->data = temp1->data + 10;
                temp1->prev->data = temp1->prev->data - borrow;
            }
            else
            {
                borrow = 0;
            }
            dif = temp1->data - temp2->data;
            dl_insert_first(resh , rest, dif);

            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        else if(temp2 == NULL && temp1 != NULL)
        {
            if(temp1->data < 0)
            {
                borrow = 1;
                temp1->data = temp1->data + 10;
                temp1->prev->data = temp1->prev->data - borrow;
            }
            dif = temp1->data;
            dl_insert_first(resh , rest, dif);

            temp1 = temp1->prev;
        }
    }
    return 0;

}