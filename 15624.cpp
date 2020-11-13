#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, vector<long long>> fibs;

int mod = 1000000007;

vector<long long> multiply(vector<long long> a, vector<long long> b){
	vector<long long> c = {(a[0] * b[0] % mod + a[1] * b[2] % mod) % mod,
	            (a[0] * b[1] % mod + a[1] * b[3] % mod) % mod, 
	            (a[2] * b[0] % mod + a[3] * b[2] % mod) % mod,
				(a[2] * b[1] % mod + a[3] * b[3] % mod) % mod};
	return c;
}

void fibonacci(int n){
	if(n == 0){
		vector<long long> id = {1, 0, 0, 1};
		fibs[0] = id;
		return;
	}
	vector<long long> fib = {1, 1, 1, 0};
	if(n == 1){
		fibs[1] = fib;
	}else if(n % 2 == 0){
		fibonacci(n/2);
		fibs[n] = multiply(fibs[n/2], fibs[n/2]);
	}else{
		fibonacci(n/2);
		fibonacci(n/2+1);
		fibs[n] = multiply(fibs[n/2], fibs[n/2+1]);
	}
}

int main(){
	int n;
	cin >> n;
	fibonacci(n);
	cout << fibs[n][2] << endl;
	return 0;
}
