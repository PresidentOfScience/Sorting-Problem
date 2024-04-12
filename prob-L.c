#include <stdio.h>

void merge(int arr[], int startIdx, int endIdx, int midIdx){
	int leftArrSize = midIdx - startIdx + 1;
	int rightArrSize = endIdx - midIdx;
	
	int leftArr[leftArrSize], rightArr[rightArrSize];
	
	for(int i=0; i<leftArrSize; i++){
		leftArr[i] = arr[startIdx + i];
	}
	
	for(int i=0; i<rightArrSize; i++){
		rightArr[i] = arr[midIdx + 1 + i];
	}
	
	int idxCurrentLeft = 0, idxCurrentRight = 0;
	int idxCurrentMerged = startIdx;
	
	while(idxCurrentLeft < leftArrSize && idxCurrentRight < rightArrSize){
		if(leftArr[idxCurrentLeft] < rightArr[idxCurrentRight]){
			arr[idxCurrentMerged] = leftArr[idxCurrentLeft];
			idxCurrentMerged++;
			idxCurrentLeft++;
		}
		else{
			arr[idxCurrentMerged] = rightArr[idxCurrentRight];
			idxCurrentMerged++;
			idxCurrentRight++;
		}
	}
	
	while(idxCurrentLeft < leftArrSize){
		arr[idxCurrentMerged] = leftArr[idxCurrentLeft];
		idxCurrentMerged++;
		idxCurrentLeft++;
	}
	
	while(idxCurrentRight < rightArrSize){
		arr[idxCurrentMerged] = rightArr[idxCurrentRight];
		idxCurrentMerged++;
		idxCurrentRight++;
	}
}

void mergeSort(int arr[], int startIdx, int endIdx){
	if(endIdx <= startIdx) return;
	int midIdx = (startIdx + endIdx)/2;
	mergeSort(arr, startIdx, midIdx);
	mergeSort(arr, midIdx+1, endIdx);
	merge(arr, startIdx, endIdx, midIdx);
}

int search(int arr[], int size, int find){
	int left = 0, right = size-1, mid;
	while(left <= right){
		mid = (left + right)/2;
		if(find == arr[mid]) return mid+1;
		else if(find < arr[mid]) right = mid-1;
		else left = mid+1;
	}
	return -1;
}

int main(){
	int N, Q, A[210000], X;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	mergeSort(A, 0, N-1);
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		scanf("%d", &X);
		int result = search(A, N, X);
		printf("%d\n", result);
	}
	
	return 0;
}
