/*
  Lefter Sergiu - 09/04/2022
  Sudoku Solver
*/
#include <iostream>

using namespace std;

int a[81][81];

bool nrInLinie(int nr, int lin)
{
  for (int i = 0; i < 9; ++i)
  {
    if (a[lin][i] == nr)
    {
      return false;
    }
  }
  return true;
}

bool nrInCol(int nr, int col)
{
  for (int i = 0; i < 9; ++i)
  {
    if (a[i][col] == nr)
    {
      return false;
    }
  }
  return true;
}

bool nrInPatrat(int nr, int lin, int col)
{
  int Linpatrat = lin - lin % 3;
  int Colpatrat = col - col % 3;
  for (int i = Linpatrat; i < Linpatrat + 3; ++i)
  {
    for (int j = Colpatrat; j < Colpatrat + 3; ++j)
    {
      if (a[i][j] == nr)
      {
        return false;
      }
    }
  }
  return true;
}

bool ok(int nr, int lin, int col)
{
  return nrInLinie(nr, lin) && nrInCol(nr, col) && nrInPatrat(nr, lin, col);
}

bool rezolvare()
{
  for (int lin = 0; lin < 9; ++lin)
  {
    for (int col = 0; col < 9; ++col)
    {
      if (a[lin][col] == 0)
      {
        for (int nr = 1; nr <= 9; ++nr)
        {
          if (ok(nr, lin, col))
          {
            a[lin][col] = nr;
            if (rezolvare())
            {
              return true;
            }
            else
            {
              a[lin][col] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main()
{
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      cin >> a[i][j];
    }
  }
  if (rezolvare())
  {
    cout << "Rezolvat cu succes!" << '\n';
    for (int i = 0; i < 9; ++i)
    {
      if (i % 3 == 0 && i != 0)
      {
        cout << "-----------" << '\n';
      }
      for (int j = 0; j < 9; ++j)
      {
        if (j % 3 == 0 && j != 0)
        {
          cout << "|";
        }
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  else
  {
    cout << "Nu se poate rezolva.";
  }
  return 0;
}
