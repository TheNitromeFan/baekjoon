#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<long long> v(n);
		long long sum = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> v[i];
			}
			sum += v[i];
		}
		for(int i = 0; i < n; ++i){
			long long g = gcd(v[i], sum);
			cout << v[i] / g << " / " << sum / g << "\n";
		}
	}
	return 0;
}
