/*



Please note that the use of this document may require some knowledge of computers or mathematics. I have no copyright claims or restrictions, and of course, I cannot guarantee against any potential losses.







A Simple Iterative Merge-Based Sorting Method

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
2026-06-05
			Performance optimization and security enhancement
			
			old  cpu  For reference only   x86_64 Linux  -O3 -march=native
					this sort222  performance
							1 million Array
									fast
											a Quicksort  	9.61%
											lib   qsort     35.29%  
							10 million Array
									fast
											a Quicksort  	7.84%
											lib   qsort     34.68% 
							100 million Array
									fast
											a Quicksort  	3.28%
											lib   qsort     33.56%

			2026-06-07
					a virtual private serve
							a Quicksort  fast  sort222  2.5418%
										

*/

char globalbbb111=1;  /* 1   to  skip   print         */


#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
/*#include<malloc.h>*/
#include <string.h>

inline __attribute__((always_inline))  void sort55555xxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{
		int * temp111;  int * temp222;  int * temp333;  size_t temp555=l222-1;

		temp111=pd111+temp555+l333;  temp333=pd111+(l333-1);  temp222=ps111+temp555;

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=ps111  ){  temp222--;  temp111--;  goto  lll222;  }
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if( temp333!=pd111){  temp333--;  temp111--;  goto  lll333;  }
		if(  temp222>=ps111  ){  memcpy(  pd111,ps111,( ( temp222-ps111 )+1 ) * sizeof( int )  );  return;  }

		return;
}



inline __attribute__((always_inline))  void sort22222xxx(  int  *restrict  ps111,  int  *restrict pd111,  size_t l222,  size_t l333  )
{
		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;  size_t laaa;

		laaa=l222+l222;l22222=(l222-1)+ps111;  temp333=ps111+laaa;  l33333=(temp333-1)+l333;  temp111=pd111;  temp222=ps111;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof(int)  );  return;  }
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }

		return;
}


inline __attribute__((always_inline))  void sortxxxxxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l555)
{
		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;  int * l11111;

		l33333=(ps111-l222)+1;  l22222=l33333-l555;  temp111=pd111;  temp333=ps111;  temp222=l22222+l222-1;  l11111=pd111-l222-l222+1;

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  )  {  temp222--;  temp111--;  goto  lll222;  }
		if(  temp333>=l33333  ){  memcpy(  l11111,l33333,( ( temp333-l33333 )+1 ) * sizeof( int ) );  return;  }
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  )  {  temp333--;  temp111--;  goto  lll333;  }
		if(  temp222>=l22222  ){  memcpy(  l11111,l22222,( ( temp222-l22222 )+1 ) * sizeof( int ) );  return;  }

		return;
}

inline __attribute__((always_inline))  void sortxxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l555)  /*类型扩展*/
{
		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;

		l22222=ps111+(l222-1);  l33333=l22222+l555;  temp111=pd111;  temp222=ps111;  temp333=temp222+l555;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof( int )  );  return;  }                   
		return;

		lll333:

		if( *(temp222)<=*(temp333) ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }
		return;
}


inline __attribute__((always_inline))  void sort55555(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{
		int * l33333;  int * temp111;  int * temp222;  int * temp333;  size_t laaa;

		laaa=(l222-1)+l333;  l33333=ps111+l222;  temp111=pd111+laaa;  temp333=ps111+laaa;  temp222=temp333-l333;

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=ps111  ){  temp222--;  temp111--;  goto  lll222;  }
		if(  temp333>=l33333  ){  memcpy(  pd111,l33333,( ( temp333-l33333 )+1 ) * sizeof( int )  );  return;  }
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if( temp333!=l33333){  temp333--;  temp111--;  goto  lll333;  }
		if(  temp222>=ps111  ){  memcpy(  pd111,ps111,( ( temp222-ps111 )+1 ) * sizeof( int )  );  return;  }

		return;
}

inline __attribute__((always_inline))  void sort33333(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{
		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;  size_t laaa;
		
		laaa=l222-1;  l22222=ps111+laaa;  l33333=pd111+laaa+l333;  temp111=pd111;  temp222=ps111;  temp333=pd111+l222;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof(int)  );return;  }

		return;
}

inline __attribute__((always_inline))  void sort22222(int  *restrict  ps111,int  *restrict pd111,size_t l222,size_t l333)
{
		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;
		
		l22222=(l222-1)+ps111;  l33333=l22222+l333;  temp111=pd111;  temp222=ps111;  temp333=l22222+1;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof(int)  );  return;  }
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }

		return;
}

