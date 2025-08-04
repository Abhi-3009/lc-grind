class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 == 0 && x!=0))
            return false;
        int rev_no = 0;
        while(x>rev_no){
            int digit = x%10;
            rev_no = (rev_no*10) + digit;
            x = x/10;
        }
        return (x == rev_no || x == rev_no/10);
    }
};