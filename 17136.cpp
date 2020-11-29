#include <cstdio>

bool can_cover(int paper[][10], int sz, int x, int y){
	if(!(x + sz <= 10 && y + sz <= 10)){
		return false;
	}
	for(int i = x; i < x + sz; ++i){
		for(int j = y; j < y + sz; ++j){
			if(paper[i][j] == 0){
				return false;
			}
		}
	}
	return true;
}

void place(int paper[][10], int sz, int x, int y, int z){
	for(int i = x; i < x + sz; ++i){
		for(int j = y; j < y + sz; ++j){
			paper[i][j] = z;
		}
	}
}

bool cover(int paper[][10], int squares[6], int &cnt){
	int x = -1, y = -1;
	bool found = false;
	for(x = 0; x < 10; ++x){
		for(y = 0; y < 10; ++y){
			if(paper[x][y] == 1){
				found = true;
				break;
			}
		}
		if(found){
			break;
		}
	}
	if(!found){
		cnt = 0;
		return true;
	}
	bool ret = false;
	for(int sz = 5; sz >= 1; --sz){
		if(squares[sz] > 0 && can_cover(paper, sz, x, y)){
			place(paper, sz, x, y, 0);
			--squares[sz];
			int cnt1 = 26;
			bool ret1 = cover(paper, squares, cnt1);
			if(ret1){
				ret = true;
				if(cnt > cnt1 + 1){
					cnt = cnt1 + 1;
				}
			}
			place(paper, sz, x, y, 1);
			++squares[sz];
		}
	}
	return ret;
}

int main(){
	int paper[10][10];
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			scanf("%d", &paper[i][j]);
		}
	}
	int squares[6] = {0, 5, 5, 5, 5, 5};
	int cnt = 26;
	bool ans = cover(paper, squares, cnt);
	if(ans){
		printf("%d", cnt);
	}else{
		printf("-1");
	}
	return 0;
}
