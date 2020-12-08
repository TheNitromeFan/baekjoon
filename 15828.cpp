#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned buffer;
	cin >> buffer;
	queue<int> router;
	int x;
	while(true){
		cin >> x;
		if(x == -1){
			break;
		}else if(x == 0){
			router.pop();
		}else if(router.size() < buffer){
			router.push(x);
		}
	}
	if(!router.empty()){
		while(!router.empty()){
			cout << router.front() << ' ';
			router.pop();
		}
	}else{
		cout << "empty";
	}
	return 0;
}
