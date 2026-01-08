#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int Add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest)
{
    if(*head1 == NULL && *head2 == NULL)
    {
        if(dl_insert_first(resh, rest, 0) == FAILURE)
            return FAILURE;
        return SUCCESS;
    }
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0;
    int sum = 0;
    while(temp1 || temp2)
    {
        if(temp1 && temp2)
        {
            sum = temp1->data + temp2->data + carry;
            carry = sum/10;
            sum = sum % 10;
            if(dl_insert_first(resh , rest, sum) == FAILURE)
                return FAILURE;

            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        else if (temp1 == NULL && temp2 != NULL)
        {
            sum = temp2->data + carry;
            carry = sum / 10;        
            sum   = sum % 10; 
            if(dl_insert_first(resh , rest, sum) == FAILURE)
                return FAILURE;

            temp2 = temp2->prev;
        }
        else if(temp2 == NULL && temp1 != NULL)
        {
            sum = temp1->data + carry;
            carry = sum / 10;        
            sum   = sum % 10; 
            if(dl_insert_first(resh , rest, sum) == FAILURE)
                return FAILURE;

            temp1 = temp1->prev;
        }
    }
    if(carry)
    {
        if(dl_insert_first(resh , rest, 1) == FAILURE)
                return FAILURE;
    } 

    return SUCCESS;
}
