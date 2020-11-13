#include <cstdio>
#include <map>
#define MAX 100

using std::map;

void treat(map<int, int> &m, int d[MAX], int len){
	int ans[MAX];
	for(int i = 0; i < len; ++i){
		if(m.find(d[i]) == m.end()){
			printf("YOU DIED\n");
			return;
		}
		ans[i] = m[d[i]];
	}
	for(int i = 0; i < len; ++i){
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d", &n);
	map<int, int> med;
	for(int i = 0; i < n; ++i){
		int e, name;
		scanf("%d %d", &e, &name);
		med[e] = name;
	}
	int m;
	scanf("%d", &m);
	for(int j = 0; j < m; ++j){
		int len;
		scanf("%d", &len);
		int ill[MAX];
		for(int k = 0; k < len; ++k){
			scanf("%d", &ill[k]);
		}
		treat(med, ill, len);
	}
	return 0;
}
