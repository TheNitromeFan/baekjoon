#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<int> v;
	int prev = a[0];
	v.push_back(prev);
	for(int i = 1; i < n; ++i){
		int cur = a[i];
		if(cur > prev){
			v.push_back(cur);
			prev = cur;
		}
	}
	cout << v.size() << '\n';
	for(int x : v){
		cout << x << ' ';
	}
	return 0;
}
