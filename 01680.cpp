#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int w, n;
		cin >> w >> n;
		int dist = 0;
		int load = 0;
		int pos = 0;
		for(int i = 0; i < n; ++i){
			int xi, wi;
			cin >> xi >> wi;
			dist += xi - pos;
			pos = xi;
			load += wi;
			if(i + 1 < n && load == w){
				dist += 2 * xi;
				load = 0;
			}else if(load > w){
				dist += 2 * xi;
				load = wi;
			}
			// cout << dist << '\n';
		}
		dist += pos;
		cout << dist << '\n';
	}
	return 0;
}
