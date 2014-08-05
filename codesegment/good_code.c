#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 删除字符串中的某个字符
void deleteonecharacterinstr(char *s, int c) {
  int i,j;
  for(i=j=0; s[i] != '\0'; ++i) {
    if(s[i] != c)
      s[j++] = s[i];
  }
  s[j] = '\0';
}

// 计算x中二进制表示时1的个数
int bitcount(int x) {
  int b=0;
  for(; x != 0; x&=x-1) {
    ++b;
  }
  return b;
}
  
// 删除字符串末尾的空格，制表符，与换行符
int trim(char *str) {
  int len;
  for(len = strlen(str) - 1; len >= 0; --len)
    if(str[len] != '\n' && str[len] != ' ' && str[len] != '\t')
      break;
  str[len+1] = '\0';
  return len;
}

int main() {
  char s[] = "abccdcdcd   ";
  deleteonecharacterinstr(s, 'c');
  printf("%s\n", s);

  char s2[] = "a bbbbbbb        s";
  trim(s2);
  printf("%send\n", s2);
  return 0;
}
