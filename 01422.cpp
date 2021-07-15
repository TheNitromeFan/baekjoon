#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	vector<int> v(k);
	for(int i = 0; i < k; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int j = 0; j < n - k; ++j){
		v.push_back(v[0]);
	}
	sort(v.begin(), v.end(), [](int a, int b){
		return stoll(to_string(a) + to_string(b)) > stoll(to_string(b) + to_string(a));
	});
	for(int x : v){
		cout << x;
	}
	return 0;
}
