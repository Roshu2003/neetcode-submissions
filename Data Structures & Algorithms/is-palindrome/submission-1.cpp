class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(auto it:s){
            char c = tolower(it);
            if(isalnum(c))temp += c;
        }
        cout<<temp<<endl;
        int i = 0;
        int j = temp.size() - 1;
        while(i <= j){
            if(tolower(temp[i]) != tolower(temp[j]))return false;
            i++;
            j--;
        }
        return true;
    }
};
