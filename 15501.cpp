#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	deque<int> d1, d2;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		d1.push_back(x);
	}
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		d2.push_back(x);
	}
	while(d2.front() != d1.front()){
		d2.push_front(d2.back());
		d2.pop_back();
	}
	if(d1 == d2){
		printf("good puzzle");
		return 0;
	}
	reverse(d2.begin(), d2.end());
	d2.push_front(d2.back());
	d2.pop_back();
	if(d1 == d2){
		printf("good puzzle");
		return 0;
	}
	printf("bad puzzle");
	return 0;
}
