#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 31

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, k, w;
	cin >> m >> n >> k >> w;
	int a[MAX][MAX];
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= m - w + 1; ++i){
		for(int j = 1; j <= n - w + 1; ++j){
			vector<int> pixels;
			for(int x = 0; x < w; ++x){
				for(int y = 0; y < w; ++y){
					pixels.push_back(a[i + x][j + y]);
				}
			}
			sort(pixels.begin(), pixels.end());
			cout << pixels[pixels.size() / 2] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
