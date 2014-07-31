#include <stdio.h>

// 使用GCC扩展typeof可以获知参数的类型
#define test_add(x, add) ({                         \
      typeof(add) _add = (add); typeof(x) _x = (x); _x += _add; _x;})

int main() {
  float f = 0.5f;
  float f2 = test_add(f, 10);
  int i = 10;
  int i2 = test_add(i, 10.5);
  printf("%f\n", f2);
  printf("%d\n", i2);
  return 0;
}
