/*
##Insights

5. Consider a file, where each line holds necessary values for Customer
   "1001,Scott,9845012345,5000.0"
   Read the file in CSV format and construct Customer object. 
   Create a temporary object for each line and display the state
   (No need to store objects as collection for now)
    
6. Count no.of lines, words, characters in given file. Use istream class functionality
*/

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class customer {
private:
  int addr;
  int bal;
  string name;

public:
  customer();
  customer(int, int, std::string);
  void display();
  std::string getname();
};
customer::customer() : addr(0000), bal(00000) { name = "NULL"; }
customer::customer(int a, int b, string n) : addr(a) {
  name = n;
  bal = b;
}

string customer::getname() { return name; }

void customer::display() {
  cout << addr << '\t';
  cout << name << "\t";
  cout << bal << endl;
}

void readfromcsv(customer c1, int);

int main() {
  customer c1;
  readfromcsv(c1, 6);
}

void readfromcsv(customer c1, int size) {
  std::cout << "Addess" << '\t' << "Name" << '\t' << "Balance" << std::endl;
  ifstream Read("customer.csv");
  string myText;
  string n, a, b;
  while (Read.good()) {
    getline(Read, a, ',');
    getline(Read, n, ',');
    getline(Read, b, ',');
    getline(Read, myText, '\n');
    int a_int;
    stringstream geek(a);
    geek >> a_int;
    int b_int;
    std::stringstream geeks(b);
    geeks >> b_int;
    customer c(a_int, b_int, n);
    c.display();
  }
  Read.close();
}