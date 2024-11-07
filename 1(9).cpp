#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int a, r, a2, r2;
float a3, a4;

cout << "Введите стороны прямоугольника"<< endl;
cin >> a >> a2;
cout << "Введите радиус окружности";
cin >> r;

a3 = ~a2 + 1;
a4 = ~a + 1;
if (a == 0  or r <= 0 or a2 == 0 or a == a2) 
   {
   cout << "Неверный ввод";
   return 0;
   }
int x, y;
cout << "Введите координаты (x,y) точки: ";
cin >> x >> y;
if ((y<= 0 and y >= a and  a2/2 >= x and a3/2 <=x) or (y<= 0 and y >= a2 and  a/2 >= x and a4/2 <=x))
   {
    cout << "Точка попадает в закрашенную область"<< endl;
   }
   else 
      {
      cout << "Точка не попадает в закрашенную область"<< endl;

      }

r2 = ~r + 1;
if (y<=r and y>= 0 and r >= x and r2 <=x) 
   {
   cout << "Точка попадает в закрашенную область" << endl;

   }
   else 
      {
      cout << "Точка не попадает в закрашенную область";
      }
}
