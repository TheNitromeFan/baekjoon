#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<char, int> pci;

bool ok_to_pass(const pci &last, const pci &cur){
	return last.first < cur.first || (last.first == cur.first && last.second < cur.second);
}

int main(){
	int n;
	scanf("%d\n", &n);
	pci arr[500], sorted[500];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 5; ++j){
			scanf(" %c-%d", &arr[5*i+j].first, &arr[5*i+j].second);
			sorted[5*i+j].first = arr[5*i+j].first;
			sorted[5*i+j].second = arr[5*i+j].second;
			// printf("%c-%d\n", arr[5*i+j].first, arr[5*i+j].second);
		}
	}
	sort(sorted, sorted+5*n, ok_to_pass);
	stack<pci> st;
	int idx = 0;
	for(int i = 0; i < 5*n; ++i){
		if(arr[i] == sorted[idx]){
			++idx;
		}else if(!st.empty()){
			if(st.top() == sorted[idx]){
				--i;
				++idx;
				st.pop();
			}else{
				st.push(arr[i]);
			}
		}else{
			st.push(arr[i]);
		}
	}
	while(!st.empty()){
		if(st.top() == sorted[idx]){
			++idx;
			st.pop();
		}else{
			printf("BAD");
			return 0;
		}
	}
	printf("GOOD");
	return 0;
}
