#include <cstdio>

void roman(bool visited[1100], int n, int pos, int cur, int last, int &cnt){
	if(n == pos){
		if(!visited[cur]){
			visited[cur] = true;
			++cnt;
		}
		return;
	}
	if(last <= 1){
		roman(visited, n, pos + 1, cur + 1, 1, cnt);
	}
	if(last <= 5){
		roman(visited, n, pos + 1, cur + 5, 5, cnt);
	}
	if(last <= 10){
		roman(visited, n, pos + 1, cur + 10, 10, cnt);
	}
	if(last <= 50){
		roman(visited, n, pos + 1, cur + 50, 50, cnt);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	bool visited[1100] = {};
	int cnt = 0;
	roman(visited, n, 0, 0, 1, cnt);
	printf("%d", cnt);
	return 0;
}
