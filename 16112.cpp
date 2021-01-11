#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &ai : a){
		cin >> ai;
	}
	sort(a.begin(), a.end());
	long long r = 0, s = 0;
	for(int i = n - 1; i >= 0; --i){
		if(i < k){
			r += s;
		}
		s += a[i];
	}
	cout << r;
	return 0;
}
