#include <cstdio>

char hands[12][31];
bool alive[12];

int winner(int robots){
	int victor = 0;
	for(int i = 1; i <= robots; ++i){
		if(alive[i] && victor == 0){
			victor = i;
		}else if(alive[i]){
			victor = 0;
			break;
		}
	}
	return victor;
}

int rps(int robots){
	for(int i = 1; i <= robots; ++i){
		alive[i] = true;
	}
	for(int j = 0; hands[1][j] != '\0'; ++j){
		bool r = false, s = false, p = false;
		for(int i = 1; i <= robots; ++i){
			if(!alive[i]){
				continue;
			}
			switch(hands[i][j]){
				case 'R':
					r = true;
					break;
				case 'S':
					s = true;
					break;
				case 'P':
					p = true;
					break;
			}
			if(r && s && p){
				break;
			}
		}
		if(r && s && p){
			continue;
		}else if(r && s){
			for(int i = 1; i <= robots; ++i){
				if(alive[i] && hands[i][j] == 'S'){
					alive[i] = false;
				}
			}
		}else if(s && p){
			for(int i = 1; i <= robots; ++i){
				if(alive[i] && hands[i][j] == 'P'){
					alive[i] = false;
				}
			}
		}else if(p && r){
			for(int i = 1; i <= robots; ++i){
				if(alive[i] && hands[i][j] == 'R'){
					alive[i] = false;
				}
			}
		}
	}
	return winner(robots);
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%s", hands[i]);
		}
		printf("%d\n", rps(n));
	}
	return 0;
}
