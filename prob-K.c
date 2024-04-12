#include <stdio.h>

int main(){	
	int T, S[255], max, min;
	scanf("%d", &T); getchar();
	for(int i=0; i<T; i++){
		for(int j=0; j<25; j++){
			scanf("%d", &S[j]);
			getchar();
		}
		int temp;
		for(int i=0; i<25; i++){
			for(int j=0; j<24-i; j++){
				if(S[j] >= S[j+1]){
					temp = S[j];
					S[j] = S[j+1];
					S[j+1] = temp;
				}
			}
		}
		min = S[0]/2;
		max = S[24]/2;
		printf("Case #%d: %d %d %d %d %d\n", i+1, min, S[1]-min, S[4]-min, S[23]-max, max);
	}

	return 0;
}
