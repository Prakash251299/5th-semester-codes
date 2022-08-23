#include<stdio.h>
#include<stdlib.h>
struct node{
	int count;
	struct node *next,*prev;
}*start =NULL,*q,*r,*fast,*slow;

int midFinder(struct node **source, struct node **h,struct node **t){
	struct node *qs = *source;
	if(qs==NULL||qs->next==NULL){
		if(qs==NULL){
			*h = NULL;
			*t = NULL;
			return 0;
		}
		*h = qs;
		*t = qs;
		return 0;
	}
	fast = qs;
	slow = qs;
	while(1){
		if(fast->next==NULL || fast->next->next==NULL){
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	*h = *source;
	*t = slow->next;
	slow->next = NULL;
	return 0;
}

int divide(struct node **q){
	struct node *head = *q;
	struct node *front;
	struct node *back;
	if(head==NULL || head->next==NULL){
		return 0;
	}
	front = *q;
	midFinder(q,&head,&back);
	r = front;
	while(r!=NULL){
		printf("%d ",r->count);
		r=r->next;
	}
	printf("\n");
	divide(&front);
	r = back;
	while(r!=NULL){
		printf("%d ",r->count);
		r=r->next;
	}
	printf("\n");
	divide(&back);
	return 0;
}

int insert(int n){
	int i=0;
	while(i<n){
		if(start==NULL){
			start = (struct node*)malloc(sizeof(struct node));
			start->next = NULL;
			start->prev  =NULL;
			printf("Element %d: ",i);
			scanf("%d",&start->count);
			q = start;
		}
		else{
			r = q;
			q->next = (struct node*)malloc(sizeof(struct node));
			q = q->next;
			q->next = NULL;
			q->prev = r;
			printf("\nElement %d: ",i);
			scanf("%d",&q->count);
		}
		i++;
	}
	return 0;
}

void display(){
	q = start;
	while(1){
		if(q==NULL){
			break;
		}
		printf("%d ",q->count);
		q = q->next;
	}
	printf("\n");
	return;
}

int main(){
	int i=0,a=0,n=0;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	insert(n);
	divide(&start);
	return 0;
}