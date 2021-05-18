#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	if((n / 2) * (n - n / 2) < k){
		cout << -1;
		return 0;
	}
	string s(n, 'B');
	if(k == 0){
		s[n - 1] = 'A';
		cout << s;
		return 0;
	}
	int a = 0, b = n;
	while(true){
		if(a * b >= k){
			s.replace(0, a - 1, string(a - 1, 'A'));
			int rem = k - (a - 1) * b;
			s[n - 1 - rem] = 'A';
			break;
		}else{
			++a;
			--b;
		}
	}
	cout << s;
	return 0;
}
