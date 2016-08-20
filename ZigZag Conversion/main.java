public class Solution {
    public String convert(String s, int numRows) {
        if (s.length() <= numRows || numRows == 1) {
            return s;
        }
        
        int gap = numRows + (numRows-2);
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= numRows; i++) {
            int index = i - 1;
            while(index < s.length()) {
                if (i == 1 || i == numRows) {
                    sb.append(s.charAt(index));
                } else {
                    sb.append(s.charAt(index));
                    int nextIndex = index + (numRows - i)*2;
                    if (nextIndex < s.length()) {
                        sb.append(s.charAt(nextIndex));
                    }
                }
                
                index += gap;
            }
        }
        
        return sb.toString();
    }
}
