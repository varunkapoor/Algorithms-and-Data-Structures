#include <iostream>
#include <limits>
#include <vector>
#include <stdio.h>

template<class T>
struct Result
{
    size_t max_left, max_right;
    T sum;
};

template <class T>
Result<T> FindMaxCrossingSubarray(std::vector<T>& A, int low, int mid, int high)
{
    Result<T> retval;
    T sum = 0, sum2 = std::numeric_limits<T>::min();
    int i = mid;
    
    // Left
    for(; i>=low; --i)
    {
        sum += A[i];
        if(sum > sum2)
        {
            sum2 = sum;
            retval.max_left = i;
        }
    }
    
    retval.sum = sum2;
    sum = 0;
    sum2 = std::numeric_limits<T>::min();
    i = mid + 1;
    
    // Right
    for(; i<=high; ++i)
    {
        sum += A[i];
        if(sum > sum2)
        {
            sum2 = sum;
            retval.max_right = i;
        }
    }
    
    retval.sum += sum2;
    return retval;
}

template <class T>
Result<T> FindMaxSubarray(std::vector<T>& A, int low, int high)
{
    if(high == low)
    {
        Result<T> retval;
        retval.sum = A[low];
        retval.max_left = low;
        retval.max_right = high;
        return retval;
    }
    
    int mid = (low + high) / 2;
    Result<T> max_left = FindMaxSubarray(A, low, mid);
    Result<T> max_right = FindMaxSubarray(A, mid+1, high);
    Result<T> max_mid = FindMaxCrossingSubarray(A, low, mid, high);

    if(max_right.sum >= max_left.sum && max_right.sum >= max_mid.sum)
    {
        return max_right;
    }
    else if(max_left.sum >= max_right.sum && max_left.sum >= max_mid.sum)
    {
        return max_left;
    }
    return max_mid;
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
    Result<int> a = FindMaxSubarray<int>(A, 0, A.size()-1);
    std::cout << a.sum;
}
