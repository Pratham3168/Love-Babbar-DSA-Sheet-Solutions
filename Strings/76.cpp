#include <bits/stdc++.h>
using namespace std;

// GETTING MINIMUM REVERSAL COUNT BASED ON UNBALANCED STACK
int getMinRevCount(stack<char> st)
{

    int n = st.size();
    if (n % 2 != 0)
        return -1;

    int cnt = 0;

    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();

        if (a == b)
        {
            // {{ or }}
            cnt += 1;
        }
        else
        {
            // }{
            cnt += 2;
        }
    }

    return cnt;
}

// GENERATING UNBALANCED STACK
void getStack(string &s, stack<char> &st)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
}

int main()
{
    string s = "}{{}}{{{";
    stack<char> st;
    getStack(s, st);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    cout << endl;

    int ans = getMinRevCount(st);
    cout << "Minimum reversals required is : " << ans;
    return 0;
}