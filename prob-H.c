#include <stdio.h>
#include <string.h>

void merge(char str[], int l, int r){
	if (r == l) return;
	
	int m = (l+r)/2;
	merge(str, l, m);
	merge(str, m+1, r);
	
	char temp[r-l];
	int left = l, leftm = m, right = m+1, rightm = r;
	int idx = 0;
	
	while(left <= leftm && right <= rightm){
		if(str[left] > str[right]){
			temp[idx++] = str[right++];
		}
		else{
			temp[idx++] = str[left++];
		}
	}
	while(left <= leftm){
		temp[idx++] = str[left++];
	}
	while(right <= rightm){
		temp[idx++] = str[right++];
	}
	idx = 0;
	for(int i=l; i<=r; i++){
		str[i] = temp[idx++];
	}
}

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	char str[R+1][C+1], temp[C+1];
	for(int i=0; i<R; i++){
		scanf("%s", str[i]);
	}
	for(int i=0; i<R; i++){
		merge(str[i], 0, C-1);
	}
	for(int i=0; i<R-1; i++){
		for(int j=0; j<R-i-1; j++){
			if(strcmp(str[j], str[j+1]) < 0){
				strcpy(temp, str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], temp);
			}
		}
	}
	for(int i=0; i<R; i++){
		printf("%s\n", str[i]);
	}
	
	return 0;
}
