//#include<iostream>
//using namespace std;
//#include<queue>
//
//int main()
//{
//	queue<char> q1;
//	queue<int> q2;
//
//	int t;
//	cin >> t;
//	char x;
//	int y;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> x;
//		q1.push(x);
//	}
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> y;
//		q2.push(y);
//	}
//
//	int A_time = 0;
//	int B_time = 0;
//	int C_time = 0;
//	int A_num = 0;
//	int B_num = 0;
//	int C_num = 0;
//
//	for (int i = 0; i < t; i++)
//	{
//		if (q1.front() == 'A')
//		{
//			A_num++;
//			A_time += q2.front();
//		}
//		else if (q1.front() == 'B')
//		{
//			B_num++;
//			B_time += q2.front();
//		}
//		else
//		{
//			C_num++;
//			C_time += q2.front();
//		}
//
//		q1.pop();
//		q2.pop();
//
//	}
//
//	cout << A_time / A_num << endl;
//	cout << B_time / B_num << endl;
//	cout << C_time / C_num << endl;
//
//
//	return 0;
//}




#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<string>

string test(double n, int k)
{
	queue<int> q;
	stack<int> st;

	int integer = (int)n;									// ����������С������
	double dec = n - integer;

	if (integer == 0)										// ��ջ������������
		st.push(0);
	else
		while (integer)
		{
			st.push(integer % k);
			integer /= k;
		}

	string abc;
	while (!st.empty())
	{
		int digit = st.top();								// ȡջ�����ݼ����ַ�����
		st.pop();

		if (digit < 10)										// С��10׷�ӵ��ַ�����,����10����16����
		{
			abc += to_string(digit);
		}
		else
			abc += (char)('A' + digit - 10);				// 16����ת��
	}



	for (int i = 0; i < 3; i++)								// ���д���С������
	{
		dec *= k;
		int digit = (int)dec;
		q.push(digit);										// ������ջ
		dec -= digit;
	}

	string jkl;
	if (!q.empty())
	{
		jkl = ".";
		while (!q.empty())
		{
			int digit = q.front();							// ȡ��ͷԪ�ؼ����ַ�����
			q.pop();

			if (digit < 10)
				jkl += to_string(digit);
			else
				jkl += static_cast<char>('A' + digit - 10);
		}
	}

	return abc + jkl;

}


int main()
{
	int t, k;
	double n;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> k;
		cout << test(n, k) << endl;

	}




	return 0;
}