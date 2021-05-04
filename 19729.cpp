#include <iostream>
#include <algorithm>

using namespace std;

int folds(long long n, long long m, long long w, long long h){
	int ret = 0;
	while(n > w){
		w *= 2;
		++ret;
	}
	while(m > h){
		h *= 2;
		++ret;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m, w, h;
	cin >> n >> m >> w >> h;
	cout << min(folds(n, m, w, h), folds(m, n, w, h));
	return 0;
}
