#pragma once

#include <algorithm>
#include <iostream>

template <typename T>
typename T::const_iterator easyfind(T const &container, int tofind_) {
  typename T::const_iterator it =
      std::find(container.begin(), container.end(), tofind_);

  if (it == container.end()) {
    std::cerr << "Error: value " << tofind_ << " does not exist in container."
              << std::endl;
  }
  return container.end();
}
