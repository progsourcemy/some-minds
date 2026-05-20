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

2026-05-19
			Optimize 
					include 2^n+1 
2026-05-20
			Some optimizations include in-place memory rollback and optimizations to comparison statements.
2026-05-21 
			Some optimizations.
*/

char globalbbb111=1;  /* 1   to  skip   print         */


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include <string.h>


inline __attribute__((always_inline))  void sort55555(int * ps111,int * pd111,int l222,int l333,int p11,int p12,int p13)
{
	int * l22222=0;int * l33333=0;int * temp111=0;int * temp222=0;int * temp333=0;int * ps333=0;int * l11111=0;
	/*l22222=ps111+p12+l222-1;l33333=ps111+p13+l333-1;temp111=pd111+p11;temp222=ps111+p12;temp333=ps111+p13;*/
	l22222=ps111+p12;l33333=ps111+p13;temp111=pd111+p11+l222+l333-1;temp222=ps111+p12+l222-1;temp333=ps111+p13+l333-1;l11111=pd111+p11;
	/*while(( temp222>=l22222 ) && ( temp333>=l33333 ))
	{
			if( *(temp222)>=*(temp333) )  {*(temp111)=*(temp222);temp222--;temp111--;continue;}
			else  						  {*(temp111)=*(temp333);temp333--;temp111--;continue;}
	}
	if( temp222<l22222 )
	{
			if(temp333>=l33333){  memcpy(l11111,l33333, (temp333-l33333+1) * sizeof(int)  );return;  }                   
			else{ return; }
	}
	if( temp333<l33333 )
	{
			if(temp222>=l22222){  memcpy(l11111,l22222, (temp222-l22222+1) * sizeof(int)  );return;  }              
			else{ return; }
	}*/



	lll222:
	if( *(temp222)>=*(temp333) ){  }else{ goto  lll333333; }
	lll222222:
	*(temp111)=*(temp222);temp222--;temp111--;if( temp222>=l22222){  goto  lll222;  };
	if(temp333>=l33333){  memcpy(l11111,l33333, (temp333-l33333+1) * sizeof(int)  );return;  }                   
	else{ return; }
	return;
	lll333:
	if( *(temp222)>=*(temp333) ){ goto  lll222222; }else{  }
	lll333333:
	*(temp111)=*(temp333);temp333--;temp111--;if( temp333>=l33333){  goto  lll333;  };
	if(temp222>=l22222){  memcpy(l11111,l22222, (temp222-l22222+1) * sizeof(int)  );return;  }              
	else{ return; }

	return;
}



inline __attribute__((always_inline))  void sort33333(int * ps111,int * pd111,int l222,int l333,int p11,int p12,int p13)
{
	int * l22222=0;int * l33333=0;int * temp111=0;int * temp222=0;int * temp333=0;
	l22222=ps111+p12+l222-1;l33333=pd111+p13+l333-1;temp111=pd111+p11;temp222=ps111+p12;temp333=pd111+p13;
	/*while(( temp222<=l22222 ) && ( temp333<=l33333 ))
	{
			if( *(temp222)<=*(temp333) )  {*(temp111)=*(temp222);temp222++;temp111++;continue;}
			else{*(temp111)=*(temp333);temp333++;temp111++;continue;}
	}
	if( temp222>l22222 )
	{
			return;
	}
	if( temp333>l33333 )
	{
			if(temp222<=l22222){  memcpy(temp111,temp222, (l22222-temp222+1) * sizeof(int)  );return;  }              
			else{ return; }
	}*/

	lll222:
	if( *(temp222)<=*(temp333) ){  }else{ goto  lll333333; }
	lll222222:
	*(temp111)=*(temp222);temp222++;temp111++;if( temp222<=l22222){  goto  lll222;  };
	return;
	lll333:
	if( *(temp222)<=*(temp333) ){ goto  lll222222; }else{  }
	lll333333:
	*(temp111)=*(temp333);temp333++;temp111++;if( temp333<=l33333){  goto  lll333;  };
	if(temp222<=l22222){  memcpy(temp111,temp222, (l22222-temp222+1) * sizeof(int)  );return;  }              
	else{ return; }

	return;
}


