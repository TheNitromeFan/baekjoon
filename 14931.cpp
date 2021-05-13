#include <iostream>
#define MAX 1000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int river[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> river[i];
	}
	long long score[MAX] = {};
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; j += i){
			score[i] += river[j];
		}
	}
	long long max_score = 0, interval = 0;
	for(int i = 1; i <= n; ++i){
		if(score[i] > max_score){
			max_score = score[i];
			interval = i;
		}
	}
	cout << interval << ' ' << max_score;
	return 0;
}
