#include <stdio.h>

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
  
int main() {
  char s[] = "abccdcdcd";
  deleteonecharacterinstr(s, 'c');
  printf("%s\n", s);
  return 0;
}
