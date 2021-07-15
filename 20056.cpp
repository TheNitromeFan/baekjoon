#include <iostream>
#include <vector>
#include <tuple>
#define MAXN 50

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<tuple<int, int, int>> map[MAXN][MAXN];
	for(int i = 0; i < m; ++i){
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		map[r - 1][c - 1].push_back(make_tuple(m, s, d));
	}
	int dx[8] = {n - 1, n - 1, 0, 1, 1, 1, 0, n - 1};
	int dy[8] = {0, 1, 1, 1, 0, n - 1, n - 1, n - 1};
	for(int a0 = 0; a0 < k; ++a0){
		vector<tuple<int, int, int>> nmap[MAXN][MAXN];
		for(int r = 0; r < n; ++r){
			for(int c = 0; c < n; ++c){
				for(tuple<int, int, int> t : map[r][c]){
					int s = get<1>(t), d = get<2>(t);
					int nr = (r + dx[d] * s) % n;
					int nc = (c + dy[d] * s) % n;
					nmap[nr][nc].push_back(t);
				}
			}
		}
		for(int r = 0; r < n; ++r){
			for(int c = 0; c < n; ++c){
				if(nmap[r][c].size() >= 2){
					int sum_m = 0;
					int sum_s = 0;
					int cnt = 0;
					bool all_even = true, all_odd = true;
					while(!nmap[r][c].empty()){
						tuple<int, int, int> t = nmap[r][c].back();
						nmap[r][c].pop_back();
						int m = get<0>(t), s = get<1>(t), d = get<2>(t);
						sum_m += m;
						sum_s += s;
						++cnt;
						if(d % 2 == 0){
							all_odd = false;
						}else{
							all_even = false;
						}
					}
					int nm = sum_m / 5;
					if(nm == 0){
						continue;
					}
					int ns = sum_s / cnt;
					int offset = 0;
					if(!all_odd && !all_even){
						offset = 1;
					}
					for(int i = offset; i < 8; i += 2){
						nmap[r][c].push_back(make_tuple(nm, ns, i));
					}
				}
			}
		}
		for(int r = 0; r < n; ++r){
			for(int c = 0; c < n; ++c){
				map[r][c] = nmap[r][c];
			}
		}
	}
	int mass = 0;
	for(int r = 0; r < n; ++r){
		for(int c = 0; c < n; ++c){
			for(tuple<int, int, int> t : map[r][c]){
				mass += get<0>(t);
			}
		}
	}
	cout << mass << '\n';
	return 0;
}
