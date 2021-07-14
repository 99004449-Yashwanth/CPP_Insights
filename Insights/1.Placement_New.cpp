// Copyright[2021]<Yashwanth>
/* 
## Insights
 1. Placement new operators
    a. Create an array of 3 integers, fill some values. 
       Construct a Box object with length, breadth, height on this array.
    b. Create an 2D array of N rows, 3 columns, fill some values. 
       Construct an array of N Box objects in this area.
    c. Create an array of N empty Box objects, implement a function
       construct, which takes index as parameter and construct
       objects at given index and return pointer to that object
*/

#include <iostream>

using namespace std;

class Box
{
private:
    int m_length;  // Length of a box
    int m_breadth; // Breadth of a box
    int m_height;  // Height of a box

public:
    Box() : m_length(0), m_breadth(0), m_height(0)
    {
    }

   Box(int length, int breadth, int height):m_length(length), m_breadth(breadth), m_height(height)
   {
   }

   Box *construct(Box *barr, int index, int l, int b, int h)
   {
       void *addr = &barr[index];
       Box *ptr = new (addr) Box(l, b, h);
       return ptr;
   }

   ~Box()
   {
       std::cout << "Destructor\n";
   }
};

int main()
{
    int arr[3] = {2, 4, 6};
    Box *ptr = new (arr) Box;

    int arr1[5][3] = {{0, 2, 1}, {5, 7, 4}, {4, 5, 7}, {5, 6, 9}, {4, 3, 2}};
    Box *parr = new (arr1) Box[5];

    Box barr[10];
    barr->construct(barr, 2, 1, 5, 7);
}
