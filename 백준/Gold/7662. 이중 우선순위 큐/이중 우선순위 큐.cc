#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

multiset<int> prioritySet;

int t, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> t ;

	for (int i = 0; i < t; i++)
	{
		cin >> k;
		char command; 
		int temp;

		for (int j = 0; j < k; j++)
		{
			cin >> command >> temp;
			if (command == 'I')
			{
				prioritySet.insert(temp);
			}

			else if (command == 'D' && prioritySet.empty() ==false)
			{
				if (temp == 1)
				{
					auto it = prev(prioritySet.end());
					prioritySet.erase(it);
				}
				else if (temp == -1)
				{
					auto it = prioritySet.begin();
					prioritySet.erase(it);

				}
			}
		}

		if (prioritySet.empty())
		{
			cout << "EMPTY" << "\n";
		}
		else
		{
			cout << *prioritySet.rbegin() << " " << *prioritySet.begin() << "\n";
		}
		prioritySet.clear();
	}
	
	return 0;
}