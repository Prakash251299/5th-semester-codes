#include<stdio.h>
#include<malloc.h>
struct node{
	int count;
	struct node *next,*prev;
}*start = NULL,*q,*r,*s,*t,*m,*n;

int swap(node *q, node *r){
	if(q==r){
		printf("Same element\n");
		return 0;
	}
	if(q->next == r){
		if(q == start){
			start = start->next;
			r = start->next;
			start->next = q;
			q->prev = start;
			q->next = r;
			if(r!=NULL){
				r->prev = q;
			}
			start->prev = NULL;
		}
		else{
			r = q->next->next;
			q = q->prev;
			q->next = q->next->next;
			q->next->next = q->next->prev;
			q->next->next->next = r;
			if(r!=NULL){
				r->prev = q->next->next;
			}
			q->next->prev = q;
			q->next->next->prev = q->next;
		}
		return 0;
	}
	s = r->prev;
	t = r->next;
	if(q!=start){
		q->prev->next = r;
	}else{
		start = r;
	}
	r->prev = q->prev;
	r->next = q->next;
	r->next->prev = r;
	s->next = q;
	q->prev = s;
	q->next = t;
	if(q->next!=NULL){
		q->next->prev = q;
	}
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
	q = start;
	int n = 0, k = 0, l = 0;
	printf("Enter number of element\n");
	scanf("%d",&n);
	insert(n);
	display();
	while(1){
		printf("Enter elements position to swap them\n");
		printf("Element 1: ");
		scanf("%d",&k);
		printf("Element 2: ");
		scanf("%d",&l);
		if(k<=0 || l<=0 || k>n || l>n){
			printf("Not valid positions\n");
			continue;
		}
		else{
			break;
		}
	}
	int i = 0;
	q = start;
	while(i<k-1){
		q = q->next;
		i++;
	}
	r = start;
	i=0;
	while(i<l-1){
		r = r->next;
		i++;
	}
	swap(q,r);
	printf("\n");
	display();
	return 0;
}