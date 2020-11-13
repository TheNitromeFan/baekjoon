#include <cstdio>
#define MAX (25 + 1)

bool all_visited(char map[][MAX], bool visited[][MAX], int r, int c){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(map[i][j] != '.' && !visited[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int r, c;
	scanf("%d %d", &r, &c);
	char map[MAX][MAX];
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for(int i = 0; i < r; ++i){
		scanf("%s", map[i]);
		for(int j = 0; j < c; ++j){
			if(map[i][j] == 'M'){
				x1 = i;
				y1 = j;
			}else if(map[i][j] == 'Z'){
				x2 = i;
				y2 = j;
			}
		}
	}
	bool visited[MAX][MAX] = {};
	visited[x1][y1] = true;
	visited[x2][y2] = true;
	int dir1, dir2, nx, ny;
	bool found;
	found = false;
	for(dir1 = 0; dir1 < 4; ++dir1){
		nx = x1 + dx[dir1];
		ny = y1 + dy[dir1];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != '.' && map[nx][ny] != 'Z'){
			found = true;
			x1 = nx;
			y1 = ny;
			visited[x1][y1] = true;
			break;
		}
	}
	while(found){
		switch(map[x1][y1]){
			case '1':
				if(dir1 == 2){
					dir1 = 1;
				}else if(dir1 == 3){
					dir1 = 0;
				}
				break;
			case '2':
				if(dir1 == 0){
					dir1 = 1;
				}else if(dir1 == 3){
					dir1 = 2;
				}
				break;
			case '3':
				if(dir1 == 0){
					dir1 = 3;
				}else if(dir1 == 1){
					dir1 = 2;
				}
				break;
			case '4':
				if(dir1 == 1){
					dir1 = 0;
				}else if(dir1 == 2){
					dir1 = 3;
				}
				break;
		}
		nx = x1 + dx[dir1];
		ny = y1 + dy[dir1];
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '.'){
			break;
		}
		x1 = nx;
		y1 = ny;
		visited[x1][y1] = true;
	}
	found = false;
	for(dir2 = 0; dir2 < 4; ++dir2){
		nx = x2 + dx[dir2];
		ny = y2 + dy[dir2];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != '.' && map[nx][ny] != 'M'){
			found = true;
			x2 = nx;
			y2 = ny;
			visited[x2][y2] = true;
			break;
		}
	}
	while(found){
		switch(map[x2][y2]){
			case '1':
				if(dir2 == 2){
					dir2 = 1;
				}else if(dir2 == 3){
					dir2 = 0;
				}
				break;
			case '2':
				if(dir2 == 0){
					dir2 = 1;
				}else if(dir2 == 3){
					dir2 = 2;
				}
				break;
			case '3':
				if(dir2 == 0){
					dir2 = 3;
				}else if(dir2 == 1){
					dir2 = 2;
				}
				break;
			case '4':
				if(dir2 == 1){
					dir2 = 0;
				}else if(dir2 == 2){
					dir2 = 3;
				}
				break;
		}
		nx = x2 + dx[dir2];
		ny = y2 + dy[dir2];
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '.'){
			break;
		}
		x2 = nx;
		y2 = ny;
		visited[x2][y2] = true;
	}
	// printf("%d %d %d %d\n", x1, y1, x2, y2);
	if(x1 == x2){
		if(all_visited(map, visited, r, c)){
			printf("%d %d %c", x1 + 1, (y1 + y2) / 2 + 1, '-');
		}else{
			printf("%d %d %c", x1 + 1, (y1 + y2) / 2 + 1, '+');
		}
	}else if(y1 == y2){
		if(all_visited(map, visited, r, c)){
			printf("%d %d %c", (x1 + x2) / 2 + 1, y1 + 1, '|');
		}else{
			printf("%d %d %c", (x1 + x2) / 2 + 1, y1 + 1, '+');
		}
	}else if(x1 == x2 + 1 && y1 == y2 + 1){
		if(dir1 == 2 || dir2 == 1){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x2 + 1, y1 + 1, '4');
			}else{
				printf("%d %d %c", x2 + 1, y1 + 1, '+');
			}
		}else if(dir1 == 3 || dir2 == 0){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x1 + 1, y2 + 1, '2');
			}else{
				printf("%d %d %c", x1 + 1, y2 + 1, '+');
			}
		}
	}else if(x1 == x2 + 1 && y1 == y2 - 1){
		if(dir1 == 2 || dir2 == 3){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x2 + 1, y1 + 1, '1');
			}else{
				printf("%d %d %c", x2 + 1, y1 + 1, '+');
			}
		}else if(dir1 == 1 || dir2 == 0){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x1 + 1, y2 + 1, '3');
			}else{
				printf("%d %d %c", x1 + 1, y2 + 1, '+');
			}
		}
	}else if(x1 == x2 - 1 && y1 == y2 + 1){
		if(dir1 == 0 || dir2 == 1){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x2 + 1, y1 + 1, '3');
			}else{
				printf("%d %d %c", x2 + 1, y1 + 1, '+');
			}
		}else if(dir1 == 3 || dir2 == 2){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x1 + 1, y2 + 1, '1');
			}else{
				printf("%d %d %c", x1 + 1, y2 + 1, '+');
			}
		}
	}else if(x1 == x2 - 1 && y1 == y2 - 1){
		if(dir1 == 0 || dir2 == 3){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x2 + 1, y1 + 1, '2');
			}else{
				printf("%d %d %c", x2 + 1, y1 + 1, '+');
			}
		}else if(dir1 == 1 || dir2 == 2){
			if(all_visited(map, visited, r, c)){
				printf("%d %d %c", x1 + 1, y2 + 1, '4');
			}else{
				printf("%d %d %c", x1 + 1, y2 + 1, '+');
			}
		}
	}
	return 0;
}
