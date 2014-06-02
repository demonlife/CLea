/*
 * 排序算法
 *
 */
 
 // 插入排序
 void insert_sort(int *arr, int len) {
	int i, j, tmp;
	for (i = 1; i < len; ++i) {
		tmp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = tmp;
	}
 }
 
 // 归并排序
 void merge(int *arr, int start, int mid, int end) {
	int n1 = mid - start + 1;
	int n2 = end - mid;
	
	int left[n1], right[n2]; // 能否想办法去掉
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