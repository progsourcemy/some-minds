/*



Please note that the use of this document may require some knowledge of computers or mathematics. I have no copyright claims or restrictions, and of course, I cannot guarantee against any potential losses.




A  Iterative Merge-Based Sorting Method




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

			For reference only   x86_64 Linux  -O3 -march=native
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

						

*/


char globalbbb111=1;  /* 1   to  skip   print         */


#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
/*#include<malloc.h>*/
#include <string.h>

inline __attribute__((always_inline))  void sort55555xxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{


		/*  三个连续数列  A B C , A 与 B  规模相同 ,  C 规模较小 , C 应该是真正的余数部分 ,  此时 A  C  已经合并排序到对面缓存对应  A 开始的一段位置   本函数要逆向合并排序 源缓存的  B  部分与对面缓存的对应的 A 开始的一段数据  到  对面缓存  C 的末尾开始的逆向增长对应位置  */


		int * temp111;  int * temp222;  int * temp333;  size_t temp555=l222-1;

		temp111=pd111+temp555+l333;  temp333=pd111+(l333-1);  temp222=ps111+temp555;

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=ps111  ){  temp222--;  temp111--;  goto  lll222;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=pd111  ){  temp333--;  temp111--;  goto  lll333;  }    /*  防止溢出  */
		if(  temp222>=ps111  ){  memcpy(  pd111,ps111,( ( temp222-ps111 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */

		return;
}

inline __attribute__((always_inline))  void sort22222xxx(  int  *restrict  ps111,  int  *restrict pd111,  size_t l222,  size_t l333,  size_t l555  )
{


		/*  三个连续数列  A B C , A 与 B  数目相同 ,  C 规模较小 , C 应该是真正的余数部分 ,  本函数要合并排序 源缓存的  A  与  C  部分到对面缓存的对应的 A 开始的一段位置  */


		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;

		temp222=ps111;  temp333=temp222+l555;  l22222=temp333-l222-1;  l33333=l22222+l222+l333;  temp111=pd111;  

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;    /*  防止溢出  */
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof(int)  );  return;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;    /*  防止溢出  */
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */

		return;
}


inline __attribute__((always_inline))  void sortxxxxxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l555,size_t l666)
{

		/*  两个连续数列  A B , A 与 B  规模相同 , 本函数要逆向合并排序 源缓存的  A 与 B  部分 到 对面缓存  B   的末尾开始的逆向增长对应位置  */


		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;  int * l11111;

		temp333=ps111;  temp222=temp333-l555;  l33333=(ps111-l222)+1;  l22222=l33333-l555;  temp111=pd111;  l11111=pd111-(l666-1);    /*    防止溢出    */

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  )  {  temp222--;  temp111--;  goto  lll222;  }    /*  防止溢出  */
		if(  temp333>=l33333  ){  memcpy(  l11111,l33333,( ( temp333-l33333 )+1 ) * sizeof( int ) );  return;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  )  {  temp333--;  temp111--;  goto  lll333;  }    /*  防止溢出  */
		if(  temp222>=l22222  ){  memcpy(  l11111,l22222,( ( temp222-l22222 )+1 ) * sizeof( int ) );  return;  }    /*  防止溢出  */

		return;
}