inline __attribute__((always_inline))  void sort22222(int * ps111,int * pd111,int l222,int l333,int p11,int p12,int p13)
{
	int * l22222=0;int * l33333=0;int * temp111=0;int * temp222=0;int * temp333=0;int * ps333=0;
	l22222=ps111+p12+l222-1;l33333=ps111+p13+l333-1;temp111=pd111+p11;temp222=ps111+p12;temp333=ps111+p13;
	
	/*while(( temp222<=l22222 ) && ( temp333<=l33333 ))
	{
			if( *(temp222)<=*(temp333) )  {*(temp111)=*(temp222);temp222++;temp111++;continue;}
			else{*(temp111)=*(temp333);temp333++;temp111++;continue;}
	}
	if( temp222>l22222 )
	{
			if(temp333<=l33333){  memcpy(temp111,temp333, (l33333-temp333+1) * sizeof(int)  );return;  }                   
			else{ return; }
	}
	if( temp333>l33333 )
	{
			if(temp222<=l22222){  memcpy(temp111,temp222, (l22222-temp222+1) * sizeof(int)  );return;  }              
			else{ return; }
	}*/

	lll222:
	if( *(temp222)<=*(temp333) ){  }else{ goto  lll333333; }
	lll222222:
	*(temp111)=*(temp222);temp222++;temp111++;if( temp222<=l22222){  goto  lll222;  };
	if(temp333<=l33333){  memcpy(temp111,temp333, (l33333-temp333+1) * sizeof(int)  );return;  }                   
	else{ return; }
	return;
	lll333:
	if( *(temp222)<=*(temp333) ){ goto  lll222222; }else{  }
	lll333333:
	*(temp111)=*(temp333);temp333++;temp111++;if( temp333<=l33333){  goto  lll333;  };
	if(temp222<=l22222){  memcpy(temp111,temp222, (l22222-temp222+1) * sizeof(int)  );return;  }              
	else{ return; }

	return;
}

