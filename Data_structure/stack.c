/*Stack operations*/

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct snode *head = NULL;

int main()
{
	 int val,choice;	
  while(1)
  {
  	printf("press 1 for push\n");
  	printf("press 2 for pop\n");
  	printf("press 3 for display top element\n");
  	printf("press 4 for display all elements\n");
  	printf("press 5 for exit\n");
  	printf("enter the choice\n");
  	scanf("%d",&choice);
	switch(choice)
	{
		case 1: 
			printf("Enter the value you want to push\n");
			scanf("%d",&val);
			head = push(head,val);
			break;

		case 2: 
			printf("1---%p\n", head);
			val = pop(head);
			printf("poped value is : %d\n",val);
			printf("8---%p\n", head);
			break;
			
		case 3: 
			printf("Value at the top is: %d\n",peek(head));
			break;
		
		case 4: 
			display(head);
			break;

		case 5: 
			exit(1);

		default: printf("Wrong choice\n");
	}
  }
 return 0;
}