int sort222(int * p,const size_t n)
{
		int * ps111=0;  int * pd111=0;  int * pt111=0;  int * pt555=0;    size_t  p11=0;  size_t yl111=0;  size_t y111=0;  size_t yl222=0;  size_t y222=0;  size_t t111=0;  int tempsw111=0;  /*  前面内容  扩展类型相关  */  size_t i=0;  size_t i222=0;  int * pt1111=0;  int * pt1112=0;  int * pt1113=0;  size_t t222=0;  char t666=0;  char o111=0;  char yb222=0;  size_t nd222=0;  size_t  p12=0;  /*  size_t i666=0;  size_t i333=0;  char t777=0;  char i555=0;  size_t i777=0;  */  size_t i888=0;  int * p15=0;
		
		if(      n    >    (SIZE_MAX/(sizeof(int)))  /*  前面内容  扩展类型相关  */    )    {  return -1;  }    /*  避免溢出  */

		if(n==0){  return 0;  }
		
		ps111=p;   /*  用本函数内变量保存传入数据块指针  */
		
		pd111=malloc(n*sizeof(int));  /*  尝试分配内存  */  /*  前面内容  扩展类型相关  */
		
		if(  pd111==NULL  ){  printf("malloc111 error.\r\n");  return -1;  }  /*  内存分配如果失败,返回 -1  */
		
		pt555=pd111;    /*  由于  ps111  与  pd111  可能需要频繁交换,所以用一个 指针保存分配的内存地址用以将来释放内存  */
		yl222=(size_t)(n%4);  /*  数列元素个数 相对于 4 的余数  */
		y222=n-yl222;		  /*  是不是 不大于数列元素个数的最大的 4 的倍数,是否需要明确限定条件  */
		
		for(  i=0;  i<y222;  i+=4  )  /*  尽量顺序对整体数列的中的四个元素的数据块排序  */
		{
				pt111=ps111+i;
				pt1111=pt111+1;
				pt1112=pt111+2;
				pt1113=pt111+3;
				if(  *(pt1111) > *(pt1112)  ){  tempsw111=*(pt1111);  *(pt1111)=*(pt1112);  *(pt1112)=tempsw111;  }
				if(  *pt111 > *(pt1113)  ){  tempsw111=*pt111;  *pt111=*(pt1113);  *(pt1113)=tempsw111;  }
				if(  *pt111 > *(pt1112)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=*(pt1112);  *(pt1112)=tempsw111;  continue;  }
				if(  *(pt1111) > *(pt1113)  ){  tempsw111=*(pt1113);  *(pt1113)=*(pt1112);  *(pt1112)=*(pt1111);  *(pt1111)=tempsw111;  continue;  }
				if(  *pt111 > *(pt1111)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=tempsw111;  }
				if(  *(pt1112) > *(pt1113)  ){  tempsw111=*(pt1112);  *(pt1112)=*(pt1113);  *(pt1113)=tempsw111;  }
		}
		
		if( yl222 > 0 )
		{		/*   ----------------   有余数    对余数部分排序   ----------------------   */

				yb222=1;  pt111=ps111+y222;
				
				if(  yl222==1  )  {  goto cx555;  }
				
				if(  yl222==2  )
				{
					pt1111=pt111+1;
					if(  *pt111 > *(pt1111)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=tempsw111;  goto cx555;  }
					goto cx555;
				}
				
				if(  yl222==3  )
				{
					pt1111=pt111+1;  pt1112=pt111+2;
					if(  *pt111 > *(pt1111)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=tempsw111;  }
					if(  *(pt1111  ) > *(pt1112)  ){  tempsw111=*(pt1111);  *(pt1111)=*(pt1112);  *(pt1112)=tempsw111;  }  else  {  goto cx555;  }
					if(  *pt111 > *(pt1111)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=tempsw111;  goto cx555;  }
					goto cx555;
				}

				cx555:

		}

		t111=4;  t222=8;  o111=1;  nd222=n/2;

		if(  t222>n  ){  goto rel111;  }

		rel222:

		yl111=(size_t)( n%( t222 ) );
		y111=n-yl111;
		if(  yl111 > 0  )
		{		/*   ----------------   有余数  ----------------------   */
				if(  yb222!=0  )
				{		/*   ----------------   上次本次都有余数     ----------------------   */
						if(  y111!=y222  )
						{		/*   ----------------   上次本次都有余数  且上次和本次的余数不同     ----------------------   */

								if(  t666==1  ){  yb222=2;  t666=0;  }  else  {  yb222=3;  }
						}
						else
						{		/*   ----------------   上次本次都有余数  且余数相同     ----------------------   */

								if(  t666==0  )
								{
										yb222=5;
										t666=1;
								}else
								{		
										/*  上次也是余数相同  */
										yb222=4;
								}
						}
				}
				else
				{		/*   ----------------   本次  有余数  而  上次  没有余数     ----------------------   */
						yb222=1;
				}
		}
				
		if(  ( o111==1 ) && ( yb222!=0 )  ){  goto ysk111;  }    /*  内存尽量逆序访问 且余数不为零  */

		qbk111:		/*  前部数据块  处理代码段  */

		if(  o111==0  )  /*  内存尽量顺序访问  */
		{
				i=y111-t222*t666;  /*i333=i/t222;  i555=i333%2;*/
				/*if(  i==t222  ){  sortxxx(ps111,pd111,t111,0);  t777=1;  t777=1;  goto  ysk111;  }*/
				/*if(  i555==0  )
				{
						t777=0;
				}
				else
				{
						sortxxx(ps111,pd111,t111,0);  t777=1;
				}*/
				i888=i/2;  p15=pd111;
				for(  i222=0;  i222<i888;  i222+=t111  )
				{
						sortxxx(ps111+i222,p15,t111,i888);
						p15+=t222;
				}
		}
		else
		{		/*  特别注意 由大向小的循环判断 0  */
				/*  内存尽量逆序访问  有余数或无余数的情况  注意,此时应该对可能造成 size_t  成为负值倾向的情况进行规避.  对应的是  o111==1  且无余数 ,,,或者   o111==2   经过分析此分支完成后直接跳转  jw111  */
			
				i=y111-t222*t666;  /*i333=i/t222;  i555=i333%2;*/
				/*if(  i==t222  ){  sortxxxxxx(ps111+i,pd111+i,t111,0);  t777=1;  goto  jw111;  }*/
				/*if(  i555==0  )
				{
						t777=0;
				}
				else
				{
						sortxxxxxx(ps111+i,pd111+i,t111,0);  t777=1;
				}*/
				if(  i==0  )  {  goto  jw111;  }
				i888=i/2;  p15=pd111+(i-1);
				for(  i222=i-1;  i222>i888;  i222-=t111  )
				{
						sortxxxxxx(ps111+i222,p15,t111,i888);
						p15-=t222;
				}
				goto  jw111;  /*  前部数据段 处理完成    跳转本次循环结尾处理段  */
		}

		ysk111:		/*  余数数据块  处理代码段  */

		if(  yb222==5  )  /*   本次上次  都有余数  且  余数无变化  且  上次    不是     余数相同   注意  需要三列合并  */
		{

				/*   ----------------   需要三列合并    		按目前的情况是 三个数列  A B C     A 与 B  数目相同    C 规模较小, C 应该是真正的余数部分 ,先合并 B C 成为 D  数列,此时开始对 A 与 D 进行特殊合并排序,开始的目标缓存是对面缓存的  数列  A 的对应部分,这样进行应该会完成     ----------------------   */

				/*  余数部分与相邻 t111 块的合并排序  */
				p11=y111-t111;  p12=p11-t111;

				if(  o111==0  )
				{
						sort22222xxx(  ps111+p12,  pd111+p12,  t111,  yl111  );
						sort55555xxx(  ps111+p11,  pd111+p12,  t111,   t111+yl111  );

				}
				else
				{
						sort55555(  ps111+p11,  pd111+p11,  t111,  yl111  );
						sort33333(  ps111+p12  ,pd111+p12  ,t111,  t111+yl111  );
				}
				
				goto yskeee111;
		}
		if(yb222==3)  /*   本次上次  都有余数  且  余数有变化  且  上次    不是     余数相同   */
		{
				if(o111==0)   {  sort22222(  ps111+y111,  pd111+y111,  t111,  yl222  );  }
				else          {  sort55555(  ps111+y111,  pd111+y111,  t111,  yl222  );  }
				yl222=yl111;  y222=y111;
				goto yskeee111;
		}
		if(  yb222==2  )  /*   本次上次  都有余数  且  余数有变化  且  上次    是      余数相同   */
		{
				memcpy(  pd111+y111,  ps111+y111,  yl111*sizeof( int )  );  /*  扩展类型相关  */
				yl222=yl111;  y222=y111;
				goto yskeee111;
		}
		if(yb222==4)  /*   本次上次  都有余数  且  余数无变化  且  上次    是      余数相同   */
		{
				p11=y111-t222;
				if(  o111==0  )  {  sort22222(  ps111+p11,  pd111+p11,  t111,  t111+yl111  );  }
				else             {  sort55555(  ps111+p11,  pd111+p11,  t111,  t111+yl111  );  }
				goto yskeee111;
		}
		if(  yb222==1  )  /*   本次有余数上次无余数   */
		{
				memcpy(  pd111+y111,  ps111+y111,  yl111*sizeof( int )   );  /*  扩展类型相关  */
				yl222=yl111;  y222=y111;
				goto yskeee111;
		}

		yskeee111:

		if(  o111==1  ){  o111=2;  goto qbk111;  }

		jw111:

		if(o111!=0)  {  o111=0;  }  else  {  o111=1;  }
		pt111=ps111;  ps111=pd111;  pd111=pt111;  t111=t111*2;
		if(  t111>nd222  ){  goto  rel111;  }
		t222=t111*2;
		goto rel222;

		rel111:

		if(  yb222!=0  )
		{
				if(  ( t666==1 )  ||  ( y222==0 )  ){  goto cxi333;  }

				if(  o111==0  )  {  sort22222(  ps111,  pd111,  t111,  yl222  );  }
				else             {  sort55555(  ps111,  pd111,  t111,  yl222  );  }
				
				ps111=pd111;

				cxi333:

		}
		
		if(  p!=ps111  ){  memcpy(  p,  ps111,  n*sizeof( int )  );  }  /*  扩展类型相关  */

		if(  globalbbb111==1  ){  goto cxttt111;  }
		
		/*  For reference only; overflow may occur, leading to incorrect display.  */
		printf("------------------------------------------------------------\r\n ");
		if(  n<15  )
		{
				for(  i=0;  i<n;  i++  ){  printf(" %d ",*(p+i));  }
				printf("\r\n");
		}
		else
		{
				printf(" %d ",*(p));
				printf(" %d ",*(p+1));
				printf(" %d ",*(p+2));

				y111=n/2-1;  y222=y111+2;

				for(  i=y111;  i<=y222;  i++  ){  printf(" %d ",*(p+i));  }
				printf(" %d ",*(p+n-3));
				printf(" %d ",*(p+n-2));
				printf(" %d \r\n",*(p+n-1));
		}
		printf("------------------------------------------------------------\r\n ");
		

		cxttt111:

		free(pt555);

		return 0;
}



