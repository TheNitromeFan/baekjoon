#include <iostream>
#include <vector>

using namespace std;

int first_rotation(vector<bool> &forbidden, int n){
	for(int i = 0; i < n; ++i){
		if(!forbidden[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<bool> forbidden(n + 1);
	for(int i = 1; i <= n; ++i){
		int x;
		cin >> x;
		forbidden[(i + n - x) % n] = true;
	}
	cout << first_rotation(forbidden, n);
	return 0;
}
