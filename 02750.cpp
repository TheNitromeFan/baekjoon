#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::sort;

int main(){
	int n = 0;
	cin >> n;
	vector<int> v;
	int x;
	for(int i = 0; i < n; ++i){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for(int x : v)
		cout << x << '\n';
	return 0;
}
