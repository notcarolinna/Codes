#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    Vector v;

     cout << "Size: " << v.getSize() <<  endl;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

     cout << "Size: " << v.getSize() <<  endl;
     cout << "v[0]: " << v[0] <<  endl;
     cout << "v[1]: " << v[1] <<  endl;
     cout << "v[2]: " << v[2] <<  endl;

    v.pop_back();

     cout << "Size: " << v.getSize() <<  endl;

    return 0;
}
