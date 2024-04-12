#include <stdio.h>

// prob-M : Top Half

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int startIdx, int endIdx){
	int pivot = arr[endIdx];
	int idxLesser = startIdx - 1;
	
	for(int i=startIdx; i<endIdx; i++){
		if(arr[i] < pivot){
			idxLesser++;
			swap(&arr[i], &arr[idxLesser]);
		}
	}
	
	swap(&arr[idxLesser + 1], &arr[endIdx]);
	return idxLesser + 1;
}

void quickSort(int arr[], int startIdx, int endIdx){
	if(endIdx <= startIdx) return;
	int partitionIdx = partition(arr, startIdx, endIdx);
	quickSort(arr, startIdx, partitionIdx-1);
	quickSort(arr, partitionIdx+1, endIdx);
}

int main(){
	int N, A[20000000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	quickSort(A, 0, N-1);
	int mid = N/2 + 1;
	for(int i=mid; i<N; i++){
		printf("%d", A[i]);
		if(i != N-1) printf(" ");
		if(i == N-1) printf("\n");
	}
	
	return 0;
}
