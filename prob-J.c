#include <stdio.h>

int main(){
	int T, N;
	double A[10000], mean, median;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		double sum = 0;
		scanf("%d", &N);
		for(int j=0; j<N; j++){
			scanf("%lf", &A[j]);
		}
		for(int j=0; j<N-1; j++){
			for(int k=0; k<N-j-1; k++){
				double temp;
				if(A[k] > A[k+1]){
					temp = A[k];
					A[k] = A[k+1];
					A[k+1] = temp;
				}
			}
		}
		for(int j=0; j<N; j++){
			sum += A[j];
		}
		mean = sum/N;
		if(N%2 == 1) median = A[N/2];
		else median = (A[N/2 - 1] + A[N/2])/2;
		printf("Case #%d:\n", i+1);
		printf("Mean : %.2lf\n", mean);
		printf("Median : %.2lf\n", median);
	}
	
	return 0;
}
