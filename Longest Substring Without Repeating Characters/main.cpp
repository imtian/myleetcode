#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int max_len = 0;
        int cur_len = 0;
        int prepos = -1;
		int preprepos = 0;
        int hashtable[255];

		for(int i=0; i < 255; i++)
            hashtable[i] = -1;
        
        for(i=0; i < s.length(); i++)
        {
			if(hashtable[s[i]] == -1)
			{
				cur_len = i - prepos;
				
				hashtable[s[i]] = i;
			}
			else
			{
				if(hashtable[s[i]] > prepos)    //prepos只能向前滑行，不能后退
					prepos = hashtable[s[i]];
				cur_len = i - prepos;
				
				hashtable[s[i]] = i;
			}
			
			if(cur_len > max_len)
				max_len = cur_len;
        }
        
        return max_len;
    }
};


int main()
{
	int max_len;
	Solution slu;
	string str("abba");

	max_len = slu.lengthOfLongestSubstring(str);
	
	cout<< max_len<< endl;

	return 0;
}