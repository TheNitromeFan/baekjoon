#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	if(m < 0){
		cout << 0;
		return 0;
	}
	int mx = m;
	for(int i = 0; i < n; ++i){
		int in, out;
		cin >> in >> out;
		m += in - out;
		if(m < 0){
			cout << 0;
			return 0;
		}else if(m > mx){
			mx = m;
		}
	}
	cout << mx;
	return 0;
}
