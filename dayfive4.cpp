#include<iostream>

using namespace std;

void swap(int x, int y);

main()
{
    int x=5;
    int y=7;
    cout << "main. Before swap, x:" << x << "main y is:" << y << "\n";  //x:5 y:7
    swap(x,y);
    cout << "main. After swap, x: " << x << " y: " << y << endl; //x:5 y:7
}


void swap(int x, int y) // these x and y are local variables
{
    int temp;
    cout << "Swap. Before swap, x: " << x << " y: " << y << endl; //x:5 y:7
    temp= x;
    x=y;
    y=temp;
     cout << "Swap. After swap, x: " << x << " y: " << y << endl; //x:7 y:5
}
