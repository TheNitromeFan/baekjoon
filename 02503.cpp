#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<tuple<int, int, int>> guesses;
	for(int query = 0; query < n; ++query){
		int guess, strikes, balls;
		cin >> guess >> strikes >> balls;
		guesses.push_back(make_tuple(guess, strikes, balls));
	}
	int cnt = 0;
	for(int a = 1; a <= 9; ++a){
		for(int b = 1; b <= 9; ++b){
			for(int c = 1; c <= 9; ++c){
				if(a == b || b == c || c == a){
					continue;
				}
				bool flag = true;
				for(auto tup : guesses){
					int guess = get<0>(tup);
					int h = guess / 100, t = guess / 10 % 10, o = guess % 10;
					int strikes = 0, balls = 0;
					if(h == a){
						++strikes;
					}else if(h == b || h == c){
						++balls;
					}
					if(t == b){
						++strikes;
					}else if(t == a || t == c){
						++balls;
					}
					if(o == c){
						++strikes;
					}else if(o == a || o == b){
						++balls;
					}
					if(get<1>(tup) != strikes || get<2>(tup) != balls){
						flag = false;
						break;
					}
				}
				if(flag){
					++cnt;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
