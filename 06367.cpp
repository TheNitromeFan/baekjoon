#include <cstdio>

struct color{
	int red;
	int green;
	int blue;
} rgb[16];

int dist(int r1, int g1, int b1, int r2, int g2, int b2){
	return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}

int main(){
	for(int i = 0; i < 16; ++i){
		scanf("%d %d %d", &rgb[i].red, &rgb[i].green, &rgb[i].blue);
	}
	while(true){
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		if(r == -1 && g == -1 && b == -1){
			break;
		}
		int ind = 0;
		int minDist = 2000000000;
		for(int i = 0; i < 16; ++i){
			int d = dist(r, g, b, rgb[i].red, rgb[i].green, rgb[i].blue);
			if(minDist > d){
				minDist = d;
				ind = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, rgb[ind].red, rgb[ind].green, rgb[ind].blue);
	}
	return 0;
}
