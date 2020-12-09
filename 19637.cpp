#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pair<string, int>> name(n);
	for(int i = 0; i < n; ++i){
		cin >> name[i].first >> name[i].second;
	}
	for(int j = 0; j < m; ++j){
		int x;
		cin >> x;
		int low = 0, high = n - 1;
		while(low < high){
			int mid = (low + high) / 2;
			if(x <= name[mid].second){
				high = mid;
			}else{
				low = mid + 1;
			}
		}
		cout << name[low].first << '\n';
	}
	return 0;
}