void sort222(int * p,const int n)
{
	int * ps111=0;int * pd111=0;int * pt111=0;int * pt555=0;int  p11=0;int  p12=0;int  p13=0;int l222=0;int l333=0;int yl111=0;int y111=0;int yl222=0;int y222=0;int t111=0;int i111=0;int i222=0;int i333=0;int tempsw111=0;char yb111=0;int i=0;int i555=0;int * pt1111=0;int * pt1112=0;int * pt1113=0;int t222=0;int t333=0;char t666=0;char o111=0;char yb222=0;

	if(n<1){  return;  }
	if(n==1){  return;  }
	if(n==2)
	{
			if( *p > *(p+1) ){tempsw111=*p;*p=*(p+1);*(p+1)=tempsw111;}
			return;
	}
	if(n==3)
	{
			if( *p > *(p+1) ){tempsw111=*p;*p=*(p+1);*(p+1)=tempsw111;}
			if( *(p+1) > *(p+2) ){tempsw111=*(p+1);*(p+1)=*(p+2);*(p+2)=tempsw111;}else{return;}
			if( *p > *(p+1) ){tempsw111=*p;*p=*(p+1);*(p+1)=tempsw111;}
			return;
	}
	if(n==4)
	{
			if( *(p+1) > *(p+2) ){tempsw111=*(p+1);*(p+1)=*(p+2);*(p+2)=tempsw111;}
			if( *p > *(p+3) ){tempsw111=*p;*p=*(p+3);*(p+3)=tempsw111;}
			if( *p > *(p+2) ){tempsw111=*p;*p=*(p+1);*(p+1)=*(p+2);*(p+2)=tempsw111;return;}
			if( *(p+1) > *(p+3) ){tempsw111=*(p+3);*(p+3)=*(p+2);*(p+2)=*(p+1);*(p+1)=tempsw111;return;}
			if( *p > *(p+1) ){tempsw111=*p;*p=*(p+1);*(p+1)=tempsw111;}
			if( *(p+2) > *(p+3) ){tempsw111=*(p+2);*(p+2)=*(p+3);*(p+3)=tempsw111;}
			return;
	}
	ps111=p;
	pd111=malloc(n*sizeof(int));
	if(pd111==NULL){ printf("malloc111 error.\r\n");return;}
	pt555=pd111;
	yl222=(int)(n%4);
	y222=n-yl222;
	
	for(i=0;i<y222;i+=4)
	{
			pt111=ps111+i;
			pt1111=pt111+1;
			pt1112=pt111+2;
			pt1113=pt111+3;
			if( *(pt1111) > *(pt1112) ){tempsw111=*(pt1111);*(pt1111)=*(pt1112);*(pt1112)=tempsw111;}
			if( *pt111 > *(pt1113) ){tempsw111=*pt111;*pt111=*(pt1113);*(pt1113)=tempsw111;}
			if( *pt111 > *(pt1112) ){tempsw111=*pt111;*pt111=*(pt1111);*(pt1111)=*(pt1112);*(pt1112)=tempsw111;continue;}
			if( *(pt1111) > *(pt1113) ){tempsw111=*(pt1113);*(pt1113)=*(pt1112);*(pt1112)=*(pt1111);*(pt1111)=tempsw111;continue;}
			if( *pt111 > *(pt1111) ){tempsw111=*pt111;*pt111=*(pt1111);*(pt1111)=tempsw111;}
			if( *(pt1112) > *(pt1113) ){tempsw111=*(pt1112);*(pt1112)=*(pt1113);*(pt1113)=tempsw111;}
	}
	
	if( yl222 > 0 )
	{		/*   ----------------   有余数  yl222      ----------------------   */
			yb111=1;pt111=ps111+y222;
			if(yl222==1){   }
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
	}

	t111=4;t222=8;o111=1;
	
	while( ( t222 ) <= n )
	{	
			yl111=(int)( n%( t222 ) );
			y111=n-yl111;
			if( yl111 > 0 )
			{		/*   ----------------   有余数  yl111      ----------------------   */
					if(yb111==1)
					{		/*   ----------------   上次本次都有余数     ----------------------   */
							if( y111!=y222 )
							{		/*   ----------------   上次本次都有余数  且上次和本次的余数不同     ----------------------   */
								
									if(t666==1){  yb222=2;t666=0;  }else{  yb222=3;t666=0;  }
							}
							else
							{		/*   ----------------   上次本次都有余数  且余数相同     ----------------------   */

									if(t666==0)
									{
											yb222=5;
											t666=1;
											/*   ----------------   需要三列合并  设置标志  		按目前的情况是 三个数列  A B C     A 与 B  数目相同    C 规模较小, C 应该是真正的余数部分 ,先合并 B C 成为 D  数列,此时开始对 A 与 D 进行特殊合并排序,开始的目标缓存是对面缓存的  数列  A 的对应部分,这样进行应该会完成     ----------------------   */
											
											/*  余数部分与 t111 块的合并排序  */
											
											/*  余数部分与 t111 块的合并排序后与另一个 t111 块合并排序  */
										
									}else
									{		
											/*  上次也是三列合并  */
											yb222=4;
									}
							}
					}
					else
					{		/*   ----------------   如果  本次  有余数  而  上次  没有余数     ----------------------   */
							yb222=1;
					}
			}
			else{    }    /* 无余数  */
			
			if(    ( o111==1 ) && ( yb222!=0 )    ){  goto  ysk111;  }
			
qbk111:		/*  前部块代码段  */

			if(o111==0)  /*  顺序  */
			{
					i555=y111-t222*t666;
					for(i222=0;i222<i555;i222+=t222)
					{
							sort22222(ps111,pd111,t111,t111,i222,i222,i222+t111);
					}
			}
			else if (o111==2)  /*  倒序  */
			{
					i555=y111-t222*t666-t222;
					for(i222=i555;i222>=0;i222-=t222)
					{
							sort55555(ps111,pd111,t111,t111,i222,i222,i222+t111);
					}
					goto  jw111;  /*  逆序前部段处理完成 跳转本次循环结尾处理段  */
			}
			else
			{  /*  无余数  且是倒序处理  跳转次循环结尾处理段*/

						i555=y111-t222*t666-t222;
						for(i222=i555;i222>=0;i222-=t222)
						{
								sort55555(ps111,pd111,t111,t111,i222,i222,i222+t111);
						}
						goto  jw111; 
			}  

			
			
ysk111:		/*  余数块代码段  */


			if(yb222==1)  /*   本次有余数上次无余数   */
			{
					memcpy(pd111+y111,ps111+y111,yl111*sizeof(int));
					yb111=1;yl222=yl111;y222=y111;
			}
			if(yb222==2)  /*   本次上次  都有余数  且  余数有变化  但是上次    是      三列合并   */
			{
					memcpy(pd111+y111,ps111+y111,yl111*sizeof(int));
					yl222=yl111;y222=y111;
			}
			if(yb222==3)  /*   本次上次  都有余数  且  余数有变化  但是上次    不是     三列合并   */
			{
					p11=y111;p12=y111;p13=y222;l222=t111;l333=yl222;
					if(o111==0)   {  sort22222(ps111,pd111,l222,l333,p11,p12,p13);  }
					else          {  sort55555(ps111,pd111,l222,l333,p11,p12,p13);  }
					yl222=yl111;y222=y111;
			}
			if(yb222==4)  /*   本次上次  都有余数  且  余数无变化  但是上次    是      三列合并   */
			{
					p11=y111-t222;p12=p11;p13=y222-t111;
					if(o111==0)   {  sort22222(ps111,pd111,t111,t111+yl222,p11,p12,p13);  }
					else          {  sort55555(ps111,pd111,t111,t111+yl222,p11,p12,p13);  }
			}
			if(yb222==5)  /*   本次上次  都有余数  且  余数无变化  但是上次    不是     三列合并   */
			{
					/*  余数部分与 t111 块的合并排序  */
					p11=y111-t111;p12=p11;p13=y222;/*l111=yl111;*/l222=t111;l333=yl222;


					if(o111==0)   {  sort22222(ps111,pd111,t111,l333,p11,p12,p13);  }
					else          {  sort55555(ps111,pd111,t111,l333,p11,p12,p13);  }
			
					/*  余数部分与 t111 块的合并排序后与另一个 t111 块合并排序  */
					p11=p11-t111;p12=p11;p13=p13-t111;/*l111=yl111;l222=t111;l333=t111+yl222;*/
					sort33333(ps111,pd111,t111,t111+yl222,p11,p12,p13);
			}

			if( o111==1 ){  o111=2;  goto  qbk111;  }


jw111:
			/*for(i222=0;i222<i555;i222+=t222)
			{
					sort22222(ps111,pd111,t111,t111,i222,i222,i222+t111);
			}*/
			if(o111!=0){  o111=0;  }else{  o111=1;  }
			pt111=ps111;  ps111=pd111;  pd111=pt111;  t111=t111*2;  t222=t111*2;
		
	}
	if(yb111==1)
	{
			if(t666==1){goto cxi333;}


			if(o111==0)   {  sort22222(ps111,pd111,t111,yl222,0,0,y222);  }
			else          {  sort55555(ps111,pd111,t111,yl222,0,0,y222);  }



			
			ps111=pd111;
			cxi333:
	}
	
	if(p!=ps111){  memcpy(p,ps111,n*sizeof(int));  }else{    }
	
	if(globalbbb111){  goto  cxttt111;    }	
	
	if(n<15)
	{
			for(  i111=0;  i111<n;  i111++  ){  printf("jjjjjjjjjjjjjj---%d---\n",*(p+i111));  }
	}
	else
	{
			printf("jjjjjjjjjjjjjj---%d---\n",*(p));
			printf("jjjjjjjjjjjjjj---%d---\n",*(p+1));
			printf("jjjjjjjjjjjjjj---%d---\n",*(p+2));
			i222=n/2-1;i333=i222+2;
			for(  i111=i222;  i111<i333;  i111++  ){  printf("jjjjjjjjjjjjjj---%d---------\n",*(p+i111));  }
			printf("jjjjjjjjjjjjjj---%d------------------\n",*(p+n-3));
			printf("jjjjjjjjjjjjjj---%d------------------\n",*(p+n-2));
			printf("jjjjjjjjjjjjjj---%d------------------\n",*(p+n-1));
	}

cxttt111:	

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


	*(p+0)=17;*(p+1)=16;*(p+2)=15;*(p+3)=14;*(p+4)=13;*(p+5)=12;*(p+6)=11;*(p+7)=10;*(p+8)=9;*(p+9)=8;
	*(p+10)=7;*(p+11)=6;*(p+12)=5;*(p+13)=4;*(p+14)=3;*(p+15)=2;*(p+16)=1;*(p+17)=983;*(p+18)=982;*(p+19)=981;
	*(p+20)=980;*(p+21)=979;*(p+22)=978;*(p+23)=977;*(p+24)=976;*(p+25)=975;*(p+26)=974;*(p+27)=973;*(p+28)=972;*(p+29)=971;
	*(p+30)=80;*(p+31)=80;

	
	sort222(p,17);
	
	
	for(  i111=0;  i111<17;  i111++  )
	{
				printf("jjjjjjjjjjjjjj---%d---\n",*(p+i111));
	}
	free(p);
	return intreturn;
}

