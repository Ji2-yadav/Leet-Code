class Solution {
public:
    void swap(int i, int j, vector<char>& s){
        char ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    void reverseString(vector<char>& s) {
        int i,j;
        i=0;
        j=s.size()-1;
        while(i<j)
        {
            swap (i,j,s);
            i++;
            j--;
        }
    }
};