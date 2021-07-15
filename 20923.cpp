#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	int m;
	cin >> n >> m;
	deque<int> cards1, cards2;
	deque<int> ground1, ground2;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		cards1.push_front(x);
		cin >> x;
		cards2.push_front(x);
	}
	int winner = 0;
	for(int j = 0; j < m; ++j){
		if(j % 2 == 0){
			ground1.push_front(cards1.front());
			cards1.pop_front();
			if(cards1.empty()){
				winner = 2;
				break;
			}
			if(!ground1.empty() && !ground2.empty() && ground1.front() + ground2.front() == 5){
				while(!ground1.empty()){
					cards2.push_back(ground1.back());
					ground1.pop_back();
				}
				while(!ground2.empty()){
					cards2.push_back(ground2.back());
					ground2.pop_back();
				}
			}else if((!ground1.empty() && ground1.front() == 5) || (!ground2.empty() && ground2.front() == 5)){
				while(!ground2.empty()){
					cards1.push_back(ground2.back());
					ground2.pop_back();
				}
				while(!ground1.empty()){
					cards1.push_back(ground1.back());
					ground1.pop_back();
				}
			}
		}else{
			ground2.push_front(cards2.front());
			cards2.pop_front();
			if(cards2.empty()){
				winner = 1;
				break;
			}
			if(!ground1.empty() && !ground2.empty() && ground1.front() + ground2.front() == 5){
				while(!ground1.empty()){
					cards2.push_back(ground1.back());
					ground1.pop_back();
				}
				while(!ground2.empty()){
					cards2.push_back(ground2.back());
					ground2.pop_back();
				}
			}else if((!ground1.empty() && ground1.front() == 5) || (!ground2.empty() && ground2.front() == 5)){
				while(!ground2.empty()){
					cards1.push_back(ground2.back());
					ground2.pop_back();
				}
				while(!ground1.empty()){
					cards1.push_back(ground1.back());
					ground1.pop_back();
				}
			}
		}
	}
	if(cards1.size() > cards2.size()){
		winner = 1;
	}else if(cards1.size() < cards2.size()){
		winner = 2;
	}
	if(winner == 1){
		cout << "do\n";
	}else if(winner == 2){
		cout << "su\n";
	}else{
		cout << "dosu\n";
	}
	return 0;
}
