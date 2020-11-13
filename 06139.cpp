#include <cstdio>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; ++i){
		int s, t, r;
		scanf("%d %d %d", &s, &t, &r);
		int pages = n;
		int time = 0;
		int session = t;
		while(pages > 0){
			if(session > 0){
				++time;
				--session;
				pages -= s;
			}else{
				time += r;
				session = t;
			}
		}
		printf("%d\n", time);
	}
	return 0;
}
