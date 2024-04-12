#include <stdio.h>
#include <string.h>

struct taskManager{
	char S[100];
	int deadline;
};

int main(){
	struct taskManager schedule[1000];
	int N;
	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		scanf("%s %d", schedule[i].S, &schedule[i].deadline);
	}
	
	for(int i=0; i<N-1; i++){
		for(int j=0; j<N-1-i; j++){
			struct taskManager temp;
			if(schedule[j].deadline > schedule[j+1].deadline){
				temp = schedule[j];
				schedule[j] = schedule[j+1];
				schedule[j+1] = temp;
			}
			else if(schedule[j].deadline == schedule[j+1].deadline){
				if(strcmp(schedule[j].S, schedule[j+1].S) > 0){
					temp = schedule[j];
					schedule[j] = schedule[j+1];
					schedule[j+1] = temp;
				}
			}
		}
	}
	
	for(int i=0; i<N; i++){
		printf("%s\n", schedule[i].S);
	}
	
	return 0;
}
