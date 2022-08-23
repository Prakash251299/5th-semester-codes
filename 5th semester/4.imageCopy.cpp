#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fs,*ft;
    int ch;

    fs=fopen("C:/Users/Ishu/Desktop/rd.jpg","rb");
    if(fs==NULL)
    {
        puts("Unable to open source!");
        exit(1);
    }
    ft=fopen("C:/Users/Ishu/Desktop/abc.jpg","wb");
    if(ft==NULL)
    {
        puts("Unable to copy!");
        fclose(fs);
        exit(2);
    }

    while(1)
    {
        ch=fgetc(fs);
        if(ch==EOF) break;
        fputc(ch,ft);
//    	printf("%d ",ch); // It prints all the characters of the jpg file
	}
    fclose(fs);
    fclose(ft);
    return 0;
}