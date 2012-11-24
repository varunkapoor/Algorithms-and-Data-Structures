#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * @brief: Copies (B.size() - Bi) elements from A to B
 * 
 * @param: Vector in which elements will be copied
 * @param: Vector from which elementes will be copied
 * @param: Index of A where first element will be copied
 * @param: Index of B from where first element will be copied
 * */
template <class T>
void CopyRest(vector<T>& A, vector<T>& B, int i, int Bi)
{
    while(Bi < B.size())
    {
        A[i] = B[Bi];
        ++i; ++Bi;
    }
}

/*
 * @brief: Merges 2 sorted adjacent subarrays in vector
 * 
 * @param: Vector containing sorted subarrays
 * @param: Index of first element of first subarray
 * @param: Index of last element of first subarray
 * @param: Index of last element of second subarray
 * */
template <class T>
void Merge(vector<T>& A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    
    vector<T> L(n1);
    vector<T> R(n2);
    
    for(int i = 0; i < n1; ++i)
    {
        L[i] = A[p + i];
    }
    
    for(int i = 0; i < n2; ++i)
    {
        R[i] = A[q + i + 1];
    }
    
    int Li = 0, Ri = 0;
    
    for(int i = p; i <=r; ++i)
    {
        if(Li == L.size())
        {
            CopyRest(A, R, i, Ri);
            return;
        }
        else if(Ri == R.size())
        {
            CopyRest(A, L, i, Li);
            return;
        }
        if(L[Li] <= R[Ri])
        {
            A[i] = L[Li];
            ++Li;
        }
        else
        {
            A[i] = R[Ri];
            ++Ri;
        }
    }
}

/*
 * @brief: Sorts the vector using merge sort algorithm
 * 
 * @param: Vector to be sorted
 * @param: Index of first element to be sorted
 * @param: Index of last element to be sorted
 * */
template <class T>
void MergeSort(vector<T>& A, int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

int main()
{
    const int ELEMENTS = 15;
    
    vector<int> A(ELEMENTS);
    
    srand(time(NULL));
    
    for(int i=0; i<ELEMENTS; ++i)
    {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << endl;
    
    MergeSort(A, 0, A.size() - 1);
    
    for(int i=0; i<ELEMENTS; ++i)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
