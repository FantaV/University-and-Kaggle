#include <iostream>
#include <stack>
#include <string>

using namespace std;


float calc(float o1,float o2,char c)
{
    if(c=='+') return o1+o2;
    if(c=='-') return o1-o2;
    if(c=='*') return o1*o2;
    if(c=='/') return o1/o2;
    else return 0;
}

float evaluate(string exp)
{
    float result=0;
    stack<char>s;
    for(int i=0;i<exp.length();i++)
    {
        if(isdigit(exp[i]))
        {
            s.push(exp[i]-'0');
            /*A character is basically nothing more than an integer,
            whose value is the encoding of the character.
            In the most common encoding scheme, ASCII, the value for e.g. the character '0' is 48
           and the value for e.g. '3' is 51.
           Now, if we have a variable someChar containing the character '3'
           and you do someChar - '0' it's the same as doing 51 - 48
           which will result in the value 3.*/

        }
        else
        {
            float o2=s.top();
            s.pop();
            float o1=s.top();
            s.pop();
            result = calc(o1,o2,exp[i]);
            s.push(result);

        }
    }
    return s.top();
}

int main() {
    // (2+(3*5)) = 2+15=17
    //str = "2 3 5 * +""
    string exp="235*+";
    //  cout<<exp;
    cout<<evaluate(exp)<<endl;
    cout<<exp<<" = "<<evaluate(exp);
    cout<<"   Output Postfix Expression \n";

    return 0;
}