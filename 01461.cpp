#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	priority_queue<int> pbooks, nbooks;
	for(int i = 0; i < n; ++i){
		int book;
		scanf("%d", &book);
		if(book > 0){
			pbooks.push(book);
		}else{
			nbooks.push(-book);
		}
	}
	int dist = 0, greatest = 0;
	if(!pbooks.empty() && greatest < pbooks.top()){
		greatest = pbooks.top();
	}
	if(!nbooks.empty() && greatest < nbooks.top()){
		greatest = nbooks.top();
	}
	while(!pbooks.empty()){
		dist += pbooks.top();
		for(int i = 0; i < m && !pbooks.empty(); ++i){
			pbooks.pop();
		}
	}
	while(!nbooks.empty()){
		dist += nbooks.top();
		for(int i = 0; i < m && !nbooks.empty(); ++i){
			nbooks.pop();
		}
	}
	printf("%d", 2 * dist - greatest);
	return 0;
}
