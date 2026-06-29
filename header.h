#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct dnode
{
	int data;
	struct dnode *prev;
	struct dnode *next;
}Dlist;

int validate(char *str);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int add(int num1, int num2, int carry);
int print_list(Dlist *head);
void addition( Dlist **tail1, Dlist **tail2, Dlist **head, Dlist **tail);
void subtraction( Dlist **tail1,  Dlist **tail2, Dlist **head, Dlist **tail);
int count_list(Dlist **head);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head, Dlist **tail);
int dl_delete_list(Dlist **head, Dlist **tail);
int add_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int copy_list(Dlist **sourceHead, Dlist **sourceTail, Dlist **destHead, Dlist **destTail);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
