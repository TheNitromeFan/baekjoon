#include <cstdio>
#include <cstdlib>
#include <algorithm>

using std::max;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		int bat = 1, oat = 1;
		int btime = 0, otime = 0;
		for(int i = 0; i < n; ++i){
			char c;
			int next;
			scanf(" %c %d", &c, &next);
			if(c == 'B'){
				btime = max(btime + abs(bat - next), otime) + 1;
				bat = next;
			}else{
				otime = max(otime + abs(oat - next), btime) + 1;
				oat = next;
			}
		}
		printf("Case #%d: %d\n", a0, max(btime, otime));
	}
	return 0;
}
