/* Method - 1*/
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
void openWeb(){
	char *cmd;
	asprintf(&cmd,"START www.google.com");
	system(cmd);
	free(cmd);
}
int main(){
	openWeb();
	return 0;
}


/* Method - 2 */

//#include<stdio.h>
//#include<stdlib.h>
//#define FORMAT_STRING "START www.google.com"
//void openWeb(){
//	size_t len = snprintf(NULL,0,FORMAT_STRING)+1;
//	char *cmd = (char*)malloc(len*sizeof(char));
//	snprintf(cmd,len,FORMAT_STRING);
//	system(cmd);
//	free(cmd);
//}
//int main(){
//	openWeb();
//	return 0;
//}