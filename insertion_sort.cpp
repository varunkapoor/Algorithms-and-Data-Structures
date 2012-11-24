#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

/*
 * @brief: Sorts the vector
 * 
 * @param: Vector to be sorted
 * @param: true if it should be sorted in
 *         increasing order, false otherwise
 * */
template<class T>
void InsertionSort(vector<T>& A, const bool Increasing)
{
    T key;
    int i;

    // Pocinjemo od drugog elementa u polju (prvog nema potrebe sortirati)
    for(int j=1; j != A.size(); ++j)
    {
        key = A[j]; // Uzimamo trenutni element za kasniju upotrebu
        
        i = j - 1; // Svi ljevo od trenutnog elementa su sortirani
                   // Trazimo prvi element naljevo koji je manji/veci od
                   // trenutnog elementa.
        while(i >= 0 && (Increasing ? A[i] > key : A[i] < key)) // Ako dođe index do nule, tu je kraj 
                                    // liste i novi element je najmanji/najveci
        {
            A[i + 1] = A[i]; // sve veće od trenutnog guramo nadesno
            --i;
        }
        A[i + 1] = key; // napokon, nasli smo di treba biti trenutni element
    }
}
 
int main()
{
    vector<int> A(5);
    
    srand(time(NULL));
    
    for(int i=0; i<5; ++i)
    {
        A[i] = rand() % 100;
    }
    
    InsertionSort(A, true);
    
    for(int i=0; i<5; ++i)
    {
        cout << A[i] << " ";
    }
    
    cout << '\n';
    
    InsertionSort(A, false);
    
    for(int i=0; i<5; ++i)
    {
        cout << A[i] << " ";
    }
    
    cout << '\n';
}
