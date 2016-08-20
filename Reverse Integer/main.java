class Solution {  
public:  
    int reverse(int x) {  
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值  
        long long sum = 0;   
          
        while(x != 0)  
        {  
            int remainder = x % 10;  
            sum = sum * 10 + remainder;  
            if (sum > max || sum < min)   //溢出处理  
            {  
                return 0;
            }  
            x = x / 10;  
        }  
				
        return sum;  
    }  
}
