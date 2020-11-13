#include <cstdio>

using namespace std;

int backtrack(int s[][11], bool taken[11], int cur){
	if(cur == 11){
		return 0;
	}
	int ret = -987654321;
	for(int i = 0; i < 11; ++i){
		if(!taken[i] && s[cur][i] != 0){
			taken[i] = true;
			int cmp = s[cur][i] + backtrack(s, taken, cur + 1);
			if(ret < cmp){
				ret = cmp;
			}
			taken[i] = false;
		}
	}
	return ret;
}

int main(){
	int c;
	scanf("%d", &c);
	for(int a0 = 0; a0 < c; ++a0){
		int s[11][11];
		for(int i = 0; i < 11; ++i){
			for(int j = 0; j < 11; ++j){
				scanf("%d", &s[i][j]);
			}
		}
		bool taken[11] = {};
		printf("%d\n", backtrack(s, taken, 0));
	}
	return 0;
}
