// copy on write: 读时也拷贝技术
// http://coolshell.cn/articles/1443.html
#include <string>
#include <iostream>
#include <sys/time.h>
using namespace std;
 
static long getcurrenttick()
{
  long tick ;
  struct timeval time_val;
  gettimeofday(&time_val , NULL);
  tick = time_val.tv_sec * 1000 + time_val.tv_usec / 1000 ;
  return tick;
}
 
 
int main( )
{
  string the_base(1024 * 1024 * 10, 'x');
  long begin =  getcurrenttick();
  for( int i = 0 ;i< 100 ;++i ) {
    string the_copy = the_base ;
    the_copy[0] = 'y';
  }
  fprintf(stdout,"耗时[%ld] \n",getcurrenttick() - begin );
}
