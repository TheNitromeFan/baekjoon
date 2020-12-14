#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

string max_capacity(vector<int> &balloons, int n){
	double ret = 1;
	for(int i = 0; i < n; ++i){
		if(balloons[i] > n - i){
			return "impossible";
		}
		double cmp = balloons[i] / (double)(n - i);
		if(ret > cmp){
			ret = cmp;
		}
	}
	return to_string(ret);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		cin >> c[i];
	}
	sort(c.begin(), c.end(), greater<int>());
	cout << max_capacity(c, n);
	return 0;
}
