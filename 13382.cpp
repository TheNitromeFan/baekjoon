#include <iostream>
#include <algorithm>
#include <iomanip>
#define MAX 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		double p[MAX];
		for(int i = 1; i <= n; ++i){
			cin >> p[i];
		}
		double psum[MAX] = {};
		psum[1] = p[1];
		psum[2] = max(psum[1], p[2]);
		psum[3] = max(psum[2], p[3]);
		for(int i = 4; i <= n; ++i){
			psum[i] = max(psum[i - 1], psum[i - 3] + p[i]);
		}
		cout << fixed << setprecision(1) << psum[n] << '\n';
	}
	return 0;
}
