#include <iostream>
#include <vector>
#include <string>

using namespace std;

void separateString(string equ, vector<int> &digits)
{
    for (auto i : equ)
    {
        if (isdigit(i))
          {
            digits.push_back(stoi(string{i}));
        }
    }

}

int main()
{
  string equ;
  vector<int> digits;
  cout << "enter your equation: \n";
  cin >> equ;
  separateString(equ, digits);
  for (auto& i : digits)
  {
     cout << i << endl;
   }
   return 0;
}
