#include <cstdio>
#include <cstring>

int win[101][10001];

int game(int n, int total_turns, int num, int turns){
	if(turns == total_turns){
		return total_turns % 2 == 0 ? num > n : num <= n;
	}
	if(win[turns][num] != -1){
		return win[turns][num];
	}
	win[turns][num] = 0;
	int tens[4] = {1, 10, 100, 1000};
	for(int i = 0; i < 4; ++i){
		int digit = num / tens[i] % 10;
		if(digit < 9){
			win[turns][num] |= !game(n, total_turns, num + tens[i], turns + 1);
		}else{
			win[turns][num] |= !game(n, total_turns, num - 9 * tens[i], turns + 1);
		}
	}
	return win[turns][num];
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	memset(win, -1, sizeof(win));
	printf("%s", game(n, m, n, 0) ? "koosaga" : "cubelover");
	return 0;
}
