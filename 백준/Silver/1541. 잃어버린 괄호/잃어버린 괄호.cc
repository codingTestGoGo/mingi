#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

string strFormula;
vector<char> operands;
bool bMinusActivated = false;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	char chCurOperator;

	cin >> strFormula;

	for (int i = 0; i < strFormula.length(); i++)
	{
		if (strFormula[i] == '+')
		{
			operands.push_back('\0');
			if (bMinusActivated) sum -= atoi(operands.data());
			else sum += atoi(operands.data());
			operands.clear();
			continue;
		}
		else if (strFormula[i] == '-')
		{
			operands.push_back('\0');
			if(bMinusActivated == true) sum -= atoi(operands.data());
			else sum += atoi(operands.data());
			bMinusActivated = true;
			operands.clear();
			continue;
		}

		operands.push_back(strFormula[i]);
	}
	
	operands.push_back('\0');
	if (bMinusActivated) sum -= atoi(operands.data());
	else sum += atoi(operands.data());

	cout << sum;
	return 0;
}