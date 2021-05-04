#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	int cnt = 0;
	for(int z = 0; z <= m; ++z){
		for(int y = 0; y <= z; ++y){
			for(int x = 0; x <= y; ++x){
				if(x * x + y * y == z * z){
					++cnt;
				}
			}
		}
	}
	cnt += (m + 1) * (n - 2);
	cout << cnt;
	return 0;
}
