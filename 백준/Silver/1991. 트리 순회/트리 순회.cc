#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//char tree[26][3];
char inorderArr[26];
pair<char, char> tree[26];
int n;

void PreorderTraversal(char curChar)
{
	if (curChar == '.') return;
	cout << curChar;

	PreorderTraversal(tree[curChar - 'A'].first);
	PreorderTraversal(tree[curChar - 'A'].second);
}

void InorderTraversal(char CurChar)
{
	if (CurChar == '.') return;
	InorderTraversal(tree[CurChar - 'A'].first);
	cout << CurChar;
	InorderTraversal(tree[CurChar - 'A'].second);
}

void PostorderTraversal(char curChar)
{
	if (curChar == '.') return;
	PostorderTraversal(tree[curChar - 'A'].first);
	PostorderTraversal(tree[curChar - 'A'].second);
	cout << curChar;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char node, left, right;
		cin >> node >> left >> right;

		//tree[i][0] = node;
		tree[node - 'A'].first = left;
		tree[node - 'A'].second = right;
	}

	PreorderTraversal('A');
	cout << "\n";
	InorderTraversal('A');
	cout << "\n";
	PostorderTraversal('A');

	return 0;
}