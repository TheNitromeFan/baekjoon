#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		string s;
		cin >> s;
		int len = (int)s.length();
		int m = (int)ceil(sqrt(len));
		char arr[101][101];
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < m; ++j){
				if(i * m + j < len){
					arr[i][j] = s[i * m + j];
				}else{
					arr[i][j] = '*';
				}
			}
		}
		for(int j = 0; j < m; ++j){
			for(int i = m - 1; i >= 0; --i){
				if(arr[i][j] != '*'){
					cout << arr[i][j];
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
