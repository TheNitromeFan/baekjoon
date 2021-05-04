#include <iostream>
#define MAX 101

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	for(int a0 = 1; a0 <= k; ++a0){
		int n, m;
		cin >> n >> m;
		bool friends[MAX][MAX] = {};
		for(int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			friends[x][y] = true;
			friends[y][x] = true;
		}
		int s;
		cin >> s;
		cout << "Data Set " << a0 << ":\n";
		for(int x = 1; x <= n; ++x){
			if(friends[s][x]){
				cout << x << ' ';
			}
		}
		cout << "\n\n";
	}
	return 0;
}
