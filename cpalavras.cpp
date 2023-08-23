#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// create a string matrix 10x15
string m_game[10][15];
string copycat[10][15];

// raw numbers of rows and columns
int row = 10;
int col = 15;

// randomize letters in a string
int alfa_max = 26;
string randomLetter(const char letter)
{

  char l_string[alfa_max] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                             'j', 'k', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                             'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  string result_string = "";
  for (int i = 0; i < letter; i++)
  {
    result_string = l_string[rand() % alfa_max];
  }

  return result_string;
}

// randomize letters in the board and show it
void board()
{

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 15; ++j)
    {
      cout << m_game[i][j] << " ";
      // cout << copycat[i][j] << " ";
    }
    cout << endl;
  }
}

// randomize horizontal and vertical positions
void createPositions(string word)
{

  int row_r = 0;
  int col_r = 0;
  int positionRandom = 0;

  do
  {
    row_r = rand() % 10;
    col_r = rand() % 15;

    positionRandom = rand() % 2;
    // 0 for horizontal, 1 for vertical

    if (copycat[row_r][col_r] != "#")
    {
      if (positionRandom == 0 && col_r + word.length() < col)
      {
        break;
      }

      if (positionRandom == 1 && row_r + word.length() < row)
      {
        break;
      }
    }

  } while (copycat[row_r][col_r] == "#");

  for (int i = 0; i < word.length(); i++)
  {
    m_game[row_r][col_r] = word[i];
    copycat[row_r][col_r] = "#"; // copycat matrix of the main one, replacing the letter with a hashtag
    if (positionRandom == 0)
      row_r++;
    else
      col_r++;
  }
}

// create a function to check if the position(X,Y) is already occupied
// creating a copy of the main matrix and replacing the letter with special characters
// and then comparing the two of them to check, if not, randomize another position

int main()
{

  srand(time(NULL));
  bool game_running = true;
  int i = 0;
  string word_List;

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 15; ++j)
    {
      m_game[i][j] = randomLetter(1);
      copycat[i][j] = m_game[i][j]; // copycatting the main matrix
    }
  }

  do
  {

    cout << "Bem Vindo ao Caça Palavras" << endl;
    cout << "1) Criar uma lista" << endl;
    cout << "2) Jogar" << endl;
    cout << "3) Mostrar Lista" << endl;
    cout << "4) Finalizar o jogo" << endl;
    int choice = 0;
    cin >> choice;

    switch (choice)
    {
    case 1:
      i = 0;
      do
      {
        cout << "Write the" << i + 1 << " word" << endl;
        cin >> word_List;
        i++;

        if (word_List != "leave")
        {
          if (word_List.length() < 3 || word_List.length() > 10)
          {
            cout << "Write Again: " << endl;
            cin >> word_List;
            continue;
          }

          createPositions(word_List);
        }

      } while (word_List != "leave");
      break;

    case 2:
      board();
      break;

    case 3:
      cout << word_List << " ";
      cout << endl;
      break;

    case 4:
      game_running = false;
      break;
    default:
      cout << "error" << endl;
      break;
    }

  } while (game_running);

  return 0;
}