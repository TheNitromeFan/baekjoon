#include <cstdio>
#define MAX (1000 + 1)

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int board[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &board[i]);
	}
	int roll, pos = 1;
	for(roll = 1; roll <= m; ++roll){
		int die;
		scanf("%d", &die);
		pos += die;
		if(pos >= n){
			printf("%d", roll);
			break;
		}
		pos += board[pos];
		if(pos >= n){
			printf("%d", roll);
			break;
		}
	}
	return 0;
}
