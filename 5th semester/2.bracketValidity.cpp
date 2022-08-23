#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node{
	char data;
	struct node *next,*prev;
}*start=NULL,*q;

int main(){
	int len = 0, i = 0;
//	char a[100];
//  printf("Enter the brackets to check its validity");
//	scanf("%s",&a);
	char a[100] = {'[',']','{','(',')','}'};
	len = strlen(a);
	while(i<len){
		if(a[i]!='[' && a[i]!='{' && a[i]!='(' && a[i]!=')' && a[i]!='}' && a[i]!=']'){
			printf("Characters other than brackets are not allowed");
			return 0;
		}
		i++;
	}
	if(len%2!=0){
		printf("Invalid brackets0");
		return 0;
	}
	else{
		i = 0;
		while(1){
			if(i==len){
				if(start==NULL){
					printf("Valid brackets");
					return 0;
				}
				else{
					printf("Invalid brackets1");
					return 0;
				}
			}
			else{
				if(start==NULL){
					start = (struct node*)malloc(sizeof(struct node));
					start->data = a[i];
					printf("%c ",start->data);
					q = start;
					q->next = NULL;
				}
				else{
					q->next = (struct node*)malloc(sizeof(struct node));
					q->next->data = a[i];
					printf("%c ",q->next->data);
					q->next->prev = q;
					q->next->next = NULL;
				}
				if(q->next!=NULL){ // In case of '[]{()}' start will be null after '[]' so this q->next is required
					if(q->next->data==')' or q->next->data== '}' or q->next->data==']'){
						if((q->data=='(' && q->next->data==')') || (q->data=='{' && q->next->data=='}') ||
						 (q->data=='[' && q->next->data==']')){
							if(q==start){
								start = NULL;
							}
							else{
								q = q->prev;
								q->next = NULL;
							}
						}
						else{
							printf("Invalid brackets2");
							return 0;
						}
					}
					else{
						q = q->next;
					}
				}
			}
			i++;
		}
	}
	return 0;
}