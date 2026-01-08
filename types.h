#ifndef SLL_H
#define SLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *prev;
    struct node *next;
}Dlist;

// insert the data at last of double linked list
int dl_insert_last(Dlist **head, Dlist **tail, int data);
// insert the data at first of double linked list
int dl_insert_first(Dlist **head, Dlist **tail, int data);
// to print double linked list
void print_list(Dlist *head);
// Addition operation
int Add(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest);
// substraction operation
int Substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest);
// multiplication operation
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest);
// dividion operation
int Division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **resh, Dlist **rest);
// to delete the linked list
int dl_delete_list(Dlist **head, Dlist **tail);
// swap the list
void swap(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
// to remove preceeding zeros
void pre_zero(Dlist **head, Dlist **tail);
// to compare two linked list
int compare(Dlist *head1, Dlist *head2);

#endif