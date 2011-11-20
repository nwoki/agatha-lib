/*
 * libAgatha library test
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef REQUESTMAKER_TEST_H
#define REQUESTMAKER_TEST_H

#include <QtTest/QtTest>

#include "../src/requestmaker.h"

/**
 * @class RequestMakerTest
 * @brief test class for Agatha::RequestMaker
 * @author Francesco Nwokeka
 *
 * This class is a test class for Agatha::RequestMaker
 */

class RequestMakerTest : public QObject
{
    Q_OBJECT

public:
    RequestMakerTest(QObject *parent = 0);
    ~RequestMakerTest();

private slots:
    void testCreateRequest();

private:
    Agatha::RequestMaker *m_requestMaker;
};

#endif  // REQUESTMAKER_TEST_H