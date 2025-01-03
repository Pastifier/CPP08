#include "easyfind.hpp"
#include <cstdlib>
#include <vector>

#define PRINT(X) std::cout << X
#define FLUSH() std::cout << std::endl

#define _IntVector std::vector<int>

int main(void) {
  _IntVector vec1;
  vec1.push_back(1);
  vec1.push_back(2);
  vec1.push_back(3);
  vec1.push_back(4);
  PRINT(vec1.capacity() << "\n");

  for (int i = -2; i < 6; ++i) {
    _IntVector::const_iterator it = easyfind(vec1, i + 1);
    if (it != vec1.end())
      PRINT(*it << (i == 5 ? "" : "\n"));
  }
  FLUSH();
  return 0;
}
