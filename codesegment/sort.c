/*
 * ÅÅĞòËã·¨
 *
 */
 
 // ²åÈëÅÅĞò
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