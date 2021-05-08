#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	long long a_sum = 0, b_sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		a_sum += a[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> b[j];
		b_sum += b[j];
	}
	int cnt = 0;
	while(a_sum != b_sum){
		if(a_sum > b_sum){
			a_sum -= a.back();
			a.pop_back();
		}else{
			b_sum -= b.back();
			b.pop_back();
		}
		++cnt;
	}
	cout << cnt;
	return 0;
}
