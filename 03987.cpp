#include <cstdio>
#define MAX 500

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

char directions[5] = "URDL";

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	char space[MAX][MAX];
	for(int i = 0; i < n; ++i){
		scanf("%s", space[i]);
	}
	int startx, starty;
	scanf("%d %d", &startx, &starty);
	--startx;
	--starty;
	int max_travel_time = 0, starting_dir = -1;
	for(int d = 0; d < 4; ++d){
		int x = startx, y = starty;
		int dir = d;
		int time = 0;
		while(true){
			if(space[x][y] == 'C'){
				break;
			}
			++time;
			if(space[x][y] == '/'){
				dir = (5 - dir) % 4;
			}else if(space[x][y] == '\\'){
				dir = (3 - dir) % 4;
			}
			x += dx[dir];
			y += dy[dir];
			if(x < 0 || x >= n || y < 0 || y >= m || time > n * m){
				break;
			}
		}
		if(time > max_travel_time){
			max_travel_time = time;
			starting_dir = d;
		}
	}
	printf("%c\n", directions[starting_dir]);
	if(max_travel_time > n * m){
		printf("Voyager");
	}else{
		printf("%d", max_travel_time);
	}
	return 0;
}
