#include <iostream>
#define MAX 10

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	for(int j = 0; j < n; ++j){
		int height = 0;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			if(a[i][j] > height){
				height = a[i][j];
				++cnt;
			}
		}
		cout << cnt << ' ';
	}
	cout << '\n';
	for(int i = 0; i < n; ++i){
		int height = 0;
		int cnt = 0;
		for(int j = 0; j < n; ++j){
			if(a[i][j] > height){
				height = a[i][j];
				++cnt;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
