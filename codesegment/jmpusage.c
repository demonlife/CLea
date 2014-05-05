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

typedef void(*func_t)();
func_t test() {
  void func1() {
    printf("%s\n", __func__);
  }
  return func1;
}

int main(int argc, char *argv[]) {
  test()();
  return EXIT_SUCCESS;
}

