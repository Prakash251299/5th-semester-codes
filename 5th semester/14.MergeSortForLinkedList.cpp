/* Merge sort for linked list */

#include<stdio.h>
#include<stdlib.h>
void display();

struct Sort{
	int count;
	char data;
	struct Sort *next,*prev;
}*start=NULL,*q,*r;

/* In '**q', q is a pointer that contains address of another pointer, *q is the address that is contained by q and **q is the data
   that is at the address *q
 */
void midFinder(struct Sort *head, struct Sort **q,struct Sort **r){ // **q is address pointer
	struct Sort *fast = head;
	struct Sort *slow = head;
	while(1){
		if(fast->next==NULL || fast->next->next==NULL){
			break;
		}
		fast = fast->next->next;
		slow = slow->next;
	}
	*q = head; 
	*r = slow->next;
	slow->next = NULL;
}

struct Sort *sortedMerge(struct Sort *q, struct Sort *r){
	struct Sort *result = NULL; // It is a container for the merged list
	if(q==NULL){
		return r;
	}else{
		if(r==NULL){
			return q;
		}
	}
	if(q->count>r->count){
		result = r;
		result->next = sortedMerge(q,r->next);
	}else{
		result = q;
		result->next = sortedMerge(q->next,r);
	}
	
	return result;
}

void mergeSort(struct Sort **q){  // Here **q holds address of pointer (initially address of start)
	struct Sort *head = *q; // *q is pointer ( initially start)
	struct Sort *front;
	struct Sort *back;
	if(head==NULL || head->next==NULL){
		return;
	}
	midFinder(head,&front,&back);
	mergeSort(&front);
	mergeSort(&back);
	*q = sortedMerge(front,back);
}

int insert(int n){
	int i=0;
	while(i<n){
		if(start==NULL){
			start = (struct Sort*)malloc(sizeof(struct Sort));
			start->next = NULL;
			start->prev  =NULL;
//			start->count = count;
//			printf("Element %d: ",i);
//			scanf("%d",&start->count);
			start->count = rand()%20+1;
			q = start;
		}
		else{
			r = q;
			q->next = (struct Sort*)malloc(sizeof(struct Sort));
			q = q->next;
			q->next = NULL;
			q->prev = r;
//			printf("\nElement %d: ",i);
//			scanf("%d",&q->count);
			q->count = rand()%20+1;
//			printf("\n");
		}
		i++;
	}
	return 0;
}

void display(){
	q = start;
	while(1){
		if(q==NULL){
//			q = m;
			break;
		}
		printf("%d ",q->count);
//		m = q;
		q = q->next;
	}
	printf("\n");
	return;
}

int main(){
	int n = 10000; // For 1 crore data, it takes about 8.09 seconds
	insert(n);
//	display();
	mergeSort(&start);
	printf("Sorted!\n");
//	display();
	return 0;
}