#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <setjmp.h>

#if 0
// jmp
void test_jmp(jmp_buf *env) {
  printf("1.......\n");
  longjmp(*env, 10);
}

int main(int argc, char *argv[]) {
  jmp_buf env;

  int ret = setjmp(env);

  if (ret == 0) {
    test_jmp(&env);
  } else {
    printf("2........(%d)\n", ret);
  }
  return EXIT_SUCCESS;
}
#endif

// gcc 支持函数嵌套
typedef void(*func_t)();
func_t test() {
  int test_a = 10;
  void func1() {
    printf("%s\n", __func__);
    printf("test_a = %d\n", test_a);
  }
  return func1;
}

int main(int argc, char *argv[]) {
  test()();
  return EXIT_SUCCESS;
}

