#include"line.cpp"
#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int m1[4] = { 0,1,2,3 };
	int m2[4] = { 4,5,6,8 };
	bool l[4] = { true,true,true,0 };
	line <char> s("line", 4);
	line <char> s1("ege", 3);
	s1 = s + s1;
	cout << "Sum: " << s << endl;
	s = s * 2;
	cout << "Mull: " << s << endl;
	s = s(1, 2);
	cout << "Sub: " << s << endl;
	line <int> i(m1, 4);
	line <int> i1(m2, 4);
	i = i + i1;
	cout << "Sum: " << i << endl;
	i = i1 * 2;
	cout << "Mull: " << i << endl;
	i = i1(1, 3);
	cout << "Sub: " << i << endl;
	line <bool> b(l, 4);
	cout << b << endl;
	cout << (i1 == i);
}