/*Stack header*/

#include"single_link_list.h"

struct snode *push(struct snode *head,int val);
int pop(struct snode *head);
int peek(struct snode *head);
int isempty(struct snode *head);

struct snode *push(struct snode *head,int val)
{
	return insert_beg(head,val);
}


int pop(struct snode *head)
{
	printf("2---%p\n", head);
	return del_beg(head);
	printf("7---%p\n", head);
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

/*int pop(struct snode *head)
{
	struct snode *temp;
	int val;
	if(isempty(head))
	{
		printf("Stack underflow\n");
		return 0;
	}
	temp = head;
	val = temp->data;
	head = head->next;
	free(temp);
	return val;
}*/
