#include <iostream>
#include <vector>

using namespace std;

bool sabotage(vector<long long> &v, int n){
	for(int i = 0; i < n; ++i){
		long long x = v[i];
		long long pow10 = 1;
		while(pow10 <= x){
			pow10 *= 10;
		}
		pow10 /= 10;
		if(pow10 <= 1){
			v[i] = 0;
		}else{
			v[i] = pow10 + x % pow10;
		}
		if(i > 0 && v[i] < v[i - 1]){
			return true;
		}
		if(pow10 <= 1){
			v[i] = 9;
		}else{
			v[i] = 9 * pow10 + x % pow10;
		}
		if(i < n - 1 && v[i] > v[i + 1]){
			return true;
		}
		v[i] = x;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	if(sabotage(a, n)){
		for(long long x : a){
			cout << x << ' ';
		}
	}else{
		cout << "impossible";
	}
	return 0;
}
