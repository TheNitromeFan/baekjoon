#include <iostream>
#define MAX 1000

using namespace std;

bool reconstruct(int a[][2], int b[MAX], int n){
	for(int i = 0; i < n; ++i){
		int j = i + a[i][1];
		if(j >= 0 && j < n && b[j] == 0){
			b[j] = a[i][0];
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int a[MAX][2];
		for(int i = 0; i < n; ++i){
			cin >> a[i][0] >> a[i][1];
		}
		int b[MAX] = {};
		if(reconstruct(a, b, n)){
			for(int i = 0; i < n; ++i){
				cout << b[i] << ' ';
			}
		}else{
			cout << -1;
		}
		cout << '\n';
	}
	return 0;
}
