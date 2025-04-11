//	【id:54】【20分】C. 串应用- 计算一个串的最长的真前后缀


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



//	【id:55】【20分】D. DS串应用—最长重复子串


//#include <iostream>
//using namespace std;
//#include <string>
//
//void test(const string& str)
//{
//    int maxS = str.size() / 2+1;         // 最大子串长度          +1 ？？？
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


//	【id:52】【20分】A. DS串应用--KMP算法
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
//	int i = 0;											// 遍历主串
//	int j = 0;											// 遍历从串
//	int strlen = str.size();
//	int sublen = sub.size();
//
//	while (i < str.size() && j < sublen)				// 存在j为-1的情况   将无法进行隐式类型转换，此时为max int，最好都用临时变量      ！！！！！
//	{
//		if (j == -1 || str[i] == sub[j])				// -1下标回退到起始位置
//		{
//			i++;
//			j++;
//		}
//		else 
//			j = next[j];								// 回退
//		
//	}
//
//	if (j >= sub.size()) 
//		return i - j + 1;								// 题目要求从位置1开始计算，而不是下标位0
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
//	int i = 2;												// 前两项为固定值，从下标2开始遍历
//	int j = 0;												// 记录当前最长公共前后缀的长度
//
//	while (i < sub.size())
//	{
//		if (j == -1 || sub[i-1] == sub[j])					// 它的前一项如果等于对应的j下标
//		{
//			next[i] = j + 1;
//			i++;
//			j++;
//		}
//		else
//			j = next[j];									// 否则回退，回退可能不止一次
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
//		Next(sub,next);										// 构建next数组
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




//	【id:53】【20分】B.DS串应用--串替换


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
//	if (y == -1)												 // 没找到直接返回-1，在起始为正常返回0 
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
//		int a = KMPFind(str, sub, next);						// KMP找位置直接返回下标
//		Inser(str, abc, sub.size(), a);
//
//	}
//
//
//
//
//	return 0;
//}




//	【id:56】【20分】E. 子串循环问题 (Ver. I)


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


