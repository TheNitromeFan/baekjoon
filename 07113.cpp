#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int cnt = 1;
	while(n != m){
			++cnt;
		if(n > m){
			n -= m;
		}else{
			m -= n;
		}
	}
	cout << cnt;
	return 0;
}
