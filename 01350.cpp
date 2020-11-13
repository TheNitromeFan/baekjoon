#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> file_sizes;
	for(int i = 0; i < n; ++i){
		int file_size;
		cin >> file_size;
		file_sizes.push_back(file_size);
	}
	int part_size;
	cin >> part_size;
	long long part_cnt = 0;
	for(int f : file_sizes){
		if(f != 0){
			part_cnt += (f - 1) / part_size + 1;
		}
	}
	cout << part_cnt * part_size;
	return 0;
}
