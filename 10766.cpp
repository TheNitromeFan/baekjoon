#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int go(vector<pair<int, int>> &hay, int mem[][4001], int n, int a, int b){
	if(mem[a][b] != -1){
		return mem[a][b];
	}
	int speed = hay[b].first - hay[a].first;
	if(a == 0 && speed > hay[a].second){
		mem[a][b] = 1;
		return 1;
	}else if(b == n - 1 && speed > hay[b].second){
		mem[a][b] = 1;
		return 1;
	}
	mem[a][b] = 0;
	if(speed > hay[a].second){
		mem[a][b] |= go(hay, mem, n, a - 1, b);
	}
	if(speed > hay[b].second){
		mem[a][b] |= go(hay, mem, n, a, b + 1);
	}
	return mem[a][b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int mem[4001][4001];
	memset(mem, -1, sizeof(mem));
	int n;
	cin >> n;
	vector<pair<int, int>> hay(n);
	for(int i = 0; i < n; ++i){
		cin >> hay[i].second >> hay[i].first;
	}
	sort(hay.begin(), hay.end());
	int area = 0;
	for(int i = 0; i + 1 < n; ++i){
		if(!go(hay, mem, n, i, i + 1)){
			area += hay[i + 1].first - hay[i].first;
		}
	}
	cout << area;
	return 0;
}
