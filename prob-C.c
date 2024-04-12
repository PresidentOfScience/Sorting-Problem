#include <stdio.h>
#define s strcmp(dataProperties[j].nim, dataProperties[j+1].nim)
#include <string.h>

struct data{
   char nim[1001];
   char nama[1001];   
};

int main(){
	FILE *baca = fopen("testdata.in", "r");
	
	int N;
	struct data dataProperties[1001];

	fscanf(baca, "%d", &N);

	for(int i=0; i<N; i++){
    	fscanf(baca, "%s %[^\n]\n", dataProperties[i].nim, dataProperties[i].nama);
	}

	struct data temp;
   
	for(int i=0; i<N; i++){
		for(int j=0; j<N-1-i; j++){
			if(s>0){
				temp = dataProperties[j];
				dataProperties[j] = dataProperties[j+1];
				dataProperties[j+1] = temp;
			}
		}
	}
   
	for(int i=0; i<N; i++){
		printf("%s %s\n", dataProperties[i].nim, dataProperties[i].nama);
	}
   
	fclose(baca);

}
