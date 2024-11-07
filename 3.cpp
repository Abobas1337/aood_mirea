#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime> 
using namespace std;
int main() 
{
srand(static_cast<unsigned int>(time(0)));
int n, m;
cout<<"кол-во строк и столбцов: "; 
cin>>n>>m;
    if ((n <= 1 or n > 100) or (m <= 1 or m > 50)) 
    {
        cout << "размеры не те, 1 < n <= 100 и 1 < m <= 50" << endl;
        return 0;
    }
vector<vector <int>> matrix(n, vector<int>(m));
for (int i=0; i<n; i++)
{
    for (int j=0; j<m; j++)
    {
        matrix[i][j] = rand() % 100 - 20;
    }
}
for (const auto& num : matrix) 
        {
            cout << "[";
           for (int nam : num) 
           {
            cout << nam << " ";
        }
        cout << endl;
    }
       


int count = 0;

    for (int j = 0; j < m; ++j) 
    {
        int summa = 0;
        for (int i = 0; i < n; ++i) 
        {
            summa += matrix[i][j];
        }

        for (int i = 0; i < n; ++i) 
        {
            if (matrix[i][j] > summa - matrix[i][j]) 
            {
                count++;
            }
        }
    }


        
cout << "Кол-во элементов, которые больше суммы элементов столбца: "<< count << endl;
return 0;
}
