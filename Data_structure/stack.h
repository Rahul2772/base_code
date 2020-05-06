/*Stack header*/

#include"single_link_list.h"

struct snode *push(struct snode *head,int val);
int pop(struct snode **phead);
int peek(struct snode *head);
int isempty(struct snode *head);

struct snode *push(struct snode *head,int val)
{
	return insert_beg(head,val);
}


int pop(struct snode **phead)
{
	return del_beg(phead);
}

int isempty(struct snode *head)
{
	if(head == NULL)
		return 1;
	else
		return 0;
}

int peek(struct snode *head)
{
	if(isempty(head))
	{	
		printf("Stack Underflow\n");
		return 0;	
	}
 	return head->data;
}

