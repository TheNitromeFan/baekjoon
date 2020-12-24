#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += a[i] * a[(i + 1) % n] * a[(i + 2) % n] * a[(i + 3) % n];
	}
	for(int j = 0; j < q; ++j){
		int qi;
		cin >> qi;
		--qi;
		a[qi] *= -1;
		for(int k = qi + n - 3; k <= qi + n; ++k){
			sum += 2 * a[k % n] * a[(k + 1) % n] * a[(k + 2) % n] * a[(k + 3) % n];
		}
		cout << sum << '\n';
	}
	return 0;
}
