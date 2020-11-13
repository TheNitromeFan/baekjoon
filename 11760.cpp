#include <cstdio>

int main(){
	int n;
	char code[51], guess[51];
	scanf("%d %s %s", &n, code, guess);
	int r = 0, s = 0;
	bool matched_code[51] = {}, matched_guess[51] = {};
	for(int i = 0; i < n; ++i){
		if(code[i] == guess[i]){
			++r;
			matched_code[i] = true;
			matched_guess[i] = true;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(matched_code[j] || matched_guess[i]){
				continue;
			}
			if(code[j] == guess[i]){
				++s;
				matched_code[j] = true;
				matched_guess[i] = true;
				break;
			}
		}
	}
	printf("%d %d", r, s);
	return 0;
}
