#include <cstdio>

int main(){
	for(int a0 = 0; a0 < 3; ++a0){
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int start = 60 * 60 * h + 60 * m + s;
		scanf("%d:%d:%d", &h, &m, &s);
		int end = 60 * 60 * h + 60 * m + s;
		if(end < start){
			end += 60 * 60 * 24;
		}
		int ans = 0;
		for(int time = start; time <= end; ++time){
			h = time / 60 / 60 % 24;
			m = time / 60 % 60;
			s = time % 60;
			if((h + m + s) % 3 == 0){
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
