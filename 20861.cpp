#include <cstdio>
#define MAX 101

void treasure(char map[][MAX]){
	bool visited[MAX][MAX] = {};
	int x = 0, y = 0;
	while(true){
		if(map[x][y] == 'A'){
			printf("sushi");
			return;
		}else if(map[x][y] == 'B'){
			printf("samuraj");
			return;
		}else if(visited[x][y]){
			printf("cykel");
			return;
		}
		visited[x][y] = true;
		if(map[x][y] == '>'){
			++y;
		}else if(map[x][y] == '<'){
			--y;
		}else if(map[x][y] == 'v'){
			++x;
		}else{
			--x;
		}
	}
}

int main(){
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
	}
	treasure(map);
	return 0;
}
