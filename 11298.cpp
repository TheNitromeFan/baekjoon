#include <iostream>
#define MAX 110

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int a, b;
		cin >> a >> b;
		char graph[MAX][11];
		for(int i = 0; i < MAX; ++i){
			for(int j = 0; j < 11; ++j){
				graph[i][j] = ' ';
			}
		}
		for(int i = 0; i < MAX; ++i){
			graph[i][0] = '*';
		}
		for(int j = 0; j < 11; ++j){
			graph[0][j] = '*';
		}
		for(int j = 0; j < 11; ++j){
			graph[a * j + b][j] = '*';
		}
		cout << "y = " << a << "x + " << b << '\n';
		for(int i = a * 10 + b; i >= 0; --i){
			for(int j = 0; j < 11; ++j){
				cout << graph[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
