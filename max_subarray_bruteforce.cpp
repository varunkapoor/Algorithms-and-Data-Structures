#include <iostream>
#include <limits>
#include <vector>

template<class T>
struct Result
{
    size_t max_left, max_right;
    T sum;
};

template<class T>
Result<T> FindMaxSubarray(std::vector<T>& A)
{
    Result<T> retval;
    retval.sum = std::numeric_limits<T>::min();
    T sum;
    
    for(int i=0; i<A.size(); ++i)
    {
        sum = 0;
        for(int j=i; j<A.size(); ++j)
        {
            sum += A[j];
            if(sum > retval.sum)
            {
                retval.sum = sum;
                retval.max_left = j;
                retval.max_right = i;
            }
        }
    }
    return retval;
}

int main()
{
    std::vector<int> A;
    // Yeah, I know, don't judge
    A.push_back(13);
    A.push_back(-3);
    A.push_back(-25);
    A.push_back(20);
    A.push_back(-3);
    A.push_back(-16);
    A.push_back(-23);
    A.push_back(18);
    A.push_back(20);
    A.push_back(-7);
    A.push_back(12);
    A.push_back(-5);
    A.push_back(-22);
    A.push_back(15);
    A.push_back(-4);
    A.push_back(7);
    Result<int> a = FindMaxSubarray<int>(A);
    std::cout << a.sum;
}
