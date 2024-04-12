#include <stdio.h>

int main(){
	int T, N, X, A[1200];
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int counter = 0;
		scanf("%d %d", &N, &X);
		for(int j=0; j<N; j++){
			scanf("%d", &A[j]);
		}
		for(int j=0; j<N-1; j++){
			for(int k=0; k<N-j-1; k++){
				if(A[k] > A[k+1]){
					int temp;
					temp = A[k];
					A[k] = A[k+1];
					A[k+1] = temp;
					counter++;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, X*counter);
	}
	
	return 0;
}
