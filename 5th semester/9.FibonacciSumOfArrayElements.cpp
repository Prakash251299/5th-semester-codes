/* Array that contains sum of all previous indexed elements of an array*/
#include<stdio.h>
int main(){
	int arr[4] = {4,3,2,1};
	int size = 4;
	for(int i = 1;i<size;i++){
		arr[i] = arr[i-1] + arr[i];
	}
	for(int i = 0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}

/*
Output: 4,7,9,10
*/