#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
typedef struct SNode {
	char data;
	struct SNode* next;
}SNode,*LinkStack;

LinkStack nums;
LinkStack OPs;

int InitStack(LinkStack &S) {
	S = NULL;
	return 1;
}

int Push(LinkStack&S, char elm) {
    SNode* p;p = new SNode;
    p->data = elm;
    p->next = S;
    S = p;
    return 1;


}

char Pop(LinkStack& S) {
    char elm;
    if (S == NULL)return 0;
    elm = S->data;
    SNode* p = S;
    S = S->next;
    delete p;
    return elm;

}

char GetTop(LinkStack S) {
    if (S != NULL)return S->data;
    else {
        puts("空栈顶");
            return 0;
    }
}

int In(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '#')
        return 1;
    else return 0;
}//符号入栈

char Precede(char t, char ch) {
    switch (ch) {
    case'(': {
        return'<';
        break; }
    case'*': {
        if (t == '*' || t == '(' || t == '-' || t == '#')
            return '<';
        else
            return '>';
        break; }
    case'/': {
        if (t == '*' || t == '(' || t == '-' || t == '#')
            return'<';
        else
            return '>';
        break; }
    case'+': {
        if (t == '(' || t == '#')
            return'<';
        else
            return '>';
        break; }
    case'#': {
        if (t != '#') {
            return'>';
            break;
        }
    }
    }
}


int Operate(int a, char c, int b)
{
    int t=0;
    switch (c)
    {
    case '+':
        t = a + b; break;
    case '-':
        t = a - b; break;
    case '*':
        t = a * b; break;
    case '/':
        t = a / b; break;
    }
    return t;   //返回计算结果 
}


void EvaluateExpression()
{
    InitStack(OPs);
    InitStack(nums);
    Push(OPs, '#');
    char ch,th,a,b=0;
    int x, y, t;
    cin >> ch;
    while (ch != '#' || GetTop(OPs) != '#') {
        if (!In(ch)) {
            Push(nums, ch);
            cin >> ch;
        }
        else {
            switch (Precede(GetTop(OPs), ch)) {
            case'<': {
                Push(OPs, ch);
                cin >> ch;
                break;
            }
            case'>': {
                th = Pop(OPs);
                a = Pop(nums);
                b = Pop(nums);
                x = a - '0';
                y = b - '0';
                Push(nums, Operate(y, th, x) + '0');
                break; }
            case'=': {
                a = Pop(nums);
                b = Pop(nums);
                th = Pop(OPs);
                x = a - '0';
                y = b - '0';
                Push(nums, Operate(y, th, x) + '0');
                Pop(OPs);
                cin >> ch;
                break; }
            }
        }
    }
    printf_s("计算结果为 %d",GetTop(nums)-'0');
    
}
void main() {
    puts("请输入计算表达式：\n");
        EvaluateExpression();

}
