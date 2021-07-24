class Solution {
public:
    string reverseParentheses(string str) {
    stack<string> s;
    
    for(int i=0;i<str.size();i++){
        if(str[i]==')'){                
            string temp="";
            while(!s.empty() and s.top()!="(")
            {   
                string top =s.top();
                s.pop();
                reverse(top.begin(), top.end());
                temp += top;
            }
            s.pop();
            s.push(temp);
        }
        else 
        {
            string x;
            x += str[i];
            s.push(x);
        }
    }
    vector<string> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    
    reverse(v.begin(), v.end());
    string ans;
    for(auto stri:v)
        ans += stri;
    
    return ans;
}
};