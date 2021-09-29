class Solution {
public:
    bool isInteger(string s){
        if(s.empty()) return true;
        int i = 0;
        if(s.front() == '+' || s.front() == '-') i = 1;
        if(i >= s.length()) return false;
        for(; i < s.length(); ){
            if(isdigit(s[i])){
                i++;
            }
            else return false;
        }
        return true;
    }
    bool isDecimal(string s){
        int i = 0;
        if(s.front() == '+' || s.front() == '-') i = 1;
        int startI = i;
        bool foundDot = false; int dotIndex = -1;
        if(i >= s.length()) return false;
        for(; i < s.length(); ){
            if(s[i] == '.'){
                if(foundDot) return false;
                dotIndex = i;
                foundDot = true;
                i++;
            }
            else if(isdigit(s[i])){
                i++;
            }
            else return false;
        }
        if(!foundDot) return true;
        if(dotIndex == startI){
            if(dotIndex + 1 >= s.length()) return false;
        }
        return true;
    }
    bool isNumber(string s) {
        string firstHalf = "", secondHalf = ""; int i = 0; bool gotBroken = false;
        for(i = 0; i < s.length(); i++){
            if(s[i] == 'e' || s[i] == 'E'){
                firstHalf = s.substr(0, i);
                secondHalf = s.substr(i + 1);
                gotBroken = true;
                break;
            }
        }
        if(gotBroken && secondHalf == "") return false;
        if(firstHalf == "") firstHalf = s;
        return (isDecimal(firstHalf) || isInteger(firstHalf)) && isInteger(secondHalf);
    }
};