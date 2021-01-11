#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<double> v(n);
	for(int i = 0; i < n; ++i){
		string pass;
		cin >> pass >> v[i];
	}
	sort(v.begin(), v.end(), greater<double>());
	double attempts = 0;
	for(int i = 0; i < n; ++i){
		attempts += v[i] * (i + 1);
	}
	cout << attempts;
	return 0;
}
