#ifndef _UTIL
#define _UTIL

auto *multiplyBigInt(int *bigInt, int &length, int number)
{
  int carry = 0, total;
  for (int i = 0; i < length; ++i)
  {
    total = *(bigInt + i) * number;
    *(bigInt + i) = (total + carry) % 10;
    carry = (total + carry) / 10;
  }
  while (carry != 0)
  {
    *(bigInt + length) = carry % 10;
    ++length;
    carry /= 10;
  }
  return bigInt;
}

void factorial(int *bigInt, int &length, int number)
{
  // asumes bigint is set to zero
  for (int i = 2; i <= number; i++)
    multiplyBigInt(bigInt, length, i);
}

void printBigInt(int *bigInt, int length)
{
  for (int i = length - 1; i >= 0; --i)
    cout << *(bigInt + i);
  cout << endl;
}

#endif