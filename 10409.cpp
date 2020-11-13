#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	vector<int> v;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		v.push_back(x);
	}
	int cnt = 0;
	for(cnt = 0; cnt < n; ++cnt){
		if(t - v[cnt] >= 0){
			t -= v[cnt];
		}else{
			break;
		}
	}
	cout << cnt;
	return 0;
}
