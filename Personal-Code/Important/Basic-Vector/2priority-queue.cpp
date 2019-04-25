#include <bits/stdc++.h>
using namespace std;

class Point
{
   int x;
   int y;
public:
   Point(int _x, int _y)
   {
      x = _x;
      y = _y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};

class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX(); //Pq will give me p1 and p2 and will ask me weather i want
                                    //to place p2 before p1 or not

                                    //here i given that permission if p2.x is less than p1.x
    }
};

int main ()
{
    priority_queue <Point, vector<Point>, myComparator > pq;

    pq.push(Point(10, 2));
    pq.push(Point(2, 1));
    pq.push(Point(1, 5));

    while (pq.empty() == false)
    {
        Point p = pq.top();
        cout << "(" << p.getX() << ", " << p.getY() << ")";
        cout << endl;
        pq.pop();
    }

    return 0;
}
/*
    here is another code by my madam for putting a structure in a pq
#include<iostream>
#include<queue>

using namespace std;

struct people
{
    int age;
    int salary;
    bool operator<(const people &p) const
    {
        if(salary==p.salary)
        {
            return age>p.age;
        }
        else
        {
            return salary>p.salary;
        }
    }
};

int main()
{
    priority_queue<people> pq;
    people p1,p2,p3;
    p1.age=10;
    p1.salary=200;
    p2.age=20;
    p2.salary=200;
    p3.age=15;
    p3.salary=300;
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    while(!pq.empty())
    {
        people p=pq.top();
        cout<< p.age << " ";
        cout<< p.salary <<endl;
        pq.pop();
    }
    return 0;
}



*/
