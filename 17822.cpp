#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool bfs(vector<deque<int>> &dq, vector<deque<bool>> &erased, int &sum, int &erased_count, int n, int m, int sx, int sy){
	if(erased[sx][sy]){
		return false;
	}
	deque<int> q;
	int cmp = dq[sx][sy];
	q.push_back(sx);
	q.push_back(sy);
	int erase_cnt = 0;
	erased[sx][sy] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop_front();
		int y = q.front();
		q.pop_front();
		++erase_cnt;
		sum -= cmp;
		++erased_count;
		if(x > 1 && dq[x - 1][y] == cmp && !erased[x - 1][y]){
			q.push_back(x - 1);
			q.push_back(y);
			erased[x - 1][y] = true;
		}
		if(x < n && dq[x + 1][y] == cmp && !erased[x + 1][y]){
			q.push_back(x + 1);
			q.push_back(y);
			erased[x + 1][y] = true;
		}
		int ny = y - 1;
		if(ny < 0){
			ny += m;
		}
		if(dq[x][ny] == cmp && !erased[x][ny]){
			q.push_back(x);
			q.push_back(ny);
			erased[x][ny] = true;
		}
		ny = y + 1;
		if(ny >= m){
			ny -= m;
		}
		if(dq[x][ny] == cmp && !erased[x][ny]){
			q.push_back(x);
			q.push_back(ny);
			erased[x][ny] = true;
		}
	}
	if(erase_cnt == 1){
		erased[sx][sy] = false;
		sum += cmp;
		--erased_count;
	}
	return erased[sx][sy];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	vector<deque<int>> dq(n + 1);
	vector<deque<bool>> erased(n + 1);
	int sum = 0;
	int erased_count = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < m; ++j){
			int x;
			cin >> x;
			dq[i].push_back(x);
			erased[i].push_back(false);
			sum += x;
		}
	}
	for(int a0 = 0; a0 < t; ++a0){
		int xi, di, ki;
		cin >> xi >> di >> ki;
		if(di){
			for(int i = xi; i <= n; i += xi){
				for(int j = 0; j < ki; ++j){
					dq[i].push_back(dq[i].front());
					dq[i].pop_front();
					erased[i].push_back(erased[i].front());
					erased[i].pop_front();
				}
			}
		}else{
			for(int i = xi; i <= n; i += xi){
				for(int j = 0; j < ki; ++j){
					dq[i].push_front(dq[i].back());
					dq[i].pop_back();
					erased[i].push_front(erased[i].back());
					erased[i].pop_back();
				}
			}
		}
		/*
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < m; ++j){
				cout << dq[i][j] << ' ';
			}
			cout << '\n';
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < m; ++j){
				cout << erased[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		bool erase = false;
		for(int i = 1; i <= n; ++i){
			for(int j = 0; j < m; ++j){
				if(bfs(dq, erased, sum, erased_count, n, m, i, j)){
					erase = true;
				}
			}
		}
		if(!erase){
			int delta = 0;
			for(int i = 1; i <= n; ++i){
				for(int j = 0; j < m; ++j){
					if(erased[i][j]){
						continue;
					}
					if(dq[i][j] * (n * m - erased_count) < sum){
						++dq[i][j];
						++delta;
					}else if(dq[i][j] * (n * m - erased_count) > sum){
						--dq[i][j];
						--delta;
					}
				}
			}
			sum += delta;
		}
	}
	cout << sum << '\n';
	return 0;
}
