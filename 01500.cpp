#include <iostream>

using namespace std;

int main(){
	int s, k;
	cin >> s >> k;
	int d = s / k, m = s % k;
	long long product = 1LL;
	for(int i = 0; i < m; ++i){
		product *= (d + 1);
	}
	for(int i = m; i < k; ++i){
		product *= d;
	}
	cout << product << endl;
	return 0;
}
