#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
	{
        vector<int> indexs;
        map<int, int> vi;
        
        for(int i=0; i < nums.size(); i++)
        {
            if(!vi.count(nums[i]))
                vi.insert(pair<int, int>(nums[i], i));
            
            if(vi.count(target-nums[i]))
            {
                int n = vi[target-nums[i]];
                if(n < i)    //防止取本身，比如target=8，若遇到为4的元素，此时n == i。
                {
                    indexs.push_back(n+1);
                    indexs.push_back(i+1);
                    break;
                }
            }
        }
        
        return indexs;
    }
};


int main()
{
	int target;
	vector<int> param;
	vector<int> indexs;

	param.push_back(0);
	param.push_back(-5);
	param.push_back(4);
	param.push_back(0);

	target = -1;

	Solution slu;
	indexs = slu.twoSum(param, target);

	if(indexs.size())
	{
	    cout<< "index1: "<< indexs[0]<< endl;
	    cout<< "index2: "<< indexs[1]<< endl;
	}
	else
	{
		cout<< "no result!"<< endl;
	}

	return 0;
}