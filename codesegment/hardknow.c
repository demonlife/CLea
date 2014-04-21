#if 0
// 理解float于double的存储方式.
// 帮助理解的网址: http://coolshell.cn/articles/945.html,
// http://www.ruanyifeng.com/blog/2010/06/ieee_floating-point_representation.html
#include <stdio.h>

int main() {
  float a = 12.5;
  printf("%d\n", a); // maybe 0, mac os 10.9 Apple LLVM version 5.0 => 1596070576
  printf("%d\n", *(int *)&a); // 1095237632
  return 0;
}
#endif 

#if 0
#include <stdio.h>
#include "file1.c"

extern int arr[]; // 编译通过, 正常运行
// exter int *arr; // mac os 10.9 Apple LLVM version 5.0 => 1596070576 // 编译错误
int main() {
  arr[1] = 100;
  printf("%d\n", arr[1]);
  return 0;
}

// 能编译通过, 但运行出错的解释:
// 原因是，在另一个文件中用 extern int *arr来外部声明一个数组并不能得到实际的期望值，因为他们的类型并不匹配。所以导致指针实际并没有指向那个数组。注意：一个指向数组的指针，并不等于一个数组。修改：extern int arr[]。（参考：ISO C语言 6.5.4.2 节）
// 关于 external数组与external指针之间的区别: http://blog.csdn.net/hxg130435477/article/details/4012686, http://blog.csdn.net/honghuzhilangzixin/article/details/8992658
#endif

#if 0
#include <stdio.h>
int main()  
{      
  int a=1;      
  switch(a)      
    {   
      int b=20;          
    case 1: 
      printf("b is %d\n",b);
      break;
    default:
      printf("b is %d\n",b);
      break;
    }
  return 0;
}
// 解释:
// 程序在编译时，可能会出现一条warning: unreachable code at beginning of switch statement。我们以为进入switch后，变量b会被初始化，其实并不然，因为switch-case语句会把变量b的初始化直接就跳过了。所以，程序会输出一个随机的内存值
#endif

#if 0
#include <stdio.h>
int main()  
{ 
    int a=3, b = 5;
 
    printf(&a["Ya!Hello! how is this? %s\n"], &b["junk/super"]);
     
    printf(&a["WHAT%c%c%c  %c%c  %c !\n"], 1["this"],
        2["beauty"],0["tool"],0["is"],3["sensitive"],4["CCCCCC"]);
         
    return 0;  
}
// 程序是合法的, a[i] 其实就是 *(a+i)也就是 *(i+a)，所以如果写成 i[a] 应该也不难理解了
#endif

#if 0
#include <stdio.h>
int main()  
{ 
  char dummy[80];
  printf("Enter a string:\n");
  scanf("%[^r]",dummy);
  printf("%s\n",dummy);
  return 0;
}
// scanf中的”%[^r]“是从中作梗的东西。意思是遇到字符r就结束了
#endif

#if 1
#include <iostream>
#include <vector>
 
typedef int UINT4;
using namespace std;
class Hack
{
};
 
Hack& operator< (Hack &a , Hack &b)
{
    std::cerr << "小于操作符\n";
    return a;
}
 
Hack& operator> (Hack &a, Hack &b)
{
    std::cerr <<  "大于操作符\n";
    return a;
}
 
int main(int argc, char ** argv)
{
    Hack vector;
    Hack UINT4;
    Hack foo;
 
    vector<UINT4> foo;
 
return(0);
}
#endif
