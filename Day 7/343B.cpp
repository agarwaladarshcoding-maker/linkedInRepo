#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    // Fast I/O - Important For CP
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    
    stack<char> st;
    int n = s.length();

    for(int i = 0; i < n; i++){
        char ch = s[i];
        if(st.empty()){
            st.push(ch);
        }
        else{
            if(st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    if(st.empty()){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    return 0;
}