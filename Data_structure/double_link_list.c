/*Double linked list*/

#include<stdio.h>
#include<stdlib.h>
#include"double_link_list.h"

int main()
{
	struct dnode *head = NULL;
	int choice,val,pos;
        AGAIN : 
        while(1)
	{
		printf("press--1--for creating list\n");
		printf("press--2--for dispaly\n");
		printf("press--3--for insert value at begning\n");
		printf("press--4--for insert value at end\n");
		printf("press--5--for insert at nth position\n");
		printf("press--6--for deleting value from the list\n");
		printf("press--7--for reversing the list\n");
		printf("press--8--for exit\n");
		printf("Enter the choice you want to perform\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : 
				head = create_list(head);
				break;

			case 2 : 
				display(head);
				break;

			case 3 :
				printf("Enter the value you want to insert at begning\n");
				scanf("%d",&val);
				head = insert_beg(head,val);
				break;

			case 4 : 
				printf("Enter the value you want to insert at end\n");
				scanf("%d",&val);
				head = insert_end(head,val);
				break;

			case 5 :
				printf("Enter the element you want to insert at nth position\n");
				scanf("%d",&val);
				printf("Enter the position at which you want to insert\n");
				scanf("%d",&pos);
				head = insert_pos(head,val,pos);
				break;

			case 6 :
				printf("Enter the elenemt you want to delete\n");
				scanf("%d",&val);
				head = del(head,val);
				break;

			case 7 :
				head = rev(head);
				break;

			case 8 :
				exit(1);

			default :
				printf("You entered the wrong choice\n");
				goto AGAIN;
		}
	}
 return 0;	
}

