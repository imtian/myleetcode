public class Solution {
    public int myAtoi(String str) {
        if (str == null) {
            return 0;
        }
        str = str.trim();
        
        boolean isMinus = str.startsWith("-") ? true : false;
        
        int i = 0;
        if (str.startsWith("+") || str.startsWith("-")) {
            i = 1;
        }
        long sum = 0;
        for (; i < str.length(); i++) {
            int num = (int)str.charAt(i) - 48;
            if (num<0 || num>9) {
                break;
            }
            
            sum = sum*10 + num;
            if (isMinus) {
                if ((0-sum) < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
            } else {
                if (sum > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
            }
        }
        
        return (int)(isMinus ? 0-sum : sum);
    }
}
