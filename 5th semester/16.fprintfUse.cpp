/* Use of fprintf */

#include<stdio.h>
int main(){
	FILE *f;
	f = fopen("ASCII.txt","r+");
	int i=0;
	while(i<256){
		printf("%d: %c\n",i,i);
		fprintf(f,"%d. %c\r\n",i,i); // For '\n', '\r' is used
		i++;
	}
	return 0;
}