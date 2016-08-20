public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long sum = 0;
        long backup = x;
        while(x != 0) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        
        return sum == (long)backup;
    }
}
