/*



Please note that the use of this document may require some knowledge of computers or mathematics. I have no copyright claims or restrictions, and of course, I cannot guarantee against any potential losses.



Please note that the sorting method in this file is not a stable sorting method. This is mainly to ensure that the sorting method performs as consistently as possible across various situations. A stable sorting version might exhibit significant performance differences when sorting in ascending order versus descending order; one scenario could be quite fast, while the other could be quite slow. We are currently working on a stable sorting version of this method. The stable sorting version should be able to adjust to suit either ascending or descending order scenarios based on parameter requirements and will be released as soon as possible.


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

2026-09-01
		Some tests have been completed. It's worth noting that after what I consider extreme optimization, the code complexity has increased significantly, so I still need to frequently review the current code. In one test, the latest version, on a device with a nearly 20-year-old CPU and less than 4GB of RAM, was approximately 12% faster than minimal quicksort, even when sorting three massive ordered sequences with a total size of 201,326,592 random numbers, which is notoriously difficult to sort by merge sort.


*/



#include<stdio.h>
#include <stdint.h>
#include<stdlib.h>
/*#include<malloc.h>*/
#include <string.h>


char globalbbb111 = 1;  /* 1   to  skip   print         */
size_t globalvar222 = 210;










inline __attribute__((always_inline)) void sortxxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l555 );
inline __attribute__((always_inline)) void sortxxxxxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l555, size_t l666 );
inline __attribute__((always_inline)) void sort22222( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
inline __attribute__((always_inline)) void sort33333( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
inline __attribute__((always_inline)) void sort55555( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
inline __attribute__((always_inline)) void sort55555xxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );

__attribute__((noinline)) void sort22222slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
__attribute__((noinline)) void sort33333slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
__attribute__((noinline)) void sort55555slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
__attribute__((noinline)) void sort55555xxxslow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 );
__attribute__((noinline)) void n111( int *restrict ps111, int *restrict pd111, size_t t111, char o111 );
__attribute__((noinline)) void n555( int *restrict ps111, int *restrict pd111, size_t t111, size_t yl111, char o111 );
__attribute__((noinline)) void eee111( int *restrict ps111, int *restrict pd111, size_t t111, size_t yl222, char b111, char o111 );

__attribute__((noinline)) void zx111( int * l22222, int * l33333, int ** ptemp111, int ** ptemp222, int ** ptemp333, size_t tempaaa );
__attribute__((noinline)) void nx111( int * l22222, int * l33333, int ** ptemp111, int ** ptemp222, int ** ptemp333, size_t tempaaa );



int sort222(int * p,const size_t n)
{

		int * ps111 = 0; int * pd111 = 0; int * pt111 = 0; int * pt555 = 0; size_t yl111 = 0; size_t y111 = 0; size_t yl222 = 0; size_t y222 = 0; size_t t111 = 0; size_t i = 0; size_t i222 = 0; size_t t222 = 0; char t666 = 0; char o111 = 0; char yb222 = 0; size_t nd222 = 0; size_t p12 = 0; size_t i888 = 0; int * p15 = 0; size_t i999 = 0; int * pt1111 = 0; int * pt1112 = 0; int * pt1113 = 0; int * p2t111 = 0; int * p2t1111 = 0; int * p2t1112 = 0; int * p2t1113 = 0; int tempsw111 = 0; size_t yl333 = 0; size_t n222; size_t n333; size_t n666;

		n222 = n;

		if ( n > ( SIZE_MAX / ( sizeof( int ) ) ) ) { return -1; }		/*	避免溢出	*/

		if ( n == 0 ) { return 0; }

		ps111 = p;		/*	用本函数内变量保存传入数据块指针	*/

		yl222 = ( size_t ) ( n % 8 );		/*	数列元素个数 相对于 8 的余数		*/

		y222 = n - yl222;


		for( i = 0; i < y222; i += 8 ) 			/*	尽量顺序对整体数列的中的八个元素的数据块排序	*/
		{
				pt111   = ps111 + i;
				pt1111  = pt111 + 1;
				pt1112  = pt111 + 2;
				pt1113  = pt111 + 3;
				p2t111  = pt111 + 4;
				p2t1111 = pt111 + 5;
				p2t1112 = pt111 + 6;
				p2t1113 = pt111 + 7;

				/*
				  建立一个三维正方体,顶点是数列的元素,数列适当划分几个更小的组,对于小的组适当组织,横向向右变大,横向先排序,纵向向上变大,纵向接着排序,上下方向向上变大,上下方向最后排序, 注意,分析过程可能是比较复杂的,文字较为简单,但是分析可能会需要相当的努力,  对于八位数组,对 0 与 1 排序, 2 与 3 排序, 然后  0 2  1 3   4 5  6 7  4 6  5 7  0 4  1 5  2 6  3 7 排序,此时 0 7 已排好, 此时有可能优化, 如果 4 大于等于 3 ,那么排序 1 与 2 和 5 与 6,排序完成,否则  3  5 6  排序 ,   1  2  4 排序    3 4 排序  排序完成.

				*/

				/*  0 pt111   1 pt1111   2 pt1112   3 pt1113   4 p2t111   5 p2t1111   6 p2t1112   7 p2t1113  */


				if ( *pt111   >  *pt1111  ) { tempsw111 = *pt111;   *pt111   =  *pt1111;  *pt1111  = tempsw111; }
				if ( *pt1112  >  *pt1113  ) { tempsw111 = *pt1112;  *pt1112  =  *pt1113;  *pt1113  = tempsw111; }
				if ( *pt111   >  *pt1112  ) { tempsw111 = *pt111;   *pt111   =  *pt1112;  *pt1112  = tempsw111; }
				if ( *pt1111  >  *pt1113  ) { tempsw111 = *pt1111;  *pt1111  =  *pt1113;  *pt1113  = tempsw111; }
				
				if ( *p2t111  >  *p2t1111 ) { tempsw111 = *p2t111;  *p2t111  = *p2t1111;  *p2t1111 = tempsw111; }
				if ( *p2t1112 >  *p2t1113 ) { tempsw111 = *p2t1112; *p2t1112 = *p2t1113;  *p2t1113 = tempsw111; }
				if ( *p2t111  >  *p2t1112 ) { tempsw111 = *p2t111;  *p2t111  = *p2t1112;  *p2t1112 = tempsw111; }
				if ( *p2t1111 >  *p2t1113 ) { tempsw111 = *p2t1111; *p2t1111 = *p2t1113;  *p2t1113 = tempsw111; }

				if ( *pt111   >  *p2t111  ) { tempsw111 = *pt111;   *pt111   = *p2t111;   *p2t111  = tempsw111; }
				if ( *pt1111  >  *p2t1111 ) { tempsw111 = *pt1111;  *pt1111  = *p2t1111;  *p2t1111 = tempsw111; }
				if ( *pt1112  >  *p2t1112 ) { tempsw111 = *pt1112;  *pt1112  = *p2t1112;  *p2t1112 = tempsw111; }
				if ( *pt1113  >  *p2t1113 ) { tempsw111 = *pt1113;  *pt1113  = *p2t1113;  *p2t1113 = tempsw111; }
 
				if ( *p2t111 >= *pt1113 )
				{
						if( *p2t1111 > *p2t1112 ) { tempsw111 = *p2t1111; *p2t1111 = *p2t1112; *p2t1112 = tempsw111; }
						if( *pt1111  > *pt1112  ) { tempsw111 = *pt1111;  *pt1111  = *pt1112;  *pt1112  = tempsw111; }
						goto jjjbbb;
				}

				if ( *pt1113  >  *p2t1111 ) { tempsw111 = *pt1113; *pt1113 = *p2t1111; *p2t1111 = tempsw111; }
				if ( *p2t1111 <= *p2t1112 ) { goto jjj666; }
				tempsw111 = *p2t1111; *p2t1111 = *p2t1112; *p2t1112 = tempsw111;
				if ( *pt1113 > *p2t1111 ) { tempsw111 = *pt1113; *pt1113 = *p2t1111; *p2t1111 = tempsw111; }

				jjj666:

				if ( *pt1111 >  *pt1112 ) { tempsw111 = *pt1111; *pt1111 = *pt1112; *pt1112 = tempsw111; }
				if ( *pt1112 <= *p2t111 ) { goto jjj777; }
				tempsw111 = *pt1112; *pt1112 = *p2t111; *p2t111 = tempsw111;
				if ( *pt1111 > *pt1112 ) { tempsw111 = *pt1111; *pt1111 = *pt1112; *pt1112 = tempsw111; }

				jjj777:

				if ( *pt1113 > *p2t111 ) { tempsw111 = *pt1113; *pt1113 = *p2t111; *p2t111 = tempsw111; }

				jjjbbb:

		}


		if		 	(  ( n222 > 4  ) && ( n222 <  8  )  ) 		{ n222 = n222 - 4; }
		else if  	(  ( n222 > 8  ) && ( n222 <= 16 )  )	 	{ n222 = n222 - 8; }
		else if  	(    n222 > 16 						)		{ 				   }
		else 													{ n222 = 0; 	   }

		if ( n222 )		/*	综合分析 此时 根据条件 确定 是否分配 如何分配 内存 较为适合	*/
		{

				pd111 = malloc( n222 * sizeof( int ) );

				if ( pd111 == NULL ) { return -1; } 

		}

		pt555 = pd111;

		if ( yl222 > 0 )			/*  有余数  对余数部分排序  可能的余数变量布局 pt111 pt1111 pt1112 pt1113  */
		{

				if ( y222 == 8 ) { yb222 = 1; }

				pt111 = ps111 + y222;

				if ( yl222 >= 4 )
				{

						pt1111 = pt111 + 1; pt1112 = pt111 + 2; pt1113 = pt111 + 3;

						if ( *pt111  > *pt1111 ) { tempsw111 = *pt111;  *pt111  = *pt1111; *pt1111=tempsw111; }
						if ( *pt1112 > *pt1113 ) { tempsw111 = *pt1112; *pt1112 = *pt1113; *pt1113=tempsw111; }
						if ( *pt111  > *pt1112 ) { tempsw111 = *pt111;  *pt111  = *pt1112; *pt1112=tempsw111; }
						if ( *pt1111 > *pt1113 ) { tempsw111 = *pt1111; *pt1111 = *pt1113; *pt1113=tempsw111; }
						if ( *pt1111 > *pt1112 ) { tempsw111 = *pt1111; *pt1111 = *pt1112; *pt1112=tempsw111; }

				}

				if ( yl222  > 4 ) { yl333 = yl222 - 4; pt111 += 4; } else { yl333 = yl222; }

				if ( yl333 == 1 ) { goto jjjaaa; }

				if ( yl333 == 2 )
				{

						pt1111 = pt111 + 1;

						if ( *pt111 > *pt1111 ) { tempsw111 =* pt111; *pt111 =* pt1111; *pt1111 = tempsw111; goto jjjaaa; }

						goto jjjaaa;

				}

				if ( yl333 == 3 )
				{

						pt1111 = pt111 + 1; pt1112 = pt111 + 2;

						if ( *pt111  >  *pt1111 ) { tempsw111 =* pt111; *pt111 = *pt1111; *pt1111 = tempsw111; }
						if ( *pt1111 <= *pt1112 ) { goto jjjaaa; }
						tempsw111 = *pt1111; *pt1111 = *pt1112; *pt1112 = tempsw111;
						if ( *pt111  >  *pt1111 ) { tempsw111 = *pt111; *pt111 = *pt1111; *pt1111 = tempsw111; goto jjjaaa; }

						goto jjjaaa;

				}

				jjjaaa:

				if ( yl222 > 4 )
				{
						eee111( pt111 - 4, pd111 + ( n222 - ( yl222 - 4 ) ), 4, yl222 - 4, 0, 0 );
				}

		}


		t111 = 8; t222 = 16; o111 = 1; nd222 = n / 2;

		if ( t222 > n ) { goto rel111; }

		rel222:  /*  主循环 主循环  主循环  主循环  主循环  主循环 主循环  主循环  主循环  主循环  主循环  主循环  主循环  */

		yl111 = ( size_t ) ( n % ( t222 ) );

		y111 = n - yl111;

		if ( yl111 > 0 )			/*  有余数  */
		{
				if ( yl222 != 0 )			/*  上次本次都有余数  */
				{
						if ( yl111 != yl222 )		/*		上次本次都有余数 且上次和本次的余数不同    yb222 状态为  2  或  3	*/
						{
								if ( t666 == 1 )  			/*		yb222 状态为 2		*/
								{
										n333 = n / t111; n666 = n % t111;		/*  防止溢出  */
										if (    (n333==5)  &&  (n666>=1)    &&    (n666<(t111-7))    &&    (ps111!=p)    )
										{
												if ( o111 ==0 )
												{
														sort22222slow	(	ps111,			  			pd111 + t111 + yl111,     	t111, 	    	t111		);
														sort55555xxxslow(	ps111 + t111 * 2, 			pd111 + t111 + yl111,     	t111, 	    	t111 * 2	);
														sort55555slow	(	ps111 + t111 * 3, 			ps111 + t111 * 2 - yl111, 	t111, 	    	yl111 	 	);
														sort33333slow	(	ps111 + t111 * 2 - yl111,	pd111,					  	t111 + yl111, 	t111 * 3	);
												}
												else
												{
														sort55555slow	(	ps111 + t111,				pd111 + t111,	 			t111,			t111		);
														sort33333slow	(	ps111, 		 				pd111,						t111,			t111 * 2	);
														sort22222slow	(	ps111 + t111 * 3, 			ps111 + t111 * 2 - yl111, 	t111,			yl111 		);
														sort55555xxxslow(	ps111 + t111 * 2 - yl111,	pd111,						t111 + yl111, 	t111 * 3	);
												}
												goto rel333;
										}
										if (    (n333==3)  &&  (n666>=1)    &&    (n666<(t111-7))    &&    (ps111==p)    )
										{
												if ( o111 == 0 )
												{
														sort22222slow(	ps111,	pd111,	t111,		t111	);
														sort33333slow(	pd111,	ps111,	t111 * 2,	yl111	);
												}
												else
												{
														sort55555slow(	ps111,	pd111,	t111,		t111	);
														sort33333slow(	pd111,	ps111,	t111 * 2,	yl111	);
												}
												goto rel333;
										}
										yb222 = 2; 
								}
								else			/* yb222 状态为 3 */
								{
										n333 = n / t111; n666 = n % t111;		/*  防止溢出  */
										if (    (n333==3)    &&    (n666>=(t111-7))    &&    (n666<=(t111-1))    &&    (ps111!=p)    )
										{
												if ( o111 == 0 )
												{
														sort22222slow	(	ps111,					pd111,					t111,			t111		);
														sort22222slow	(	ps111 + t111 * 2,		ps111 + t111 - yl222,	t111,			yl222		);
														sort55555xxxslow(	ps111 + t111 - yl222,	pd111,					t111 + yl222,	t111 * 2	);
												}
												else
												{
														sort55555slow(	ps111,					pd111 + t111 + yl222,	t111,			t111		);
														sort55555slow(	ps111 + t111 * 2,		ps111 + t111 - yl222,	t111,			yl222		);
														sort33333slow(	ps111 + t111 - yl222,	pd111,					t111 + yl222,	t111 * 2	);
												}
												goto rel333;
										}
										yb222 = 3;
								}
						}
						else			/*	上次本次都有余数 且余数相同		yb222 状态为  4  或  5	*/
						{
								if ( t666 == 0 )			/*		yb222 状态为 5		 此状态最多出现一次		*/
								{
										n333 = n / t111; n666 = n % t111;		/*  防止溢出  */
										if (    (n333==4)    &&    (n666>=(t111-7))    &&    (n666<=(t111-1))    &&    (ps111!=p)    )
										{
												if ( o111 == 0 )
												{
														sort22222slow	(	ps111 + t111 * 3,	pd111 + t111 * 2,	t111,		yl111				);
														sort55555xxxslow(	ps111 + t111 * 2,	pd111 + t111 * 2,	t111,		t111 + yl111		);
														sort55555slow	(	ps111,				ps111 + t111 * 2,	t111,		t111				);
														sort33333slow	(	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 2 + yl111	);
												}
												else
												{
														sort55555slow	(	ps111 + t111 * 3,	pd111 + t111,		t111,		yl111				);
														sort22222slow	(	ps111 + t111 * 2,	pd111,				t111,		t111 + yl111		);
														sort22222slow	(	ps111,				ps111 + t111 * 2,	t111,		t111				);
														sort55555xxxslow(	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 2 + yl111	);
												}
												goto rel333;
										}
										if (    (n333==2)    &&    (n666>=(t111-7))    &&    (n666<=(t111-1))    &&    (ps111==p)    )
										{
												if ( o111 == 0 )
												{
														sort22222slow	(	ps111 + t111,	pd111 + t111,	t111,			yl111	);
														sort55555xxxslow(	pd111 + t111,	ps111,			t111 + yl111,	t111	);
												}
												else
												{
														sort55555slow	(	ps111 + t111,	pd111 + t111,	t111,			yl111	);
														sort55555xxxslow(	pd111 + t111,	ps111,			t111 + yl111,	t111	);
												}
												goto rel333;
										}
										yb222 = 5; t666 = 1;
								}
								else				/*		yb222 状态为 4		*/
								{
										n333 = n / t111; n666 = n % t111;		/*  防止溢出  */
										if (    (n333==4)  &&  (n666>=1)    &&    (n666<(t111-7))    &&    (ps111!=p)    )
										{
												if ( o111 == 0 )
												{
														sort22222slow	(	ps111 + t111 * 2,	pd111,				t111,		t111 + yl111		);
														sort22222slow	(	ps111,				ps111 + t111 * 2,	t111,		t111				);
														sort55555xxxslow(	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 2 + yl111	);
												}
												else
												{
														sort55555slow(	ps111 + t111 * 2,	pd111 + t111 * 2,	t111,		t111 + yl111		);
														sort55555slow(	ps111,				ps111 + t111 * 2,	t111,		t111				);
														sort33333slow(	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 2 + yl111	);
												}
												goto rel333;
										}
										yb222 = 4;
								}
						}
				}
				else			/*  yb222 状态为 1  */	/*  此状态最多出现一次  */
				{
						if (    (n==(t111*3))    &&    (ps111==p)    )		/*		紧贴边界操作	值得注意		同时顺序很重要	  否则可能会溢出	*/
						{
								if ( o111 == 0 )
								{
										sort22222slow(	ps111,	pd111,	t111,		t111   );
										sort33333slow(	pd111,	ps111,	t111 * 2,	t111   );
								}
								else
								{
										sort55555slow	(	ps111 + t111,	pd111 + t111,	t111,		t111	);
										sort55555xxxslow(	pd111 + t111,	ps111,			t111 * 2,	t111	);
								}
								goto rel333;
						}
						if (    (n==(t111*5))    &&    (ps111!=p)    )		/*		紧贴边界操作	值得注意		同时顺序很重要  否则可能会溢出	*/
						{
								if ( o111 == 0 )
								{
										sort22222slow	(	ps111,				pd111 + t111 * 2,	t111,		t111		);
										sort55555xxxslow(	ps111 + t111 * 2,	pd111 + t111 * 2,	t111,		t111 * 2	);
										sort55555slow	(	ps111 + t111 * 3,	ps111 + t111,		t111,		t111		);
										sort33333slow	(	ps111 + t111,		pd111,				t111 * 2,	t111 * 3	);
								}
								else
								{
										sort55555slow	(	ps111 + t111 * 3,	pd111 + t111,		t111,		t111		);
										sort33333slow	(	ps111 + t111 * 2,	pd111,				t111,		t111 * 2	);
										sort22222slow	(	ps111,				ps111 + t111 * 2,	t111,		t111		);
										sort55555xxxslow(	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 3	);
								}
								goto rel333;
						}
						yb222 = 1; t666 = 1;
				}
		}
		else					/*  yb222 状态为 0  */
		{
				if ( n == 16 )
				{
						if ( o111 == 0 )
						{

								memcpy( pd111, ps111, t111 * sizeof( int ) );

								sort33333slow( pd111, ps111, t111, t111 );

						}
						else
						{

								memcpy( pd111, ps111 + t111, t111 * sizeof( int ) );

								sort55555xxxslow( pd111, ps111, t111, t111 );

						}
						goto rel333;
				}
				if (    (n==(t111*4))    &&    (ps111!=p)    )		/*		紧贴边界操作	值得注意		*/
				{
						if ( o111 == 0 )
						{
								sort22222slow	(	ps111,				pd111,	t111,		t111		);
								sort22222slow	(	ps111 + t111 * 2,	ps111,	t111,		t111		);
								sort55555xxxslow(	ps111,				pd111,	t111 * 2,	t111 * 2	);
						}
						else
						{
								sort55555slow(	ps111 + t111 * 2,	pd111 + t111 * 2,	t111,		t111		);
								sort55555slow(	ps111,				ps111 + t111 * 2,	t111,		t111		);
								sort33333	 (	ps111 + t111 * 2,	pd111,				t111 * 2,	t111 * 2	);
						}
						goto rel333;
				}
		}

		i = y111 - t222 * t666;

		if ( ( o111 == 1 ) && ( yl111 != 0 ) ) { goto ysk111; }  /* 如果 状态监测到 内存尽量逆序访问 且余数不为零 跳转到 余数数据块 处理代码段 */

		qbk111:			/*		前部数据块 处理代码段		*/

		if ( o111 == 0 )		/*		内存尽量顺序访问		*/
		{

				i888 = i / 2; p15 = pd111;

				for( i222 = 0; i222 < i888; i222 += t111 )
				{
						sortxxx( ps111 + i222, p15, t111, i888 );
						p15 += t222;  /* 可能溢出,但是已经不会造成问题 */
				}

				if ( yl111 == 0 )
				{

						if ( o111 != 0 )	{ o111 = 0; }
						else				{ o111 = 1; }

						pt111 = ps111; ps111 = pd111; pd111 = pt111;

						if ( t222 > nd222 ) { goto rel111; }	/*		同时有防止可能的溢出的功能		*/

						t111 = t111 * 2; t222 = t111 * 2;

						goto rel222;

				}

		}
		else
		{
				/* 内存尽量逆序访问 有余数或无余数的情况 */
				/* 特别注意 由大向小的循环此时需要在下面判断 0 并相应操作避免溢出 */
				/* 注意,此时应该对可能造成 size_t 成为负值倾向的情况进行规避. */
				/* 此处处理的情况可能会有余数也可能会无余数,如果有余数,由于是逆序,所以流程是先跳转到 余数数据块 代码处理段 ,然后到此余数已经处理完,如果无余数,不需要处理余数,所以此分支完成后直接结束本次循环 */

				if ( i == 0 ) { goto nb111; }  /*  跳过等于零的情况防止溢出   */

				i999 = i - 1;	/* 前面跳过零的代码使操作不会溢出 */
				i888 = i / 2; p15 = pd111 + i999;

				for( i222 = i999; i222 > i888; i222 -= t111 )		/* 此处循环需特别注意,不是特别典型的应用,套用可能会更容易出问题 */
				{
						sortxxxxxx( ps111 + i222, p15, t111, i888, t222 );
						p15 -= t222;  /* 可能溢出,但是已经不会造成问题 */
				}

				/* 前部数据段 处理完成  跳转本次循环结尾处理段 */

				nb111:

				if ( o111 != 0 )	{ o111 = 0; }
				else				{ o111 = 1; }

				pt111 = ps111; ps111 = pd111; pd111 = pt111;

				if ( t222 > nd222 ) { goto rel111; }	/*		同时有防止可能的溢出的功能		*/

				t111 = t111 * 2; t222 = t111 * 2;

				goto rel222;

		}

		ysk111:					/* 余数数据块 处理代码段 */

		if ( yb222 == 4 )				/*  本次上次 都有余数 且 余数无变化 且 t666==1  */
		{

				p12 = y111 - t222;

				if ( o111==0 ) { sort22222( ps111 + p12, pd111 + p12, t111, t111 + yl111 ); goto yskeee111; }
				else { sort55555( ps111 + p12, pd111 + p12, t111, t111 + yl111 ); goto yskeee111; }

		}
		if ( yb222 == 2 ) 		/*  本次上次 都有余数 且 余数有变化 且 t666==1  */
		{

				p12 = y111 - t222;
				yl222 = yl111; y222 = y111;
				if ( o111 == 0 )
				{
						sort22222( ps111 + p12, pd111 + p12, t111, t111 );
						sort55555xxx( ps111 + y111, pd111 + p12, yl111, t111 * 2 );

						goto yskeee111;

				}
				else
				{
						sort55555( ps111 + p12,  pd111 + p12 + yl111, t111, t111 );
						sort33333( ps111 + y111, pd111 + p12, yl111, t111 * 2 );

						goto yskeee111;

				}
		}
		if ( yb222 == 3 )		  /*  本次上次 都有余数 且 余数有变化 且 t666==0  */
		{
				if ( o111 == 0 ) { sort22222( ps111 + y111, pd111 + y111, t111, yl222 ); yl222 = yl111; y222 = y111; goto yskeee111; }
				else			 { sort55555( ps111 + y111, pd111 + y111, t111, yl222 ); yl222 = yl111; y222 = y111; goto yskeee111; }
		}
		if ( yb222 == 1 )			/*  本次有余数上次无余数  */
		{

				p12 = y111 - t222;

				n111( ps111 + p12, pd111 + p12, t111, o111 );

				yl222 = yl111; y222 = y111;

				goto yskeee111;

		}
		if ( yb222 == 5 )			/*  本次上次 都有余数 且 余数无变化 且 t666!=1 注意  三列两步单面合并排序 */
		{

				p12 = y111 - t222;		/* 目前看不会溢出 */

				n555( ps111 + p12, pd111 + p12, t111, yl111, o111 );
				
				goto yskeee111;

		}

		yskeee111:

		if ( o111 == 1 ) { o111 = 2; goto qbk111; }		/*		逆序模式下 余数数据块 处理完成 跳转到 前部数据块 处理代码段		*/

		if ( o111 != 0 ) { o111 = 0; } else { o111 = 1; }
		pt111 = ps111; ps111 = pd111; pd111 = pt111;
		if ( t222 > nd222 ) { goto rel111; }	/*		同时有防止可能的溢出的功能		*/
		t111 = t111 * 2; t222 = t111 * 2;

		goto rel222;

		rel111:

		if (	( yb222 != 0 ) && ( t666 != 1 ) )
		{

				if ( y222 == 8 )	{ eee111( ps111, pd111, t111, yl222, 0, o111 ); }
				else 			 	{ eee111( ps111, pd111, t222, yl222, 1, o111 ); }

		}

		rel333:

		if ( pt555 )  {  free( pt555 );  }

		if ( globalbbb111 == 1 ) { goto cxttt111; }

		printf( "------------------------------11111111111111------------------------------\n " );

		if ( n < 15 ) { for( i = 0; i < n; i++ ){ printf( " %d ", *( p + i ) ); } printf( "\n" ); }
		else
		{
				printf( " %d ", *p ); printf( " %d ", *( p + 1 ) ); printf( " %d ", *( p + 2 ) ); y111 = n / 2 - 1; y222 = y111 + 2;

				for( i = y111; i <= y222; i++ ){ printf( " %d ", *( p + i ) ); }

				printf( " %d ", *( p + ( n - 3 ) ) ); printf( " %d ", *( p + ( n - 2 ) ) ); printf( " %d \n", *( p + ( n - 1 ) ) );
		}

		printf( "------------------------------11111111111111------------------------------\n " );

		cxttt111:

		return 0;

}




__attribute__((noinline)) void zx111( int * l22222, int * l33333, int ** ptemp111, int ** ptemp222, int ** ptemp333, size_t tempaaa )
{

		size_t tempbbb; size_t tempccc; int * paaa; int * temp111; int * temp222; int * temp333;

		temp111 = *ptemp111; temp222 = *ptemp222; temp333 = *ptemp333;

		lllaaa:

		tempaaa = tempaaa - ( tempaaa % 32 );
		if ( tempaaa <= globalvar222 ) { goto lll222; }		/*		同时有防止可能的溢出的功能		*/
		paaa = temp111 + tempaaa;		/*	紧贴边界操作	*/

		goto lllbbb;

		lllddd:

		temp111++;

		lllbbb:

		if ( temp111 < paaa )
		{

				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; goto lllddd; }
				else					   { *temp111 = *temp333; temp333++; goto lllddd; }

		}

		tempbbb = ( l22222 - temp222 );		/* 防止溢出 */
		tempccc = ( l33333 - temp333 );		/* 防止溢出 */
		tempaaa = ( tempbbb < tempccc ? tempbbb : tempccc );

		goto lllaaa;

		lll222:

		*ptemp111 = temp111; *ptemp222 = temp222; *ptemp333 = temp333;

}



