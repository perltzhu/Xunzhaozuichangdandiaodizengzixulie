#include <stdio.h>

#include <stdlib.h>

void findAllMax(int *,int *,int *,int);

void trackBack(int *,int *,int *,int);

int main(void)

{

         //数组的长度

         int len;

         scanf("%d", &len);

         //存储每个位置的最长子序列

         int *s;

         //给定的随机数组

         int *a;

         //保存回溯点,默认是-1

         int *m;

         s = (int *)malloc(sizeof(int) * len);

         a = (int *)malloc(sizeof(int) * len);

         m = (int *)malloc(sizeof(int) * len);

         //赋值

         for(int i = 0; i < len; i++)

         {

                   scanf("%d", &a[i]);

         }

         //找出所有位子的最长子序列的长度，并记录回溯点

         findAllMax(a, s, m, len);

         //回溯输出结果

         trackBack(a, s, m, len);

         return 0;

}

 

//找出所有位子的最长子序列的长度，并记录回溯点

void findAllMax(int *a, int *s, int *m,int len)

{

         for(int i = 0; i < len; i++)

         {

                   //初始化时最长子序列为一,回溯矩阵为-1

                   s[i] = 1;

                   m[i] = -1;

                   //暂时存放最大的子序列长度的变量

                   int u = 1;

                   //根据最优递归关系，基于最优子解来求得i的最长子序列

                   for(int j = 0; j < i; j++)

                   {

                            //递归条件是:a[j] <= a[i] && (s[j] + 1) >= u

                            if(a[j] <= a[i] && (s[j] + 1) >= u)

                            {

                                     //重新修改最大子序列的长度

                                     u = s[j] + 1;

                                     //记录上一个回溯点

                                     m[i] = j;

                            }

                   }

                   //将U赋给s[i]

                   s[i] = u;

         }

}

 

//回溯输出结果

void trackBack(int *a, int *s, int *m,int len)

{

         //保存最大子序列

         int c[8];

         //记录最大子序列的下标

         int j = 0;

         //回溯下标暂时保存变量

         int k = 0;

         //暂时保存拥有最长子序列的位置

         int max = 0;

         //遍历数组s[]找出位置

         for(int i = 0; i < len; i++)

         {

                   max = (s[i] > max) ? i : max;

         }

         //回溯获得结果

         c[j] = max;

         k = m[max];

         j++;

         while(k >= 0)

         {

                   c[j] = k;

                   k = m[k];

                   j++;

         }

         //输出结果

         j--;

         while(c[j] >= 0)

         {

                   printf("%d ", a[c[j]]);

                   j--;

         }

         printf("\n");

}