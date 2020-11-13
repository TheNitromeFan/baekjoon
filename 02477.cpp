#include <cstdio>

int main(){
	int mult;
	scanf("%d", &mult);
	int dir[7], dist[7];
	for(int i = 0; i < 6; ++i){
		scanf("%d %d", &dir[i], &dist[i]);
	}
	dir[6] = dir[0];
	dist[6] = dist[0];
	int bigw, bigh, smallw, smallh;
	for(int i = 0; i < 6; ++i){
		if((dir[i] == 4 && dir[i+1] == 1) || (dir[i] == 1 && dir[i+1] == 3)
		|| (dir[i] == 3 && dir[i+1] == 2) || (dir[i] == 2 && dir[i+1] == 4)){
			bigw = dist[(i + 3) % 6];
			bigh = dist[(i + 4) % 6];
			smallw = dist[i];
			smallh = dist[i+1];
			break;
		}
	}
	printf("%d", (bigw * bigh - smallw * smallh) * mult);
	return 0;
}
