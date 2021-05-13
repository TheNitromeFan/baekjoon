#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << 3 << '\n';
	for(int v = 1; v <= 3; ++v){
		for(int i = v; i <= 99999; i += 3){
			cout << i << ' ';
		}
		cout << '\n';
	}
	return 0;
}
