#include <cstdio>
#include <utility>
#include <map>

using namespace std;

map<int, pair<int, int>> slot; // vote, age

int main(){
	int n;
	scanf("%d", &n);
	int k;
	scanf("%d", &k);
	int cnt = 0;
	for(int i = 1; i <= k; ++i){
		int x;
		scanf("%d", &x);
		if(slot.find(x) == slot.end()){
			if(slot.size() < n){
				slot[x].first = 1;
				slot[x].second = i;
			}else{
				int victim = slot.begin()->first;
				pair<int, int> value = slot.begin()->second;
				for(auto a : slot){
					if(a.second < value){
						victim = a.first;
						value = a.second;
					}
				}
				slot.erase(victim);
				slot[x].first = 1;
				slot[x].second = i;
			}
		}else{
			++slot[x].first;
		}
	}
	for(auto a : slot){
		printf("%d ", a.first);
	}
	return 0;
}