int main(int argc, char *argv[])
{
	int  intreturn=0;
	int * p;
	int i111=0;
	int i22222=10;
	p=malloc(32*sizeof(int));
	if(p==NULL){ printf("malloc111 error.\r\n");return  -1;}
	
/*	*(p+0)=1209;*(p+1)=9108;*(p+2)=6107;*(p+3)=103;*(p+4)=103;*(p+5)=105;*(p+6)=105;*(p+7)=107;*(p+8)=108;*(p+9)=1109;
	*(p+10)=699;*(p+11)=367;*(p+12)=590;*(p+13)=6107;*(p+14)=722;*(p+15)=988;*(p+16)=766;*(p+17)=218;*(p+18)=916;*(p+19)=999;
	*(p+20)=253;*(p+21)=523;*(p+22)=333;*(p+23)=555;*(p+24)=729;*(p+25)=6107;*(p+26)=866;*(p+27)=219;*(p+28)=9699999;*(p+29)=909;*/


	*(p+0)=17;*(p+1)=16;*(p+2)=15;*(p+3)=14;*(p+4)=13;*(p+5)=12;*(p+6)=11;*(p+7)=10;*(p+8)=9;*(p+9)=8;
	*(p+10)=7;*(p+11)=6;*(p+12)=5;*(p+13)=4;*(p+14)=3;*(p+15)=2;*(p+16)=1;*(p+17)=983;*(p+18)=982;*(p+19)=981;
	*(p+20)=980;*(p+21)=979;*(p+22)=978;*(p+23)=977;*(p+24)=976;*(p+25)=975;*(p+26)=974;*(p+27)=973;*(p+28)=972;*(p+29)=971;
	*(p+30)=80;*(p+31)=80;

	
	sort222(p,i22222);
	
	
	for(  i111=0;  i111<i22222;  i111++  )
	{
				printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXX  main  print  not  sort222  ---%d---\n",*(p+i111));
	}
	free(p);
	return intreturn;
}

