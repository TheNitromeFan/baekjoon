#include <iostream>
#include <queue>

using namespace std;

int four_seven(int number){
	queue<int> q;
	if(number >= 4){
		q.push(4);
	}
	if(number >= 7){
		q.push(7);
	}
	int ret;
	while(!q.empty()){
		ret = q.front();
		q.pop();
		if(number >= ret * 10 + 4){
			q.push(ret * 10 + 4);
		}
		if(number >= ret * 10 + 7){
			q.push(ret * 10 + 7);
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << four_seven(n);
	return 0;
}
