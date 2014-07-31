#include <stdio.h>
#include <stdarg.h>

void test(int count, ...) {
  va_list args;
  va_start(args, count);

  int i = 0;
  for (i = 0; i < count; ++i) {
    int value = va_arg(args, int);
    printf("%d\n", value);
  }

  va_end(args);
}

void test2(const char *s, ...) {
  printf("%s\n", s);

  va_list args;
  va_start(args, s);

  char *value;
  do {
    value = va_arg(args, char*);
    if (value)
      printf("%s\n", value);
  } while (value != NULL);
  va_end(args);
}

void test3(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

// 宏定义
#define println(format, ...) ({                 \
  printf(format "\n", __VA_ARGS__);})

int main(int argc, char *argv[]) {
  test(3, 11, 22, 33);
  test2("hello", "aa", "bb", "cc", "dd", NULL);
  test3("%s, %d\n", "hello, world!", 1234);
  println("%s, %d", "string", 1234);
  return 1;
}
