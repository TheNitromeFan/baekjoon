#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> x(n), y(n);
		for(int i = 0; i < n; ++i){
			cin >> x[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> y[i];
		}
		int dist = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				int d = 0;
				if(j >= i && y[j] >= x[i]){
					d = j - i;
				}
				dist = max(dist, d);
			}
		}
		cout << "The maximum distance is " << dist << "\n\n";
	}
	return 0;
}
