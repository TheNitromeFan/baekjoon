#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char boxes[101][101];
	for(int i = 0; i < n; ++i){
		scanf("%s", boxes[i]);
	}
	int left = -1, right = m;
	for(int j = 0; j < m; ++j){
		if(boxes[n - 1][j] != '.'){
			left = j;
			break;
		}
	}
	for(int j = m - 1; j >= 0; --j){
		if(boxes[n - 1][j] != '.'){
			right = j;
			break;
		}
	}
	int mx = 0, mass = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(boxes[i][j] != '.'){
				mx += j;
				++mass;
			}
		}
	}
	double x = mx / (double)mass;
	if(x < left - 0.5){
		printf("left");
	}else if(x > right + 0.5){
		printf("right");
	}else{
		printf("balanced");
	}
	return 0;
}
