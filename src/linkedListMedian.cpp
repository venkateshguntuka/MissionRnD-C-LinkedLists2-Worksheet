/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
int listLength(struct node*);
int linkedListMedian(struct node *head) {
	if (head==NULL)
		return -1;
	int len, median,evenflag=0;
	len = listLength(head);
	if (len % 2 == 0)
	{
		median = len / 2;
		evenflag = 1;
	}
	else
		median = len / 2 + 1;
	len = 1;
	struct node* temp = head;
	while (temp != NULL)
	{
		if (len == median)
		{
			if (evenflag == 1)
				return ((temp->num) + (temp->next->num)) / 2;
			else
				return temp->num;
		}
		temp = temp->next;
		len++;
	}
}
int listLength(struct node* head)
{
	struct node* temp = head;
	int length = 0;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}