#include <iostream>
#define MAX (100000 + 1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int cows[MAX], psum[MAX][4] = {};
	for(int i = 1; i <= n; ++i){
		cin >> cows[i];
		psum[i][1] = psum[i - 1][1];
		psum[i][2] = psum[i - 1][2];
		psum[i][3] = psum[i - 1][3];
		++psum[i][cows[i]];
	}
	for(int j = 0; j < q; ++j){
		int a, b;
		cin >> a >> b;
		for(int k = 1; k <= 3; ++k){
			cout << psum[b][k] - psum[a - 1][k] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
