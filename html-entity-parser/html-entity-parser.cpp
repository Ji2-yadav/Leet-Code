class Solution {
public:
    string entityParser(string text) {
     for(int i=0;i<text.length();i++)
     {
         if(text[i]=='&')
         {
             if(i<text.length()-3)
             {
             if(text[i+1]=='g' && text[i+2]=='t' && text[i+3]==';')
                 text.replace(i,4,">");
             else if(text[i+1]=='l' && text[i+2]=='t' && text[i+3]==';')
                 text.replace(i,4,"<");
             }
             if(i<text.length()-6)
             {
                 if(text[i+1]=='f' && text[i+2]=='r' && text[i+3]=='a' && text[i+4]=='s'  && text[i+5]=='l' && text[i+6]==';')
                     text.replace(i,7,"/");
             }
             if(i<text.length()-5)
             {
                 if(text[i+1]=='q' && text[i+2]=='u' && text[i+3]=='o' && text[i+4]=='t' && text[i+5]==';')
                    text.replace(i,6,"\"");
                 else if(text[i+1]=='a' && text[i+2]=='p' && text[i+3]=='o' && text[i+4]=='s' && text[i+5]==';' )
                    text.replace(i,6,"'");
             }
             if(i<text.length()-4)
             {
                if(text[i+1]=='a' && text[i+2]=='m' && text[i+3]=='p' && text[i+4]==';' )
                    text.replace(i,5,"&");
             }
             
             
         }
     }
    return text;
    }
};