/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */
#include "../include/agathacallback.h"

using namespace Agatha;

class Agatha::CallbackPrivate {
public:
    CallbackPrivate( const std::string &authToken ) 
        : token( authToken )
        {};

    std::string token;
};

AgathaCallback::AgathaCallback( const std::string &authToken )
    : d ( new Agatha::CallbackPrivate( authToken ) )
{
}

AgathaCallback::~AgathaCallback()
{
    delete d;
}
