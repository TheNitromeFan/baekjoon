#include <cstdio>

char s[100003], f[100003], st[100003], ft[100003];

char press(char c){
	return (c == '0') ? '1' : '0';
}

int presses(int n, int prev_cnt){
	int cnt = prev_cnt;
	for(int i = 1; i < n-1; ++i){
		if(st[i-1] != ft[i-1]){
			st[i-1] = press(st[i-1]);
			st[i] = press(st[i]);
			st[i+1] = press(st[i+1]);
			++cnt;
		}
	}
	if(st[n-2] == ft[n-2] && st[n-1] == ft[n-1]){
		return cnt;
	}else if(press(st[n-2]) == ft[n-2] && press(st[n-1]) == ft[n-1]){
		return cnt + 1;
	}else{
		return -1;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", f);
	int ans = -1;
	int tmp;
	for(int i = 0; i < n; ++i){
		st[i] = s[i];
		ft[i] = f[i];
	}
	tmp = presses(n, 0);
	if(ans == -1 || (tmp != -1 && ans > tmp)){
		ans = tmp;
	}
	for(int i = 0; i < n; ++i){
		st[i] = s[i];
		ft[i] = f[i];
	}
	st[0] = press(st[0]);
	st[1] = press(st[1]);
	tmp = presses(n, 1);
	if(ans == -1 || (tmp != -1 && ans > tmp)){
		ans = tmp;
	}
	printf("%d", ans);
	return 0;
}
