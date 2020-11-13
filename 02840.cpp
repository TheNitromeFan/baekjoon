#include <cstdio>
#include <cstring>

int main(){
	char wheel[26];
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		wheel[i] = '?';
	}
	int pointer = 0;
	int selected[26] = {};
	memset(selected, -1, sizeof(selected));
	for(int j = 0; j < k; ++j){
		int s;
		char c;
		scanf("%d %c", &s, &c);
		pointer = (pointer + s) % n;
		if(wheel[pointer] != '?' && wheel[pointer] != c){
			printf("!");
			return 0;
		}
		if(selected[c - 'A'] != -1 && selected[c - 'A'] != pointer){
			printf("!");
			return 0;
		}
		wheel[pointer] = c;
		selected[c - 'A'] = pointer;
	}
	for(int i = pointer + n; i > pointer; --i){
		printf("%c", wheel[i % n]);
	}
	return 0;
}
