#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int x;
	cin >> x;
	long long sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(gcd(a[i], x) == 1){
			sum += a[i];
			++cnt;
		}
	}
	cout << sum / (double)cnt;
	return 0;
}
