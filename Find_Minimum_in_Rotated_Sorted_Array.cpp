#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
        vector<int>::iterator begin = num.begin();
        vector<int>::iterator end = begin + num.size() -1 ;
        vector<int>::iterator mid ;

        while (begin < end)
        {
            mid = begin + (end - begin)/2;
            if ( *mid == *end || *begin == *mid )
            {
                *mid == *end ?end--:begin ++;
            }
            else if (*mid > *end)
            {
                begin = mid + 1;
            }
            else //if (*mid < *end)
            {
                end = mid;
            }
        }
        return *begin;
    }
};
#if 0
int main()
{
    vector<int> num1(10,10);
    num1[2] = 1;
    /*
    for (vector<int>::iterator it = num1.begin(); it < num1.end(); it ++)
        cout << *it <<endl;
    */
    Solution test;
    
    cout << "result:"<<test.findMin(num1) <<endl;
    return 0;
}
#endif
