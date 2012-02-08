/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef AGATHACALLBACK_H
#define AGATHACALLBACK_H

#include <string>

#include "flags.h"
#include "player.h"

namespace Agatha {

    /**
    * @class AgathaCallback
    * @brief class that manages the callback calls of the lib.
    * @author Daminato Simone
    *
    * This is an abstract class: it declares the methods that this library will call to give you the Agatha's answers.
    * You have to create one and only one instance (you should never delete it) of the child of this class for every server that your bot will control (that is,
    * every AgathaCallback object identifies and serve a single game server).
    */

class AgathaCallback
{
public:
    /** 
     * Default AgathaCallback constructor.
     *
     * @param authToken token assigned to the server
     */
    AgathaCallback( const std::string &authToken );

    /** Default AgathaCallback destructor */
    virtual ~AgathaCallback();

    /**
    * Reports an error that occurred while communicating with Agatha
    * @param type specifies the generic error type
    * @param msg specifies details of the error
    */
    virtual void error(CallError type, const std::string &msg) = 0;

    /**
    * Returns the player's information found on Agatha
    * @param player player information
    */
    virtual void playerInfos(const Player *player) = 0;

    /**
    * Tells that the player was banned on Agatha, giving player's and ban's informations
    * @param player player informations
    * @param ban ban informations
    */
    //TODO decide a way to represent bans: it concerns the db too.
    virtual void banned(const Player *player, const std::string &ban) = 0;

protected:
    std::string m_authToken;
};

};
#endif  // AGATHACALLBACK_H
