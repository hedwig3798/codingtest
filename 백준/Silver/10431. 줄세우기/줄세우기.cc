#include <bits/stdc++.h>
#include <unordered_set>
#define le9 1'000'000'001
#define MOD 1'000'003

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int P;
	cin >> P;

	for (int i = 0; i < P; i++)
	{
		int T;
		cin >> T;

		vector<int> students(20);
		for (int i = 0; i < 20; i++)
		{
			cin >> students[i];
		}

		vector<int> sorted;
		int ans = 0;
		sorted.push_back(students[0]);

		for (int i = 1; i < 20; i++)
		{
			bool flag = true;
			for (int j = 0; j < sorted.size(); j++)
			{
				if (students[i] < sorted[j])
				{
					ans += sorted.size() - j;
					sorted.insert(sorted.begin() + j, students[i]);
					flag = false;
					break;
				}
			}
			if (flag)
			{
				sorted.push_back(students[i]);
			}
		}
		cout << T << " " << ans << "\n";
	}


	return 0;
}