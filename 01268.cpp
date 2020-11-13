#include <cstdio>

bool isFriend(int classes[][6], int x, int y){
	for(int j = 1; j <= 5; ++j){
		if(classes[x][j] == classes[y][j]){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	int classes[1001][6];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 5; ++j){
			scanf("%d", &classes[i][j]);
		}
	}
	int maxFriends = -1, maxStudent = 0;
	for(int i = 1; i <= n; ++i){
		int friends = 0;
		for(int j = 1; j <= n; ++j){
			if(i != j && isFriend(classes, i, j)){
				++friends;
			}
		}
		if(maxFriends < friends){
			maxFriends = friends;
			maxStudent = i;
		}
	}
	printf("%d", maxStudent);
	return 0;
}
