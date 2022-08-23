#include<stdio.h>
#include<string.h>
int main(){
	char a[100],c[100],var;
	int size = 0,i=0,k=0;
	printf("Enter the string\n");
	scanf("%s",&a);
	while(a[i]!='\0'){
		size++;i++;
	}
	i=0;
	while(i<size){
		if(i==0 and (a[i]>=65 and a[i]<=90)){
			var = char(int(a[i])+32);
			strncat(c,&var,1);
			k++;
		}
		else{
			if(a[i]>=65 and a[i]<=90){
				var = '_';
				strncat(c,&var,1);k++;
				var = char(int(a[i])+32);
				strncat(c,&var,1);
				k++;
			}
			else{
				strncat(c,&a[i],1);
				k++;
			}
		}
		i++;
	}
	printf("CamelCase: %s -> snake_case: %s",a,c);
	return 0;
}