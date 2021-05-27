#include <iostream>
#define MAX 1000001

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int d[MAX];
	for(int i = 1; i < n; ++i){
		cin >> d[i];
	}
	int ans1[MAX] = {}, ans2[MAX];
	for(int i = n - 1; i >= 1; --i){
		if(d[i] == 0 || d[i] == 2){
			ans1[i] = ans1[i + 1] + 1;
		}
	}
	for(int i = 2; i <= n; ++i){
		if(d[i - 1] == 1 || d[i - 1] == 2){
			ans2[i] = ans2[i - 1] + 1;
		}
	}
	for(int i = 1; i <= n; ++i){
		cout << ans1[i] + ans2[i] << ' ';
	}
	return 0;
}
