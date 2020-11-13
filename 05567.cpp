#include <cstdio>

int main(){
	int n, m;
	scanf("%d\n%d", &n, &m);
	bool friends[501] = {false}, friends2[501] = {false};
	int list[20000];
	for(int i = 0; i < m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == 1){
			friends[b] = true;
		}else if(b == 1){
			friends[a] = true;
		}
		list[2*i] = a;
		list[2*i+1] = b;
	}
	for(int i = 0; i < m; ++i){
		int a = list[2*i], b = list[2*i+1];
		if(friends[a]){
			friends2[b] = true;
		}else if(friends[b]){
			friends2[a] = true;
		}
	}
	int count = 0;
	for(int i = 2; i <= n; ++i){
		if(friends[i] || friends2[i]){
			++count;
		}
	}
	printf("%d", count);
	return 0;
}
