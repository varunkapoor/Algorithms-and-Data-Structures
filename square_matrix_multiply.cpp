#include <iostream>
#include <vector>

template<class T>
struct Matrix
{
    Matrix(size_t r, size_t c)
    {
        Data.resize(c, std::vector<T>(r, 0));
    }    
    
    static Matrix SquareMultiply(Matrix<T>& A, Matrix<T>& B)
    {
        Matrix<int> retval(A.Data.size(), A.Data.size());
        
        for(int r=0; r<A.Data[0].size(); ++r)
        {
            for(int c=0; c<A.Data[0].size(); ++c)
            {
                retval.Data[c][r] = 0;
                for(int k=0; k<A.Data[0].size(); ++k)
                {
                    retval.Data[c][r] += A.Data[k][r] * B.Data[c][k];
                }
            }
        }
        
        return retval;
    }

    void Print()
    {
        for(int c=0; c<Data.size(); ++c)
        {
            for(int r=0; r<Data[0].size(); ++r)
            {
                std::cout << Data[c][r] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    std::vector<std::vector<T> > Data;
};

int main()
{
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);
    A.Data[0][0] = 2;
    A.Data[0][1] = 1;
    A.Data[1][0] = 1;
    A.Data[1][1] = 2;
    
    B.Data[0][0] = 2;
    B.Data[0][1] = 1;
    B.Data[1][0] = 1;
    B.Data[1][1] = 2;
    
    A.Print();
    B.Print();
    
    Matrix<int> C(Matrix<int>::SquareMultiply(A, B));
    
    C.Print();
}
