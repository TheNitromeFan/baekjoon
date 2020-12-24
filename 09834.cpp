#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, k;
	cin >> m >> k;
	string moves;
	cin >> moves;
	deque<int> dq;
	for(int i = 0; i < m; ++i){
		dq.push_back(i);
	}
	for(char move : moves){
		if(move == '.'){
			break;
		}
		if(move == 'B'){
			int card = dq.front();
			dq.pop_front();
			dq.push_back(dq.front());
			dq.pop_front();
			dq.push_front(card);
		}else if(move == 'A'){
			dq.push_back(dq.front());
			dq.pop_front();
		}
	}
	for(int j = 0; j < k - 1; ++j){
		dq.pop_front();
	}
	cout << dq.front() << ' ';
	dq.pop_front();
	cout << dq.front() << ' ';
	dq.pop_front();
	cout << dq.front();
	return 0;
}
