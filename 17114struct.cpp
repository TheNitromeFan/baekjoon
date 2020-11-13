#include <cstdio>
#include <queue>
#include <map>

using namespace std;

struct tup{
	int p[11];
	int grid;
	int days;
} elem[100000];

void bfs(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, queue<int> qu){
	while(!qu.empty()){
		int idx = qu.front();
		qu.pop();
		for(int d = 0; d < 22; ++d){
			int component = d / 2;
			int dir;
			if(d % 2 == 1){
				dir = 1;
			}else{
				dir = -1;
			}
			struct tup new_tmp;
			for(int i = 0; i < 11; ++i){
				if(component == i){
					new_tmp.p[i] = tmp.p[i] + dir;
				}else{
					new_tmp.p[i] = tmp.p[i]
				}
			}
			if(new_tmp.p[0] >= 0 && new_tmp.p[0] < m 
			&& new_tmp.p[1] >= 0 && new_tmp.p[1] < n 
			&& new_tmp.p[2] >= 0 && new_tmp.p[2] < o 
			&& new_tmp.p[3] >= 0 && new_tmp.p[3] < p 
			&& new_tmp.p[4] >= 0 && new_tmp.p[4] < q 
			&& new_tmp.p[5] >= 0 && new_tmp.p[5] < r 
			&& new_tmp.p[6] >= 0 && new_tmp.p[6] < s 
			&& new_tmp.p[7] >= 0 && new_tmp.p[7] < t 
			&& new_tmp.p[8] >= 0 && new_tmp.p[8] < u 
			&& new_tmp.p[9] >= 0 && new_tmp.p[9] < v 
			&& new_tmp.p[10] >= 0 && new_tmp.p[10] < w 
			&& (grid[new_tmp] == 0 || (grid[new_tmp] == 1 && days[new_tmp] > days[tmp] + 1))){
			    grid[new_tmp] = 1;
				days[new_tmp] = days[tmp] + 1;
				qu.push(new_tmp);
				/*
				printf("direction: %d\n", d);
				printf("pushed: ");
				printf("days: %d, tuple: ", days[new_tmp]);
				print_tuple(new_tmp);
				*/
			}
		}
	}
}

int max_days(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w){
	int answer = 0;
	for(int a = 0; a < m; ++a){
	for(int b = 0; b < n; ++b){
	for(int c = 0; c < o; ++c){
	for(int d = 0; d < p; ++d){
	for(int e = 0; e < q; ++e){
	for(int f = 0; f < r; ++f){
	for(int g = 0; g < s; ++g){
	for(int h = 0; h < t; ++h){
	for(int i = 0; i < u; ++i){
	for(int j = 0; j < v; ++j){
	for(int k = 0; k < w; ++k){
		t11 tmp = make_tuple(a, b, c, d, e, f, g, h, i, j, k);
		if(grid[tmp] == 0){
			return -1;
		}else if(grid[tmp] == 1 && days[tmp] > answer){
			answer = days[tmp];
		}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	return answer;
}

int main(){
	int m, n, o, p, q, r, s, t, u, v, w;
	scanf("%d %d %d %d %d %d %d %d %d %d %d", &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w);
	queue<int> qu;
	int idx = 0;
	for(int k = 0; k < w; ++k){
	for(int j = 0; j < v; ++j){
	for(int i = 0; i < u; ++i){
	for(int h = 0; h < t; ++h){
	for(int g = 0; g < s; ++g){
	for(int f = 0; f < r; ++f){
	for(int e = 0; e < q; ++e){
	for(int d = 0; d < p; ++d){
	for(int c = 0; c < o; ++c){
	for(int b = 0; b < n; ++b){
	for(int a = 0; a < m; ++a){
		int x;
		scanf("%d", &x);
		elem[idx].p[0] = a;
		elem[idx].p[1] = b;
		elem[idx].p[2] = c;
		elem[idx].p[3] = d;
		elem[idx].p[4] = e;
		elem[idx].p[5] = f;
		elem[idx].p[6] = g;
		elem[idx].p[7] = h;
		elem[idx].p[8] = i;
		elem[idx].p[9] = j;
		elem[idx].p[10] = k;
		elem[idx].grid = x;
		elem[idx].days = 0;
		if(x == 1){
			qu.push(idx);
		}
		++idx;
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
    bfs(m, n, o, p, q, r, s, t, u, v, w, qu);
    /*
    for(int a = 0; a < m; ++a){
	for(int b = 0; b < n; ++b){
	for(int c = 0; c < o; ++c){
	for(int d = 0; d < p; ++d){
	for(int e = 0; e < q; ++e){
	for(int f = 0; f < r; ++f){
	for(int g = 0; g < s; ++g){
	for(int h = 0; h < t; ++h){
	for(int i = 0; i < u; ++i){
	for(int j = 0; j < v; ++j){
	for(int k = 0; k < w; ++k){
		printf("%d\n", days[make_tuple(a, b, c, d, e, f, g, h, i, j, k)]);
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	}
	*/
    printf("%d", max_days(m, n, o, p, q, r, s, t, u, v, w));
	return 0;
}
