#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int alphabet_index(char c){
	if(c == 'b'){
		return 0;
	}else if(c <= 'h'){
		return c - 'b' - 1;
	}else if(c <= 'm'){
		return c - 'b' - 2;
	}else if(c <= 's'){
		return c - 'b' - 3;
	}else{
		return c - 'b' - 4;
	}
}

bool can_read(string s, string bitmask){
	for(char c : s){
		if(c == 'a' || c == 'c' || c == 'i' || c == 'n' || c == 't'){
			continue;
		}else if(!bitmask[alphabet_index(c)]){
			return false;
		}
	}
	return true;
}

int count_words(string s[50], int word_count, string bitmask){
	int cntr = 0;
	for(int i = 0; i < word_count; ++i){
		if(can_read(s[i], bitmask)){
			++cntr;
		}
	}
	return cntr;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	if(k <= 4){
		printf("0");
		return 0;
	}
	string s[50];
	for(int i = 0; i < n; ++i){
		char tmp[16];
		scanf("%s", tmp);
		s[i] = tmp;
	}
	string bitmask(k-5, 1);
	bitmask.resize(21, 0);
	int mx = 0;
	do{
		int cmp = count_words(s, n, bitmask);
		if(cmp > mx){
			mx = cmp;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	printf("%d", mx);
	return 0;
}
