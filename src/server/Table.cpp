#include "Table.h"
#include <algorithm>

using namespace std;

namespace WhistGame
{

Table::Table(WhistGame::Player *player, short int type, unsigned int id)
{
    this->id = id;
    this->type = type;
    players[0] = player;

    for (int i = 0; i < 6; i++)
        players[i] = NULL;
}

bool Table::AddPlayer(WhistGame::Player* player, int position)
{
    if(players[position] == NULL)
    {
        players[position] = player;
        playersNumber++;
        return true;
    }

    return false;
}

bool Table::RemovePlayer(WhistGame::Player* player)
{
    for(int i = 0; i < 6; i++)
    {
        if(player == players[i])
        {
            players[i] = NULL;
            playersNumber--;
            return true;
        }
    }

    return false;
}

bool Table::AddSpectator(WhistGame::Player* player)
{
    auto i = find(spectators.begin(), spectators.end(), player);
    if (i == spectators.end())
        return false;

    spectators.push_back(player);

    return true;
}

bool Table::RemoveSpectator(WhistGame::Player* player)
{
    auto i = find(spectators.begin(), spectators.end(), player);
    if (i == spectators.end())
        return false;

    spectators.remove(player);

    return true;
}

unsigned int Table::GetId()
{
    return id;
}

short int Table::GetType()
{
    return type;
}

Table::~Table()
{
}

}