__attribute__((noinline)) void nx111( int * l22222, int * l33333, int ** ptemp111, int ** ptemp222, int ** ptemp333, size_t tempaaa )
{

		size_t tempbbb; size_t tempccc; int * paaa; int * temp111; int * temp222; int * temp333;

		temp111 = *ptemp111; temp222 = *ptemp222; temp333 = *ptemp333;

		lllaaa:

		tempaaa = tempaaa - ( tempaaa % 32 );
		if ( tempaaa <= globalvar222 ) { goto lll222; }		/*		同时有防止可能的溢出的功能		*/
		paaa = temp111 - tempaaa;		/*	紧贴边界操作	*/

		goto lllbbb;

		lllddd:

		temp111--;

		lllbbb:

		if ( temp111 > paaa )
		{

				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; goto lllddd; }
				else					   { *temp111 = *temp333; temp333--; goto lllddd; }

		}

		tempbbb = ( temp222 - l22222 );		/* 防止溢出 */
		tempccc = ( temp333 - l33333 );		/* 防止溢出 */
		tempaaa = ( tempbbb < tempccc ? tempbbb : tempccc );

		goto lllaaa;

		lll222:

		*ptemp111 = temp111; *ptemp222 = temp222; *ptemp333 = temp333;

}

__attribute__((noinline)) void sort22222slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{
		sort22222( ps111, pd111, l222, l333 );
}

