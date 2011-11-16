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
    Player();
    ~Player();

    std::string gear() const;
    std::string ip() const;
    std::string name() const;
    std::string weaponMode() const;

    void setGear(const std::string &gear);
    void setIp(const std::string &ip);
    void setName(const std::string &name);
    void setWeaponMode(const std::string &weaponMode);

private:
    PlayerPrivate *const d;
};

};


#endif  // PLAYER_H
