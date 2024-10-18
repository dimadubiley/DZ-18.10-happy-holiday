#include<iostream>
#include<time.h>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        cout << "Construct\n";  // construct by default
        x = y = 0;
    }
    Point(int x1, int y1)   // Construct by 2 param
    {
        cout << "Construct by 2 param\n";
        x = x1;
        y = y1;
    }
    void Init()
    {
        x = rand() % 10;
        y = rand() % 10;
    }
    void Init(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
    void Output()
    {
        cout << "X: " << x << "\tY: " << y << endl;
    }
    // перегрузка бинарных операции

    Point operator+(Point& b)
    {
        Point temp;
        temp.x = this->x + b.x;
        temp.y = this->y + b.y;
        return temp;
    }
    Point operator+(int a)
    {
        Point temp(x + a, y + a);
        return temp;
    }

    Point operator*(int a)
    {
        Point temp(x * a, y * a);
        return temp;
    }

    Point operator/(int a)
    {
        Point temp(x / a, y / a);
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Point& p)
    {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main()
{
    srand(unsigned(time(0)));

    Point a(1, 2);
    Point b(3, 4);

    Point c = a + b;
    cout << "c: " << c << endl;

    c = a + 10;
    cout << "c: " << c << endl;

    c = a * 3;
    cout << "c: " << c << endl;

    c = a / 2;
    cout << "c: " << c << endl;

}
