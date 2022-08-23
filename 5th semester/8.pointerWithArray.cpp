#include<stdio.h>
#include<stdlib.h>
int *ord(int b[]){ // It acts as a pointer which holds the address of the received array 'a'
	b[0] = 8;
	b[1] = 7;
	b[64] = 6;
	printf("add: %x\n",b); // '&b' is different from value of 'b'
	return b; // The value that b contains (i.e. address of array 'a') is returned
}

int main(){
	int *p;
	int a[65];
	p = ord(a); // Here 'p' holds the address of array 'a'
	printf("%d\n",*p);
	printf("Add of p: %x a: %x\n",p,&a); // Same
	return 0;
}



