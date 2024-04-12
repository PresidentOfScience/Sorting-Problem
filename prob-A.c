#include <stdio.h>

void merge(long long A[], long long left, long long right){
	if(left == right){
		return;
	}
		
	long long mid = (left+right)/2;
	merge(A, left, mid);
	merge(A, mid+1, right);
	
	long long temp[right - left];
	long long leftIndex = left;
	long long leftLen = mid;
	long long rightIndex = mid+1;
	long long rightLen = right;
	
	long long tempIndex = 0;
	
	while(leftIndex <= leftLen && rightIndex <= rightLen){
		if(A[leftIndex] < A[rightIndex]){
			temp[tempIndex] = A[leftIndex];
			leftIndex++;
			tempIndex++;
		}
		else{
			temp[tempIndex] = A[rightIndex];
			rightIndex++;
			tempIndex++;
		}
	}
	
	while(leftIndex <= leftLen){
		temp[tempIndex] = A[leftIndex];
		leftIndex++;
		tempIndex++;
	}
	while(rightIndex <= rightLen){
		temp[tempIndex] = A[rightIndex];
		rightIndex++;
		tempIndex++;
	}	
	tempIndex = 0;
	long long i = 0;
	for(i=left; i<=right; i++){
		A[i] = temp[tempIndex];
		tempIndex++;
	}
}

int main(){
	long long n;
	long long A[100001];
	scanf("%lld", &n); getchar();
	for(long long i=0; i<n; i++){
		scanf("%lld", &A[i]);
	}
	merge(A, 0, n-1);
	long long max = 0; 
	for(long long i=1; i<n; i++){
		long long b = A[i] - A[i-1];
		if((i == 1) || ((i != 1) && (b > max))){
			max = b;
		}
	}
	long long sum = 0;
	for(long long i=1; i<n; i++){
		long long findnumber = A[i] - A[i-1];
		if(findnumber == max){
			if(sum > 0){
				printf(" ");
			}
			printf("%lld %lld", A[i-1], A[i]);
			sum++;
		}		
	}
	puts("");
}
