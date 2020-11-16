#include <cstdio>

int main(){
	int road[100] = {}, speed[100] = {};
	int n, m;
	scanf("%d %d", &n, &m);
	int pos = 0;
	for(int i = 0; i < n; ++i){
		int x, s;
		scanf("%d %d", &x, &s);
		for(int j = 0; j < x; ++j, ++pos){
			road[pos] = s;
		}
	}
	pos = 0;
	for(int i = 0; i < m; ++i){
		int x, s;
		scanf("%d %d", &x, &s);
		for(int j = 0; j < x; ++j, ++pos){
			speed[pos] = s;
		}
	}
	int speeding = 0;
	for(pos = 0; pos < 100; ++pos){
		if(speeding < speed[pos] - road[pos]){
			speeding = speed[pos] - road[pos];
		}
	}
	printf("%d", speeding);
	return 0;
}
