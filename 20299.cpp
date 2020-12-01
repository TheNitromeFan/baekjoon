#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, l;
	cin >> n >> k >> l;
	vector<int> vip;
	for(int i = 0; i < n; ++i){
		int x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		if(x1 >= l && x2 >= l && x3 >= l && x1 + x2 + x3 >= k){
			vip.push_back(x1);
			vip.push_back(x2);
			vip.push_back(x3);
		}
	}
	cout << vip.size() / 3 << '\n';
	for(int x : vip){
		cout << x << ' ';
	}
	return 0;
}
