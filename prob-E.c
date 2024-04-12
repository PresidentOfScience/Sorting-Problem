#include <stdio.h>
#include <string.h>

struct temperatures{
	char city[1200];
	double temperature;
	char metric;
	double result;
};

int main(){
	struct temperatures data[1000];
	int counter = 0;
	
	FILE *baca = fopen("testdata.in", "r");
	
	while(!feof(baca)){
		fscanf(baca, "%[^#]#%lf#%c\n", data[counter].city, &data[counter].temperature, &data[counter].metric);
		counter++;
	}
	
	for(int i=0; i<counter; i++){
		if(data[i].metric == 'F') data[i].result = (data[i].temperature - 32)*5/9;
		else if(data[i].metric == 'C') data[i].result = data[i].temperature;
	}
	
	for(int i=0; i<counter-1; i++){
		for(int j=0; j<counter-1-i; j++){
			struct temperatures temp;
			if(data[j].result > data[j+1].result){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			else if(data[j].result == data[j+1].result){
				if(strcmp(data[j].city, data[j+1].city) > 0){
					temp = data[j];
					data[j] = data[j+1];
					data[j+1] = temp;
				}
			}
		}
	}

	for(int i=0; i<counter; i++){
		printf("%s is %.2lf%c\n", data[i].city, data[i].temperature, data[i].metric);
	}
	
	fclose(baca);
	
	return 0;
}
