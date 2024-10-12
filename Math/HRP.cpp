#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <Windows.h>

/*Higher residuosity Problem (고차잉여문제)*/

using namespace std;

vector<int>c;		//class of Z*n
vector<int>q;		//quadratic residue
vector<int>nq;		//quadratic non-residue
clock_t start, finish;
int types = -1;
int k, N;

bool isPrime(int n);
void consolUI();
bool isCoprime(int y1, int y2);
void makeClasses(int N);
int modularOP(int x2, int N);
void findResidue(int x, int k, int N);
void findNonResidue();
void displayResult();

int main()
{
	system("cls");
	consolUI();
	//timer on
	start = clock();
	makeClasses(N);
	int sszie = c.size();
	cout << "[Finding residue...]";
	for (int i = 0; i < sszie; i++)
	{
		findResidue(c.at(i), k, N);
	}
	cout << "\t\tDone.\n";
	sort(q.begin(), q.end());	//sorting
	findNonResidue();
	//timer off
	finish = clock();
	displayResult();
	
	return 0;
}

void consolUI()
{
	cout << "===================  Equation   ====================\n";
	cout << "=                                                  =\n";
	cout << "=                 q = x^k (mod N)                  =\n";
	cout << "=                                                  =\n";
	cout << "====================================================\n\n";

	cout << "===================   Types     ====================\n";
	cout << "= Type 1 : N = p1*p2                               =\n";
	cout << "= Type 2 : prime N                                 =\n";
	cout << "====================================================\n";
	cout << "> Enter the type of operation : ";
	cin >> types;

	cout << "\n===============   Enter values     =================\n";
	while (1)
	{
		cout << "> Enter the value of k(>1) : ";
		cin >> k;
		if (k < 2)
		{
			cout << "k must be more than 1\n";
			k = -1;
		}
		else break;
	}
	if (types == 1)
	{
		int p1, p2;
		while (1)
		{
			cout << "> Enter the prime value of p1(>1) : ";
			cin >> p1;
			if (p1 < 2)
			{
				cout << "N must be more than 1\n";
				p1 = -1;
			}
			else if (isPrime(p1) == false)
			{
				cout << "p1 must be prime number\n";
				p1 = -1;
			}
			else break;
		}
		while (1)
		{
			cout << "> Enter the prime value of p2(>1) : ";
			cin >> p2;
			if (p2 < 2)
			{
				cout << "N must be more than 1\n";
				p2 = -1;
			}
			else if (isPrime(p2) == false)
			{
				cout << "p2 must be prime number\n";
				p2 = -1;
			}
			else break;
		}
		N = p1 * p2;
	}
	else
	{
		while (1)
		{
			cout << "> Enter the prime value of N(>2) : ";
			cin >> N;
			if (N <= 2)
			{
				cout << "N must be more than 2\n";
				N = -1;
			}
			else if (isPrime(N) == false)
			{
				cout << "N must be prime number\n";
				N = -1;
			}
			else break;
		}
	}
	cout << "====================================================\n\n";
	return;
}

bool isPrime(int n) 
{
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

bool isCoprime(int y1, int y2)
{
	int x1 = y1;
	int x2 = y2;
	while (1)
	{
		int a = x1 / x2;
		int b = x1 % x2;
		if (b == 0) break;
		x1 = x2;
		x2 = b;
	}
	if (x2 == 1) return true;
	else return false;
}

void makeClasses(int N)
{
	cout << "[Making classes of Z*n...]";
	//find N's coprime over integer ield
	for (int i = 1; i < N; i++)
	{
		if (isCoprime(i, N) == true) c.push_back(i);
	}
	cout << "\tDone.\n";
}

int modularOP(int x2, int N)
{
	int r = x2;
	while (1)
	{
		r = r - N;
		if (r < 0) return (r + N);
		else continue;
	}
}

void findResidue(int x, int k, int N)
{
	int z = modularOP(pow(x, k), N);
	//z is elemenent of N and not exists in vector q
	if ((N / z != 0) && (find(q.begin(), q.end(), z) == q.end()))
	{
		q.push_back(z);
	}
}

void findNonResidue()
{
	cout << "[Finding non-residue...]";
	int isize = c.size();
	int jsize = q.size();
	int i = 0, j = 0;
	while ((i < isize) && (j < jsize))
	{
		int a = c.at(i);
		int b = q.at(j);
		if (a == b)	//residue
		{
			i++;
			j++;
		}
		else
		{
			nq.push_back(a);	//non-residue
			i++;
		}
	}
	if (i < isize)
	{
		for (; i < isize; i++)
		nq.push_back(c.at(i));
	}
	cout << "\tDone.\n";
}

void displayResult()
{
	int size;
	cout << "\n===================== Results ======================\n";
	printf("=                 q = x^%d (mod %d)                  \n", k, N);
	cout << "====================================================\n";
	//print elements of Z
	size = c.size();
	printf("\n>> Elements of Z*N(%d):\n", size);
	cout << "Z*N = { ";
	for (int i = 0; i < size; i++)
		cout << c[i] << " ";
	cout << "}\n";
	//print residue
	size = q.size();
	printf("\n>> Residue(%d):\n", size);
	cout << "q = { ";
	for (int i = 0; i < size; i++)
		cout << q[i] << " ";
	cout << "}\n";
	//print residue
	size = nq.size();
	printf("\n>> Non-residue(%d):\n", size);
	cout << "nq = { ";
	for (int i = 0; i < size; i++)
		cout << nq[i] << " ";
	cout << "}\n";
	cout << "\n>> Total time : " << finish - start << "ms\n\n";
	cout << "====================================================\n";
}
