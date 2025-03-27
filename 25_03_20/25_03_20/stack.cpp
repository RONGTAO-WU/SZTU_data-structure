//#include<iostream>
//using namespace std;
//#include<string>
//
//int main()
//{
//	/*string abc = "abc";
//
//	cout << abc << endl;
//
//	string x(abc);
//
//	cout << x << endl;
//
//	string y(x, 2, 1000);
//	cout << y << endl;*/
//
//	char arr[] = "hello world";
//	string s1(arr,5);
//
//	cout << s1 << endl;
//
//	return 0;
//}




//#include<iostream>
//using namespace std;
//#include<string>
//#include<stack>
//#include<iterator>
//
//int mxp(char x, char y)
//{
//	int i,j;
//
//	if (x == '+' || x == '-')
//		i = 1;
//	else
//		i = 2;
//
//	if (y == '+' || y == '-' || y == '(' || y == ')')
//		j = 1;
//	else
//		j = 2;
//
//	return i > j ? 1 : 0;
//}

//void test1(const string& abc)
//{
//	stack<char>s1;
//	stack<char>s2;
//
//	reverse(abc.begin(), abc.end());
//
//	for (auto& e : abc)
//	{
//		if (e == '+' || e == '-' || e == '*' || e == '/' )		// 遇到运算符
//		{
//			if (!s1.empty() || s1.top() == ')')
//			{
//				s1.push(e);
//			}
//			else
//			{
//				int i = 0;
//				while (!s1.empty() && i == 0)
//				{
//					i = test2(e, s1.top());
//					if (i == 1)
//					{
//						s1.push(e);					// 高优先直接入s1
//						break;
//					}
//					else
//					{
//						s2.push(s1.top());			// 低优先直接入s2
//						s1.pop();
//					}
//				}
//
//				if (s1.empty())
//					s1.push(e);
//			}
//		}
//		else
//			s2.push(e);				// 数字栈
//
//
//
//		if (e == ')')								// 遇到括号
//		{
//			s1.push(e);
//		}else
//			if (e == '(')
//			{
//				while (s1.top() != ')')
//				{
//					s2.push(s1.top());
//					s1.pop();
//				}
//
//			}
//
//	}
//
//	while (!s1.empty())
//	{
//		s2.push(s1.top());
//		s1.pop();
//	}
//
//	while (!s2.empty())
//	{
//		cout << s2.top() << " ";
//		s2.pop();
//	}
//}

//void test2(const string& abc)
//{
//	stack<char>s1;
//	string str;
//
//
//	for (int i = 0;i<abc.size();i++)
//	{
//		if (isdigit(i))						// 操作数
//		{
//			while(isdigit(i))
//				str += i;
//				i++;
//			cout << str.c_str() << " ";
//		}
//		else if (i == '(')					// 括号
//			s1.push(i);
//		else if (i == ')')
//		{
//			while (s1.top() != '(')
//			{
//				cout << s1.top() << " ";
//				s1.pop();
//			}
//		}
//
//		if (i == '+' || i == '-' || i == '*' || i == '/')
//		{
//			if (s1.empty() || mxp(i, s1.top()) == 1)		// 操作符
//				s1.push(i);
//			else
//				while (s1.empty() && mxp(i, s1.top()) == 0)
//				{
//					cout << s1.top() << " ";
//					s1.pop();
//				}
//		}
//	}
//	cout << endl;
//
//}

//int main()
//{
//	
//	string abc;
//
//	int t;
//	cin >> t;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> abc;
//	//	test1(abc);			// 中转前
//		test2(abc);			// 中转后
//	}
//
//
//	return 0;
//}



