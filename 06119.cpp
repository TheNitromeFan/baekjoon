#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	int cow = 1;
	deque<int> cows;
	for(int i = 1; i <= s; ++i){
		char action;
		cin >> action;
		if(action == 'A'){
			char dir;
			cin >> dir;
			if(dir == 'L'){
				cows.push_front(cow);
			}else{
				cows.push_back(cow);
			}
			++cow;
		}else{
			char dir;
			int cnt;
			cin >> dir >> cnt;
			if(dir == 'L'){
				for(int j = 0; j < cnt; ++j){
					cows.pop_front();
				}
			}else{
				for(int j = 0; j < cnt; ++j){
					cows.pop_back();
				}
			}
		}
	}
	while(!cows.empty()){
		cout << cows.front() << '\n';
		cows.pop_front();
	}
	return 0;
}
