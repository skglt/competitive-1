#ifndef _UTIL_HPP_
#define _UTIL_HPP_

class Square
{
public:
  bool has_ladder;
  int ladder_length;
  Square(bool has_ladder = false, int ladder_length = -1)
      : has_ladder{has_ladder}, ladder_length{ladder_length} {};
};

long ways_to_get_to_last(std::vector<Square> &list, long starting_position)
{
  long n = list.size();
  if (starting_position > n - 1)
    return 0;
  if (starting_position == n - 1)
    return 1;
  if (starting_position == n - 2)
    return 1;
  if (list.at(starting_position).has_ladder)
  {
    bool on_ladder = true;
    int position = starting_position;
    while (on_ladder)
    {
      position += list.at(position).ladder_length;
      if (list.at(position).has_ladder)
        on_ladder = true;
      else
        on_ladder = false;
    }
    return ways_to_get_to_last(list, position);
  }
  return ways_to_get_to_last(list, starting_position + 1) + ways_to_get_to_last(list, starting_position + 2) + ways_to_get_to_last(list, starting_position + 3) + ways_to_get_to_last(list, starting_position + 4) + ways_to_get_to_last(list, starting_position + 5) + ways_to_get_to_last(list, starting_position + 6);
}

long ways_to_get_to_position(std::vector<Square> &list, long starting_position, long end_position)
{
  if (starting_position >= end_position)
    return 0;
  if (list.at(starting_position).has_ladder)
  {
    bool on_ladder = true;
    int position = starting_position;
    while (on_ladder)
    {
      position += list.at(position).ladder_length;
      if (list.at(position).has_ladder)
        on_ladder = true;
      else
        on_ladder = false;
    }
    return ways_to_get_to_position(list, position, end_position);
  }
  return ways_to_get_to_position(list, starting_position + 1, end_position) + ways_to_get_to_position(list, starting_position + 2, end_position) + ways_to_get_to_position(list, starting_position + 3, end_position) + ways_to_get_to_position(list, starting_position + 4, end_position) + ways_to_get_to_position(list, starting_position + 5, end_position) + ways_to_get_to_position(list, starting_position + 6, end_position);
}
#endif