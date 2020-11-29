#include <cstdio>
#include <deque>

using std::deque;

void turn(deque<char> &cog, int dir){
	if(dir == 1){
		cog.push_front(cog.back());
		cog.pop_back();
	}else{
		cog.push_back(cog.front());
		cog.pop_front();
	}
}

int main(){
	deque<char> cogs[1000];
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; ++i){
		char state[9];
		scanf("%s", state);
		for(int j = 0; j < 8; ++j){
			cogs[i].push_back(state[j]);
		}
	}
	int k;
	scanf("%d", &k);
	for(int t = 0; t < k; ++t){
		int n, dir;
		scanf("%d %d", &n, &dir);
		--n;
		int i;
		for(i = n - 1; i >= 0; --i){
			if(cogs[i][2] == cogs[i + 1][6]){
				break;
			}
		}
		for(int j = n - 1; j > i; --j){
			if((n - j) % 2 == 0){
				turn(cogs[j], dir);
			}else{
				turn(cogs[j], -dir);
			}
		}
		for(i = n + 1; i < m; ++i){
			if(cogs[i][6] == cogs[i - 1][2]){
				break;
			}
		}
		for(int j = n; j < i; ++j){
			if((j - n) % 2 == 0){
				turn(cogs[j], dir);
			}else{
				turn(cogs[j], -dir);
			}
		}
		/*
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 8; ++j){
				printf("%c", cogs[i][j]);
			}
			printf("\n");
		}
		*/
	}
	int points = 0;
	for(int i = 0; i < m; ++i){
		points += cogs[i][0] == '1';
	}
	printf("%d", points);
	return 0;
}
