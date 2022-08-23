#include<stdio.h>
#include<stdlib.h>
int main(){
	int m=0,n=0,i=0,j=0;
	printf("Enter size of 2D array: ");
	scanf("%d",&m);
	printf("Enter size of each 1D array: ");
	scanf("%d",&n);
	int a[m][n],sum[n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			a[i][j] = rand()%20+1;
		}
	}
	printf("[");
	for(i=0;i<m;i++){
		printf("[");
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\b],");
	}
	printf("\b]\n");
	int s=0;
	for(i=0;i<n;i++){
		s=0;
		for(j=0;j<m;j++){
			s = s + a[j][i];
		}
		sum[i] = s;
	}
	printf("[");
	for(i=0;i<n;i++){
		printf("%d,",sum[i]);
	}
	printf("\b]");
	return 0;
}