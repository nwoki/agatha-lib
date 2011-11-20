/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/player.h"

using namespace Agatha;

class Agatha::PlayerPrivate
{
public:
    std::string name;
    std::string ip;
    std::string gear;
    std::string weaponMode;
//     std::string equip;
//     std::string funstuff;
};


Player::Player()
    : d(new PlayerPrivate)
{
}

Player::Player(const std::string &gear, const std::string &ip, const std::string &name, const std::string &weaponMode)
    : d(new PlayerPrivate)
{
    d->gear = gear;
    d->ip = ip;
    d->name = name;
    d->weaponMode = weaponMode;
}

Player::~Player()
{
    delete d;
}

std::string Player::gear() const
{
    return d->gear;
}

std::string Player::ip() const
{
    return d->ip;
}

std::string Player::name() const
{
    return d->name;
}

std::string Player::weaponMode() const
{
    return d->weaponMode;
}

void Player::setGear(const std::string &gear)
{
    d->gear = gear;
}

void Player::setIp(const std::string &ip)
{
    d->ip = ip;
}

void Player::setName(const std::string &name)
{
    d->name = name;
}

void Player::setWeaponMode(const std::string &weaponMode)
{
    d->weaponMode = weaponMode;
}





