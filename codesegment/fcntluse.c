#if 0
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MSG_TRY "try again\n"

int main(void) {
  char buf[10];
  int n;
  int flags;

  flags = fcntl(STDIN_FILENO, F_GETFL);
  flags |= O_NONBLOCK;
  if (fcntl(STDIN_FILENO, F_SETFL, flags) == -1) {
    perror("fcntl");
    exit(1);
  }
 tryagain:
  n = read(STDIN_FILENO, buf, 10);
  if (n < 0) {
    if (errno == EAGAIN) {
      sleep(2);
      write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
      goto tryagain;
    }
    perror("read stding");
    exit(1);
  }
  write(STDOUT_FILENO, buf, n);
  return 0;
}
#endif

#if 1
// 通过命令行的第一个参数指定一个文件描述符，同时利用Shell的重定向功能在该描述符上打开文件，
// 然后用fcntl的F_GETFL命令取出File Status Flag并打印
// 调用方法：./a.out 0 < /dev/tty, 将0重定向到/dev/tty上
// ./a.out 1 > temp.foo， 将1重定向到temp.foo文件上
// ./a.out 2 2>>temp.foo
// ./a.out 5 5<>temp.foo, 将5重定向到temp.foo，并且是可读写的
// 
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int val;
  if (argc != 2) {
    fputs("usage: a.out <descriptor#>\n", stderr);
    exit(1);
  }

  if ((val = fcntl(atoi(argv[1]), F_GETFL)) < 0) {
    printf("fcntl error for fd %d\n", atoi(argv[1]));
    exit(1);
  }

  switch(val & O_ACCMODE) {
  case O_RDONLY:
    printf("read only");
    break;
  case O_WRONLY:
    printf("write only");
    break;
  case O_RDWR:
    printf("read write");
    break;
  default:
    fputs("invalid access mode\n", stderr);
    exit(1);
  }

  if (val & O_APPEND)
    printf(", append");
  if (val & O_NONBLOCK)
    printf(", nonblocking");
  putchar('\n');
  return 0;
}
#endif
