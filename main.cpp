#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getPrecendence(char c)
{
    if (c == '(')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(char* str)
{
    string postfix;
    stack<char> stk;

    for (int i = 0; i < 80; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            postfix += str[i];
        else if (str[i] == '(')
            stk.push('(');
        else if (str[i] == ')')
        {
            while (stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if (str[i] != ' ')
        {
            while (!stk.empty() && getPrecendence(str[i]) <= getPrecendence(stk.top()))
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }
    }

    return postfix;
}

char* AddDelimitersToStr(char* str)
{
    int spacesNeeded = 0;
    int length = 0;
    while (str[length] != '\0')
    {
        if (str[length] != ' ')
            spacesNeeded = spacesNeeded + 1;
        length = length + 1;
    }

    int size = length + spacesNeeded + 1;
    char* adjustedStr = new char[size];

    int newInx = 0;
    for (int inx = 0; inx < length; inx++)
    {
        if (str[inx] != ' ')
        {
            adjustedStr[newInx] = str[inx];
            newInx = newInx + 1;
            adjustedStr[newInx] = ' ';
            newInx = newInx + 1;
        }
    }

    adjustedStr[newInx] = '\0';

    return adjustedStr;
}

int main(){
    char* str = new char[80];
    while (1)
    {
        cout << "Enter an arithmetic equation..." << endl;
        cin.getline(str, 80);
        str = AddDelimitersToStr(str);
        cout << str << endl;
        cout << InfixToPostfix(str) << endl;
        return 0;
    }
    return 0;
}
