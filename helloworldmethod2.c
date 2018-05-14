#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main(int argc, char *argv[])
{
	int  intreturn=0;
	char * temp1;
	char * temp2;
	char * temp4;
	temp1=(char *)malloc(7);
	if(temp1==NULL)
	{
		printf("Malloc error.\r\n");
		intreturn=-1;
		goto proceerror1;
	}
	else
	{
	}
	temp1[0]='H';  temp1[1]='e';  temp1[2]='l';  temp1[3]='l';  temp1[4]='o';  temp1[5]=' ';  temp1[6]=0;
	temp2=(char *)malloc(7);
	if(temp2==NULL)
	{
		printf("Malloc error.\r\n");
		intreturn=-1;
		goto proceerror2;
	}
	else
	{
	}
	temp2[0]='w';  temp2[1]='o';  temp2[2]='r';  temp2[3]='l';  temp2[4]='d';  temp2[5]='.';  temp2[6]=0;
	temp4=(char *)malloc(3);
	if(temp4==NULL)
	{
		printf("Malloc error.\r\n");
		intreturn=-1;
		goto proceerror3;
	}
	else
	{
	}
	temp4[0]='\r';  temp4[1]='\n';  temp4[2]=0;
	if( printf("%s",temp1)<0 )
	{
		intreturn=-1;
		goto proceerror4;
	}
	else 
	{
	}
	free(temp1);
	if( printf("%s",temp2)<0 )
	{
		intreturn=-1;
		goto proceerror5;
	}
	else 
	{
	}
	free(temp2);
	if( printf("%s",temp4)<0 )
	{
		intreturn=-1;
		goto proceerror6;
	}
	else 
	{
	}
	free(temp4);
	goto proceerrorend;
	proceerror1:
	return intreturn;
	proceerror2:
	free(temp1);
	return intreturn;
	proceerror3:
	free(temp1);
	free(temp2);
	return intreturn;
	proceerror4:
	free(temp1);
	free(temp2);
	free(temp4);
	return intreturn;
	proceerror5:
	free(temp2);
	free(temp4);
	return intreturn;
	proceerror6:
	free(temp4);
	return intreturn;
	proceerrorend:
	return intreturn;
}

