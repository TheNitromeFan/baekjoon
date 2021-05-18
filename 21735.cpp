#include <iostream>
#include <vector>

using namespace std;

int snowball(vector<int> &a, int n, int m, int x){
	int pos = 0;
	int ret = 1;
	for(int i = 0; i < m; ++i){
		if(x % 2 == 0){
			++pos;
			ret += a[pos];
		}else{
			pos += 2;
			ret /= 2;
			ret += a[pos];
		}
		x /= 2;
		if(pos > n){
			break;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 2);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	int biggest = 0;
	for(int x = 0; x < (1 << m); ++x){
		int cmp = snowball(a, n, m, x);
		if(biggest < cmp){
			biggest = cmp;
		}
	}
	cout << biggest;
	return 0;
}
