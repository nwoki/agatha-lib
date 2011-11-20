/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef PLAYER_SERIALIZER_OBJECT_H
#define PLAYER_SERIALIZER_OBJECT_H

#include <QtCore/QObject>

namespace Agatha {

class Player;


/**
 * Wrapper class used to generate json from an Agatha::Player object
 * @author Francesco Nwokeka
 */

class PlayerSerializerObject : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString gear READ gear)
    Q_PROPERTY(QString ip READ ip)
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QString weaponMode READ weaponMode)

public:
    PlayerSerializerObject(Player *player);

    QString gear() const;
    QString ip() const;
    QString name() const;
    QString weaponMode() const;

private:
    QString m_gear;
    QString m_ip;
    QString m_name;
    QString m_weaponMode;
};

};

#endif  // PLAYER_SERIALIZER_OBJECT_H