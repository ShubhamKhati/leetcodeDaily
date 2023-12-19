class Solution {
public:
    //eg string : nitin
    bool checkpalindrome(int i,vector<char>&ch,int n) // This function is comparing first and the last character of the string;
    {
        if(i>=n/2) //if the string is palindrome then we have to only go to half of it's length
        return true;

        if(ch[i]!=ch[n-i-1]) // if we get any character which is not equal to its (n-i-1) position then we return false
        return false;
        
        return checkpalindrome(i+1,ch,n); // call the function for i+1 ;
    }



    bool isPalindrome(string s) {
        vector<char>ch; //To store the characters of a string ;
       for(int i=0;i<s.length();i++)
       {
             if((s[i]>='a' && s[i]<='z') || (s[i]>='0'&& s[i]<='9'))// This will only store characters from a-z and 0-9
             ch.emplace_back(s[i]);  // Store the character into ch vector
             else if(s[i]>='A' && s[i]<='Z')// if the character is between A-Z then we have to convert it into lowercase;
             {
                 char lower=tolower(s[i]); //tolower function to convert the uppercase letter to lowercase letter;
                 ch.emplace_back(lower);  // Store the character into ch vector;
             }
       }

       int len=ch.size(); // This will store the size of ch vector which will be used in above function;
       if(checkpalindrome(0,ch,len)==true) // If the function returns true then the string is a palindrome else not;
       return true;
       else
       return false;
    }
};