#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void divisors(vector<int> &div, int n){
	for(int d = 1; d * d <= n; ++d){
		if(d * d == n){
			div.push_back(d);
		}else if(n % d == 0){
			div.push_back(d);
			div.push_back(n / d);
		}
	}
	sort(div.begin(), div.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		sum += a[i];
	}
	vector<int> div;
	divisors(div, sum);
	vector<int> ans(n);
	for(int d : div){
		int fights = 0;
		int sum1 = 0;
		for(int i = 0; i < n; ++i){
			sum1 += a[i];
			if(sum1 % d != 0){
				++fights;
			}
		}
		for(int k = fights; k < n; ++k){
			ans[k] = d;
		}
	}
	for(int x : ans){
		cout << x << ' ';
	}
	return 0;
}
