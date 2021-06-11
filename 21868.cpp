#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long ne, de, a, b, x0;
	cin >> ne >> de >> a >> b >> x0;
	cout << a * x0 + b << '\n';
	if(a){
		cout << ne << ' ' << llabs(de * a);
	}else{
		cout << 0 << ' ' << 0;
	}
	return 0;
}
