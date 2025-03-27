#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// 定义运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 中缀表达式转前缀表达式
string infixToPrefix(const string& infix) {
    stack<char> S1;
    stack<string> S2;
    string result;

    for (int i = static_cast<int>(infix.size()) - 1; i >= 0; --i) {
        char c = infix[i];

        if (isalnum(c)) {
            string num;
            num += c;
            while (i > 0 && isalnum(infix[i - 1])) {
                num = infix[i - 1] + num;
                --i;
            }
            S2.push(num);
        }
        else if (c == ')') {
            S1.push(c);
        }
        else if (c == '(') {
            while (!S1.empty() && S1.top() != ')') {
                if (S2.size() < 2) {
                    cerr << "Invalid expression: Not enough operands for operator." << endl;
                    return "";
                }
                string op1 = S2.top();
                S2.pop();
                string op2 = S2.top();
                S2.pop();
                char op = S1.top();
                S1.pop();
                S2.push(string(1, op) + " " + op1 + " " + op2);
            }
            if (!S1.empty()) S1.pop(); // 弹出右括号
        }
        else {
            while (!S1.empty() && S1.top() != ')' && precedence(c) < precedence(S1.top())) {
                if (S2.size() < 2) {
                    cerr << "Invalid expression: Not enough operands for operator." << endl;
                    return "";
                }
                string op1 = S2.top();
                S2.pop();
                string op2 = S2.top();
                S2.pop();
                char op = S1.top();
                S1.pop();
                S2.push(string(1, op) + " " + op1 + " " + op2);
            }
            S1.push(c);
        }
    }

    while (!S1.empty()) {
        if (S2.size() < 2) {
            cerr << "Invalid expression: Not enough operands for operator." << endl;
            return "";
        }
        string op1 = S2.top();
        S2.pop();
        string op2 = S2.top();
        S2.pop();
        char op = S1.top();
        S1.pop();
        S2.push(string(1, op) + " " + op1 + " " + op2);
    }


    result = S2.top();
    return result;
}

// 中缀表达式转后缀表达式
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (int i = 0; i < infix.length(); ++i) {
        char c = infix[i];
        if (isalnum(c)) {
            string num;
            num += c;
            while (i + 1 < infix.length() && isalnum(infix[i + 1])) {
                num += infix[i + 1];
                ++i;
            }
            if (!postfix.empty()) postfix += " ";
            postfix += num;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if (!postfix.empty()) postfix += " ";
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty()) operators.pop(); // 弹出左括号
        }
        else {
            while (!operators.empty() && precedence(c) <= precedence(operators.top())) {
                if (!postfix.empty()) postfix += " ";
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        if (!postfix.empty()) postfix += " ";
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int main() {
    string abc;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> abc;
        string prefix = infixToPrefix(abc);
        cout << prefix << " " << endl;
        string postfix = infixToPostfix(abc);
        cout << postfix << " " << endl;
    }

    return 0;
}