//	��id:54����20�֡�C. ��Ӧ��- ����һ�����������ǰ��׺


//#include<iostream>
//using namespace std;
//#include<string>
//
//
//void matched_Prefix_Postfix(const string& str)
//{
//    string s1, s2;
//
//    if (str.size() == 1)
//    {
//        cout << "empty" << endl;
//        return;
//    }
//
//    for (int i = str.size() - 1; i > 0; i--)
//    {
//        s1 = str.substr(0, i);
//        s2 = str.substr(str.size()- i, i);
//        if (s1 == s2)
//        {
//            cout << s1 << endl;
//            return;
//        }
//        
//    }
//
//    cout << "empty" << endl;
//   
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	string abc;
//
//	while (n--)
//	{
//		cin >> abc;
//        matched_Prefix_Postfix(abc);
//	}
//
//	return 0;
//}



//	��id:55����20�֡�D. DS��Ӧ�á���ظ��Ӵ�


//#include <iostream>
//using namespace std;
//#include <string>
//
//void test(const string& str)
//{
//    int maxS = str.size() / 2+1;         // ����Ӵ�����          +1 ������
//
//    string s1;
//    string s2;
//
//    while (maxS--)
//    {
//        for (int i = 0; i <= str.size() - maxS * 2; i++)
//        {
//            s1 = str.substr(i, maxS);
//            for (int j = i + maxS; j <= str.size() - maxS; j++)
//            {
//                s2 = str.substr(j, maxS);
//
//                if (s1 == s2 && !s1.empty())
//                {
//                    cout << s1.size() << endl;
//                    return;
//                }
//            }
//        }
//    }
//
//    cout << "-1" << endl;
//
//}
//
//int main() {
//    int t;
//    cin >> t;
//
//    string str;
//    
//    while (t--)
//    {
//        cin >> str;
//        test(str);
//    }
//
//
//
//    return 0;
//}


//	��id:52����20�֡�A. DS��Ӧ��--KMP�㷨
// 
// 
//#include<iostream>
//using namespace std;
//#include<string>
//
//int KMPFind(const string& str, const string& sub,int *next)
//{
//	if (str.size() == 0 || sub.size() == 0 || next == nullptr)
//		return 0;
//	
//	int i = 0;											// ��������
//	int j = 0;											// �����Ӵ�
//	int strlen = str.size();
//	int sublen = sub.size();
//
//	while (i < str.size() && j < sublen)				// ����jΪ-1�����   ���޷�������ʽ����ת������ʱΪmax int����ö�����ʱ����      ����������
//	{
//		if (j == -1 || str[i] == sub[j])				// -1�±���˵���ʼλ��
//		{
//			i++;
//			j++;
//		}
//		else 
//			j = next[j];								// ����
//		
//	}
//
//	if (j >= sub.size()) 
//		return i - j + 1;								// ��ĿҪ���λ��1��ʼ���㣬�������±�λ0
//	else 
//		return 0;
//
//
//}
//
//void Next(const string& sub, int *next)
//{
//	if (sub.size() == 0)
//		return;
//
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;												// ǰ����Ϊ�̶�ֵ�����±�2��ʼ����
//	int j = 0;												// ��¼��ǰ�����ǰ��׺�ĳ���
//
//	while (i < sub.size())
//	{
//		if (j == -1 || sub[i-1] == sub[j])					// ����ǰһ��������ڶ�Ӧ��j�±�
//		{
//			next[i] = j + 1;
//			i++;
//			j++;
//		}
//		else
//			j = next[j];									// ������ˣ����˿��ܲ�ֹһ��
//	}
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str, sub;
//
//	while (t--)
//	{
//		cin >> str >> sub;
//
//		int* next = new int[sub.size()];
//		Next(sub,next);										// ����next����
//
//		for (int i = 0; i < sub.size(); i++) 
//			cout << next[i] << " ";
//
//		cout << endl;
//
//
//		cout << KMPFind(str, sub, next) << endl;
//
//	}
//
//
//
//
//	return 0;
//}




//	��id:53����20�֡�B.DS��Ӧ��--���滻


//#include<iostream>
//using namespace std;
//#include<string>
//
//int KMPFind(const string& str, const string& sub, int* next)
//{
//	if (str.size() == 0 || sub.size() == 0 || next == nullptr)
//		return 0;
//
//	int i = 0;											
//	int j = 0;											
//	int strlen = str.size();
//	int sublen = sub.size();
//
//	while (i < str.size() && j < sublen)				
//	{
//		if (j == -1 || str[i] == sub[j])				
//		{
//			i++;
//			j++;
//		}
//		else
//			j = next[j];								
//
//	}
//
//	if (j >= sub.size())
//		return i - j;								
//	else
//		return -1;
//
//
//}
//
//
//void Next(const string& sub, int* next)
//{
//	if (sub.size() == 0)
//		return;
//
//	next[0] = -1;
//	next[1] = 0;
//	int i = 2;												
//	int j = 0;												
//
//	while (i < sub.size())
//	{
//		if (j == -1 || sub[i - 1] == sub[j])					
//		{
//			next[i] = j + 1;
//			i++;
//			j++;
//		}
//		else
//			j = next[j];									
//	}
//}
//
//void Inser(string& str, string& abc, int x, int y)
//{
//	if (y == -1)												 // û�ҵ�ֱ�ӷ���-1������ʼΪ��������0 
//	{
//		cout << str << endl;
//		cout << str << endl;
//		return;
//	}
//	
//	string s1 = str.substr(0, y);
//	string s2 = str.substr(x + y, str.size());
//	
//	cout << str << endl;
//	cout << s1 + abc + s2 << endl;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	string str, sub, abc;
//
//	while (t--)
//	{
//		cin >> str >> sub >> abc;
//
//		int* next = new int[sub.size()];
//		Next(sub, next);										
//
//		int a = KMPFind(str, sub, next);						// KMP��λ��ֱ�ӷ����±�
//		Inser(str, abc, sub.size(), a);
//
//	}
//
//
//
//
//	return 0;
//}




//	��id:56����20�֡�E. �Ӵ�ѭ������ (Ver. I)


//#include<iostream>
//using namespace std;
//#include<string>
//
//void Next(const string& abc, int* next)
//{
//	int j = 0;
//	next[0] = 0;
//
//	for (int i = 1; i < abc.size(); i++)
//	{
//		while (j > 0 && abc[i] != abc[j])
//		{
//			j = next[j - 1];
//		}
//
//
//		if (abc[i] == abc[j])
//			j++;
//
//
//		next[i] = j;
//	}
//}
//
//int main() {
//
//	int t;
//	cin >> t;
//	string abc;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> abc;
//		int n = abc.size();
//
//		int* next = new int[n];
//		Next(abc, next);
//
//		for (int i = 0; i < n; i++)
//			cout << next[i] << " ";
//		cout << endl;
//
//		int minAdd;
//		if (n % (n - next[n - 1]) == 0 && n - next[n - 1] < n)
//
//			minAdd = 0;
//		else
//			minAdd = n - next[n - 1] - (n % (n - next[n - 1]));
//
//
//		cout << minAdd << endl;
//
//		delete[] next;
//	}
//
//	return 0;
//}