__attribute__((noinline)) void sort33333slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{
		sort33333( ps111, pd111, l222, l333 );
}

__attribute__((noinline)) void sort55555slow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{
		sort55555( ps111, pd111, l222, l333 );
}

__attribute__((noinline)) void sort55555xxxslow( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{
		sort55555xxx( ps111, pd111, l222, l333 );
}

__attribute__((noinline)) void eee111( int *restrict ps111, int *restrict pd111, size_t t111, size_t yl222, char b111, char o111 )
{

		if ( b111 == 0 )
		{
				memcpy			(		pd111, ps111 + t111, yl222 * sizeof( int )		);
				sort55555xxxslow(		pd111, ps111, yl222, t111						);

				return;

		}

		if ( b111 == 1 )
		{
				if ( o111 == 0 )	{		sort22222slow( ps111, pd111, t111, yl222 );		}
				else				{		sort55555slow( ps111, pd111, t111, yl222 );		}

				return;

		}

}

__attribute__((noinline)) void n111( int *restrict ps111, int *restrict pd111, size_t t111, char o111 )
{

		if ( o111 == 0 )
		{
				sort22222slow	(	ps111,				pd111,	t111,	t111		);
				sort55555xxxslow(	ps111 + t111 * 2,	pd111,	t111,	t111 * 2	);

				return;

		}
		else
		{
				sort55555slow(		ps111 + t111,	pd111 + t111,	t111,	t111		);
				sort33333slow(		ps111,			pd111,			t111,	t111 * 2	);

				return;

		}

}

__attribute__((noinline)) void n555( int *restrict ps111, int *restrict pd111, size_t t111, size_t yl111, char o111 )
{

		if ( o111 == 0 )
		{
				sort22222slow	(	ps111 + t111,	pd111,	t111,	yl111			);
				sort55555xxxslow(	ps111,			pd111,	t111,	t111 + yl111	);

				return;

		}
		else
		{
				sort55555slow(	ps111 + t111,	pd111 + t111,	t111,	yl111			);
				sort33333slow(	ps111,			pd111,			t111,	t111 + yl111	);

				return;

		}

}

inline __attribute__((always_inline)) void sort22222( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{

		/* ps111 与 pd111 都是 A B 结构, A 与 B 可以有不同的规模 , 本函数要合并排序 ps111 的 A 与 B 到 pd111 */

		int * l22222; int * l33333; int * temp111; int * temp222; int * temp333; size_t tempaaa;

		temp222 = ps111; temp333 = temp222 + l222; l22222 = temp333 - 1; l33333 = l22222 + l333; temp111 = pd111;

		tempaaa = ( l222 < l333 ? l222 : l333 );

		if ( tempaaa < globalvar222 ) { goto lll222; }
		tempaaa = tempaaa - 1;		/* 防止溢出 */



		zx111( l22222, l33333, &temp111, &temp222, &temp333, tempaaa );



		lll222:

		if ( *temp222 < *temp333 )
		{
				*temp111 = *temp222;
				if ( temp222 != l22222 )	{ temp222++; temp111++; goto lll222; }
				temp111++;
				if ( temp333 <= l33333 )	{ memcpy( temp111, temp333, ( ( l33333 - temp333 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if ( temp333 != l33333 )	{ temp333++; temp111++; goto lll222; }
				temp111++;
				if ( temp222 <= l22222 )	{ memcpy( temp111, temp222, ( ( l22222 - temp222 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}

}

inline __attribute__((always_inline)) void sort33333( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{

		/* ps111 是 A 这样的规模结构 , pd111 是 A B 结构, A 与 B 可以有不同的规模 , 本函数要合并排序 ps111 的 A 与 pd111 的 B 到 pd111 */

		int * l22222; int * l33333; int * temp111; int * temp222; int * temp333; size_t laaa; size_t tempaaa;

		laaa = l222 - 1; l22222 = ps111 + laaa; temp333 = pd111 + l222; l33333 = pd111 + laaa + l333; temp111 = pd111; temp222 = ps111;

		tempaaa = ( l222 < l333 ? l222 : l333 );

		if ( tempaaa < globalvar222 ) { goto lll222; }
		tempaaa = tempaaa - 1;		/* 防止溢出 */



		zx111( l22222, l33333, &temp111, &temp222, &temp333, tempaaa );



		lll222:

		if ( *temp222 < *temp333 )
		{
				*temp111 = *temp222;
				if ( temp222 != l22222 )	{ temp222++; temp111++; goto lll222; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if ( temp333 != l33333 )	{ temp333++; temp111++; goto lll222; }
				temp111++;
				if ( temp222 <= l22222 )	{ memcpy( temp111, temp222, ( ( l22222 - temp222 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}
}

inline __attribute__((always_inline)) void sort55555( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{

		/* ps111 与 pd111 都是 A B 结构, A 与 B 可以有不同的规模 , 本函数要逆向合并排序 ps111 的 A 与 B 到 pd111 */

		int * l33333; int * temp111; int * temp222; int * temp333; size_t laaa; size_t tempaaa;

		laaa = ( l222 - 1 ) + l333; l33333 = ps111 + l222; temp111 = pd111 + laaa; temp333 = ps111 + laaa; temp222 = temp333 - l333;

		tempaaa = ( l222 < l333 ? l222 : l333 );

		if ( tempaaa <  globalvar222 ) { goto lll222; }
		tempaaa = tempaaa - 1;		/* 防止溢出 */



		nx111( ps111, l33333, &temp111, &temp222, &temp333, tempaaa );



		lll222:

		if ( *temp222 > *temp333 )
		{
				*temp111 = *temp222;
				if (  temp222 != ps111   )		{ temp222--; temp111--; goto lll222; }
				if (  temp333 >= l33333  )		{ memcpy( pd111, l33333, ( ( temp333 - l33333 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if (  temp333 != l33333  )		{ temp333--; temp111--; goto lll222; }
				if (  temp222 >= ps111   )		{ memcpy( pd111, ps111, ( ( temp222 - ps111 ) + 1 ) * sizeof( int ) ); return;	 }
				return;
		}

}

inline __attribute__((always_inline)) void sort55555xxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l333 )
{

		/* ps111 是 B 这样的规模结构 , pd111 是 A B 结构, A 与 B 可以有不同的规模 , 本函数要逆向合并排序 ps111 的 B 与 pd111 的 A 到 pd111 */

		int * temp111; int * temp222; int * temp333; size_t temp555 = l222 - 1; size_t tempaaa;

		temp111 = pd111 + temp555 + l333; temp333 = pd111 + ( l333 - 1 ); temp222 = ps111 + temp555;

		tempaaa = ( l222 < l333 ? l222 : l333 );

		if ( tempaaa <  globalvar222 ) { goto lll222; }
		tempaaa = tempaaa - 1;		/* 防止溢出 */



		nx111( ps111, pd111, &temp111, &temp222, &temp333, tempaaa );



		lll222:

		if ( *temp222 > *temp333 )
		{
				*temp111 = *temp222;
				if ( temp222 != ps111 )		{ temp222--; temp111--; goto lll222; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if ( temp333 != pd111 )		{ temp333--; temp111--; goto lll222; }
				if ( temp222 >= ps111 )		{ memcpy( pd111, ps111, ( ( temp222 - ps111 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}

}

inline __attribute__((always_inline)) void sortxxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l555 )
{

		/* 当前缓存两个可能不连续数列 A B , A 与 B 规模相同 , 本函数要合并排序 当前缓存的 A 与 B 部分到对面缓存 */

		int * l22222; int * l33333; int * temp111; int * temp222; int * temp333; size_t tempaaa; size_t tempbbb; size_t tempccc; int * paaa; 

		temp222 = ps111; temp333 = temp222 + l555; l22222 = ps111 + ( l222 - 1 ); l33333 = l22222 + l555; temp111 = pd111;  

		tempaaa = l222;

		if ( tempaaa < globalvar222 ) { goto lll222; }		/*		同时有防止可能的溢出的功能		*/
		tempaaa = tempaaa - 1;		/* 防止溢出 */

		lllaaa:

		tempaaa = tempaaa - ( tempaaa % 32 );
		if ( tempaaa <= globalvar222 ) { goto lll222; }
		paaa = temp111 + tempaaa;		/*	紧贴边界操作	*/

		goto lllbbb;

		lllddd:

		temp111++;

		lllbbb:

		/* 循环中执行的操作很少那么维持循环的消耗可能会过大而影响性能,所以运行多组相同指令来节省多次循环边界的检查以提高性能  这应该需要准确而高效的控制结构 */

		if ( temp111 < paaa )
		{

				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;
				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; }
				else					   { *temp111 = *temp333; temp333++; }
				temp111++;


				if ( *temp222 < *temp333 ) { *temp111 = *temp222; temp222++; goto lllddd; }
				else					   { *temp111 = *temp333; temp333++; goto lllddd; }

		}

		tempbbb = ( l22222 - temp222 );		/* 防止溢出 */
		tempccc = ( l33333 - temp333 );		/* 防止溢出 */
		tempaaa = ( tempbbb < tempccc ? tempbbb : tempccc );

		goto lllaaa;

		lll222:

		if ( *temp222 < *temp333 )
		{
				*temp111 = *temp222;
				if ( temp222 != l22222 )	{ temp222++; temp111++; goto lll222; }
				temp111++;
				if ( temp333 <= l33333 )	{ memcpy( temp111, temp333, ( ( l33333 - temp333 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if ( temp333 != l33333 )	{ temp333++; temp111++; goto lll222; }
				temp111++;
				if ( temp222 <= l22222 )	{ memcpy( temp111, temp222, ( ( l22222 - temp222 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}

}

inline __attribute__((always_inline)) void sortxxxxxx( int *restrict ps111, int *restrict pd111, size_t l222, size_t l555, size_t l666 )
{

		/* 当前缓存两个可能不连续数列 A B , A 与 B 规模相同 , 本函数要逆向合并排序 源缓存的 A 与 B 部分 到 对面缓存 */

		int * l22222; int * l33333; int * temp111; int * temp222; int * temp333; int * l11111; size_t tempaaa; size_t tempbbb; size_t tempccc; int * paaa; 

		temp333 = ps111; temp222 = temp333 - l555; l33333 = ( ps111 - l222 ) + 1; l22222 = l33333 - l555; temp111 = pd111; l11111 = pd111 - ( l666 - 1 );		/*  防止溢出  */

		tempaaa = l222;

		if ( tempaaa < globalvar222 ) { goto lll222; }		/*		同时有防止可能的溢出的功能		*/
		tempaaa = tempaaa - 1;		/* 防止溢出 */

		lllaaa:

		tempaaa = tempaaa - ( tempaaa % 32 );
		if ( tempaaa <= globalvar222 ) { goto lll222; }
		paaa = temp111 - tempaaa;		/*	紧贴边界操作	*/

		goto lllbbb;

		lllddd:

		temp111--;

		lllbbb:

		if ( temp111 > paaa )
		{

				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;
				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; }
				else					   { *temp111 = *temp333; temp333--; }
				temp111--;


				if ( *temp222 > *temp333 ) { *temp111 = *temp222; temp222--; goto lllddd; }
				else					   { *temp111 = *temp333; temp333--; goto lllddd; }

		}

		tempbbb = ( temp222 - l22222 );		/* 防止溢出 */
		tempccc = ( temp333 - l33333 );		/* 防止溢出 */
		tempaaa = ( tempbbb < tempccc ? tempbbb : tempccc );

		goto lllaaa;

		lll222:

		if ( *temp222 > *temp333 )
		{
				*temp111 = *temp222;
				if ( temp222 != l22222 )	{ temp222--; temp111--; goto lll222; }
				if ( temp333 >= l33333 )	{ memcpy( l11111, l33333, ( ( temp333 - l33333 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}
		else
		{
				*temp111 = *temp333;
				if ( temp333 != l33333 )	{ temp333--; temp111--; goto lll222; }
				if ( temp222 >= l22222 )	{ memcpy( l11111, l22222, ( ( temp222 - l22222 ) + 1 ) * sizeof( int ) ); return; }
				return;
		}

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

