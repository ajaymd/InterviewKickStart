#include<bits/stdc++.h>

using namespace std;

// ----------------------------------------------------------------------

long long int MAX_MOD = 1000000000000000000LL;

// Random number in range [0, mod). Mod should be <= 10^18.

long long int random_number(long long int mod)			
{
	assert(1 <= mod);
	assert(mod <= MAX_MOD);
	if (RAND_MAX == 32767)
	{
		long long int no = rand();	
		no |= ((long long int)rand() << 15LL);
		no |= ((long long int)rand() << 30LL);
		no |= ((long long int)rand() << 45LL);
		no |= ((long long int)rand() << 47LL);
		return no % mod;
	}
	else if (RAND_MAX == 2147483647)
	{
		long long int no = rand();
		no |= ((long long int)rand() << 31LL);
		return no % mod;  
	}
	assert(false);
	return -1;
}

// -----------------------------------------------------------------------

const int MAX_N = 100000, MIN_VAL = -1, MAX_VAL = 2000000000;

void only_add_and_query(int &test_cases)
{
	test_cases--;

	cout << endl;
	int n = MAX_N;
	cout << n << endl;
	while (n--)
	{
		if (n % 2)
		{
			cout << random_number(MAX_VAL) + 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}

void random_test_case(int &test_cases)
{
	test_cases--;

	cout << endl;
	int n = MAX_N;
	cout << n << endl;
	while (n--)
	{
		int type = random_number(3);
		if (type == 0)
		{
			cout << 0 << endl;
		}
		else if (type == 1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << random_number(MAX_VAL) + 1 << endl;
		}
	}
}

int main()
{
	srand(time(NULL));
	freopen(
		"..//test_cases//generated_big_test_cases_input.txt", "w", stdout
	);
	//freopen("..//test_cases//ignore.txt", "w", stdout);

	int test_cases = 5;
	cout << test_cases << endl;
	random_test_case(test_cases);
	random_test_case(test_cases);
	random_test_case(test_cases);
	only_add_and_query(test_cases);
	only_add_and_query(test_cases);

	assert(test_cases == 0);

	return 0;
}