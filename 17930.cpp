#include <cstdio>

int main(){
	int cap, x;
	scanf("%d %d", &cap, &x);
	int in = 0;
	int cnt = 0;
	for(int i = 0; i < x; ++i){
		char act[7];
		int group;
		scanf("%s %d", act, &group);
		if(act[0] == 'e' && in + group > cap){
			++cnt;
		}else if(act[0] == 'e'){
			in += group;
		}else{
			in -= group;
		}
	}
	printf("%d", cnt);
	return 0;
}
