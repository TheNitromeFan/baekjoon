#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int b, e;
	scanf("%d %d", &b, &e);
	static int bess[1000001] = {}, els[1000001] = {};
	int pos = 0, timeb = 0;
	for(int i = 0; i < b; ++i){
		int dist;
		char dir;
		scanf("%d %c", &dist, &dir);
		if(dir == 'L'){
			for(int j = 0; j < dist; ++j){
				++timeb;
				--pos;
				bess[timeb] = pos;
			}
		}else{
			for(int j = 0; j < dist; ++j){
				++timeb;
				++pos;
				bess[timeb] = pos;
			}
		}
	}
	pos = 0;
	int timee = 0;
	for(int i = 0; i < e; ++i){
		int dist;
		char dir;
		scanf("%d %c", &dist, &dir);
		if(dir == 'L'){
			for(int j = 0; j < dist; ++j){
				++timee;
				--pos;
				els[timee] = pos;
			}
		}else{
			for(int j = 0; j < dist; ++j){
				++timee;
				++pos;
				els[timee] = pos;
			}
		}
	}
	for(int t = timeb + 1; t <= timee; ++t){
		bess[t] = bess[timeb];
	}
	for(int t = timee + 1; t <= timeb; ++t){
		els[t] = els[timee];
	}
	int cnt = -1;
	int time = 0;
	int limit = max(timeb, timee);
	while(time <= limit){
		if(bess[time] != els[time]){
			++time;
			continue;
		}
		++cnt;
		while(time <= limit && bess[time] == els[time]){
			++time;
		}
	}
	printf("%d", cnt);
	return 0;
}
