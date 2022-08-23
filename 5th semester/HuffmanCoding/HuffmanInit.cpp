#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Address{
	int value;
	char data;
	struct Address *next;
}*ad=NULL,*d;

int main(){
	int small[26],capital[26];
	for(int i = 0; i<26; i++){
		small[i] = 0;
		capital[i] = 0;
	}
	FILE *p = NULL;
	p = fopen("file1.txt","r");
	char c;
	while(1){
		c = fgetc(p);
		if(c==EOF){
			break;
		}
		if(int(c)>=65 && int(c)<=91){
			capital[int(c)-65]++;
		}
		if(int(c)>=97 && int(c)<=121){
			small[int(c)-97]++;
		}
	}
	for(int i = 0; i<26; i++){
		printf("%c:%d %c:%d\n",i+97,small[i],i+65,capital[i]);
	}
	for(int i = 0; i<26; i++){
		if(small[i]!=0){
			if(ad==NULL){
				ad = (struct Address*)malloc(sizeof(struct Address));
				ad->data = i+97;
				ad->value = small[i];
				ad->next = NULL;
				d = ad;
			}
			else{
				d->next = (struct Address*)malloc(sizeof(struct Address));
				d = d->next;
				d->data = i+97;
				d->value = small[i];
				d->next = NULL;
			}
		}
	}
	for(int i = 0; i<26; i++){
		if(capital[i]!=0){
			if(ad==NULL){
				ad = (struct Address*)malloc(sizeof(struct Address));
				ad->data = i+65;
				ad->value = capital[i];
				ad->next = NULL;
				d = ad;
			}
			else{
				d->next = (struct Address*)malloc(sizeof(struct Address));
				d = d->next;
				d->data = i+65;
				d->value = capital[i];
				d->next = NULL;
			}
		}
	}
	d = ad;
	printf("\nFinal\n");
	while(1){
		if(d==NULL){
			return 0;
		}
		printf("%c: %d\n",d->data,d->value);
		d = d->next;
	}
	
	return 0;
}