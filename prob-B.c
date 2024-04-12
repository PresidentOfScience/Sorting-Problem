#include <stdio.h>
#include <string.h>

struct data {
	long int R;
	char M[50];
};

int main(){
	FILE *baca;
	baca = fopen("./testdata.in", "r");
	
	int N;
	fscanf(baca, "%d", &N);
	struct data plantData[N], temp;	

	for(int i=0; i<N; i++){
		fscanf(baca, "%ld#%[^\n]", &plantData[i].R, plantData[i].M);
	}
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-i-1; j++){
			if(strcmp(plantData[j].M, plantData[j+1].M) > 0){
				temp = plantData[j];
				plantData[j] = plantData[j+1];
				plantData[j+1] = temp;
			}
		}
	}
	for(int i=0; i<N; i++){
		printf("%ld %s\n", plantData[i].R, plantData[i].M);
	}
	
	return 0;
}
