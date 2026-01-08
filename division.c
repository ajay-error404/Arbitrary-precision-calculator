#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int Division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **resh,  Dlist **rest)
{
    Dlist* subresh = NULL;
    Dlist* subrest = NULL;

    Dlist *newSumH = NULL, *newSumT = NULL;
    Dlist *newQH = NULL, *newQT = NULL;


    Dlist *divresh = NULL, *divrest = NULL;
    Dlist *divsubresh = NULL, *divsubrest = NULL;

    dl_insert_first(&subresh, &subrest, 0);

    Dlist *oneh = NULL, *onet = NULL;
    dl_insert_first(&oneh, &onet, 1);
    
    dl_insert_first(&divsubresh, &divsubrest, 0);

    *resh = NULL;
    *rest = NULL;

    while(1)
    {

        Add(&subresh, &subrest, head2, tail2, &newSumH, &newSumT);

        dl_delete_list(&subresh, &subrest);
        subresh = newSumH;
        subrest = newSumT;

        newSumH = NULL;
        newSumT = NULL;

        if(compare(subresh,*head1) > 0)
        {
            break;
        }

        Add(&divsubresh, &divsubrest,&oneh, &onet,&newQH, &newQT);
        dl_delete_list(&divsubresh, &divsubrest);
        divsubresh = newQH;
        divsubrest = newQT;

        newQH = NULL;
        newQT = NULL;

    }

    *resh = divsubresh;
    *rest = divsubrest;

    return SUCCESS;
}
