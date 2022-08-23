#include<stdio.h>
int main(){
	FILE *f;
	char a[100];
	f = fopen("rd.jpg","rb");
	int count = 0;
	while(1){
		char b = fgetc(f);
		if(b==EOF){
			break;
		}
		count++;
		printf("%c",b);
	}
	printf("\nNumber of characters: %d",count);
	fclose(f);
	return 0;
}