/* Checks whether an array contains duplicate element or not */

#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 100,temp=0;
	int a[n];
//	a[0] = -10;
	for(int i=0;i<n;i++){
//		printf("Enter a[%d]: ",i);
//		scanf("%d",&a[i]);
		a[i] = rand()%(n-1)+1;
	}
	printf("Array: ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++){
		temp = a[i];
		if(a[i] < 0){
			temp = -a[i]; // temp is always made positive for indexing of the array
		}
		if(a[temp]<0){  // If a[temp] is negative, it means that the index is previously traversed so duplicate found
			a[temp] = -1*a[temp];
			printf("Duplicate found:- a[%d]: %d",i,temp);
			return 0;
		}
		a[temp] = -a[temp]; // Traversed element's indexed array element (i.e. a[a[i]]) is made negative
	}
	printf("No duplicate found!");
	return 0;
}