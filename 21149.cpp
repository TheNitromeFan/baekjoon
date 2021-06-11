#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> last;
	long long unread = 0;
	for(int time = 1; time <= m; ++time){
		int s;
		cin >> s;
		unread += n;
		unread -= time - last[s];
		last[s] = time;
		cout << unread << '\n';
	}
	return 0;
}
