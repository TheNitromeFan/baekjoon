#include <cstdio>
#include <cstdlib>


int min(int a, int b){
	
	if(a < b) return a;
	else return b;
}

int distance(int w, int h, int d1, int x1, int d2, int x2){
	
	if(d1 == 1){
		switch(d2){
			case 1: return abs(x1 - x2);
			case 3: return x1 + x2;
			case 4: return w - x1 + x2;
			default: return min(x1 + h + x2, w - x1 + h + w - x2);
		}
	}else if(d1 == 2){
		switch(d2){
			case 2: return abs(x1 - x2);
			case 3: return x1 + h - x2;
			case 4: return w - x1 + h - x2;
			default: return min(x1 + h + x2, w - x1 + h + w - x2);
		}
	}else if(d1 == 3){
		switch(d2){
			case 3: return abs(x1 - x2);
			case 1: return x1 + x2;
			case 2: return h - x1 + x2;
			default: return min(x1 + w + x2, h - x1 + w + h - x2);
		}
	}else{
		switch(d2){
			case 4: return abs(x1 - x2);
			case 1: return x1 + w - x2;
			case 2: return h - x1 + x2;
			default: return min(x1 + w + x2, h - x1 + w + h - x2);
		}
	}
}

int main(void){
	
	int width, height;
	scanf("%d %d", &width, &height);
	int n;
	scanf("%d", &n);
	int **positions = (int **)malloc(n * sizeof(int *));
	for(int i = 0; i < n; i++){
		*(positions+i) = (int *)malloc(2 * sizeof(int));
		scanf("%d %d", *(positions+i), *(positions+i)+1);
	}
	int direction, offset;
	scanf("%d %d", &direction, &offset);
	int total = 0;
	for(int i = 0; i < n; i++){
		total += distance(width, height, direction, offset, **(positions+i), *(*(positions+i)+1));
		free(*(positions+i));
	}
	free(positions);
	printf("%d", total);
	return 0;
}
