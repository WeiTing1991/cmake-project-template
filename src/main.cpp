#include "my_library.h"
#include <iostream>

int main() {
  std::cout << "Hello, world!" << std::endl;
  myFunction(); // Assume myFunction() is declared in my_library.h and defined
                // elsewhere
  return 0;
}
