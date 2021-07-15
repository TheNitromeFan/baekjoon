#include <iostream>
#define MAX 51

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> a[i][j];
		}
	}
	bool visible[MAX][MAX] = {};
	for(int i = 1; i <= n; ++i){
		int height = 0;
		for(int j = 1; j <= n; ++j){
			if(a[i][j] > height){
				visible[i][j] = true;
				height = a[i][j];
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		int height = 0;
		for(int j = n; j >= 1; --j){
			if(a[i][j] > height){
				visible[i][j] = true;
				height = a[i][j];
			}
		}
	}
	for(int j = 1; j <= n; ++j){
		int height = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i][j] > height){
				visible[i][j] = true;
				height = a[i][j];
			}
		}
	}
	for(int j = 1; j <= n; ++j){
		int height = 0;
		for(int i = n; i >= 1; --i){
			if(a[i][j] > height){
				visible[i][j] = true;
				height = a[i][j];
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(visible[i][j]){
				++ans;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
