#include <iostream>
#define MAX 1001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int p, n, c;
		cin >> p >> n >> c;
		if(p == 0 && n == 0 && c == 0){
			break;
		}
		int a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < p; ++j){
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for(int j = 0; j < p; ++j){
			int streak = 0;
			for(int i = 0; i < n; ++i){
				if(a[i][j]){
					++streak;
					if(streak == c){
						++ans;
					}
				}else{
					streak = 0;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
