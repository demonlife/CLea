#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50 

typedef struct Node {
  int v;
  int next;
} StaticLinkList[MAXSIZE];

void InitStaticList(StaticLinkList L) {
  int i;
  for (i = 0; i < MAXSIZE - 1; ++i)
    L[i].next = i + 1;
  L[i].next = 0; // 作为分配结束标志
}

int Malloc_SLL(StaticLinkList L) {
  int k = L[0].next;
  if (k != 0)
    L[0].next = L[k].next;
  else
    printf("has no space for malloc\n");
  return k;
}

void Free_SLL(StaticLinkList L, int k) {
  if (k != 0) {
    L[k].next = L[0].next;
    L[0].next = k;
  }
}

void InitList(StaticLinkList L, int *head) {
  *head = Malloc_SLL(L);

  if (*head == 0) {
    printf("malloc error\n");
    return;
  } else {
    L[*head].v = -1;
    L[*head].next = 0;
  }
}

int LengthList(StaticLinkList L, int head) {
  int len = 0;
  int tmp = L[head].next;
  while (tmp != 0) {
    len ++;
    tmp = L[tmp].next;
  }
  return len;
}

void InsertList(StaticLinkList L, int head, int i, int v) {
  int len = LengthList(L, head);
  //printf("insert len: %d, i = %d, v = %d\n", len, i, v);
  if (i < 1 || i > len + 1) {
    printf("wrong location to insert\n");
    return;
  }

  int curloc = 1;
  while (head != 0 && curloc < i) {
    head = L[head].next;
    curloc ++;
  }
  int tmp = Malloc_SLL(L);
  if (tmp != 0) {
    L[tmp].next = L[head].next;
    L[head].next = tmp;
    L[tmp].v = v;
  } else {
    printf("insert value: %d error\n", v);
    return;
  }
}

void DeleteList(StaticLinkList L, int head, int i, int *v) {
  int len = LengthList(L, head);
  if (i < 1 || i > len) {
    printf("wrong location to delete value\n");
    return;
  }

  int curloc = 1;
  int tmp = head;
  head = L[head].next;
  while (head != 0 && curloc < i) {
    tmp = head;
    head = L[head].next;
    curloc ++;
  }

  *v = L[head].v;
  L[tmp].next = L[head].next;
  Free_SLL(L, head);
}

void ShowList(StaticLinkList L, int head) {
  head = L[head].next;
  while (head != 0) {
    printf("%d ", L[head].v);
    head = L[head].next;
  }
  printf("\n");
}

int main(void) {
  StaticLinkList L;
  InitStaticList(L);

  int head = 0;
  InitList(L, &head);

#ifdef TEST 
  int len = LengthList(L, head);
  printf("len = %d\n", len);

  InsertList(L, head, 1, 1);
  InsertList(L, head, 2, 2);
  InsertList(L, head, 3, 3);
  InsertList(L, head, 4, 4);
  len = LengthList(L, head);
  printf("len = %d\n", len);
  ShowList(L, head);

  int v;
  DeleteList(L, head, 3, &v);
  printf("delete value=%d\n", v);
  ShowList(L, head);

  InsertList(L, head, 3, 5);
  ShowList(L, head);
#else
  int i;
  for (i = 0; i < 5; ++i) {
    InsertList(L, head, i+1, i+1);
  }
  ShowList(L, head);
  printf("list len = %d\n", LengthList(L, head));
#endif

  return 0;
}