//#include <iostream>
//#include <stack>
//#include <string>
//#include <algorithm>
//
//// 定义运算符优先级
//int precedence(char op) {
//    if (op == '+' || op == '-')
//        return 1;
//    if (op == '*' || op == '/')
//        return 2;
//    return 0;
//}
//
//// 中缀表达式转前缀表达式
//string infixToPrefix(const string& infix) {
//    stack<char> S1;
//    stack<char> S2;
//    string result;
//
//    for (int i = infix.length() - 1; i >= 0; --i) {
//        char c = infix[i];
//
//        if (isalnum(c)) {
//            S2.push(c);
//        }
//        else if (c == ')') {
//            S1.push(c);
//        }
//        else if (c == '(') {
//            while (!S1.empty() && S1.top() != ')') {
//                S2.push(S1.top());
//                S1.pop();
//            }
//            if (!S1.empty()) S1.pop(); // 弹出右括号
//        }
//        else {
//            while (!S1.empty() && S1.top() != ')' && precedence(c) <= precedence(S1.top())) {
//                S2.push(S1.top());
//                S1.pop();
//            }
//            S1.push(c);
//        }
//    }
//
//    while (!S1.empty()) {
//        S2.push(S1.top());
//        S1.pop();
//    }
//
//    while (!S2.empty()) {
//        result += S2.top();
//        S2.pop();
//    }
//
//    return result;
//}
//
//// 中缀表达式转后缀表达式
//string infixToPostfix(const string& infix) {
//    stack<char> operators;
//    string postfix;
//
//    for (char c : infix) {
//        if (isalnum(c)) {
//            postfix += c;
//        }
//        else if (c == '(') {
//            operators.push(c);
//        }
//        else if (c == ')') {
//            while (!operators.empty() && operators.top() != '(') {
//                postfix += operators.top();
//                operators.pop();
//            }
//            if (!operators.empty()) operators.pop(); // 弹出左括号
//        }
//        else {
//            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
//                postfix += operators.top();
//                operators.pop();
//            }
//            operators.push(c);
//        }
//    }
//
//    while (!operators.empty()) {
//        postfix += operators.top();
//        operators.pop();
//    }
//
//    return postfix;
//}
//
//void print(const string& abc)
//{
//    for (int i = 0;i<abc.size();i++)
//    {
//        while (isdigit(abc[i]))
//        {
//            cout << abc[i++];
//        }
//        
//        cout << abc[i] << " ";
//    }
//
//    cout << endl;
//}





//#include<iostream>
//using namespace std;
//#include<string>
//#include<list>
//
//void test(int N, int K, int S)
//{
//	list<int> ls;
//
//	for (int i = 1; i <= N; i++)
//		ls.push_back(i);
//	
//	auto set = ls.begin();
//	for (int i = 1; i < S; i++)
//		set++;
//
//    while (!ls.empty()) 
//    {
//        for (int i = 1; i < K; i++) 
//        {
//            set++;
//            if (set == ls.end()) 
//                set = ls.begin();
//            
//        }
//
//        cout << *set << " ";
//
//        auto nextIs = next(set);
//        if (nextIs == ls.end() && ls.size() > 1) 
//            nextIs = ls.begin();
//       
//        ls.erase(set);
//        set = nextIs;
//
//        if (ls.empty()) 
//            break;
//        
//    }
//    cout << endl;
//
//
//
//}
//
//int main()
//{
//
//    int N, K, S;
//
//    while (cin >> N >> K >> S)
//   {
//        test(N, K, S);
//   }
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#include<stack>
//
//void test(const string& abc)
//{
//	stack<char> st;
//
//	for (char e : abc)
//		st.push(e);
//
//	while (!st.empty())
//	{
//		cout << st.top();
//		st.pop();
//	}
//	cout << endl;
//
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//
//	string abc;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> abc;
//		test(abc);
//	}
//
//
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//#include<list>
//
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    int value;
//    
//    list<int> ls;
//    for (int i = 0; i < n; i++) 
//    {
//        cin >> value;
//        ls.push_back(value);
//    }
//
//    for (int i = 0; i < m; ++i) 
//    {
//        int target;
//        cin >> target;
//
//        auto it = find(ls.begin(), ls.end(), target);       
//        if (it != ls.end()) 
//        {
//            
//            if (it != ls.begin()) 
//            {
//                auto prevIt = prev(it);
//                cout << *prevIt << " ";
//            }
//     
//
//            auto nextIt = next(it);
//            if (nextIt != ls.end())
//                cout << *nextIt;
//       
//            cout << endl;
//        }
//    }
//
//    return 0;
//}



