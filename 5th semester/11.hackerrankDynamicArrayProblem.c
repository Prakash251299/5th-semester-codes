/*
Declare a 2-dimensional array,arr, of  empty arrays. All arrays are zero indexed.
Declare an integer,lastAnswer, and initialize it to .

There are 2 types of queries, given as an array of strings for you to parse:

Query: 1   x y
Let idx = ((x^lastAnswer)%n).
Append the integer y to arr[idx].
Query: 2   x y
Let idx = ((x^lastAnswer)%n).
Assign the value arr[idx][y%size(arr[idx])] to lastAnswer.
Store the new value of lastAnswer to an answers array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Seq {
  int *data;
  int size;
} Seq;

Seq seq[100000]; // As array size can be upto 100000

void ins(int n, int y){
    seq[n].data = realloc(seq[n].data, seq[n].size + 1); // realloacting size of 'nth data array'
    seq[n].size += 1; // size increased by one of the 'nth data array'
    seq[n].data[seq[n].size-1] = y; // y is appended to the 'nth data array'
}

int print(int n, int y){
    int t;
    t = seq[n].data[y%seq[n].size]; // reuired value is assigned to t as lastanswer
    printf("%d\n",t);
    return t;
}

int main() {
    int i=0,n=0,q=0,choice=0,x=0,y=0,lastAnswer=0;
    printf("Enter size of array and number of queries\n");
    scanf("%d %d",&n,&q);
    while(i<q){
    	printf("Enter values of choice, x, y\n");
        scanf("%d %d %d",&choice,&x,&y);
        int s = (x^lastAnswer)%n; // chosing the array (created by structure)
        switch(choice){
            case 1:ins(s,y);break;
            case 2:lastAnswer = print(s,y);break;
        }
        i++;
    }
    return 0;
}