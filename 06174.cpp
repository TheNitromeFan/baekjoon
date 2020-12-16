#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

bool touch(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2){
	return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) == (r1 + r2) * (r1 + r2);
}

bool roll(vector<tuple<long long, long long, long long>> &rollers, int n, int u, vector<bool> &visited, long long xt, long long yt){
	visited[u] = true;
	if(get<0>(rollers[u]) == xt && get<1>(rollers[u]) == yt){
		return true;
	}
	for(int v = 0; v < n; ++v){
		if(!visited[v]
		&& touch(get<0>(rollers[u]), get<1>(rollers[u]), get<2>(rollers[u]), get<0>(rollers[v]), get<1>(rollers[v]), get<2>(rollers[v]))
		&& roll(rollers, n, v, visited, xt, yt)){
			return true;
		}
	}
	visited[u] = false;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long xt, yt;
	cin >> n >> xt >> yt;
	int start = -1;
	vector<tuple<long long, long long, long long>> rollers(n);
	for(int i = 0; i < n; ++i){
		long long xi, yi, ri;
		cin >> xi >> yi >> ri;
		rollers[i] = make_tuple(xi, yi, ri);
		if(xi == 0 && yi == 0){
			start = i;
		}
	}
	vector<bool> visited(n);
	roll(rollers, n, start, visited, xt, yt);
	double ans = 0;
	for(int i = 0; i < n; ++i){
		if(visited[i]){
			ans += get<2>(rollers[start]) / (double)get<2>(rollers[i]);
		}
	}
	cout << (int)(ans * 10000);
	return 0;
}
