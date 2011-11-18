/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string>

namespace Agatha {

class CommunicatorPrivate;
class Player;

/**
* @class Communicator
* @brief class used to communicate with Agatha server
* @author Francesco Nwokeka
*
* This class is used to communicate with Agatha's main servers. It sends info
* and requests too.
*/

class Communicator
{
public:
    /**
     * Constructor
     * @param agathaIp the ip of the Agatha server
     * @param agathaPort port of the Agatha server
     * @param authToken token assigned to the server
     */
    Communicator(const std::string &agathaIp, int agathaPort, const std::string &authToken);
    ~Communicator();

    /**
     * Tell Agatha to ban given player
     * @param player player object containing player info to send to Agatha
     */
    void ban(Player *player);

    /**
     * Asks Agatha if given player is banned
     * @param player player object containing player info to send to Agatha
     */
    bool isBanned(Player *player);


private:
    CommunicatorPrivate *const d;
};

};

#endif  // COMMUNICATOR_H