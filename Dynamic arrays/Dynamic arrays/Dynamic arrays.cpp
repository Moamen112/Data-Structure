#include <iostream>
#include "Vector.h";

using namespace std;

int main()
{
    Vector<int> arr;

    arr.push(3);
    arr.push(5);
    arr.push(10);
    arr.push(12);
    arr.push(7);
    arr.push(2);
    arr.push(3);
   
    
    cout << "Found " << arr.find(7) << endl;


    for (int i = 0; i < arr.Size(); i++) {
        cout << arr.at(i) << " ";
      
    }

    cout << endl;

    cout << "This is size: " << arr.Size() << endl;
    cout << "This is capacity: " << arr.Capacity() << endl;
    
    
}

