/*Double linked list header*/

struct dnode{
		struct dnode *prev;
		int data;
		struct dnode *next;
};
struct dnode *create_list(struct dnode *head);
void display(struct dnode *head);
struct dnode *insert_toempty(struct dnode *head,int data);
struct dnode *insert_beg(struct dnode *head , int val);
struct dnode *insert_end(struct dnode *head , int val);
struct dnode *insert_pos(struct dnode *head , int val,int pos);
struct dnode *del(struct dnode *head , int val);
struct dnode *rev(struct dnode *head);


struct dnode *create_list(struct dnode *head)
{
	int i,n,val1;
	printf("Enter the number of dnodes you want to enter\n");
	scanf("%d",&n);
	head = NULL;
	if(n == 0)
	{
		return head;
	}
	printf("Enter the element to be inserted\n");
	scanf("%d",&val1);
	head = insert_toempty(head,val1);
	for(i=2;i<=n;i++)
	{
		printf("Enter the element\n");
		scanf("%d",&val1);
		head = insert_end(head,val1);
	}
 return head;
}
struct dnode *insert_toempty(struct dnode *head,int val)
{
	struct dnode *temp;
	temp = (struct dnode *)malloc(sizeof(struct dnode));
	temp->data = val;
	temp->prev = NULL;
	temp->next = NULL;
	head = temp;
 return head;
}
void display(struct dnode *head)
{
	struct dnode *h;
	if(head == NULL)
	{
		printf("The list is empty\n");
	  return;
	}
	h = head;
	printf("The list is\n");
	while(h!=NULL)
	{
		printf("%d\t",h->data);
		h = h->next; 
	}
	printf("\n");
}

struct dnode *insert_beg(struct dnode *head , int val)
{
	struct dnode *temp;
	temp = (struct dnode *)malloc(sizeof(struct dnode));
	temp->data = val;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
 return head;
}

struct dnode *insert_end(struct dnode *head , int val)
{
	struct dnode *temp,*h;
	temp = (struct dnode *)malloc(sizeof(struct dnode));
	temp->data = val;
	h = head;
	while(h->next!=NULL)
	{
		h = h->next; 
	}
	h->next = temp;
	temp->prev = h;
	temp->next = NULL;
 return head;
}

struct dnode *insert_pos(struct dnode *head , int val,int pos)
{
	struct dnode *temp,*h,*p;
	int i ;
	temp = (struct dnode *)malloc(sizeof(struct dnode));
	temp->data = val;
	if(head == NULL)
	{
		printf("List is empty so add at begning\n");
		head = insert_toempty(head,val);
		return head;
	}
	if(pos==1)
	{
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp ;
		return head;
	}
	h = head;
	h->prev = NULL;
	p = head;
	for(i=2;i<pos;i++)
	{
		h = h->next; 
		h->prev = p;
		p = p->next;
	}
	temp->next = h->next;
	h->next->prev = temp;
	h->next = temp;
	temp->prev = h;
  return head;
}
struct dnode *del(struct dnode *head,int val)
{
	struct dnode *h,*temp;
	if(head == NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(head->data == val)
	{
		temp = head;
		head = head->next;
		head->next->prev = NULL;
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
			temp->next->prev = h;
			free(temp);
			return head;
		}
		h = h->next;
	}
        printf("Element not found\n");
 return head;
}
struct dnode *rev(struct dnode *head)
{
	struct dnode *ptr1,*ptr2;
	ptr1 = head;
	ptr2 = ptr1->next;
	ptr1->next = NULL;
	ptr1->prev = ptr2;
	while(ptr2 != NULL)
	{
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;	
		ptr2 = ptr2->prev;
	}
	head = ptr1;
	printf("List is reversed\n");
 return head;
}
