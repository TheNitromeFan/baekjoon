#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <cstring>
#define MAX 30303

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<2>(a) > get<2>(b) || (get<2>(a) == get<2>(b) && get<1>(a) > get<1>(b));
		}
};

bool maze(vector<vector<tuple<int, int, int>>> &adj, int r, int c, int k){
	// adj: has, left, right
	int dist[160][160][1600]; // x, y, left
	memset(dist, -1, sizeof(dist));
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq; // hash, left, right
	bool visited[160][160][1600] = {}; // x, y, left
	dist[0][0][0] = 0;
	pq.push(make_tuple(0, 0, 0));
	while(!pq.empty()){
		tuple<int, int, int> t1 = pq.top();
		pq.pop();
		int h1 = get<0>(t1), left_cost = get<1>(t1), right_cost = get<2>(t1);
		int x = h1 / 200, y = h1 % 200;
		// cout << x << ' ' << y << ' ' << get<1>(t1) << ' ' << get<2>(t1) << '\n';
		if(x == r - 1 && y == c - 1){
			return true;
		}else if(visited[x][y][left_cost]){
			continue;
		}
		visited[x][y][left_cost] = true;
		for(tuple<int, int, int> t2 : adj[h1]){
			int h2 = get<0>(t2), left = get<1>(t2), right = get<2>(t2);
			int nx = h2 / 200, ny = h2 % 200;
			if(left_cost + left <= k && right_cost + right <= k
			&& (dist[nx][ny][left_cost + left] == -1 || dist[nx][ny][left_cost + left] > right_cost + right)){
				dist[nx][ny][left_cost + left] = right_cost + right;
				pq.push(make_tuple(h2, left_cost + left, right_cost + right));
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, limit;
	cin >> r >> c >> limit;
	vector<vector<tuple<int, int, int>>> adj(MAX);
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	for(int i = 0; i < r; ++i){
		string line;
		cin >> line;
		for(int j = 0; j < c; ++j){
			int dir = 0;
			if(line[j] == 'U'){
				dir = 0;
			}else if(line[j] == 'R'){
				dir = 1;
			}else if(line[j] == 'D'){
				dir = 2;
			}else{
				dir = 3;
			}
			for(int k = 0; k <= 3; ++k){
				int ndir = (dir + k) % 4;
				int ni = i + dx[ndir], nj = j + dy[ndir];
				if(ni >= 0 && ni < r && nj >= 0 && nj < c){
					adj[i * 200 + j].push_back(make_tuple(ni * 200 + nj, 0, k));
				}
			}
			for(int k = 1; k <= 3; ++k){
				int ndir = (dir + 3 * k) % 4;
				int ni = i + dx[ndir], nj = j + dy[ndir];
				if(ni >= 0 && ni < r && nj >= 0 && nj < c){
					adj[i * 200 + j].push_back(make_tuple(ni * 200 + nj, k, 0));
				}
			}
		}
	}
	cout << (maze(adj, r, c, limit) ? "Yes" : "No");
	return 0;
}
