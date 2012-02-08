/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */
#include "../include/agathacallback.h"

using namespace Agatha;

AgathaCallback::AgathaCallback( const std::string &authToken )
    : m_authToken(authToken)
{
}

AgathaCallback::~AgathaCallback()
{
}
