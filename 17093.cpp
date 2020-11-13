#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int px[1000], py[1000], qx[1000], qy[1000];
	for(int i = 0; i < n; ++i){
		scanf("%d %d", &px[i], &py[i]);
	}
	for(int j = 0; j < m; ++j){
		scanf("%d %d", &qx[j], &qy[j]);
	}
	long long maxDist = -1;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			long long dist = (long long)(px[i] - qx[j]) * (px[i] - qx[j]) + (long long)(py[i] - qy[j]) * (py[i] - qy[j]);
			if(dist > maxDist){
				maxDist = dist;
			}
		}
	}
	printf("%lld", maxDist);
	return 0;
}
