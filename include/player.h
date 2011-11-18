/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

namespace Agatha {

class PlayerPrivate;

/**
 * @class Player
 * @brief class containing player info
 * @author Francesco Nwokeka
 *
 * This class is made to contain info about a player requested from Agatha. It's returned from the lib
 * after parsing Agatha's response after a request made to the server
 */

class Player
{
public:
    /**
     * Default player constructor
     */
    Player();

    /**
     * Construct a player class with info
     * @param gear player gear
     * @param ip player ip
     * @param name player name
     * @param weaponMode player weaponMode
     */
    Player(const std::string &gear, const std::string &ip, const std::string &name, const std::string &weaponMode);

    ~Player();

    std::string gear() const;                           /** @return player gear */
    std::string ip() const;                             /** @return player ip */
    std::string name() const;                           /** @return player name */
    std::string weaponMode() const;                     /** @return player weaponMode */

    void setGear(const std::string &gear);              /** set the player gear string */
    void setIp(const std::string &ip);                  /** set the player ip */
    void setName(const std::string &name);              /** set the player name */
    void setWeaponMode(const std::string &weaponMode);  /** set the player weaponMode */

private:
    PlayerPrivate *const d;
};

};


#endif  // PLAYER_H
