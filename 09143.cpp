#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int i = 0; i < tc; ++i){
		int n, m;
		cin >> n >> m;
		if(n <= 2 * m){
			cout << "Reseni neexistuje.\n";
		}else{
			int u = (n - 1) / m * m;
			cout << u << ' ' << u - m << '\n';
		}
	}
	return 0;
}
