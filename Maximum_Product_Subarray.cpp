#include <iostream>
/*
 *the max product happend on this 3 kinds of situation:

 * 0 (* * -* ****** -* **) 0
 * 0 (* * -* ****** )-* ** 0
 * 0 * * -*( ****** -* **) 0
 *
 * */
using namespace std;

class Solution
{
    void findmaxP(int A[], int i)
    {
#if 0
        cout << "A[i]=" << A[i]<<endl;
        cout << "tmp_o=" << tmp_o<<endl;
        cout << "tmp_n=" << tmp_n<<endl;
        cout << "tmp_l=" << tmp_l<<endl;
#endif
        
        if (A[i] > 0)
        {
            tmp_n *= A[i];
            bool_n = true;
            tmp_l *= A[i];
            bool_l = true;
        }
        else if (A[i] == 0)
        {
            if (bool_n)
                if (product < tmp_n)
                    product = tmp_n;
            if (bool_l)
                if (product < tmp_l)
                    product = tmp_l;
                /*
            if (product < (tmp_l > tmp_n ?tmp_l:tmp_n))
                product = tmp_l > tmp_n ?tmp_l:tmp_n;
                */
            tmp_n = 1;
            tmp_l = 1;
            bool_n = false;
            bool_l = false;
            firstnegtive = 1;
        }
        else if (A[i] < 0)
        {
            if (tmp_n < 0)
            {
                tmp_n *= A[i];
                bool_n = true;
            }
            else
            {
                if (bool_n)
                    if (product < tmp_n)
                        product = tmp_n;
                /*
                if (product < tmp_l > tmp_n ?tmp_l:tmp_n  )
                    product = tmp_l > tmp_n ?tmp_l:tmp_n;
                    */
                tmp_n *= A[i];
            
            }
            if (firstnegtive == 1)
            {
                tmp_l = 1;
                firstnegtive = 0;
            }
            else
            {
                tmp_l *= A[i];
                bool_l = true;
            }
        }
        if (product < A[i])
            product = A[i];
    }
public:
    long long product ;
    long long tmp_n ;
    bool bool_n;
    long long tmp_l ;
    bool bool_l;
    int firstnegtive;
    
    int maxProduct(int A[], int n)
    {  
        firstnegtive = 1;
        product = -2147483648;
        tmp_n =1;
        bool_n = false;
        tmp_l =1;
        bool_l = false;
        for (int i = 0; i < n; i++)
        {
            findmaxP(A,i);
        }
        if (bool_n)
            if (product < tmp_n)
                product = tmp_n;
        if (bool_l)
            if (product < tmp_l)
                product = tmp_l;
        
        /*
        if (product < (tmp_l > tmp_n ?tmp_l:tmp_n))
            product = tmp_l > tmp_n ?tmp_l:tmp_n;
        */
        return product;
    }
};

#if 1
int main()
{
    int a[] = {-1, 0,-1,2,-3,1,2,3,-2};
    //int a[] = {2, 3, -2, 4, -3, 0,2, -2, 4, 8, 4 ,-9, -8,2, 0,2 ,3,4};
    Solution test;
    cout << test.maxProduct(a, 9) << endl;
    return 0;

}
#endif
