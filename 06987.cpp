#include <cstdio>

bool match(int a[18], int team1, int team2){
	if(team1 == 5){
		for(int j = 0; j < 18; ++j){
			if(a[j] > 0){
				return false;
			}
		}
		return true;
	}
	bool ret = false;
	int newTeam1 = team1, newTeam2 = team2;
	if(team2 < 5){
		++newTeam2;
	}else{
		++newTeam1;
		newTeam2 = newTeam1 + 1;
	}
	for(int i = 0; i < 3; ++i){
		if(a[3 * team1 + i] > 0 && a[3 * team2 + 2 - i] > 0){
			--a[3 * team1 + i];
			--a[3 * team2 + 2 - i];
			ret = ret || match(a, newTeam1, newTeam2);
			++a[3 * team1 + i];
			++a[3 * team2 + 2 - i];
		}
	}
	return ret;
}

int main(){
	for(int i = 0; i < 4; ++i){
		int a[18];
		for(int j = 0; j < 18; ++j){
			scanf("%d", &a[j]);
		}
		printf("%d ", match(a, 0, 1));
	}
	return 0;
}
