#include <iostream>
#include <vector>

using namespace std;

bool balanced(vector<long long> &x, vector<long long> &psum, long long n, long long len){
	for(long long i = 1; i < n; ++i){
		long long sum = psum[n] - psum[i];
		if(!((n - i) * (x[i] - len) < sum && sum < (n - i) * (x[i] + len))){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, len;
	cin >> n >> len;
	vector<long long> x(n + 1);
	vector<long long> psum(n + 1);
	for(long long i = 1; i <= n; ++i){
		cin >> x[i];
		psum[i] = psum[i - 1] + x[i];
	}
	cout << (balanced(x, psum, n, len) ? "stable" : "unstable");
	return 0;
}
