/*
 * libAgatha library test
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include <QtTest/QtTest>

#include "../include/player.h"
#include "requestmakertest.h"

using namespace Agatha;

RequestMakerTest::RequestMakerTest(QObject *parent)
    : QObject(parent)
    , m_requestMaker(new RequestMaker())
{
}

RequestMakerTest::~RequestMakerTest()
{
    delete m_requestMaker;
}

void RequestMakerTest::testCreateRequest()
{
    /// TODO need to test for ALL different request types!
    Player *player = new Player("[LPG]KiicK-aSS", "GLAORAA", "90.54.12.78", "00000111220000020002", "kajnwdoooAAISON12314d");

    // Results to check with
    QByteArray addPlayerResult("{ \"command\" : \"addPlayer\", \"game\" : \"URT_411\", \"playerInfo\" : { \"gear\" : \"GLAORAA\", \"guid\" : \"kajnwdoooAAISON12314d\", \"ip\" : \"90.54.12.78\", \"name\" : \"[LPG]KiicK-aSS\", \"weaponMode\" : \"00000111220000020002\" } }");
    QByteArray banResult("{ \"command\" : \"ban\", \"game\" : \"URT_411\", \"playerInfo\" : { \"gear\" : \"GLAORAA\", \"guid\" : \"kajnwdoooAAISON12314d\", \"ip\" : \"90.54.12.78\", \"name\" : \"[LPG]KiicK-aSS\", \"weaponMode\" : \"00000111220000020002\" } }");
    QByteArray isBannedResult("{ \"command\" : \"isBanned\", \"game\" : \"URT_411\", \"playerInfo\" : { \"gear\" : \"GLAORAA\", \"guid\" : \"kajnwdoooAAISON12314d\", \"ip\" : \"90.54.12.78\", \"name\" : \"[LPG]KiicK-aSS\", \"weaponMode\" : \"00000111220000020002\" } }");

    qDebug() << "REQUEST_MAKER MESSAGE: " << m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::ADD_PLAYER, player);

    QCOMPARE(m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::ADD_PLAYER, player), addPlayerResult);  // addPlayer
    QCOMPARE(m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::BAN, player), banResult);               // ban
    QCOMPARE(m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::IS_BANNED, player), isBannedResult);    // isBanned
}

QTEST_MAIN(RequestMakerTest)

#include "requestmakertest.moc"