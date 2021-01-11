#include <iostream>
#define MAX (191229 + 1)
#define MOD 1000000007

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int fibs[MAX];
	fibs[0] = 1;
	fibs[1] = 1;
	for(int i = 2; i < MAX; ++i){
		fibs[i] = (fibs[i - 1] + fibs[i - 2]) % MOD;
	}
	int t;
	cin >> t;
	for(int j = 0; j < t; ++j){
		int n;
		cin >> n;
		cout << fibs[n] << '\n';
	}
	return 0;
}