//#include <iostream>
//#include <stack>
//#include <string>
//#include <algorithm>
//
//// 判断运算符优先级
//int precedence(char op) {
//    if (op == '+' || op == '-')
//        return 1;
//    if (op == '*' || op == '/')
//        return 2;
//    return 0;
//}
//
//// 中缀转前缀
//std::string infixToPrefix(const std::string& infix) {
//    std::stack<char> S1;  // 运算符栈
//    std::stack<char> S2;  // 储存中间结果的栈
//
//    // 从右至左扫描中缀表达式
//    for (int i = infix.length() - 1; i >= 0; --i) {
//        char c = infix[i];
//
//        // 遇到操作数时，将其压入S2
//        if (std::isalnum(c)) {
//            S2.push(c);
//        }
//        // 遇到运算符时
//        else if (c == '+' || c == '-' || c == '*' || c == '/') {
//            while (!S1.empty() && S1.top() != ')' && precedence(S1.top()) >= precedence(c)) {
//                S2.push(S1.top());
//                S1.pop();
//            }
//            S1.push(c);
//        }
//        // 遇到括号时
//        else if (c == ')') {
//            S1.push(c);
//        }
//        else if (c == '(') {
//            while (!S1.empty() && S1.top() != ')') {
//                S2.push(S1.top());
//                S1.pop();
//            }
//            if (!S1.empty()) {
//                S1.pop();  // 弹出右括号
//            }
//        }
//    }
//
//    // 将S1中剩余的运算符依次弹出并压入S2
//    while (!S1.empty()) {
//        S2.push(S1.top());
//        S1.pop();
//    }
//
//    // 依次弹出S2中的元素并输出
//    std::string prefix;
//    while (!S2.empty()) {
//        prefix += S2.top();
//        S2.pop();
//    }
//
//    return prefix;
//}
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::cin.ignore(); // 忽略掉输入 n 后的换行符
//
//    for (int i = 0; i < n; ++i) {
//        std::string infix;
//        std::getline(std::cin, infix);
//        std::string prefix = infixToPrefix(infix);
//        std::cout << prefix << " " << std::endl;
//    }
//
//    return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#include<stack>
//
//
//bool matching(char x, char y)
//{
//    return (x == '(' && y == ')')
//        || (x == '[' && y == ']')
//        || (x == '{' && y == '}');
//}
//
//void test(const string& abc)
//{
//    stack<char> st;
//
//    for (const char& ch : abc)
//    {
//
//        if (ch == '(' || ch == '[' || ch == '{')
//            st.push(ch);
//
//        else if (ch == ')' || ch == ']' || ch == '}')
//        {
//            if (st.empty() || !matching(st.top(), ch))
//            {
//                cout << "error" << endl;
//                return;
//            }
//
//            st.pop();
//
//        }
//    }
//
//    if (st.empty())
//
//        cout << "ok" << endl;
//    else
//        cout << "error" << endl;
//
//}
//
//
//int main()
//{
//
//    int t = 0;
//    cin >> t;
//    string abc;
//
//    for (int i = 0; i < t; i++)
//    {
//
//        cin >> abc;
//        test(abc);      
//    }
//
//    return 0;
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#include<stack>
//
//
//bool matching(char x, char y)
//{
//	return (x == '(' && y == ')')
//		|| (x == '[' && y == ']')
//		|| (x == '{' && y == '}');
//}
//
//void test(const string& abc)
//{
//	stack<char> st;
//
//	for (const auto& ch : abc)
//	{
//
//		if (ch == '(' || ch == '[' || ch == '{')
//			st.push(ch);
//
//		else if (ch == ')' || ch == ']' || ch == '}')
//		{
//			if (st.empty() || !matching(st.top(), ch))
//			{
//				cout << "error" << endl;
//				return;
//			}
//
//			st.pop();
//
//		}
//	}
//
//	if (st.empty())
//
//		cout << "ok" << endl;
//	else
//		cout << "error" << endl;
//
//}
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	string abc;
//
//	for (int i = 0; i < t; i++)
//	{
//		cin >> abc;
//		test(abc);
//	}
//
//	return 0;
//}









