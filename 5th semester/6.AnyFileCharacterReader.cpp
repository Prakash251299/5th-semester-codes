#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fs;
    int ch;

    fs = fopen("C:/Users/Ishu/Desktop/ticket.pdf","rb");
    if(fs==NULL)
    {
        puts("Unable to open source!");
        exit(1);
    }

    while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF) break;
//        fputc(ch,ft);
    	printf("%d ",ch); // It prints all the characters of the jpg file
	}
    fclose(fs);
    return 0;
}