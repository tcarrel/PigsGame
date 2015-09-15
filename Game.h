#ifndef GAME_H
#define GAME_H

#include <vector>
using namespace std;

#include "Player.h"
#include "CpuPlayer.h"

class Game
{
  public:
    Game();
    int whosTurn();
    int getPlayersScore();
    bool turnChange();
    void addPlayers(int n);
    void addCpus(int n);
    void setCurrentPlayerScore(int s);
    bool holdOrRoll();
    void hold();
    int turnScore(int r);

  private:
    vector<Player*> m_players;
    vector<Comp*> m_cpus;
    int m_turn;
    int m_pre_roll;
    int m_current_score;
    int m_number_of_players;
    int m_numnber_of_cpus;
    int m_current_player;
};

#endif