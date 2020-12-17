#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

bool within_range(int x1, int y1, int x2, int y2, int r){
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r;
}

double total_damage(vector<pair<int, int>> &towers, int n, int r, int d, int sx, int sy){
	double ret = 0;
	queue<int> q;
	vector<double> damage(n, -1);
	for(int i = 0; i < n; ++i){
		if(within_range(towers[i].first, towers[i].second, sx, sy, r)){
			q.push(i);
			damage[i] = d;
			ret += damage[i];
		}
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int y = 0; y < n; ++y){
			if(damage[y] == -1
			&& within_range(towers[y].first, towers[y].second, towers[x].first, towers[x].second, r)){
				q.push(y);
				damage[y] = damage[x] / 2;
				ret += damage[y];
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r, d, x, y;
	cin >> n >> r >> d >> x >> y;
	vector<pair<int, int>> towers(n);
	for(int i = 0; i < n; ++i){
		cin >> towers[i].first >> towers[i].second;
	}
	cout << setprecision(2) << fixed << total_damage(towers, n, r, d, x, y);
	return 0;
}
