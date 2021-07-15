#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int m;
	cin >> m;
	vector<int> w(m);
	for(int j = 0; j < m; ++j){
		cin >> w[j];
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	int i = 0, j = 0;
	bool a = true, b = true;
	int ans = 0;
	while(i < n || j < m){
		if(i == n){
			if(a){
				++ans;
				a = false;
			}
			b = true;
			++j;
		}else if(j == m){
			if(b){
				++ans;
				b = false;
			}
			a = true;
			++i;
		}else if(v[i] == w[j]){
			++ans;
			a = true;
			b = true;
			++i;
			++j;
		}else if(v[i] < w[j]){
			if(b){
				++ans;
				b = false;
			}
			a = true;
			++i;
		}else{
			if(a){
				++ans;
				a = false;
			}
			b = true;
			++j;
		}
	}
	cout << ans << '\n';
	return 0;
}
