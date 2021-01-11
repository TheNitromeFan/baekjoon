#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> lamps(MAX + 1);
	for(int a = 1; a * a * a <= MAX; ++a){
		for(int b = a + 1; a * b * b <= MAX; ++b){
			for(int c = b + 1; a * b * c <= MAX; ++c){
				++lamps[a * b * c];
			}
		}
	}
	vector<int> psum(MAX + 1);
	for(int i = 1; i <= MAX; ++i){
		psum[i] = psum[i - 1] + lamps[i];
	}
	int t;
	cin >> t;
	for(int j = 0; j < t; ++j){
		int n;
		cin >> n;
		cout << psum[n] << '\n';
	}
	return 0;
}
