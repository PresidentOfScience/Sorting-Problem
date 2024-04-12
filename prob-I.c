#include <stdio.h>

int main(){
	int T, N;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int A[1000], firstRow[1000], secondRow[1000], diff[1000];
		scanf("%d", &N);
		for(int j=0; j<N; j++){
			scanf("%d", &A[j]);
		}
		for(int j=0; j<N-1; j++){
			for(int k=0; k<N-1-j; k++){
				int temp;
				if(A[k] > A[k+1]){
					temp = A[k];
					A[k] = A[k+1];
					A[k+1] = temp;
				}
			}
		}
		for(int j=0; j<N/2; j++){
			firstRow[j] = A[j];
			secondRow[j] = A[N/2 + j];
		}
		for(int j=0; j<N/2-1; j++){
			diff[j] = firstRow[j+1] - firstRow[j];
			diff[N/2-1+j] = secondRow[j+1] - secondRow[j];
		}
		int max = 0;
		for(int j=0; j<N-2; j++){
			if(diff[j] > max) max = diff[j];
		}
		printf("Case #%d: %d\n", i+1, max);
	}
	
	return 0;
}
