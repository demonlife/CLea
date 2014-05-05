#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define println(format, ...) ({\
  printf(format "\n", __VA_ARGS__); })

#define test(x) ({\
  typeof(x) _x = (x); \
  _x += 1; \
  _x;})

int main(int argc, char *argv[]) {
  println("%s, %d", "string", 1234);

  float f = 0.5f;
  float f2 = test(f);
  printf("%f\n", f2);

  assert(f > 0.1f);
  return 0;
}
