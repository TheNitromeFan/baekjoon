#include <iostream>
#include <vector>

using namespace std;

int square(int x){
	return x * x;
}

bool touch(int xi, int yi, int ri, int xj, int yj, int rj){
	return square(xi - xj) + square(yi - yj) == square(ri + rj);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n), y(n), r(n);
	int cur = -1;
	for(int i = 0; i < n; ++i){
		cin >> x[i] >> y[i] >> r[i];
		if(x[i] == 0 && y[i] == 0){
			cur = i;
		}
	}
	int rollers = 1;
	vector<bool> visited(n);
	visited[cur] = true;
	while(rollers < n){
		for(int i = 0; i < n; ++i){
			if(!visited[i] && touch(x[i], y[i], r[i], x[cur], y[cur], r[cur])){
				cur = i;
				++rollers;
				visited[cur] = true;
				break;
			}
		}
	}
	cout << x[cur] << ' ' << y[cur];
	return 0;
}
