#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &v){
	long long ret = 0;
	for(int x : v){
		ret += x;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int m;
	cin >> n >> m;
	vector<int> a(m);
	for(int i = 0; i < m; ++i){
		cin >> a[i];
	}
	long long ans = 2000000000000000000LL;
	bool found = false;
	for(int a0 = 0; a0 < (1 << m); ++a0){
		int k = a0;
		vector<int> v;
		for(int i = 0; i < m; ++i){
			if(k % 2 == 1){
				v.push_back(a[i]);
			}
			k /= 2;
		}
		long long cmp = sum(v);
		if(cmp >= n && cmp < ans){
			ans = cmp;
			found = true;
		}
	}
	if(found){
		cout << ans;
	}else{
		cout << "IMPOSSIBLE";
	}
	return 0;
}
