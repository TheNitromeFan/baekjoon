#include <iostream>
#include <cmath>

using namespace std;

void sums(int s){
	int ss = 2 * s;
	for(int n = 2; n <= (int)sqrt(ss); ++n){
		if(ss % n != 0){
			continue;
		}
		int m = ss / n;
		if(n % 2 != m % 2){
			int a = (m - n + 1) / 2;
			cout << s << " = " << a;
			for(int i = 1; i <= n - 1; ++i){
				cout << " + " << a + i;
			}
			cout << '\n';
			return;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		sums(n);
	}
	return 0;
}
