#include <iostream>

using namespace std;

int level(long long n){
	int ans = 0;
	int powOf3 = 1;
	while(n > 0){
		ans += powOf3 * (n % 7);
		powOf3 *= 3;
		n /= 7;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << level(n);
	return 0;
}
