#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void swap(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    Dlist *temp = *head1;
    *head1 = *head2;
    *head2 = temp;

    temp = *tail1;
    *tail1 = *tail2;
    *tail2 = temp;

}


int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;
    
    if(*head == NULL && *tail == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new -> prev = *tail;
        (*tail)->next = new;
        *tail = new;
        return SUCCESS;
    }
}

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> prev = NULL;
    new -> data = data;
    new -> next = NULL;
    
    if(*head == NULL && *tail == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
    }

}
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL && *tail == NULL)
    {
        return FAILURE;
    }
    Dlist *temp = *head;
    while(temp != NULL)
    {
        Dlist *next = temp -> next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

void print_list(Dlist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    printf("%d", head->data);
		    head = head->next;
	    }
    }
}

void pre_zero(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return;
    }
    Dlist *temp = *head;
    while((temp->data == 0) && (temp->next != NULL))
    {
        temp = temp->next;
        free(temp->prev);
        temp->prev = NULL;
        *head = temp;
    }
    return ;
}

int compare(Dlist *head1, Dlist *head2)
{
    if (head1 == NULL && head2 == NULL)
    return SUCCESS;

    if (head1 == NULL)
        return FAILURE;

    if (head2 == NULL)
        return 1;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    int count1 = 0;
    int count2 = 0;
    while(temp1)
    {
        count1++;
        temp1 = temp1->next;
    }
    while(temp2)
    {
        count2++;
        temp2 = temp2->next;
    }
    if(count1 > count2)
    {
        return 1;
    }
    else if(count1 < count2)
    {
        return FAILURE;
    }
    else
    {
        temp1 = head1;
        temp2 = head2;

        while(temp1 && temp2)
        {
            if(temp1->data > temp2->data)
            {
                return 1; 
            }
            else if(temp1->data < temp2->data)
            {
                return FAILURE;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return SUCCESS;
}