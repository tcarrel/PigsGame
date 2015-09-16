//Thomas Russel Carrel
#include"io.h"

////////////////////////////////////////////////////////////////////////////////
//  
//   Tracks the number of Io objects created, prevents the creation of more than
// one.
//
////////////////////////////////////////////////////////////////////////////////
Io::io_num = 0;

////////////////////////////////////////////////////////////////////////////////
//PRIVATE ctor, prevents creation of Io class by any class other than game.
////////////////////////////////////////////////////////////////////////////////
//
//   Io( Game* g );
//
//  
////////////////////////////////////////////////////////////////////////////////
Io::Io() 
{
  if( io_num > 0 ) //Prevent creation of more than one io object.
  {
    return;
  }

  io_num++;

  //###########################################################################
  //   Code for player's initial setup choices might go here.  Things like
  // difficulty and number of sides on the die.
  //###########################################################################
}

int Io::turn(Player* player, int player_num)
{
  unsigned char command = 'X';

  while ( command != 'r' && command != 'h' )
  {
    cout << "\nPlayer number " << player_num << ":\n\t(R)oll or (H)old? ";

    switch( player->get_command() ) //Human player should return COM_NOT_CPU
    {         // This makes the cpu look like it's entering commands as well.
      case COM_HOLD:
        cout << "h" << endl;
        command = 'h';
        break;
      case COM_ROLL:
        cout << "r" << endl;
        command = 'r';
        break;
      case COM_NOT_CPU:
        //fallthrough.
      default:
        cin >> command;
    }

    if( 'A' >= command && command <= 'Z' ) //Switch to lowercase, if necessary.
    {
      command += 32;
    }
  }   

  if( command = 'h' )
  {
    return HOLD;
  }

  Die die; // DIIIIIEEEEEEEEEEE!!!!!!!!!!!!

  return die.roll(); // Roll the die and return its result.
}

void Io::winner(int player_num)
{  
  cout << "Player number " << player_num 
    << " has reached 100 points for the win!";
}