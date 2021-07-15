#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		int x;
		cin >> x;
		if(x == 2){
			cout << '\n';
		}
	}
	return 0;
}
