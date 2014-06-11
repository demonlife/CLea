#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(void) {
  setlocale(LC_CTYPE, "en_US.UTF-8"); // locale.h
  wchar_t wc = L'中'; // 宽字符
  char buf[100] = {};

  int len = wctomb(buf, wc);
  printf("%d\n", len);

  int i = 0;
  for (i = 0; i < len; ++ i) {
    printf("0x%02X ", (unsigned char)buf[i]);
  }
  printf("\n");

  #if 0
  wchar_t *ws = L"中国人";
  printf("%ls\n", ws);

  char sbuf[255] = {};
  size_t slen = wcstombs(sbuf, ws, 255);

  for (i = 0; i < slen; ++i) {
    printf("0x%02X ", (unsigned char)sbuf[i]);
  }
  printf("\n");
  #endif

  #if 0
  wchar_t ws[] = L"中国人";
  printf("len %d, size %d\n", wcslen(ws), sizeof(ws));
  unsigned char *b = (unsigned char*)ws;
  len = sizeof(ws);

  for (i = 0; i < len; ++i) {
    printf("%02X ", b[i]);
  }
  #endif

  #if 0
  int *pi = &(int){ 123 };
  printf("%d\n", *pi);
  int *x = (int[]){1, 2, 3, 4};

  int xa[] = {1, 2, [6] = 10, 3, [5] = 4};
  int xlen = sizeof(xa) / sizeof(int);

  for (int i = 0; i < xlen; ++i) {
    printf("x[%d] = %d\n", i, xa[i]);
  }
  #endif

  #if 0
  int x = 1;
  switch (x) {
  case 0 ... 9:
    printf("0..9\n");
    break;
  default:
    printf("default\n");
    break;
  }

  char c = 'C';
  switch(c) {
  case 'a' ... 'z':
    printf("a..z\n");
    break;
  case 'A' ... 'Z':
    printf("A..Z\n");
    break;
  }
  #endif
  
#if 1
  // 字符串分割
  
  //strtok是不可重入的
  char str[] = "root:x::0:root:/root:/bin/bash:";
  char *token;
  token = strtok(str, ":");
  printf("token = %s \n", token);
  while ((token = strtok(NULL, ":")) != NULL)
    printf("%s\n", token);
  
  //strtok_r是可重入的
  
#endif
  
  return 0;
}
