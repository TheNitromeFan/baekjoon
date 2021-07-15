#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int first = -1, last = -1;
	for(int i = 0; i < n; ++i){
		int h, m;
		scanf("%d:%d", &h, &m);
		int time = h * 60 + m;
		if((first == -1 || first > time) && time >= 6 * 60 + 30 && time <= 19 * 60){
			first = time;
		}
		if(last < time && time >= 6 * 60 + 30 && time <= 19 * 60){
			last = time;
		}
	}
	int charge = 0;
	if(first >= 6 * 60 + 30 && first <= 10 * 60 && last >= 6 * 60 + 30 && last <= 16 * 60){
		charge = 24000;
	}else if(first >= 6 * 60 + 30 && first <= 10 * 60 && last >= 16 * 60 + 1 && last <= 19 * 60){
		charge = 36000;
	}else if(first >= 10 * 60 + 1 && first <= 16 * 60 && last >= 10 * 60 + 1 && last <= 16 * 60){
		charge = 16800;
	}else if(first >= 10 * 60 + 1 && first <= 19 * 60 && last >= 16 * 60 + 1 && last <= 19 * 60){
		charge = 24000;
	}
	printf("%d\n", charge);
	return 0;
}
