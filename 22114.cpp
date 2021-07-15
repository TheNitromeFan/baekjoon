#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> dist(n);
	for(int i = 1; i < n; ++i){
		int x;
		cin >> x;
		dist[i] = dist[i - 1] + x;
	}
	int j = 0;
	bool jumped = false;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		while(j + 1 < n){
			if(dist[j + 1] - dist[j] > k){
				if(jumped){
					break;
				}else{
					jumped = true;
					++j;
				}
			}else{
				++j;
			}
		}
		ans = max(ans, j - i + 1);
		if(i + 1 < n && dist[i + 1] - dist[i] > k){
			jumped = false;
		}
	}
	cout << ans << '\n';
	return 0;
}
