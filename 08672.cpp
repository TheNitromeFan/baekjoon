#include <iostream>
#define MAX 1000001
#define MOD (1LL << 30)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long fib[MAX];
	fib[1] = 1;
	fib[2] = 2;
	for(int i = 3; i < MAX; ++i){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= MOD;
	}
	int z;
	cin >> z;
	for(int j = 0; j < z; ++j){
		int s, p;
		cin >> s >> p;
		cout << (fib[s] % (1LL << p)) << '\n';
	}
	return 0;
}
