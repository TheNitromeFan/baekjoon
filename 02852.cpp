#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int a = 0, b = 0, lead = 0;
	int timea = 0, timeb = 0;
	int prevs = 0;
	for(int i = 0; i < n; ++i){
		int t, m, s;
		scanf("%d %d:%d", &t, &m, &s);
		s += 60 * m;
		if(lead == 1){
			timea += s - prevs;
		}else if(lead == 2){
			timeb += s - prevs;
		}
		if(t == 1){
			++a;
		}else{
			++b;
		}
		if(a > b){
			lead = 1;
		}else if(a < b){
			lead = 2;
		}else{
			lead = 0;
		}
		prevs = s;
	}
	int s = 48 * 60;
	if(lead == 1){
		timea += s - prevs;
	}else if(lead == 2){
		timeb += s - prevs;
	}
	printf("%02d:%02d\n%02d:%02d", timea / 60, timea % 60, timeb / 60, timeb % 60);
	return 0;
}
