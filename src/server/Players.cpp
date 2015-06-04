#include "Players.h"
#include <functional>
#include <algorithm>

using namespace std;

namespace WhistGame {

Players::Players()
{

}

Players::~Players()
{

}

void Players::AddPlayer(Player* player)
{
    players.push_back(player);
}

Player* Players::GetPlayer(std::string& name) const
{
    for (auto i = players.begin(); i != players.end(); i++)
        if ((*i)->GetName() == name)
            return *i;

    return NULL;
}

void Players::RemovePlayer(Player* player)
{
    players.remove(player);
}

void Players::PrintPlayers() const
{
    for_each(players.begin(), players.end(), mem_fun(&Player::PrintPlayer));
}

}

