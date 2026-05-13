/*A Simple Iterative Merge-Based Sorting Method

This is a simple sorting method I designed while thinking about binary decomposition properties such as:

1161 = 2^10 + 2^7 + 2^3 + 1
33347 = 2^15 + 2^9 + 2^6 + 3

The core idea is to construct ordered blocks whose sizes grow approximately as powers of two.

Basic Idea
Split the array into many groups of four elements.
Sort each 4-element group independently.
Handle the remaining elements (if the total length is not divisible by 4).
Merge adjacent sorted groups:
4 + 4 -> 8
8 + 8 -> 16
16 + 16 -> 32
...
Continue until the whole array becomes sorted.

The method is iterative rather than recursive.

Characteristics
Advantages
Sequential memory access during merge stages
Cache-friendly behavior
Stable sorting behavior
No recursive calls
Small initial blocks can be optimized manually
Suitable for low-level C implementations
Notes

This method is conceptually related to bottom-up merge sort, but starts from pre-sorted small fixed-size blocks (in this implementation, blocks of four elements).

The implementation may benefit from:

branch prediction improvements
SIMD/vector optimization
specialized small-block sorting
parallel merging

depending on hardware and compiler behavior.

Motivation

The idea came from observing that many large ordered structures can be constructed progressively from smaller power-of-two-sized components.

Instead of starting from single elements, this method begins with small sorted blocks and repeatedly merges neighboring ordered regions.

License / Usage

I do not place copyright restrictions on this idea or implementation.

Anyone may:

use it
modify it
optimize it
integrate it into other projects
publish derived implementations

at their own discretion.

This is only a technical exploration and experiment.

*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>
inline __attribute__((always_inline))  void sort22222(int * ps111,int * pd111,int l111,int l222,int l333,int p11,int p12,int p13)
{
	int i333=0;int l22222=0;int l33333=0;int i555=0;
	l22222=p12+l222-1;l33333=p13+l333-1;
	for(i333=0;i333<l111;i333++)
	{
			if( ( p12>l22222 ) || ( p13>l33333 ) )
			{
					if( p12>l22222 )
					{
							if(p13<=l33333){  memcpy(pd111+p11,ps111+p13, (l33333-p13+1) * sizeof(int)  );return;  }                   
							else{ return; }
					}
					if( p13>l33333 )
					{
							if(p12<=l22222){  memcpy(pd111+p11,ps111+p12, (l22222-p12+1) * sizeof(int)  );return; ;  }              
							else{ return; }
					}
			}
			if( *(ps111+p12)<*(ps111+p13) )  {*(pd111+p11)=*(ps111+p12);p12++;p11++;continue;}
			else if( *(ps111+p12)>*( ps111+p13) )  {*(pd111+p11)=*(ps111+p13);p13++;p11++;continue;}
			else{*(pd111+p11)=*(ps111+p12);p12++;p11++;*(pd111+p11)=*(ps111+p13);p13++;p11++;continue;}
	}
	return;
}

void sort222(int * p,const int n)
{

	int * ps111=0;int * pd111=0;int * pt111=0;int * pt555=0;int  p11=0;int  p12=0;int  p13=0;int l111=0;int l222=0;int l333=0;int yl111=0;int y111=0;int yl222=0;int y222=0;int t111=0;int i111=0;int i222=0;int i333=0;int tempsw111=0;char yb111=0;char b11111=1;int s111=0;int i=0;int i555=0;


	ps111=p;

	
	if(n<1){  return;  }
	if(n==1){  return;  }
	
	pd111=malloc(n*sizeof(int));
	pt555=pd111;
	if(pd111==NULL){ printf("malloc111 error.\r\n");return;}
	s111=(int)(n/4);
	yl222=(int)(n%4);
	if( yl222 > 0 )
	{
			y222=n-yl222;yb111=1;pt111=ps111+y222;
			if(yl222==1)
			{
			}
			else if(yl222==2)
			{
				if( *pt111 > *(pt111+1) ){tempsw111=*pt111;*pt111=*(pt111+1);*(pt111+1)=tempsw111;}
			}
			else if(yl222==3)
			{
				if( *pt111 > *(pt111+1) ){tempsw111=*pt111;*pt111=*(pt111+1);*(pt111+1)=tempsw111;}
				if( *(pt111+1) > *(pt111+2) ){tempsw111=*(pt111+1);*(pt111+1)=*(pt111+2);*(pt111+2)=tempsw111;}else{goto  cx555;}
				if( *pt111 > *(pt111+1) ){tempsw111=*pt111;*pt111=*(pt111+1);*(pt111+1)=tempsw111;}
			}
			
			cx555:

			memcpy(pd111+y222,ps111+y222,yl222*sizeof(int));
	}

	for(i=0;i<s111;i++)
	{
			pt111=ps111+i*4;
			if( *(pt111+1) > *(pt111+2) ){tempsw111=*(pt111+1);*(pt111+1)=*(pt111+2);*(pt111+2)=tempsw111;}
			if( *pt111 > *(pt111+3) ){tempsw111=*pt111;*pt111=*(pt111+3);*(pt111+3)=tempsw111;}
			if( *pt111 > *(pt111+2) ){tempsw111=*pt111;*pt111=*(pt111+1);*(pt111+1)=*(pt111+2);*(pt111+2)=tempsw111;continue;}
			if( *(pt111+1) > *(pt111+3) ){tempsw111=*(pt111+3);*(pt111+3)=*(pt111+2);*(pt111+2)=*(pt111+1);*(pt111+1)=tempsw111;continue;}
			if( *pt111 > *(pt111+1) ){tempsw111=*pt111;*pt111=*(pt111+1);*(pt111+1)=tempsw111;}
			if( *(pt111+2) > *(pt111+3) ){tempsw111=*(pt111+2);*(pt111+2)=*(pt111+3);*(pt111+3)=tempsw111;}
	}

	t111=4;
	
	while( ( t111*2 ) <= n )
	{	
			s111=(int)( n/( t111*2 ) );
			yl111=(int)( n%( t111*2 ) );

			if( yl111 > 0 )
			{
					y111=n-yl111;
					if(yb111==1)
					{
							if( y111!=y222 )
							{
									p11=y111;p12=y111;p13=n-yl222;l111=yl111;l222=yl111-yl222;l333=yl222;
									sort22222(ps111,pd111,l111,l222,l333,p11,p12,p13);
									memcpy(ps111+y111,pd111+y111,yl111*sizeof(int));
									yl222=yl111;y222=y111;
							}
					}
					else{memcpy(pd111+y111,ps111+y111,yl111*sizeof(int));yb111=1;yl222=yl111;y222=y111;}
			}
			for(i222=0;i222<s111;i222++)
			{
					sort22222(ps111,pd111,t111*2,t111,t111,i222*t111*2,i222*t111*2,i222*t111*2+t111);
			}
			pt111=ps111;  ps111=pd111;  pd111=pt111;  t111=t111*2;
		
	}

	if(yb111==1)
	{
			sort22222(ps111,pd111,n,t111,yl222,0,0,y222);
			ps111=pd111;
	}
	if(p!=ps111){     memcpy(p,ps111,n*sizeof(int));  }else{     }
	
	free(pt555);

	return;
}

int main(int argc, char *argv[])
{
	int  intreturn=0;
	int * p;
	int i111=0;
	
	p=malloc(32*sizeof(int));
	if(p==NULL){ printf("malloc111 error.\r\n");return  -1;}
	
/*	*(p+0)=1209;*(p+1)=9108;*(p+2)=6107;*(p+3)=103;*(p+4)=103;*(p+5)=105;*(p+6)=105;*(p+7)=107;*(p+8)=108;*(p+9)=1109;
	*(p+10)=699;*(p+11)=367;*(p+12)=590;*(p+13)=6107;*(p+14)=722;*(p+15)=988;*(p+16)=766;*(p+17)=218;*(p+18)=916;*(p+19)=999;
	*(p+20)=253;*(p+21)=523;*(p+22)=333;*(p+23)=555;*(p+24)=729;*(p+25)=6107;*(p+26)=866;*(p+27)=219;*(p+28)=9699999;*(p+29)=909;*/


	*(p+0)=1000;*(p+1)=999;*(p+2)=998;*(p+3)=997;*(p+4)=996;*(p+5)=995;*(p+6)=994;*(p+7)=993;*(p+8)=992;*(p+9)=991;
	*(p+10)=990;*(p+11)=989;*(p+12)=988;*(p+13)=987;*(p+14)=986;*(p+15)=985;*(p+16)=984;*(p+17)=983;*(p+18)=982;*(p+19)=981;
	*(p+20)=980;*(p+21)=979;*(p+22)=978;*(p+23)=977;*(p+24)=976;*(p+25)=975;*(p+26)=974;*(p+27)=973;*(p+28)=972;*(p+29)=971;
	*(p+30)=80;*(p+31)=80;

	
	sort222(p,32);
	
	
	for(  i111=0;  i111<32;  i111++  )
	{
				printf("jjjjjjjjjjjjjj---%d---\n",*(p+i111));
	}
	free(p);
	return intreturn;
}

