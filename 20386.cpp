#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			return 0;
		}
		int minx = -1000000000, miny = -1000000000, minz = -1000000000, maxx = 1000000000, maxy = 1000000000, maxz = 1000000000;
		for(int i = 0; i < n; ++i){
			int x, y, z, s;
			cin >> x >> y >> z >> s;
			minx = max(minx, x);
			miny = max(miny, y);
			minz = max(minz, z);
			maxx = min(maxx, x + s);
			maxy = min(maxy, y + s);
			maxz = min(maxz, z + s);
		}
		cout << max(0, maxx - minx) * max(0, maxy - miny) * max(0, maxz - minz) << '\n';
	}
	return 0;
}
