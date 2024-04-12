#include <stdio.h>
#include <string.h>

struct video{
	char title[1001];
	char artist[1001];
	long long int view;
}video[100];

void swap(struct video *x,struct video *y){ 
    struct video temp = *x; 
    *x = *y; 
    *y = temp; 
}

void check(long long int idx1, long long int idx2){
	if(video[idx1].view < video[idx2].view){
        swap(&video[idx1], &video[idx2]); 
        return;
    }
    if(video[idx1].view == video[idx2].view && strcmp(video[idx1].title, video[idx2].title) > 0){
        swap(&video[idx1], &video[idx2]); 
        return;
    } 
} 

void sort(int n){ 
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i+1; j++){
            check(j, j+1);
        } 
    } 
}

void display(int n){
    for(int i=0; i<n; i++){
        printf("%s by %s - %lld\n", video[i].title, video[i].artist, video[i].view);
    } 
}

void read(){
    int counter = 0;
    
    FILE *baca = fopen("testdata.in", "r");
    
    if(!baca) printf("File Not Found!");
    else{
        while(!feof(baca)){
            fscanf(baca, "%[^#]#%[^#]#%lld\n", video[counter].title, video[counter].artist, &video[counter].view);
            counter++;
        }
        sort(counter);
        display(counter);
    }
    
    fclose(baca);
}

int main(){
    read();

    return 0;
}
