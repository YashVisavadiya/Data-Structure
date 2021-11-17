#include <stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void main()
{
	struct Node *ptr=NULL;
	ptr=(struct Node *)malloc(sizeof(struct Node));

	printf("Enter a Value to insert : ");
	scanf("%d",&ptr->data);

	printf("Inserted Value is %d",ptr->data);

	free(ptr);
}