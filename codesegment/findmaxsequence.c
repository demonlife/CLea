#include <stdio.h>

int data[] = {-2, 11, -4, 13, -5, 6, -2};

// 时间复杂度：N的3次方
int maxsequence1(int *data, int N) {
  int thissum, maxsum, i, j, k;
  maxsum = 0;

  for (i = 0; i < N; i++) {
    for (j = i; j < N; j++) {
      thissum = 0;
      for( k = i; k <= j; k++) {
        thissum += data[k];
      }

      if (maxsum < thissum) {
        maxsum = thissum;
      }
    }
  }
  return maxsum;
}

// 时间复杂度：N的2次方
int maxsequence2(int *data, int N) {
  int maxsum, thissum, i, j;
  maxsum = 0;
  for (i = 0; i < N; ++i) {
    thissum = 0;
    for (j = i; j < N; ++j) {
      thissum += data[j];

      if (thissum > maxsum)
        maxsum = thissum;
    }
  }
  return maxsum;
}

int max(int a, int b, int c) {
  int tmp = a > b?a:b;
  return tmp > c?tmp:c;
}

int maxsub(int *data, int left, int right) {
  int maxleft, maxright;
  int maxleftborder, maxrightborder;
  int leftborder, rightborder;
  int center, i;

  if (left == right) {
    return data[left] > 0?data[left]:0;
  }

  center = (left + right) / 2;
  maxleft = maxsub(data, left, center);
  maxright = maxsub(data, center + 1, right);
  
  maxleftborder = leftborder = 0;
  for (i = center; i>=left; --i) {
    leftborder += data[i];
    if (leftborder > maxleftborder)
      maxleftborder = leftborder;
  }

  maxrightborder = rightborder = 0;
  for (i = center + 1; i <= right; ++i) {
    rightborder += data[i];
    if (rightborder > maxrightborder)
      maxrightborder = rightborder;
  }

  return max(maxleft, maxright, maxleftborder + maxrightborder);
}

// 时间复杂度：NlogN
int maxsequence3(int *data, int len) {
  return maxsub(data, 0, len - 1);
}


// 时间复杂度：N
int maxsequence4(int *data, int N) {
  int maxsum = 0, tmp = 0, i;
  for (i = 0; i < N; ++i) {
    tmp += data[i];
    if (tmp > maxsum)
      maxsum = tmp;
    else if (tmp < 0)
      tmp = 0;
  }
  return maxsum;
}

int main(void) {
  int maxsum;
  int n = sizeof(data) / sizeof(int);
  maxsum = maxsequence1(data, n);
  printf("maxsum = %d\n", maxsum);
  maxsum = maxsequence2(data, n);
  printf("maxsum = %d\n", maxsum);
  maxsum = maxsequence3(data, n);
  printf("maxsum = %d\n", maxsum);
  maxsum = maxsequence4(data, n);
  printf("maxsum = %d\n", maxsum);
  return 0;
}
