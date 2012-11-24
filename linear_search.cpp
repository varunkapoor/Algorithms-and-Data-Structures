 #include <vector>
 #include <iostream>
 using namespace std;
 
 /*
  * @brief: Searches vector for a value
  * 
  * @param: Vector (presumably) containing the value
  * @param: Value to be found
  * 
  * @return: Index of value in vector 
  *          if found, -1 otherwise
  * */
 template<class T>
 int LinearSearch(vector<T>& A, T& What)
 {
     for(int i=0; i<A.size(); ++i)
     {
         if(A[i] == What)
         {
             return i;
         }
     }
     return -1;
 }

int main()
{
    vector<int> A(5);
    
    for(int i=0; i<5;)
    {
        A[i] = ++i;
    }
    
    int What = 3;
    
    cout << LinearSearch(A, What) << '\n';
}

