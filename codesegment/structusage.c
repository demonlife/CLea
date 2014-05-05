#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#if 0
typedef struct node_t {
  struct node_t *prev;
  struct node_t *next;
} list_node;

typedef struct {
  struct { // 匿名结构
    int length;
    char chars[100];
  } s;
  int x;
} data_t;

int main() {
  data_t d = { .s.length = 100, .s.chars = "hello", .x = 1234 };
  printf("%d\n%s\n%d\n", d.s.length, d.s.chars, d.x);

  // 直接定义一个匿名结构体变量
  struct { int a; char b[100]; } dd = { .a = 100, .b = "abcd" };
  printf("%s\n%d\n", dd.b, dd.a);

  return 0;
}
#endif

#if 0
typedef struct {
  int x;
  short y[3];
  long long z;
} data_t;

typedef struct {
  long long z;
  int x;
  short y[3];
} data_t2;

int main() {
  printf("x %d\n", offsetof(data_t, x));
  printf("y %d\n", offsetof(data_t, y));
  printf("y[1] %d\n", offsetof(data_t, y[1]));
  printf("z %d\n", offsetof(data_t, z));
  
  printf("sizeof(long long) %d \n", sizeof(long long));
  printf("sizeof(short) %d \n", sizeof(short));

  printf("z %d\n", offsetof(data_t2, z));
  printf("x %d\n", offsetof(data_t2, x));
  printf("y %d\n", offsetof(data_t2, y));
  printf("y[1] %d\n", offsetof(data_t2, y[1]));
  return 0;
} 
#endif

#if 0
int main(int argc, char *argv[]) {
  // 直接定义结构类型和变量
  struct {int x; int y; } a = {1, 2}, a2 = {};
  printf("a.x = %d, a.y = %d\n", a.x, a.y);

  // 函数内部也可以定义结构类型
  struct data { int x; short y; };
  struct data b = {.y = 3};
  printf("b.x=%d, b.y=%d\n", b.x, b.y);

  // 复合字面值
  struct data *c = &(struct data){1, 2};
  printf("c.x=%d, c.y=%d\n", c->x, c->y);

  // 可以直接将结构体类型定义放在符合字面值中
  void *p = &(struct data2 { int x; short y; }){11, 12};

  // 相同内存布局的结构体可以直接转换
  struct data *d = (struct data*)p;
  printf("d.x = %d, d.y=%d\n", d->x, d->y);
  return 0;
}
#endif

typedef struct mystring {
  int length;
  //char chars[]; // 考虑到不同编译器和ANSI C标准的问题，也用char chars[1]或
  // char chars[0]来代替，对这类结构体进行拷贝的时候，尾部结构成员不会被复制
  // 并且不能直接对弹性成员进行初始化
  char chars[1];
} mystring;

int main(int argc, char *argv[]) {
  int len = sizeof(mystring) + 20;
  char buf[len];

  mystring *s = (mystring*)buf; // 将buf转换为struct mystring指针
  s->length = 10;
  strcpy(s->chars, "0123456789");
  printf("%d\n%s\n", s->length, s->chars);

  mystring s2 = *s;
  printf("%d\n%s\n", s2.length, s2.chars); // s2.chars会出现问题

  // 一个常用的联合用法
  union { int x; struct {char a, b, c, d;} bytes;} n = {0x12345678};
  printf("%#x => %x, %x, %x, %x\n", n.x, n.bytes.a, n.bytes.b, n.bytes.c,
         n.bytes.d);
  return 0;
}
