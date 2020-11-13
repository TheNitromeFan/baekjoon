#include <cstdio>
#define MAX 9999

int main(){
	while(true){
		int n, m;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		scanf("%d", &m);
		bool registered[MAX+1] = {};
		for(int i = 0; i < n; ++i){
			int course;
			scanf("%d", &course);
			registered[course] = true;
		}
		bool clear = true;
		for(int j = 0; j < m; ++j){
			int c, r;
			scanf("%d %d", &c, &r);
			int cnt = 0;
			for(int k = 0; k < c; ++k){
				int course;
				scanf("%d", &course);
				if(registered[course]){
					++cnt;
				}
			}
			if(cnt < r){
				clear = false;
			}
		}
		if(clear){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}
