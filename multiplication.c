#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest)
{
    Dlist *h1 = NULL;
    Dlist *t1 = NULL;
    Dlist *h2 = NULL;
    Dlist *t2 = NULL;
    Dlist *h3 = NULL;
    Dlist *t3 = NULL;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    (void)head1;
    (void)head2;

    int count = 0;
    while(temp2)
    {
        int carry = 0;
        int res = 0;
        h2 = NULL;
        t2 = NULL;
        if(count != 0)
        {
            for(int i=0 ; i<count ; i++)
            {
                dl_insert_first(&h2, &t2, 0);
            }
        }
        temp1 = *tail1;
        
        while(temp1)
        {
            
            res = (temp1->data * temp2->data) + carry;
            carry = res / 10;
            res = res % 10;
            if(count==0)
            {
                dl_insert_first(&h1, &t1, res);
            }
            else
            {
                dl_insert_first(&h2, &t2, res);
            }
            temp1 = temp1->prev;
        }
        if(carry)
        {
            if (count == 0)
                dl_insert_first(&h1, &t1, carry);
            else
                dl_insert_first(&h2, &t2, carry);
        }
        if(count)
            {
                Add(&h1, &t1, &h2, &t2, &h3, &t3);
                dl_delete_list(&h1, &t1);
                h1 = h3;
                t1 = t3;
                h3 = NULL;
                t3 = NULL;
                dl_delete_list(&h2, &t2);
            }
        temp2 = temp2->prev;
        count++;
    }
    *resh = h1;
    *rest = t1;
    return SUCCESS;
}