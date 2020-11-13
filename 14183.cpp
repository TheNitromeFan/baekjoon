#include <cstdio>
#define MAX_HOLES 10

bool match(int c[MAX_HOLES], int b[MAX_HOLES], int sz){
	for(int i = 0; i < sz; ++i){
		if(c[i] < b[i]){
			return false;
		}
	}
	return true;
}

int main(){
	while(true){
		int m, n;
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0){
			break;
		}
		int customer[MAX_HOLES] = {};
		for(int j = 0; j < m; ++j){
			scanf("%d", &customer[j]);
		}
		int ans = 0;
		for(int i = 0; i < n; ++i){
			int box[MAX_HOLES] = {};
			for(int j = 0; j < m; ++j){
				scanf("%d", &box[j]);
			}
			if(match(customer, box, m)){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
