#include <stdio.h>

void merge(int arr[], int min, int mid, int max){
	int n1 = mid - min + 1;
	int n2 = max - mid;
	int l[n1], r[n2];
	
	for(int i = 0; i < n1; i++){
		l[i] = arr[min + i];
	}
	for(int j = 0; j < n2; j++){
		r[j] = arr[mid + 1 + j];
	}
	
	int i = 0, j = 0, k = min;
	while(i < n1 && j < n2){
		if(l[i] < r[j]){
			arr[k] = l[i];
			i++;
		}
		else{
			arr[k] = r[j];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		arr[k] = l[i];
		i++;
		k++;
	}
	while(j < n2){
		arr[k] = r[j];
		j++;
		k++;
	}
}

void printMerge(int arr[], int size){
	printf("Array yang sudah tersortir: ");
	for(int i = 0; i < size; i++){
		if(i == size - 1){
			printf("%d", arr[i]);
		}
		else{
		printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void mergeSort(int arr[], int min, int max){
	if(min < max){
		int mid = min + (max - min)/2;
		mergeSort(arr, min, mid);
		mergeSort(arr, mid + 1, max);
		merge(arr, min, mid, max);
	}
}

int main(){
	int arr[] = {5, 6, 1, 3, 4, 2, 9, 10, 7, 8};
	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	mergeSort(arr, 0, n - 1);
	printMerge(arr, n);

	return 0;
}
