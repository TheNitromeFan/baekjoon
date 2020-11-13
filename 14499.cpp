#include <cstdio>

struct die{
	int top;
	int bottom;
	int right;
	int left;
	int front;
	int back;
	int posx;
	int posy;
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int board[20][20];
	struct die d;
	d.top = 0;
	d.bottom = 0;
	d.right = 0;
	d.left = 0;
	d.front = 0;
	d.back = 0;
	scanf("%d %d", &d.posx, &d.posy);
	int k;
	scanf("%d", &k);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &board[i][j]);
		}
	}
	for(int move = 0; move < k; ++move){
		int dir;
		scanf("%d", &dir);
		if(dir == 1 && d.posy < m-1){
			int tmp = d.top;
			d.top = d.left;
			d.left = d.bottom;
			d.bottom = d.right;
			d.right = tmp;
			++d.posy;
			if(board[d.posx][d.posy] == 0){
				board[d.posx][d.posy] = d.bottom;
			}else{
				d.bottom = board[d.posx][d.posy];
				board[d.posx][d.posy] = 0;
			}
			printf("%d\n", d.top);
		}else if(dir == 2 && d.posy > 0){
			int tmp = d.top;
			d.top = d.right;
			d.right = d.bottom;
			d.bottom = d.left;
			d.left = tmp;
			--d.posy;
			if(board[d.posx][d.posy] == 0){
				board[d.posx][d.posy] = d.bottom;
			}else{
				d.bottom = board[d.posx][d.posy];
				board[d.posx][d.posy] = 0;
			}
			printf("%d\n", d.top);
		}else if(dir == 3 && d.posx > 0){
			int tmp = d.top;
			d.top = d.front;
			d.front = d.bottom;
			d.bottom = d.back;
			d.back = tmp;
			--d.posx;
			if(board[d.posx][d.posy] == 0){
				board[d.posx][d.posy] = d.bottom;
			}else{
				d.bottom = board[d.posx][d.posy];
				board[d.posx][d.posy] = 0;
			}
			printf("%d\n", d.top);
		}else if(dir == 4 && d.posx < n-1){
			int tmp = d.top;
			d.top = d.back;
			d.back = d.bottom;
			d.bottom = d.front;
			d.front = tmp;
			++d.posx;
			if(board[d.posx][d.posy] == 0){
				board[d.posx][d.posy] = d.bottom;
			}else{
				d.bottom = board[d.posx][d.posy];
				board[d.posx][d.posy] = 0;
			}
			printf("%d\n", d.top);
		}
	}
	return 0;
}
