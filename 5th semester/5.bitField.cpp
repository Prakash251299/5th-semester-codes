#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct foo{
	unsigned int a:3;
	unsigned int y:6;
}foo;
int main(){
	struct foo f;
	f.y = 33; // Here f.y = 100001 (of 6 bit length)
	f.a = 7; // Here f.a = 111 (in binary of 3 bit)
	printf("%d",f.a); // Here f.a is of size 4 bit
	printf("\n%c",f.y);
	return 0;
}