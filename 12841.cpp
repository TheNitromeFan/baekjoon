#include <iostream>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cross[MAX], left[MAX], right[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> cross[i];
	}
	for(int i = 1; i <= n - 1; ++i){
		cin >> left[i];
	}
	for(int i = 1; i <= n - 1; ++i){
		cin >> right[i];
	}
	long long psumLeft[MAX] = {}, psumRight[MAX] = {};
	for(int i = 1; i <= n - 1; ++i){
		psumLeft[i] = psumLeft[i - 1] + left[i];
	}
	for(int i = n - 1; i >= 1; --i){
		psumRight[i] = psumRight[i + 1] + right[i];
	}
	long long dist = psumLeft[0] + cross[1] + psumRight[1];
	int ans = 1;
	for(int i = 2; i <= n; ++i){
		if(dist > psumLeft[i - 1] + cross[i] + psumRight[i]){
			dist = psumLeft[i - 1] + cross[i] + psumRight[i];
			ans = i;
		}
	}
	cout << ans << ' ' << dist;
	return 0;
}
