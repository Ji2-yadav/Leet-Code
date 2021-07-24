class Solution {
public:
    bool is_num(const string& s)
    {
        auto it = s.begin();                            //an iterator to iterate over substr
        while (it != s.end() && isdigit(*it))           //check if each char is a digit
            ++it;      
        return !s.empty() && it == s.end();             //return false if either string size size is 0, or iterate never reached end
                                                        //i.e, while loop terminated in between, implies it found a non digit char
    }
    bool checknum(string s)             //function to check if the substr is a number
    {
        if(s.length()>1 &&s[0]=='0')    // if substr size is more then 1, it can't have leading zero
            return false;
        if(is_num(s))                   //check if the string consists of only numbers
        {
            if(stoi(s)<256)             //the number has to be less than 256
                return true;            //return true if it is
            else
                return false;           //else false
        }
        else
            return false;
    }
    bool isIPv4(string ip)
    {
        int count = 0;
        if(ip.length()>15)          //15 can be the maximum length for a valid IPv4
            return false;
        string substr="";           //substr stores each number placed between two '.'
        for(int i=0;i<ip.length();i++)  //iterate over the entire string once
        {
            if(ip[i]!='.' && substr.length()<3)     //condition to catch substr
                substr += ip[i];
            else if (ip[i]!='.' && substr.length()>=3)  //if substr length is more then 3, return false
                return false;
            else if(ip[i]=='.')         //now we have substr with desired length
            {
                if(checknum(substr))       //check if the substr only consists of numbers
                {
                    count++;            //count varibale to keep count that exact 4 substr are there
                    substr = "";        //reset the substr
                } 
                else
                {
                    return false;       //if the substr is not a number, return false
                }
                    
            }
            if(count>4)                 //if there are more then 4 substr, return false
                return false;
        }
        if(checknum(substr))            //check for last substr is still left
            count++;
        else
            return false;       
        if(count==4)                    //if the count is 4, return true (Finally! huh)
            return true;
        else
           return false;
    }
    
    bool checkHex(string s)
    {
        // Size of string
        int n = s.length();         
        if(n==0)                        //substr cant have 0 length
            return false;

        // Iterate over string
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if ((ch < '0' || ch > '9') && (ch < 'A' || ch > 'F')&& (ch < 'a' || ch > 'f'))      //condition for hex char
                return false; 
        }

        return true;
    }
    
    bool isIPv6(string ip)
    {
        int count = 0;                      //count var to keep substr count
        if(ip.length()>39)                  //max length can be 39
            return false;
        string substr="";                   //reset the substr
        for(int i=0;i<ip.length();i++)      //iterate over entire string once
        {
            if(ip[i]!=':' && substr.length()<4)     //condition to append to substr
                substr += ip[i];
            else if (ip[i]!=':' && substr.length()>=4)      //if substr size is more then 8, return false
                return false;
            else if(ip[i]==':')             // now we have substr of desired size
            {
                if(checkHex(substr))        //check if substr consists of only hex characters
                {
                    count++;                //if yes, increment count
                    substr = "";            //and reset the substr
                } 
                else
                {
                    return false;           //else, return false
                }
                    
            }
            if(count>8)                     //the substr count can not be more than 8
                return false;
        }
        if(checkHex(substr))                //check for last substr is still left
            count++;
        else
            return false;

        if(count==8)                        //if there are exactly 8 substr
            return true;                    //return true (Yay)
        else
           return false;                    //else, not an IPv6 type
    }
    
    string validIPAddress(string IP) {
        if(isIPv4(IP))          //check for IPv4
            return "IPv4";
         else if(isIPv6(IP))    //check for IPv6
            return "IPv6";
        else
            return "Neither";   //none of the above
    }
};