inline __attribute__((always_inline))  void sortxxx(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l555)  /*类型扩展*/
{

		/*  两个连续数列  A B , A 与 B  数目相同 , 本函数要合并排序 源缓存的  A 与 B  部分到对面缓存的对应的 A 开始的一段位置  */


		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;

		temp222=ps111;  temp333=temp222+l555;  l22222=ps111+(l222-1);  l33333=l22222+l555;  temp111=pd111;    

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;  	   /*  防止溢出  */
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */
		return;

		lll333:

		if( *(temp222)<=*(temp333) ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;    /*  防止溢出  */
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */
		return;
}


inline __attribute__((always_inline))  void sort55555(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{

		/*  两个连续数列  A B , A 与 B  可以有不同的规模 , 本函数要逆向合并排序 源缓存的 A 与 B 部分到  对面缓存  B  的末尾开始的逆向增长对应位置  */
		

		int * l33333;  int * temp111;  int * temp222;  int * temp333;  size_t laaa;

		laaa=(l222-1)+l333;  l33333=ps111+l222;  temp111=pd111+laaa;  temp333=ps111+laaa;  temp222=temp333-l333;

		lll222:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=ps111  ){  temp222--;  temp111--;  goto  lll222;  }    /*  防止溢出  */
		if(  temp333>=l33333  ){  memcpy(  pd111,l33333,( ( temp333-l33333 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )>*( temp333 )  ){ goto  lll222222; }

		lll333333:

		*(temp111)=*(temp333);  if( temp333!=l33333){  temp333--;  temp111--;  goto  lll333;  }    /*  防止溢出  */
		if(  temp222>=ps111  ){  memcpy(  pd111,ps111,( ( temp222-ps111 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */

		return;
}

inline __attribute__((always_inline))  void sort33333(int  *restrict  ps111,int  *restrict  pd111,size_t l222,size_t l333)
{

		/*  三个连续数列  A B C , A 与 B  规模相同 ,  C 规模较小 , C 应该是真正的余数部分 ,  此时 B  C  已经合并排序到对面缓存对应  B 开始的一段位置 ,  本函数要合并排序 源缓存  的  A  部分与对面缓存的对应的 B 开始的一段数据  到  对面缓存  A 开始的对应位置  */


		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;  size_t laaa;
		
		laaa=l222-1;  l22222=ps111+laaa;  temp333=pd111+l222;  l33333=pd111+laaa+l333;  temp111=pd111;  temp222=ps111;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;    /*  防止溢出  */
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof(int)  );return;  }    /*  防止溢出  */

		return;
}

inline __attribute__((always_inline))  void sort22222(int  *restrict  ps111,int  *restrict pd111,size_t l222,size_t l333)
{

		/*  两个数列  A B , A 与 B  可以有不同的规模 , 本函数要合并排序 源缓存  的 A 与 B 部分到  对面缓存    A 开始的对应位置  */


		int * l22222;  int * l33333;  int * temp111;  int * temp222;  int * temp333;
		
		temp222=ps111;  temp333=temp222+l222;  l22222=temp333-1;  l33333=l22222+l333;  temp111=pd111;

		lll222:

		if(  *( temp222 )>*( temp333 )  )    {  goto  lll333333;  }

		lll222222:

		*(temp111)=*(temp222);  if(  temp222!=l22222  ){  temp222++;  temp111++;  goto  lll222;  }  temp111++;    /*  防止溢出  */
		if(  temp333<=l33333  ){  memcpy(  temp111,temp333,( ( l33333-temp333 )+1 ) * sizeof(int)  );  return;  }    /*  防止溢出  */
		return;

		lll333:

		if(  *( temp222 )<=*( temp333 )  )    {  goto  lll222222;  }

		lll333333:

		*(temp111)=*(temp333);  if(  temp333!=l33333  ){  temp333++;  temp111++;  goto  lll333;  }  temp111++;    /*  防止溢出  */
		if(  temp222<=l22222  ){  memcpy(  temp111,temp222,( ( l22222-temp222 )+1 ) * sizeof( int )  );  return;  }    /*  防止溢出  */

		return;
}

int sort222(int * p,const size_t n)
{
		int * ps111=0;  int * pd111=0;  int * pt111=0;  int * pt555=0;    size_t  p11=0;  size_t yl111=0;  size_t y111=0;  size_t yl222=0;  size_t y222=0;  size_t yl333=0;  size_t t111=0;  int tempsw111=0;  /*  前面内容  扩展类型相关  */  size_t i=0;  size_t i222=0;  int * pt1111=0;  int * pt1112=0;  int * pt1113=0;  /*  int * pdt111=0;  int * pdt1111=0;  int * pdt1112=0;  int * pdt1113=0;  */  int * p2t111=0;  int * p2t1111=0;  int * p2t1112=0;  int * p2t1113=0;  size_t t222=0;  char t666=0;  char o111=0;  char yb222=0;  size_t nd222=0;  size_t  p12=0;  /*  size_t i666=0;  size_t i333=0;  char t777=0;  char i555=0;  size_t i777=0;  */  size_t i888=0;  int * p15=0;  size_t i999=0;
		
		if(  n  >  ( SIZE_MAX / ( sizeof( int ) ) )  )  {  return -1;  }    /*  避免溢出  */  /*  前面内容  扩展类型相关  */

		if(  n==0  ){  return 0;  }

		ps111=p;   								/*  用本函数内变量保存传入数据块指针  */

		pd111=malloc(  n * sizeof( int )  );  	/*  尝试分配内存  */  /*  前面内容  扩展类型相关  */
		
		if(  pd111==NULL  ){  printf(  "malloc111 error.\n"  );  return -1;  }  /*  内存分配如果失败,返回 -1  */
		
		pt555=pd111;    						/*  由于  ps111  与  pd111  可能需要频繁交换,所以用一个 指针保存分配的内存地址用以将来释放内存  */

		yl222=  ( size_t )  (  n % 8  );  		/*  数列元素个数 相对于 8 的余数  */
		y222=n-yl222;
		
		for(  i=0;  i<y222;  i+=8  )  			/*  尽量顺序对整体数列的中的八个元素的数据块排序  */
		{
				pt111   =ps111+i;
				pt1111  =pt111+1;
				pt1112  =pt111+2;
				pt1113  =pt111+3;
				p2t111  =pt111+4;
				p2t1111 =pt111+5;
				p2t1112 =pt111+6;
				p2t1113 =pt111+7;

				/*  if(  *(pt1111) > *(pt1112)  ){  tempsw111=*(pt1111);  *(pt1111)=*(pt1112);  *(pt1112)=tempsw111;  }
				if(  *pt111 > *(pt1113)  ){  tempsw111=*pt111;  *pt111=*(pt1113);  *(pt1113)=tempsw111;  }
				if(  *pt111 > *(pt1112)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=*(pt1112);  *(pt1112)=tempsw111;  continue;  }
				if(  *(pt1111) > *(pt1113)  ){  tempsw111=*(pt1113);  *(pt1113)=*(pt1112);  *(pt1112)=*(pt1111);  *(pt1111)=tempsw111;  continue;  }
				if(  *pt111 > *(pt1111)  ){  tempsw111=*pt111;  *pt111=*(pt1111);  *(pt1111)=tempsw111;  }
				if(  *(pt1112) > *(pt1113)  ){  tempsw111=*(pt1112);  *(pt1112)=*(pt1113);  *(pt1113)=tempsw111;  }  */



				/*


				   建立一个三维正方体,顶点是数列的元素,数列适当划分几个更小的组,对于小的组适当组织,横向向右变大,横向先排序,纵向向上变大,纵向接着排序,上下方向向上变大,上下方向最后排序,  注意,分析过程可能是比较复杂的,文字较为简单,但是分析可能会需要相当的努力,   对于八位数组,对  0 与 1 排序,  2  与  3  排序,  然后   0 2    1 3     4 5   6 7   4 6   5 7    0 4   1 5    2 6   3 7  排序,此时  0 7  已排好,  此时有可能优化, 如果  4 大于等于 3 ,那么排序  1 与 2  和  5 与 6,排序完成,否则   3   5  6   排序 ,      1   2   4  排序        3 4 排序   排序完成.


				*/


				/*    0 pt111     1 pt1111     2 pt1112     3 pt1113     4 p2t111     5 p2t1111     6 p2t1112     7 p2t1113    */



				if(  *pt111    >   *pt1111   ){  tempsw111=*pt111;    *pt111=  *pt1111;    *pt1111=tempsw111;   }
				if(  *pt1112   >   *pt1113   ){  tempsw111=*pt1112;   *pt1112= *pt1113;    *pt1113=tempsw111;   }
				if(  *pt111    >   *pt1112   ){  tempsw111=*pt111;    *pt111=  *pt1112;    *pt1112=tempsw111;   }
				if(  *pt1111   >   *pt1113   ){  tempsw111=*pt1111;   *pt1111= *pt1113;    *pt1113=tempsw111;   }
							/*  if(  *pt1111 > *(pt1112)  ){  tempsw111=*pt1111;  *pt1111=*(pt1112);  *(pt1112)=tempsw111;  }  */
				
				if(  *p2t111   >   *p2t1111  ){  tempsw111=*p2t111;   *p2t111= *p2t1111;   *p2t1111=tempsw111;  }
				if(  *p2t1112  >   *p2t1113  ){  tempsw111=*p2t1112;  *p2t1112=*p2t1113;   *p2t1113=tempsw111;  }
				if(  *p2t111   >   *p2t1112  ){  tempsw111=*p2t111;   *p2t111= *p2t1112;   *p2t1112=tempsw111;  }
				if(  *p2t1111  >   *p2t1113  ){  tempsw111=*p2t1111;  *p2t1111=*p2t1113;   *p2t1113=tempsw111;  }
							/*  if(  *pt1111 > *(pt1112)  ){  tempsw111=*pt1111;  *pt1111=*(pt1112);  *(pt1112)=tempsw111;  }  */

				if(  *pt111    >   *p2t111    ){  tempsw111=*pt111;    *pt111= *p2t111;    *p2t111=tempsw111;   }
				if(  *pt1111   >   *p2t1111   ){  tempsw111=*pt1111;   *pt1111=*p2t1111;   *p2t1111=tempsw111;  }
				if(  *pt1112   >   *p2t1112   ){  tempsw111=*pt1112;   *pt1112=*p2t1112;   *p2t1112=tempsw111;  }
				if(  *pt1113   >   *p2t1113   ){  tempsw111=*pt1113;   *pt1113=*p2t1113;   *p2t1113=tempsw111;  }

 
				if(  *p2t111 >= *pt1113  )
				{
						if(  *p2t1111 > *p2t1112  )  {  tempsw111=*p2t1111;  *p2t1111=*p2t1112;  *p2t1112=tempsw111;  }
						if(  *pt1111  > *pt1112   )  {  tempsw111=*pt1111;   *pt1111=*pt1112;    *pt1112=tempsw111;   }
						goto jjjbbb;
				}


				if(  *pt1113 > *p2t1111  )  {  tempsw111=*pt1113;  *pt1113=*p2t1111;  *p2t1111=tempsw111;  }
				if(  *p2t1111 <= *p2t1112  )  {  goto jjj666;  }
				tempsw111=*p2t1111;  *p2t1111=*p2t1112;  *p2t1112=tempsw111;
				if(  *pt1113 > *p2t1111  )  {  tempsw111=*pt1113;  *pt1113=*p2t1111;  *p2t1111=tempsw111;  }

				jjj666:

				/*  if(  *pt1113 > *(p2t111)  ){  tempsw111=*pt1113;  *pt1113=*(p2t111);  *(p2t111)=tempsw111;  }  */

				/*  if(  *pt1111 > *pt1112  ){  tempsw111=*pt1111;  *pt1111=*pt1112;  *pt1112=tempsw111;  }
				if(  *pt1112 <= *(pt1113)  ){  goto jjj777;  }
				tempsw111=*(p2t1112);  *(pt1112)=*(pt1113);  *(pt1113)=tempsw111;
				if(  *pt1111 > *pt1112  ){  tempsw111=*pt1111;  *pt1111=*pt1112;  *pt1112=tempsw111;  }

				jjj777:  */


				if(  *pt1111 > *pt1112  )  {  tempsw111=*pt1111;  *pt1111=*pt1112;  *pt1112=tempsw111;  }
				if(  *pt1112 <= *p2t111  )  {  goto jjj777;  }
				tempsw111=*pt1112;  *pt1112=*p2t111;  *p2t111=tempsw111;
				if(  *pt1111 > *pt1112  )  {  tempsw111=*pt1111;  *pt1111=*pt1112;  *pt1112=tempsw111;  }

				jjj777:

				if(  *pt1113 > *p2t111  )  {  tempsw111=*pt1113;  *pt1113=*p2t111;  *p2t111=tempsw111;  }

				jjjbbb:

				/*  余数处理  小于四  大于等于四 充分利用  内联函数  */


				/*pdt111=pd111+i;
				pdt1111=pdt111+1;
				pdt1112=pdt111+2;
				pdt1113=pdt111+3;

				if(  *(pt1111) > *(pt1112)  ){  *(pdt1111)=*(pt1112);  *(pdt1112)=*(pt1111);  goto  jjj111;  }

				*(pdt1111)=*(pt1111);  *(pdt1112)=*(pt1112);
				
				jjj111:
				
				if(  *(pt111) > *(pt1113)  ){  *(pdt111)=*(pt1113);  *(pdt1113)=*(pt111);  goto  jjj222;  }

				*(pdt111)=*(pt111);  *(pdt1113)=*(pt1113);

				jjj222:


				if(  *pdt111 > *(pdt1112)  ){  *(pt111)=*(pdt1111);  *(pt1111)=*(pdt1112);  *(pt1112)=*(pdt111);  *(pt1113)=*(pdt1113);  goto jjjeee;  }

				if(  *pdt1111 > *(pdt1113)  ){  *(pt111)=*(pdt111);  *(pt1111)=*(pdt1113);  *(pt1112)=*(pdt1111);  *(pt1113)=*(pdt1112);  goto jjjeee;  }


				if(  *(pdt111) > *(pdt1111)  ){  *(pt111)=*(pdt1111);  *(pt1111)=*(pdt111);  goto  jjj555;  }

				*(pt111)=*(pdt111);  *(pt1111)=*(pdt1111);
				
				jjj555:
				
				if(  *(pdt1112) > *(pdt1113)  ){  *(pt1112)=*(pdt1113);  *(pt1113)=*(pdt1112);  goto  jjjeee;  }
				
				*(pt1112)=*(pdt1112);  *(pt1113)=*(pdt1113);

				jjjeee:  */

		}
		
		if( yl222 > 0 )
		{		/*   ----------------   有余数    对余数部分排序   ----------------------   */

				yb222=1;  pt111=ps111+y222;

				if(  yl222>=4  )
				{

						pt1111=pt111+1;  pt1112=pt111+2;  pt1113=pt111+3;

						if(  *pt111  >  *pt1111  ){  tempsw111=*pt111;   *pt111=   *pt1111;  *pt1111=tempsw111;  }
						if(  *pt1112 >  *pt1113  ){  tempsw111=*pt1112;  *pt1112=  *pt1113;  *pt1113=tempsw111;  }
						if(  *pt111  >  *pt1112  ){  tempsw111=*pt111;   *pt111=   *pt1112;  *pt1112=tempsw111;  }
						if(  *pt1111 >  *pt1113  ){  tempsw111=*pt1111;  *pt1111=  *pt1113;  *pt1113=tempsw111;  }
						if(  *pt1111 >  *pt1112  ){  tempsw111=*pt1111;  *pt1111=  *pt1112;  *pt1112=tempsw111;  }
				}

				if(  yl222>4  )  {  yl333=yl222-4;  pt111+=4;  }  else  {  yl333=yl222;  }

				if(  yl333==1  )  {  goto jjjaaa;  }
				
				if(  yl333==2  )
				{
					pt1111=pt111+1;
					if(  *pt111 > *pt1111  ){  tempsw111=*pt111;  *pt111=*pt1111;  *pt1111=tempsw111;  goto jjjaaa;  }
					goto jjjaaa;
				}
				
				if(  yl333==3  )
				{
					pt1111=pt111+1;  pt1112=pt111+2;
					if(  *pt111  > *pt1111  ){  tempsw111=*pt111;   *pt111=*pt1111;   *pt1111=tempsw111;  }
					if(  *pt1111 > *pt1112  ){  tempsw111=*pt1111;  *pt1111=*pt1112;  *pt1112=tempsw111;  }  else  {  goto jjjaaa;  }
					if(  *pt111  > *pt1111  ){  tempsw111=*pt111;   *pt111=*pt1111;   *pt1111=tempsw111;  goto jjjaaa;  }
					goto jjjaaa;
				}

				jjjaaa:

				if(  yl222>4  )  {  pt111-=4;  p2t111=pd111+y222;  sort22222(  pt111,p2t111,4,yl333  );  for(i=0;i<yl222;i++){  *(pt111+i)=*(p2t111+i);  }  }

		}

		t111=8;  t222=16;  o111=1;  nd222=n/2;

		if(  t222>n  ){  goto rel111;  }

		rel222:

		yl111=  (  size_t  )  (  n % ( t222 )  );
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

		qbk111:							/*  前部数据块  处理代码段  */

		if(  o111==0  )    /*  内存尽量顺序访问  */
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
						p15+=t222;    /*  可能溢出,但是已经没有问题  */
				}
		}
		else    /*  内存尽量逆序访问  有余数或无余数的情况  */
		{
				/*  特别注意 由大向小的循环此时需要在下面判断 0  并相应操作避免溢出  */
				/*  注意,此时应该对可能造成 size_t  成为负值倾向的情况进行规避.  */
				/*  此处处理的情况可能会有余数也可能会无余数,如果有余数,由于是逆序,所以流程是先跳转到  余数数据块  代码处理段  ,然后到此余数已经处理完,如果是无余数,不需要处理余数,所以此分支完成后直接跳转  jw111  */
			
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

				if(  i==0  )  {  goto  jw111;  }    /*    跳过等于零的情况防止溢出    */

				i999=i-1;  /*  前面跳过零的代码使前面操作不会溢出  */      i888=i/2;  p15=pd111+i999;

				for(  i222=i999;  i222>i888;  i222-=t111  )    /*  此处循环需特别注意,不是特别典型的应用,套用可能会更容易出问题  */
				{
						sortxxxxxx(ps111+i222,p15,t111,i888,t222);
						p15-=t222;    /*  可能溢出,但是已经没有问题  */
				}
				goto  jw111;  /*  前部数据段 处理完成    跳转本次循环结尾处理段  */
		}

		ysk111:		/*  余数数据块  处理代码段  */

		if(  yb222==5  )  /*   本次上次  都有余数  且  余数无变化  且  上次    不是     余数相同   注意  需要三列合并  */
		{

				/*    需要三列合并    		按目前的情况是 三个数列  A B C     A 与 B  数目相同    C 规模较小, C 应该是真正的余数部分 ,先合并 B C 成为 D  数列,此时开始对 A 与 D 进行特殊合并排序,开始的目标缓存是对面缓存的  数列  A 的对应部分,这样进行应该会完成    */

				/*  余数部分与相邻 t111 块的合并排序  */

				p11=y111-t111;  p12=p11-t111;    /*  目前看不会溢出  */

				if(  o111==0  )
				{
						sort22222xxx(  ps111+p12,  pd111+p12,  t111,  yl111,       t222  );
						sort55555xxx(  ps111+p11,  pd111+p12,  t111,  t111+yl111  );
						goto yskeee111;
				}
				else
				{
						sort55555(  ps111+p11,  pd111+p11,  t111,  yl111  );
						sort33333(  ps111+p12  ,pd111+p12  ,t111,  t111+yl111  );
						goto yskeee111;
				}
				
				goto yskeee111;
		
		}
		if(yb222==3)  /*   本次上次  都有余数  且  余数有变化  且  上次    不是     余数相同   */
		{
				if      (o111==0)   {  sort22222(  ps111+y111,  pd111+y111,  t111,  yl222  );  }
				else                {  sort55555(  ps111+y111,  pd111+y111,  t111,  yl222  );  }

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

				if      (  o111==0  )  {  sort22222(  ps111+p11,  pd111+p11,  t111,  t111+yl111  );  goto yskeee111;  }
				else                   {  sort55555(  ps111+p11,  pd111+p11,  t111,  t111+yl111  );  goto yskeee111;  }

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

		if  (  t111>nd222  )  {  goto  rel111;  }

		t222=t111*2;

		goto rel222;

		rel111:

		if(  yb222!=0  )
		{
				if(  ( t666==1 )  ||  ( y222==0 )  )  {  goto cxi333;  }

				if(  o111==0  )  {  sort22222(  ps111,  pd111,  t111,  yl222  );  }
				else             {  sort55555(  ps111,  pd111,  t111,  yl222  );  }
				
				ps111=pd111;

				cxi333:

		}
		
		if(  p!=ps111  ){  memcpy(  p,  ps111,  n*sizeof( int )  );  }  /*  扩展类型相关  */

		if(  globalbbb111==1  ){  goto cxttt111;  }
		
		printf("----------------------------SSSSSSSSSSSSS--------------------------------\r\n ");


		if      (  n<15  )  {  for(  i=0;  i<n;  i++  ){  printf(" %d ",*(p+i));  }  printf("\r\n");  }
		else
		{
				printf(" %d ",*(p));  printf(" %d ",*(p+1));  printf(" %d ",*(p+2));  y111=n/2-1;  y222=y111+2;

				for(  i=y111;  i<=y222;  i++  ){  printf(" %d ",*(p+i));  }

				printf(" %d ",*(p+n-3));  printf(" %d ",*(p+n-2));  printf(" %d \r\n",*(p+n-1));
		}

		printf("------------------------------SSSSSSSSSSSSSS------------------------------\r\n ");

		cxttt111:

		free(pt555);

		return 0;

}


int main(int argc, char *argv[])
{
	int  intreturn=0;
	int * p;
	int i111=0;
	int i22222=3;
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

