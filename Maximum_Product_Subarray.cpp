#include <iostream>

using namespace std;

class Solution
{
    void findmaxP(int A[], int i)
    {
        cout << "A[i]=" << A[i]<<endl;
        cout << "tmp_o=" << tmp_o<<endl;
        cout << "tmp_n=" << tmp_n<<endl;
        if (A[i] > 0)
        {
            tmp_o *= A[i];
            tmp_n *= A[i];
        }
        else if (A[i] == 0)
        {
            if (product < (tmp_o > tmp_n ?tmp_o:tmp_n))
                product = tmp_o > tmp_n ?tmp_o:tmp_n;
            tmp_o = 1;
            tmp_n = 1;
        }
        else if (A[i] < 0)
        {
            if (tmp_n < 0)
            {
                tmp_n *= A[i];
                tmp_o = tmp_n;
            }
            else
            {
                tmp_n *= A[i];
                if (product < tmp_o )
                    product = tmp_o;
                tmp_o = 1;
            }
        }
    }
public:
    long long product ;
    long long tmp_o ;
    long long tmp_n ;
    
    int maxProduct(int A[], int n)
    {
        product = 1;
        tmp_o =1;
        tmp_n =1;
        for (int i = 0; i < n; i++)
        {
            findmaxP(A,i);
        }
        if (product < (tmp_o > tmp_n ?tmp_o:tmp_n))
            product = tmp_o > tmp_n ?tmp_o:tmp_n;
        for (int i = n-1; i>=0; i--)
        {
            findmaxP(A,i);
        }
        if (product < (tmp_o > tmp_n ?tmp_o:tmp_n))
            product = tmp_o > tmp_n ?tmp_o:tmp_n;
        return product;
    }
};

#if 1
int main()
{
    int a[] = {2, 3, -2, 4, -3, 0, -2, 4, 8, 4 ,-9, -8, 0,2 ,3,4};
    Solution test;
    cout << test.maxProduct(a, 16) << endl;
    return 0;

}
#endif
