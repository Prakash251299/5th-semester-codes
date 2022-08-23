#include<stdio.h>
int main(){
	int i=0,j=0,n=5,visited[n][n],dir=0,A[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			visited[i][j] = 0;
		}
	}
	A[0][0] = 1;
	A[0][1] = 7;
	A[0][2] = 5;
	A[0][3] = 6;
	A[0][4] = 4;
	A[1][0] = 9;
	A[1][1] = 8;
	A[1][2] = 3;
	A[1][3] = 7;
	A[1][4] = 12;
	A[2][0] = 10;
	A[2][1] = 6;
	A[2][2] = 1;
	A[2][3] = 4;
	A[2][4] = 13;
	A[3][0] = 7;
	A[3][1] = 11;
	A[3][2] = 8;
	A[3][3] = 6;
	A[3][4] = 0;
	A[4][0] = 5;
	A[4][1] = 9;
	A[4][2] = 3;
	A[4][3] = 2;
	A[4][4] = 7;
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			printf("Enter value of A[%d][%d]: ",i,j);
//			scanf("%d",&A[i][j]);
//		}
//	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	i=0;j=0;
	while(1){
		if(dir==0){
			if(j!=n or visited[i][j] == 1){
				visited[i][j] = 1;
				printf("%d ",A[i][j]);
				j++;
			}
			if(j==n or visited[i][j]==1){
				dir = 1;
				j--;i++;
				if(visited[i][j]==1){  //////
					break;
				}
			}
		}
		if(dir==1){
			if(i!=n or visited[i][j] == 1){
				visited[i][j] = 1;
				printf("%d ",A[i][j]);
				i++;
			}
			if(i==n or visited[i][j]==1){
				dir = 2;
				j--;i--;
				if(visited[i][j]==1){
					break;
				}
			}
		}
		if(dir==2){
			if(j!=-1 or visited[i][j] == 1){
				visited[i][j] = 1;
				printf("%d ",A[i][j]);
				j--;
			}
			if(j==-1 or visited[i][j]==1){
				dir = 3;
				j++;i--;
				if(visited[i][j]==1){
					break;
				}
			}
		}
		if(dir==3){
			if(i!=-1 or visited[i][j] == 1){
				visited[i][j] = 1;
				printf("%d ",A[i][j]);
				i--;
			}
			if(i==-1 or visited[i][j]==1){
				dir = 0;
				j++;i++;
				if(visited[i][j]==1){
					break;
				}
			}
		}
	}
	return 0;
}