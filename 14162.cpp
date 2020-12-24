#include <iostream>
#define MAX 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long f[MAX + 1] = {};
	for(int i = 1; i <= MAX; ++i){
		for(int n = i; n <= MAX; n += i){
			f[n] += i;
		}
	}
	long long psum[MAX + 1] = {};
	for(int i = 1; i <= MAX; ++i){
		psum[i] = psum[i - 1] + f[i];
	}
	int left, right;
	cin >> left >> right;
	cout << psum[right] - psum[left - 1];
	return 0;
}
