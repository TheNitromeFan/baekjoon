#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> line(n);
	int girl_count = 0;
	for(int i = 0; i < n; ++i){
		cin >> line[i];
		if(!line[i]){
			++girl_count;
		}
	}
	if(girl_count < k){
		cout << "NIE";
		return 0;
	}
	int idx1 = 0, idx2 = 0;
	girl_count = 0;
	while(girl_count < k){
		if(!line[idx2]){
			++girl_count;
			if(girl_count == k){
				break;
			}
		}
		++idx2;
	}
	while(line[idx1]){
		++idx1;
	}
	int ans = idx2 + 1 - idx1 - k;
	while(idx2 < n){
		do{
			++idx2;
		}while(idx2 < n && line[idx2]);
		if(idx2 == n){
			break;
		}
		do{
			++idx1;
		}while(line[idx1]);
		ans = min(ans, idx2 + 1 - idx1 - k);
	}
	cout << ans;
	return 0;
}
