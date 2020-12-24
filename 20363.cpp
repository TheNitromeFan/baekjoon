#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	if(x < y){
		swap(x, y);
	}
	cout << x + y / 10 + y;
	return 0;
}
