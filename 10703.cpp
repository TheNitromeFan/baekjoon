#include <cstdio>
#define MAX 3001

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	char picture[MAX][MAX];
	for(int i = 0; i < h; ++i){
		scanf("%s", picture[i]);
	}
	int ground[MAX] = {};
	int fall = 3001;
	for(int j = 0; j < w; ++j){
		int dist = 0;
		bool meteor = false;
		int i = 0;
		for(; i < h; ++i){
			if(picture[i][j] == 'X'){
				meteor = true;
				dist = 0;
			}else if(picture[i][j] == '#'){
				if(meteor && dist < fall){
					fall = dist;
				}
				break;
			}else{
				++dist;
			}
		}
		ground[j] = i;
		if(meteor && dist < fall){
			fall = dist;
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(i >= ground[j]){
				printf("%c", picture[i][j]);
			}else if(i >= fall){
				printf("%c", picture[i - fall][j]);
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	return 0;
}
