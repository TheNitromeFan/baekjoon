#include <cstdio>
#include <deque>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	deque<int> dq;
	for(int i = 1; i <= n; ++i){
		dq.push_back(i);
	}
	int cnt = 0;
	for(int a0 = 0; a0 < m; ++a0){
		int x;
		scanf("%d", &x);
		int idx;
		for(int i = 0; i < dq.size(); ++i){
			if(dq[i] == x){
				idx = i;
				break;
			}
		}
		if(idx < dq.size() - idx){
			while(true){
				if(dq.front() == x){
					dq.pop_front();
					break;
				}
				++cnt;
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
			}
		}else{
			while(true){
				if(dq.front() == x){
					dq.pop_front();
					break;
				}
				++cnt;
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
