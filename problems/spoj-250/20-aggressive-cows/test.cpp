#include <iostream>
#include "util.hpp"
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{

  /*--------  Initial Input Taking  --------*/
  long number_of_stalls, number_of_cows; // N and C of the problem
  std::cin >> number_of_stalls >> number_of_cows;
  std::vector<long long> positions(number_of_stalls, 0); // positions of the stall
  for (auto i = 0; i < number_of_stalls; ++i)
    std::cin >> positions.at(i);
  std::sort(positions.begin(), positions.end());

  std::cout << largest_minimun_position(positions, number_of_cows) << std::endl;

  return 0;
}
