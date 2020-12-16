#include <iostream>
#include <vector>

using namespace std;

int sum_of_odd_2x(vector<int> &v){
	int ret = 0;
	for(unsigned i = 0; i < v.size(); ++i){
		if(v[i] % 2 == 1){
			ret += (1 << i);
		}
	}
	return ret;
}

void add_2x(vector<int> &v, int x){
	for(unsigned i = 0; x > 0; ++i, x /= 2){
		if(x % 2 == 1){
			++v[i];
		}
	}
}

void subtract_2x(vector<int> &v, int x){
	for(unsigned i = 0; x > 0; ++i, x /= 2){
		if(x % 2 == 1){
			--v[i];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), v(30);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		add_2x(v, a[i]);
	}
	int ans = sum_of_odd_2x(v);
	for(int i = 0; i < n; ++i){
		subtract_2x(v, a[i]);
		int cmp = sum_of_odd_2x(v);
		if(ans < cmp){
			ans = cmp;
		}
		add_2x(v, a[i]);
	}
	cout << ans << ans;
	return 0;
}
