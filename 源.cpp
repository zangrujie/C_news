/*#include<iostream>
using namespace std;
int Cal(long int a, long int n, long int m)
{
	int result = 1;
	a = a % m;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result = (result * a) % m;
		}
		a = (a * a) % m;
		n = n / 2;
	}
	return result;
}
int main()
{
	cout << "Calculate a^n(mod m). . ." << endl;
	cout << "Please input:" << endl;
	long int a;
	long int n;
	long int m;
	cout << "a=";
	cin >> a;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	long int t = Cal(a, n, m);
	cout << a << "^" << n << "(mod" << m << ")=" << t;
}*/
#include<iostream>
using namespace std;
void Swap(int& a, int& b)
{
	int tep = a;
	a = b;
	b = tep;
}
int Ou(int a, int b,int& inv_a,int& inv_b)
{
	if (a < b) { return Ou(b, a, inv_b, inv_a); }
	int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
	int a0 = a, b0 = b, q = 1;
	while (a % b != 0)
	{
		q = a / b;
		a = a % b;
		Swap(a, b);
		s0 -= s1 * q;
		Swap(s0, s1);
		t0 -= t1 * q;
		Swap(t0, t1);
	}
	inv_a = s1 > 0 ? s1 : s1 + b0;
	inv_b = t1 > 0 ? t1 : t1 + a0;
	return 0;
}
int main()
{
	int a, b;
	cin >> a >> b;
	int inv_a = 1, inv_b = 1;
	Ou(a, b, inv_a, inv_b);
	cout << inv_a << " " << inv_b<<endl;
}
