#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	char s[1001];
	scanf("%s", s);
	int cnt[26] = {};
	for(int i = 0; i < n; ++i){
		++cnt[s[i] - 'a'];
	}
	char max_char = 'a';
	int max_cnt = 0;
	for(int j = 0; j < 26; ++j){
		if(cnt[j] > max_cnt){
			max_cnt = cnt[j];
			max_char = j + 'a';
		}
	}
	printf("%c %d", max_char, max_cnt);
	return 0;
}
