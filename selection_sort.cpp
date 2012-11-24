#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/*
 * @brief: Sorts the vector
 * 
 * @param: Vector to be sorted
 * */
template<class T>
void SelectionSort(vector<T>& A)
{
    int k;
    
    for(int i=0; i < A.size() - 1; ++i)
    {
        k = i;
        for(int j = i+1; j < A.size(); ++j)
        {
            if(std::min(A[k], A[j]) == A[j])
                k = j;
        }
        std::swap(A[i], A[k]);
    }
}

int main()
{
    srand(time(NULL));
    
    vector<int> A(5);
    
    for(int i=0; i < 5; ++i)
    {
        A[i] = rand() % 100;
        cout << A[i] << ' ';
    }
    cout << '\n';
    
    SelectionSort(A);
    
    for(int i=0; i < 5; ++i)
    {
        cout << A[i] << ' ';
    }
    cout << '\n';
}
