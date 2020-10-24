typedef struct node
{
	int data;
	struct node *link = NULL;
} node;
node *start = NULL;

int node_count()
{
	int count = 0;
	node *temp;
	temp = start;
	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}
void insert_begin(int num)
{
	node *p;
	p = (node *)malloc(sizeof(node));
	p->data = num;
	if (start == NULL)
	{
		p->link = NULL;
		start = p;
	}
	else
	{
		p->link = start;
		start = p;
	}
}

void insert_begin()
{
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("Enter Data :");
	scanf("%d", &p->data);
	if (start == NULL)
	{
		p->link = NULL;
		start = p;
	}
	else
	{
		p->link = start;
		start = p;
	}
}

void insert_end(int num)
{
	node *p, *temp;
	p = (node *)malloc(sizeof(node));
	p->data = num;
	p->link = NULL;
	if (start == NULL)
	{
		start = p;
	}
	else
	{
		temp = start;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = p;
	}
}

void insert_end()
{
	node *p, *temp;
	p = (node *)malloc(sizeof(node));
	scanf("%d", &p->data);
	p->link = NULL;
	if (start == NULL)
	{
		start = p;
	}
	else
	{
		temp = start;
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = p;
	}
}

void insert_specified_location(int num)
{
	int loc, count = node_count();
	node *p, *temp, *q;
	p = (node *)malloc(sizeof(node));
	temp = start;
	p->data = num;
	p->link = NULL;
	printf("Enter The node after which you wanna insert <Should be less than %d >  :", count);
	scanf("%d", &loc);
	if (loc <= count)
	{
		count = 0;
		temp = start;
		while (temp != NULL)
		{
			count++;
			if (count == loc)
			{
				p->link = temp->link;
				temp->link = p;
				break;
			}
			temp = temp->link;
		}
	}
	else
		printf("Node Doesn't exist ");
}

void insert_specified_location()
{
	int loc, count = 0;
	node *p, *temp, *q;
	p = (node *)malloc(sizeof(node));
	temp = start;
	p->link = NULL;
	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	printf("Enter The node on which insert <Should be less or equal to %d >  :", count);
	scanf("%d", &loc);
	loc--;
	if (loc <= count)
	{
		count = 0;
		temp = start;
		while (temp != NULL)
		{
			count++;
			if (count == loc)
			{
				printf("Enter Data:");
				scanf("%d", &p->data);
				p->link = temp->link;
				temp->link = p;
				break;
			}

			temp = temp->link;
		}
	}
	else
		printf("\n\tNode Doesn't exist ");
}

void display()
{
	node *p, *temp;
	p = (node *)malloc(sizeof(node));
	if (start == NULL)
		printf("List Doesn't Exist ");
	else
	{
		temp = start;
		while (temp != NULL)
		{
			printf("%d\t", temp->data);
			temp = temp->link;
		}
	}
}

int delete_begining()
{
	node *p;
	if (start == NULL)
	{
		printf("List Underflow \n");
		return 0;
	}
	p = start;
	int temp = start->data;
	start = p->link;
	free(p);
	return (temp);
}

int delete_end()
{
	node *p, *q;
	if (start == NULL)
	{
		printf("List Underflow \n");
		return 0;
	}
	p = start;
	q = p->link;
	while (q->link != NULL)
	{
		p = q;
		q = q->link;
	}
	p->link = NULL;
	int temp = q->data;
	free(q);
	return temp;
}

int delete_specified_location()
{
	node *temp, *p;
	int count = 0, loc, item;
	if (start == NULL)
		printf("List Underflow \n");
	temp = start;
	while (temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	printf("Enter The node to delete <Should be less or equal to %d >  :", count);
	scanf("%d", &loc);
	if (loc == 1)
		delete_begining();
	else if (loc <= count)
	{
		count = 0;
		p = start;
		temp = p->link;
		while (temp != NULL)
		{
			count++;

			if (count == loc)
			{
				temp->link = p->link;
				item = p->data;
				free(p);
				break;
			}
			temp = p;
			p = p->link;
		}
		return item;
	}
	else
		printf("Node Doesn't exist ");
}

/*********************************************************************Sorting********************************************************************/

/* void Sort()                 //Using Array
{
	 int array[node_count()],i=0,count=node_count(),j,tem;
	 char choice;
	 node *temp;
	 temp=start;
	 while(temp!=NULL)
	 {
	 	array[i++]=temp->data;
	 	temp=temp->link;
	 }
	 printf("\nSort in order\n\t A -> Ascending Order\n\t D -> Descending Order\n\t choice...");
	 fflush(stdin);
	 choice=getch();
	 printf("\n");
	 switch(choice)
	 {
	 	 case 'A':
	 	 case 'a':
		      	for(i=0;i<count;i++)
		      	  {
		      	  	 	for(j=0;j<count;j++)
		      	  	      {
		      	  	           if(array[i]<array[j])
								   {
								      tem=array[i];
									  array[i]=array[j];
									  array[j]=tem;  	
								   }	
						  }
				  }
				  
				  break;
				  
		 case 'D':
		 case 'd':
		      for(i=0;i<count;i++)
		      	  {
		      	  	 	for(j=0;j<count;j++)
		      	  	      {
		      	  	           if(array[i]>array[j])
								   {
								      tem=array[i];
									  array[i]=array[j];
									  array[j]=tem;  	
								   }	
						  }
				  }		  
	 }
	 
	temp=start;
	i=0;
	 while(temp!=NULL)
	 {
	 	temp->data=array[i++];
	 	temp=temp->link;
	 }
	 
 printf("\n\tSorted List is ...\n\t\t");
 display();	  	 
}
  */

void Sort()
{
	int count = node_count(), i = 0, j = 0, tem;
	char choice;
	node *tempA, *tempB;
	tempB = tempA = start;
	printf("\nSort in order\n\t A -> Ascending Order\n\t D -> Descending Order\n\t choice...");
	fflush(stdin);
	choice = getch();
	printf("\n");
	switch (choice)
	{
	case 'A':
	case 'a':
		while (tempA != NULL)
		{
			tempB = tempA;
			while (tempB != NULL)
			{
				if (tempA->data > tempB->data)
				{
					tem = tempA->data;
					tempA->data = tempB->data;
					tempB->data = tem;
				}
				tempB = tempB->link;
			}
			tempA = tempA->link;
		}
		break;

	case 'D':
	case 'd':
		while (tempA != NULL)
		{
			tempB = tempA;
			while (tempB != NULL)
			{
				if (tempA->data < tempB->data)
				{
					tem = tempA->data;
					tempA->data = tempB->data;
					tempB->data = tem;
				}
				tempB = tempB->link;
			}
			tempA = tempA->link;
		}
		break;

	default:
		printf("\n\tPlease Choose Correctly!!!!!!!!\n");
	}

	printf("\n\tSorted List is ...\n\t\t");
	display();
}

void reverse()
{
	node *p, *q, *r;
	if (start == NULL)
	{
		printf("\n\tPlease Create or Select Any List");
		return;
	}
	p = start;
	q = NULL;
	while (p != NULL)
	{
		r = p->link;
		p->link = q;
		q = p;
		p = r;
	}
	start = q;
	printf("\tList Reaversed\n");
}
