#include <iostream>
#include <math.h>

using namespace std;

class Solution{
public:
    bool isPalindrome(int x)
    {
        if ((x < 9 && x > 0) || x == 0)
        {
            return true;
        }
        if (x < 0 )
            return false;
        if ( (int)(x / pow(10, (int)log10(x))) == (int)(x % 10))
        {
            if (isPalindrome((int)((int)x % (int)pow(10,(int)log10(x)))/10))
                return true;
        }
        else
        {
            return false;
        }
        cout << "must something wrong if show this infor\n"<<endl;
        return false;
    }
};

#if 1
int main()
{
    int y = 123456;
    cout << "logy=" <<log10(y)<<endl;
    Solution test;
    int palind = 12344321;
    int nopalind = 123454345;
    cout << "palind=" << test.isPalindrome(palind)<<endl;
    cout << "nopalind=" << test.isPalindrome(nopalind)<<endl;
    return 0;
}
#endif
