#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char * temp1;
	char * temp2;
	char * temp3;
	char * temp4;
	temp1=(char *)malloc(7);
	temp1[0]='H';  temp1[1]='e';  temp1[2]='l';  temp1[3]='l';  temp1[4]='o';  temp1[5]=' ';  temp1[6]=0;
	temp2=(char *)malloc(7);
	temp2[0]='w';  temp2[1]='o';  temp2[2]='r';  temp2[3]='l';  temp2[4]='d';  temp2[5]='.';  temp2[6]=0;
	temp4=(char *)malloc(2);
	temp4[0]='\r';  temp4[1]='\n';
	printf("%s",temp1);
	temp3=temp4;
	temp4=temp1;
	free(temp4);
	temp1=temp2;
	temp2=temp3;
	printf("%s",temp1);
	temp3=temp2;
	temp2=temp1;
	free(temp2);
	temp1=temp3;
	printf("%s",temp1);
	free(temp1);
	return 0;
}
