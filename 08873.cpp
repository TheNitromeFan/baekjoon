#include <iostream>
#include <cstdlib>
#define MAX 500

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, w;
	cin >> h >> w;
	int r[MAX][MAX], g[MAX][MAX], b[MAX][MAX];
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> r[i][j];
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> g[i][j];
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> b[i][j];
		}
	}
	int sum = 0;
	for(int i = 0; i < h - 1; ++i){
		for(int j = 0; j < w - 1; ++j){
			sum += abs(r[i + 1][j] - r[i][j]) + abs(r[i][j + 1] - r[i][j]);
			sum += abs(g[i + 1][j] - g[i][j]) + abs(g[i][j + 1] - g[i][j]);
			sum += abs(b[i + 1][j] - b[i][j]) + abs(b[i][j + 1] - b[i][j]);
		}
	}
	if(sum < 9 * 2 * h * w){
		cout << 4;
	}else if(sum < 23 * 2 * h * w){
		cout << 1;
	}else if(sum < 54 * 2 * h * w){
		cout << 2;
	}else{
		cout << 3;
	}
	return 0;
}
