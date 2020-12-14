#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	--n;
	long long ans = 0;
	for(int i = n + 1; i != 0; i = n / (n / i + 1)){
		ans += (n / i + 1) * (i - n / (n / i + 1));
	}
	cout << ans;
	return 0;
}
