#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int note = 1111111111;
	int cnt = 0;
	while(n > 0){
		while(note > n){
			note /= 10;
		}
		while(n >= note){
			++cnt;
			n -= note;
		}
	}
	cout << cnt;
	return 0;
}
