/*
##Insights

6. Count no.of lines, words, characters in given file. Use istream class functionality
*/

#include <fstream>
#include <iostream> 
int main() {
  int noc = 0, now = 0, nol = 1;
  char ch;
  std::filebuf fb;
  if (fb.open("text.txt", std::ios::in)) {
    std::istream is(&fb);
    while (is) {
      ch = is.get();
      if (ch != ' ' && ch != '\n')
        noc++;
      if (ch == ' ')
        now++;
      if (ch == '\n') {
        nol++;
        now++;
      }
      ch = char(is.get());
    }
    nol=nol+1;
    
    
    std::cout << "\n Total No. of Characters  : " << noc;
    std::cout << "\n Total No. of Words       : " << now;
    std::cout << "\n Total No. of Lines       : " << nol;
    fb.close();
  }

  return 0;
}