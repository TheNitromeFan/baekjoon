#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n % 2 == 1){
		cout << "still running";
		return 0;
	}
	int time = 0;
	for(int i = 0; i < n; i += 2){
		int x, y;
		cin >> x >> y;
		time += y - x;
	}
	cout << time;
	return 0;
}
