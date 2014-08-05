#include <stdio.h>

/*
 * �����㷨
 *
 */
 
 // ��������
 void insert_sort(int *arr, int len) {
	int i, j, tmp;
	for (i = 1; i < len; ++i) {
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > tmp) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = tmp;
	}
 }
 
 // �鲢����
 void merge(int *arr, int start, int mid, int end) {
	int n1 = mid - start + 1;
	int n2 = end - mid;
	
	int left[n1], right[n2]; // �ܷ���취ȥ��
	int i, j, k;
	
	for (i = 0; i < n1; ++i)
		left[i] = arr[start+i];
		
	for (j = 0; j < n2; ++j)
		right[j] = arr[mid+1+j];
		
	i = j = 0;
	k = start;
	while (i < n1 && j < n2) {
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	
	while (i < n1)
		arr[k++] = left[i++];
		
	while (j < n2)
		arr[k++] = right[j++];
}

void sort(int *arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		sort(arr, start, mid);
		sort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}	

// shell ���� �μ��ٶȰٿ����shell�����㷨
// http://baike.baidu.com/view/549624.htm
void shellsort(int *arr, int n) {
  int gap, i, j, tmp;
  for(gap = n / 2; gap > 0; gap /= 2) {
    for(i = gap; i < n; ++i) {
      for(j = i - gap; j >= 0 && arr[j] > arr[j+gap]; j -= gap) {
        tmp = arr[j];
        arr[j] = arr[j+gap];
        arr[j+gap] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  shellsort(arr, 10);
  for(int i = 0; i < 10; ++i)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
