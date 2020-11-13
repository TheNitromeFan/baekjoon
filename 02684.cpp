#include <cstdio>

int idx(char s[41], int pos){
	int ret = 0;
	if(s[pos] == 'H'){
		ret += 4;
	}
	if(s[pos + 1] == 'H'){
		ret += 2;
	}
	if(s[pos + 2] == 'H'){
		ret += 1;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int occur[8] = {};
		char flips[41];
		scanf("%s", flips);
		for(int j = 0; j < 38; ++j){
			++occur[idx(flips, j)];
		}
		for(int k = 0; k < 8; ++k){
			printf("%d ", occur[k]);
		}
		printf("\n");
	}
	return 0;
}
