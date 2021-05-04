#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, s;
	cin >> x >> s;
	if(2 * s > x){
		cout << "TAK";
	}else{
		cout << "NIE";
	}
	return 0;
}
