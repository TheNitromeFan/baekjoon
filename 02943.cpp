#include <iostream>
#include <cmath>
#define MAXN 110000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int k = (int)sqrt(n);
	int box[MAXN] = {}, cup[MAXN] = {};
	for(int a0 = 0; a0 < m; ++a0){
		int b, a;
		cin >> b >> a;
		--a;
		b += a;
		int ans = 0;
		while(a < b && a % k != 0){
			++box[a];
			ans += box[a];
			++a;
		}
		if(b != n){
			while(a < b && b % k != 0){
				--b;
				++box[b];
				ans += box[b];
			}
		}
		while(a < b){
			++cup[a / k];
			ans += cup[a / k];
			a += k;
		}
		cout << ans << '\n';
	}
	return 0;
}
