#include <stdlib.h>
#include <stdio.h>

struct dnode{
	int data;
	struct dnode *next, * prev;
};

struct doublylist{
	struct dnode *head;
	struct dnode *last;
	//int len;
};

void init(struct doublylist *ptr){
	ptr->head = NULL;
	ptr->last = NULL;
}

void insertstart (struct doublylist *dptr, int data)
{
	struct dnode *temp = (struct dnode *) malloc (sizeof (struct dnode));
	if (temp == NULL) return;
	temp->data = data;
	temp->prev = NULL;
	if (dptr->head == NULL){
		dptr->head = temp;//(struct dnode *) malloc (sizeof (struct dnode));
		dptr->last = dptr->head;
		//dptr->last->data = data;
		dptr->last->next = NULL;

	} else {
		temp->next = dptr->head;
		dptr->head->prev = temp;
		dptr->head = temp;
	}
}	

void insertlast (struct doublylist *dptr, int data)
{
	// Please edit
	// ....
}

void printforward (struct doublylist *dptr){

	struct dnode *cur = dptr->head;
	int i = 1;

	while (cur)
	{
		printf ("Node No. %d. Data = %d\n", i++, cur->data);
		cur= cur->next;
	}

}


void printbackward (struct doublylist *dptr){
	// please edit
	// ....

}

void deletefront (struct doublylist *dptr){
	struct dnode *temp = dptr->head;
	if (temp == NULL) return;
	else {
		dptr->head = dptr->head->next;
		free (temp);
		if (dptr->head)
		{
			dptr->head->prev = NULL;
		} else dptr->last = NULL;
	}

}

void deletelast (struct doublylist *dptr)
{
	// do it by yourself
	// ....

}


void emptylist (struct doublylist *dptr)
{
	struct dnode *temp;
	while (dptr->head){
		temp = dptr->head;
		dptr->head = dptr->head->next;
		free (temp);
	}

	dptr->last = NULL;
}

void deletenode (struct doublylist *dptr, int data){
	struct dnode *s = dptr->head;
	while (s)
	{

		if (s->data == data){
			if (s->prev)
				s->prev->next = s->next;
			if (s->next)
				s->next->prev = s->prev;


			if (s == dptr->head) dptr->head = s->next;
			if (s == dptr->last) dptr->last = s->prev;			
			free (s);
			break;
		} else s = s->next;	
	}
}


struct dnode * search (struct doublylist *dptr, int data)
{
	struct dnode *s = dptr->head;
	// do it by themself
	//
	return s;
}


int isEmpty (struct doublylist *dptr)
{
	if (dptr->head) return 0;
	else return 1;
}

int getLen (struct doublylist *dptr){
	int len = 0;
	struct dnode *cur = dptr->head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}

void insertafter (struct doublylist *dptr, int data)
{
	// fill this function, find the data and insert after that
	// if no data is found then insert at last.
}

void reverse (struct doublylist *dptr){
	// reverse the data
}

void sort (struct doublylist *dptr){

	// sort the data
}

void binarysearch (struct doublylist *dptr)
{
	// apply binary search technique
	//
	// but before applying soft the data
}

int main (void){
	struct doublylist dl;//*dl= malloc (sizeof (struct doublylist));
	init (&dl);
	insertstart (&dl, 10);
	insertstart (&dl, 20);

	insertstart (&dl, 25);
	insertstart (&dl, 30);
	printf ("printing all the data....\n");
	printforward(&dl);
	deletenode (&dl, 40);
	printf ("printing after the delete node function....\n");
	printforward (&dl);
	printbackward (&dl);

	printf ("Print forward and backward done...\n");

	deletefront (&dl);
	printforward (&dl);
	emptylist (&dl);
	printforward (&dl);
}
