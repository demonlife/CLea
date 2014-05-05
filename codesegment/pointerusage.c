#include <stdio.h>
#include <stdlib.h>

#if 0
int main() {

#if 0
  const int x = 1;

  int *p = &x;
  printf("%d\n", *p);

  *p = 1234;
  printf("%d\n", *p);
#endif
  
  const int x = 1;
  const int *p = &x;
  printf("%d\n", *p);

  return 0;
}
#endif

#if 0
void test() {
  printf("test");
}

typedef void(func_t)();
typedef void(*func_ptr_t)();

int main(int argc, char *argv[]) {
  func_t *f = test;
  func_ptr_t p = test;

  f();
  p();
  return 0;
}
#endif

// 数组指针
void myarray() {
  int x[][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}};
  int (*p)[4] = x;

  int i = 0, k = 0;
  for (i = 0; i < 2; ++i) {
    for (k = 0; k < 4; ++k) {
      printf("[%d, %d] = %d\n", i, k, (*p)[k]);
    }
    ++p;
  }
}

// 指针数组，交错数组
void crossarray() {
  int x[] = {1, 2, 3};
  int y[] = {4, 5};
  int z[] = {7, 8, 9};

  int *ints[] = {NULL, NULL, NULL};
  ints[0] = x;
  ints[1] = y;
  ints[2] = z;
}

int main(void) {
  //myarray();
  crossarray();
  return 0;
}
