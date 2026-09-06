class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long temp=x, rev=0, rem;
        while(x!=0){
            rem=x%10;
            x/=10;
            rev=rev*10+rem;
        }
        if(rev==temp){
            return true;
        }
        else{
            return false;
        }
    }
};