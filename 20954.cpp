#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		long long x;
		cin >> x;
		long long ans = 0;
		long long dist = 1;
		while(dist < llabs(x)){
			ans += 4 * dist;
			dist *= 2;
		}
		if(x >= 0){
			ans += x;
		}else{
			ans += 2 * dist - x;
		}
		cout << ans << '\n';
	}
	return 0;
}
