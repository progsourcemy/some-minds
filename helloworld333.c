#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int main(int argc, char *argv[])
{
	OnlyMnemonicTolabeltemp0:;
	int  tempreturn;
	char * temp1;
	char * temp2;
	char * temp3;
	char * temp4;
	tempreturn=0;
	temp1=(char *)malloc(7);
	if(temp1==NULL)
	{
		printf("Malloc error.\r\n");
		tempreturn=-1;
		goto labeltemp0;
	}
	else
	{
	}
	OnlyMnemonicTolabeltemp1:
	temp1[0]='H';  temp1[1]='e';  temp1[2]='l';  temp1[3]='l';  temp1[4]='o';  temp1[5]=' ';  temp1[6]=0;
	temp2=(char *)malloc(7);
	if(temp2==NULL)
	{
		printf("Malloc error.\r\n");
		tempreturn=-1;
		goto labeltemp1;
	}
	else
	{
	}
	OnlyMnemonicTolabeltemp2:
	temp2[0]='w';  temp2[1]='o';  temp2[2]='r';  temp2[3]='l';  temp2[4]='d';  temp2[5]='.';  temp2[6]=0;
	temp4=(char *)malloc(2);
	if(temp4==NULL)
	{
		printf("Malloc error.\r\n");
		tempreturn=-1;
		goto labeltemp2;
	}
	else
	{
	}
	OnlyMnemonicTolabeltemp4:
	temp4[0]='\r';  temp4[1]='\n';
	if( printf("%s",temp1)<0 )
	{
		tempreturn=-1;
		goto labeltemp4;
	}
	else 
	{
	}
	labeltemp4:
	temp3=temp4;
	temp4=temp1;
	free(temp4);
	temp1=temp2;
	temp2=temp3;
	if(tempreturn==-1)
	{
		goto labeltemp2;
	}
	else
	{
	}
	if( printf("%s",temp1)<0 )
	{
		tempreturn=-1;
		goto labeltemp2;
	}
	else 
	{
	}
	labeltemp2:
	temp3=temp2;
	temp2=temp1;
	free(temp2);
	temp1=temp3;
	if(tempreturn==-1)
	{
		goto labeltemp1;
	}
	else
	{
	}
	if( printf("%s",temp1)<0 )
	{
		tempreturn=-1;
		goto labeltemp1;
	}
	else 
	{
	}
	labeltemp1:
	free(temp1);
	labeltemp0:;
	return tempreturn;
}

