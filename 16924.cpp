#include<iostream>
#include<vector>

using namespace std;
char arr[100][100];
char arr_2[100][100];
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int check_cross(int x, int y);
int main(void)
{
	cin >> N >> M;
	// ���� �����
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			arr_2[i][j] = arr[i][j];
			if (arr_2[i][j] == '*') arr_2[i][j] = '.';
		}
	}
	//���� Ž��
	vector<pair<pair<int, int>, int>> v;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			// *�� �ִ°��� Ž�� ( ���ڰ� üũ : continue)
			if (arr[i][j] == '*')
			{
				int cross_size = check_cross(i, j);
				if (cross_size > 0)
				{
					v.push_back(make_pair(make_pair(i + 1, j + 1), cross_size));
				}

			}
		}
	}
	//���ڰ��� ���°��
	if (v.size() == 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	else//ã�� ���ڰ��� ����, ���� arr_2�迭�� ���ڰ��� �׷����� ��
	{

		//vector�� ���� ��ǥ�� arr_2�� ���ڰ� �׸�.
		for (int i = 0; i < v.size(); ++i)
		{
			int x = v[i].first.first -1;
			int y = v[i].first.second -1;
			arr_2[x][y] = '*';
			int size = v[i].second;

			for (int k = 1; k <= size; ++k)
			{
				for (int j = 0; j < 4; ++j)
				{
					int xn = x + (k * dx[j]);
					int yn = y + (k * dy[j]);
					arr_2[xn][yn] = '*';
				}
			}
		}
		//arr_2�� ���ڰ��� arr �� ���ڰ���
		//��� ���Ҹ� ���Ͽ� �ϳ��� �ٸ��� ���� �� ����.
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] != arr_2[i][j])
				{
					cout << -1 << '\n';
					return 0;
				}
			}
		}
		// �� �Ȱ��ٸ� ��ǥ�� ���.
		int sum = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			sum += v[i].second;
		}
		cout << sum << '\n';
		for (int i = 0; i < v.size(); ++i)
		{
			int x = v[i].first.first;
			int y = v[i].first.second;
			int size = v[i].second;
			for (int j = size; j > 0; j--)
            {
                cout << x << ' ' << y << ' ' << j << '\n';
            }
		}
	}
	return 0;
}
int check_cross(int x, int y)
{
	int cnt = 0;

	for (int size = 1; size < 100; ++size)
	{
		bool isable = true;
		for (int i = 0; i < 4; ++i)
		{
			int xn = x + (size*dx[i]);
			int yn = y + (size*dy[i]);

			if (xn >= N || xn < 0 || yn >= M || yn < 0)
			{
				isable = false;
				break;
			}

			if (arr[xn][yn] != '*')
			{
				isable = false;
			}

		}
		if (!isable)  break;
		cnt += 1;
	}

	return cnt;
}
