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
    Player *player = new Player("GLAORAA", "90.54.12.78", "[LPG]KiicK-aSS", "00000111220000020002");

    // Results to check with
    QByteArray banResult("{ \"command\" : \"ban\", \"game\" : \"URT_411\", \"playerInfo\" : { \"gear\" : \"GLAORAA\", \"ip\" : \"90.54.12.78\", \"name\" : \"[LPG]KiicK-aSS\", \"weaponMode\" : \"00000111220000020002\" } }");
    QByteArray isBannedResult("{ \"command\" : \"isBanned\", \"game\" : \"URT_411\", \"playerInfo\" : { \"gear\" : \"GLAORAA\", \"ip\" : \"90.54.12.78\", \"name\" : \"[LPG]KiicK-aSS\", \"weaponMode\" : \"00000111220000020002\" } }");

    QCOMPARE(m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::BAN, player), banResult);               // ban
    QCOMPARE(m_requestMaker->createRequest(RequestMaker::URT_411, RequestMaker::IS_BANNED, player), isBannedResult);    // isBanned
}

QTEST_MAIN(RequestMakerTest)

#include "requestmakertest.moc"