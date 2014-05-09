/*
** 问题： 有一组N个数而要确定其中第k个最大者
**
*/

#include <stdio.h>
#include <stdlib.h>

// 先排序，在返回第k个位置的数据
// 排序算法有很多中，这里就先用冒泡排序吧，目前也只记得冒泡排序了。
void popsort(int *narray, int count) {
  int i = 0, j = 0, tmp = 0;
  for (i = 0; i < count - 1; ++i) {
    for (j = i + 1; j < count; ++j) {
      if (narray[i] < narray[j]) {
        tmp = narray[j];
        narray[j] = narray[i];
        narray[i] = tmp;
      }
    }
  }
}

int getkthmax(int *narray, int k) {
  if (k < 0) {
    printf("k is less than 1\n");
    return 0;
  }
  return narray[k-1];
}

int getkthmaxbyread(int *narray, int k, int len) {
  size_t size = sizeof(int) * k;
  int *tmparr = (int*) malloc(size); // 初始化需要选择个数的数组
  int i = 0, j = 0;
  for (i = 0; i < k; ++i) {
    tmparr[i] = narray[i];
  }
  popsort(tmparr, k); // 降序排列

#if 0
  // 对数组逆序
  int tmpv;
  for (i = 0, j = k - 1; i < j; ++i, --j) {
    tmpv = tmparr[i];
    tmparr[i] = tmparr[j];
    tmparr[j] = tmpv;
  }
#endif

  for (i = k; i < len; ++i) {
    if (narray[i] < tmparr[k-1]) // 小于tmparr中的最小值，直接进行下一次迭代
      continue;

    for (j = 0; j < k; ++j) {
      // 比当前值大，则将该值存入数组中，并且移动其他元素
      if (narray[i] > tmparr[j]) {
        int mvt = 0;
        for (mvt = k - 1; mvt > j; --mvt) { // 移动元素
          tmparr[mvt] = tmparr[mvt - 1];
        }
        tmparr[j] = narray[i];
        //continue; // 注意，千万不要
        break;
      }
    }
  }

  return tmparr[k-1];
}

int main(void) {
  int narr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 11, 13, 14};
  int len = sizeof(narr) / sizeof(int);

  popsort(narr, len);
  int kth = getkthmax(narr, 5);
  printf("kth max is: %d\n", kth);
  
  int narr2[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 12, 11, 13, 14};
  int kth2 = getkthmaxbyread(narr2, 5, len);
  printf("kth max is: %d\n", kth2);

  if (kth == kth2) {
    printf("both two way's result are equal\n");
  }
  
  return 0;
}
