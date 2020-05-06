/* Single linked list header*/

struct snode{
	int data;
	struct snode* next;
};
 

struct snode *create_list(struct snode *head);
void display(struct snode *head);
struct snode *insert_beg(struct snode *head,int val);
struct snode *insert_end(struct snode *head,int val);
struct snode *insert_pos(struct snode *head,int val,int pos);
struct snode *del(struct snode *head,int val);
struct snode *rev(struct snode *head);
int del_end(struct snode *head);
int del_beg(struct snode *head);
void loop_detection(struct snode *head);
int count_nodes(struct snode *n); 


struct snode *create_list(struct snode *head)
{
	int i,n,val1;
	printf("Enter the number of snodes you want to enter\n");
	scanf("%d",&n);
	head = NULL;
	if(n == 0)
	{
		return head;
	}
	printf("Enter the element to be inserted\n");
	scanf("%d",&val1);
	head = insert_beg(head,val1);
	for(i=2;i<=n;i++)
	{
		printf("Enter the element\n");
		scanf("%d",&val1);
		head = insert_end(head,val1);
	}
 return head;
}

void display(struct snode *head)
{
	struct snode *h;
	if(head == NULL)
		printf("The list is empty\n");
	h = head;
	printf("The list is\n");
	while(h!=NULL)
	{
		printf("%d\t",h->data);
		h = h->next; 
	}
	printf("\n");
}

struct snode *insert_beg(struct snode *head,int val)
{
	struct snode *temp;
	temp = (struct snode *)malloc(sizeof(struct snode));
	temp->data = val;
	temp->next = head;
	head = temp ;
	return head;
}
struct snode *insert_end(struct snode *head,int val)
{
	struct snode *h, *temp;
	temp = (struct snode *)malloc(sizeof(struct snode));
	temp->data = val;
	h = head;
	while(h->next!=NULL)
	{
		h = h->next;
	}
	h->next  = temp;
	temp->next = NULL;
 return head;
}
struct snode *insert_pos(struct snode *head,int val,int pos)
{
	struct snode *temp,*h;
	int i ;
	temp = (struct snode *)malloc(sizeof(struct snode));
	temp->data = val;
	if(head == NULL)
	{
		printf("List is empty so add at begning\n");
		head = insert_beg(head,val);
		return head;
	}
	if(pos==1)
	{
		temp->next = head;
		head = temp ;
		return head;
	}
	h = head;
	for(i=2;i<pos;i++)
	{
		h = h->next; 
	}
	temp->next = h->next;
	h->next = temp;
 return head;
}
struct snode *del(struct snode *head,int val)
{
	struct snode *h,*temp;
	if(head == NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(head->data == val)
	{
		temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	h = head;
	while(h->next!=NULL)
	{
		if(h->next->data == val)
		{
			temp = h->next;
			h->next = temp->next;
			free(temp);
			return head;
		}
		h = h->next;
	}
        printf("Element not found\n");
 return head;
}
struct snode *rev(struct snode *head)
{
	struct snode *ptr1,*ptr2,*prev;
	prev = NULL;
	ptr1 = head;
	while(ptr1 != NULL)
	{
		ptr2 = ptr1->next;
		ptr1->next = prev;
	        prev = ptr1;
		ptr1 = ptr2;	
	}
	head = prev;
 return head;
}
int del_end(struct snode *head)
{
	struct snode *temp;
	int val;
	if(head == NULL)
	{
		printf("list is empty");
		return -1;
	}
	temp = head;
	while(temp->next->next != NULL)
	{
		temp = temp->next;
	}
	val = temp->next->data;
	free(temp->next);
	temp->next = NULL;
  return val;
}

int del_beg(struct snode *head)
{
	struct snode *temp;
	int val;
	printf("3---%p\n", head);
	if(head == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	printf("4---%p\n", head);
	printf("temp 1---%p\n", temp);
	temp = head;
	val = temp->data;
	printf("5---%p\n", head);
	printf("temp 2---%p\n", temp);
	head = head->next;
	printf("6---%p\n", head);
	printf("temp 3---%p\n", temp);
	free(temp);
	temp = NULL;
	printf("val1---%d",head->data);
  return val;
}

void loop_detection(struct snode *head)
{
	struct snode *ptr1,*ptr2;
        ptr1 = head;
        ptr2 = head;
     
    while(ptr1 !=NULL && ptr2 !=NULL && ptr1->next!=NULL)
    {
       ptr1 = ptr1->next;
       ptr2 = ptr2->next->next;
       if (ptr1 == ptr2)
       {
           printf("%s","Loop Detected");
          printf("the number of snodes in the loop is : %d\n",count_nodes(ptr1));
	exit(0);
        }
    }
	printf("there is no loop\n");
}

int count_nodes(struct snode *n) 
{ 
   int res = 1; 
   struct snode *temp = n; 
   while (temp->next != n) 
   { 
      res++; 
      temp = temp->next; 
   } 
   return res; 
}
