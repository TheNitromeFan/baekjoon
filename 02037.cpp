#include <cstdio>
#include <cstring>
#include <map>
#include <utility>

using namespace std;

map<char, pair<int, int>> key;

void init(){
	key[' '] = {1, 1};
	for(int c = 'A'; c <= 'Z'; ++c){
		if(c <= 'C'){
			key[c] = {2, c - 'A' + 1};
		}else if(c <= 'F'){
			key[c] = {3, c - 'C'};
		}else if(c <= 'I'){
			key[c] = {4, c - 'F'};
		}else if(c <= 'L'){
			key[c] = {5, c - 'I'};
		}else if(c <= 'O'){
			key[c] = {6, c - 'L'};
		}else if(c <= 'S'){
			key[c] = {7, c - 'O'};
		}else if(c <= 'V'){
			key[c] = {8, c - 'S'};
		}else{
			key[c] = {9, c - 'V'};
		}
	}
}

int main(){
	init();
	int p, w;
	scanf("%d %d\n", &p, &w);
	char s[1001];
	scanf("%[^\n]s", s);
	int slen = strlen(s);
	int ans = p * key[s[0]].second;
	for(int i = 1; i < slen; ++i){
		if(key[s[i]].first != 1 && key[s[i-1]].first == key[s[i]].first){
			ans += w;
		}
		ans += p * key[s[i]].second;
	}
	printf("%d", ans);
	return 0;
}
