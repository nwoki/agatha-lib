/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/player.h"
#include "playerserializerobject.h"

using namespace Agatha;

PlayerSerializerObject::PlayerSerializerObject(Player *player)
    : QObject(0)
    , m_gear(QString(player->gear().c_str()))
    , m_guid(QString(player->guid().c_str()))
    , m_ip(QString(player->ip().c_str()))
    , m_name(QString(player->name().c_str()))
    , m_weaponMode(QString(player->weaponMode().c_str()))
{
}

QString PlayerSerializerObject::gear() const
{
    return m_gear;
}

QString PlayerSerializerObject::guid() const
{
    return m_guid;
}

QString PlayerSerializerObject::ip() const
{
    return m_ip;
}

QString PlayerSerializerObject::name() const
{
    return m_name;
}

QString PlayerSerializerObject::weaponMode() const
{
    return m_weaponMode;
}

