#include <cstdio>

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	bool arr[2000001] = {};
	for(int i = 0; i < n; ++i){
		int period;
		scanf("%d", &period);
		if(arr[period]){
			continue;
		}
		int t = period;
		while(t <= c){
			arr[t] = true;
			t += period;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= c; ++i){
		if(arr[i]){
			++cnt;
		}
	}
	printf("%d", cnt);
	return 0;
}
