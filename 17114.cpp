#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, int, int, int, int, int, int, int, int> t11;

map<t11, int> grid, days;

void print_tuple(t11 tmp){
	printf("%d %d %d %d %d %d %d %d %d %d %d\n", 
	        get<0>(tmp), get<1>(tmp), get<2>(tmp), get<3>(tmp), get<4>(tmp), get<5>(tmp), 
			get<6>(tmp), get<7>(tmp), get<8>(tmp), get<9>(tmp), get<10>(tmp));
}

t11 direction(int n){
	int component = n / 2;
	int dir;
	if(n % 2 == 0){
		dir = 1;
	}else{
		dir = -1;
	}
	if(component == 0){
		return make_tuple(dir, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}else if(component == 1){
		return make_tuple(0, dir, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	}else if(component == 2){
		return make_tuple(0, 0, dir, 0, 0, 0, 0, 0, 0, 0, 0);
	}else if(component == 3){
		return make_tuple(0, 0, 0, dir, 0, 0, 0, 0, 0, 0, 0);
	}else if(component == 4){
		return make_tuple(0, 0, 0, 0, dir, 0, 0, 0, 0, 0, 0);
	}else if(component == 5){
		return make_tuple(0, 0, 0, 0, 0, dir, 0, 0, 0, 0, 0);
	}else if(component == 6){
		return make_tuple(0, 0, 0, 0, 0, 0, dir, 0, 0, 0, 0);
	}else if(component == 7){
		return make_tuple(0, 0, 0, 0, 0, 0, 0, dir, 0, 0, 0);
	}else if(component == 8){
		return make_tuple(0, 0, 0, 0, 0, 0, 0, 0, dir, 0, 0);
	}else if(component == 9){
		return make_tuple(0, 0, 0, 0, 0, 0, 0, 0, 0, dir, 0);
	}else{
		return make_tuple(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, dir);
	}
}

void bfs(int m, int n, int o, int p, int q, int r, int s, int t, int u, int v, int w, queue<t11> qu){
	while(!qu.empty()){
		t11 tmp = qu.front();
		qu.pop();
		/*
		printf("popped: ");
		print_tuple(tmp);
		*/
		for(int d = 0; d < 22; ++d){
			t11 dir = direction(d);
			t11 new_tmp = make_tuple(get<0>(tmp) + get<0>(dir), 
									  get<1>(tmp) + get<1>(dir),
									  get<2>(tmp) + get<2>(dir), 
									  get<3>(tmp) + get<3>(dir), 
									  get<4>(tmp) + get<4>(dir), 
									  get<5>(tmp) + get<5>(dir), 
									  get<6>(tmp) + get<6>(dir), 
									  get<7>(tmp) + get<7>(dir), 
									  get<8>(tmp) + get<8>(dir), 
									  get<9>(tmp) + get<9>(dir), 
									  get<10>(tmp) + get<10>(dir));
			if(get<0>(tmp) + get<0>(dir) >= 0 && get<0>(tmp) + get<0>(dir) < m 
			&& get<1>(tmp) + get<1>(dir) >= 0 && get<1>(tmp) + get<1>(dir) < n 
			&& get<2>(tmp) + get<2>(dir) >= 0 && get<2>(tmp) + get<2>(dir) < o 
			&& get<3>(tmp) + get<3>(dir) >= 0 && get<3>(tmp) + get<3>(dir) < p 
			&& get<4>(tmp) + get<4>(dir) >= 0 && get<4>(tmp) + get<4>(dir) < q 
			&& get<5>(tmp) + get<5>(dir) >= 0 && get<5>(tmp) + get<5>(dir) < r 
			&& get<6>(tmp) + get<6>(dir) >= 0 && get<6>(tmp) + get<6>(dir) < s 
			&& get<7>(tmp) + get<7>(dir) >= 0 && get<7>(tmp) + get<7>(dir) < t 
			&& get<8>(tmp) + get<8>(dir) >= 0 && get<8>(tmp) + get<8>(dir) < u 
			&& get<9>(tmp) + get<9>(dir) >= 0 && get<9>(tmp) + get<9>(dir) < v 
			&& get<10>(tmp) + get<10>(dir) >= 0 && get<10>(tmp) + get<10>(dir) < w 
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
	queue<t11> qu;
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
		t11 tmp = make_tuple(a, b, c, d, e, f, g, h, i, j, k);
		grid[tmp] = x;
		days[tmp] = 0;
		if(x == 1){
			qu.push(tmp);
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
