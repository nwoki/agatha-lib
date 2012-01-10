/*
 * libAgatha library test
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <QtTest/QtTest>

#include "../include/player.h"

/**
 * @class PlayerTest
 * @brief test class for Agatha::Player
 * @author Francesco Nwokeka
 *
 * This class is a test class for Agatha::Player
 */

class PlayerTest : public QObject
{
    Q_OBJECT

public:
    PlayerTest(QObject *parent = 0);
    ~PlayerTest();

private slots:
    void setGear();
    void setGuid();
    void setIp();
    void setName();
    void setWeaponMode();

private:
    Agatha::Player *m_player;
};

#endif  // PLAYER_TEST_H