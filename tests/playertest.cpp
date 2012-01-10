/*
 * libAgatha library test
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "playertest.h"


PlayerTest::PlayerTest(QObject* parent)
    : QObject(parent)
    , m_player(new Agatha::Player())
{
}

PlayerTest::~PlayerTest()
{
    delete m_player;
}

void PlayerTest::setGear()
{
    m_player->setGear("GLAORWA");
    QCOMPARE(m_player->gear(), std::string("GLAORWA"));
}

void PlayerTest::setGuid()
{
    m_player->setGuid("kajnwdoooAAISON12314d");
    QCOMPARE(m_player->guid(), std::string("kajnwdoooAAISON12314d"));
}

void PlayerTest::setIp()
{
    m_player->setIp("127.0.0.1");
    QCOMPARE(m_player->ip(), std::string("127.0.0.1"));
}

void PlayerTest::setName()
{
    m_player->setName("PlayerName");
    QCOMPARE(m_player->name(), std::string("PlayerName"));
}

void PlayerTest::setWeaponMode()
{
    m_player->setWeaponMode("00000111220000020002");
    QCOMPARE(m_player->weaponMode(), std::string("00000111220000020002"));
}

QTEST_MAIN(PlayerTest)

#include "playertest.moc"
