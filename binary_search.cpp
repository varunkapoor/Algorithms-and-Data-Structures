#include <vector>
#include <iostream>
using namespace std;

/*
 * @brief: Searches vector for a value
 * @note: Vector is assumed to be sorted
 * 
 * @param: Vector (presumably) containing the value
 * @param: Value to be found
 * 
 * @return: Index of value in vector 
 *          if found, -1 otherwise
 * */
template<class T>
int BinarySearch(vector<T>& A, T& What, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
    
        if(What == A[q])
        {
            return q;
        }
        else if(What < A[q])
        {
            return BinarySearch(A, What, p, q);
        }
        else
        {
            return BinarySearch(A, What, q + 1, r);
        }
    }
    else
    {
        return -1;
    }
}

int main()
{
    vector<int> A(8);
    for(int i=0; i<8; ++i)
    {
        A[i] = i;
    }
    int What = 6;
    cout << BinarySearch(A, What, 0, A.size() - 1);
}
