#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Cmp{
	public:
		bool operator()(int a, int b){
			return abs(a) < abs(b);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t >> n;
	int ans = 0;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x != 0){
			v.push_back(x);
		}else{
			++ans;
		}
	}
	sort(v.begin(), v.end(), Cmp());
	int pos = 0;
	unsigned idx = 0;
	while(idx < v.size() && t > 0){
		if(t >= abs(v[idx] - pos)){
			t -= abs(v[idx] - pos);
			++ans;
			pos = v[idx];
			++idx;
		}else{
			break;
		}
	}
	cout << ans;
	return 0;
}
