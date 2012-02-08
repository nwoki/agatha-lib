/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

#include <string>
#include <vector>
#include "agathacallback.h"

namespace Agatha {

class CommunicatorPrivate;
class Player;

/**
* @class Communicator
* @brief class used to communicate with Agatha server
* @author Francesco Nwokeka
* @author Simone Daminato
*
* This class is used to communicate with Agatha's main servers. It sends info
* and requests too.
*/

class Communicator
{
public:
    /**
     * Default destructor.
     */
    ~Communicator();

    /**
     * Create the Communicator instance: note that this method will create an instance just at the first successfull call, thus
     * in the following invocations the parameters are ignored.
     * If the method returns null, means that an error was found, like already used (or invalid) port or invalid ip.
     * @param localPort the local port that will be used
     * @param agathaIp the ip of the Agatha server
     * @param agathaPort port of the Agatha server
     * @param multiThread specify if the lib should use an indipendent thread to give the answers (true), or if it has to maintain a
     * single thread (thus waiting you to call the method *METHOD NAME*.
     */
    static Communicator* createCommunicatorInstance(const int localPort, const std::string &agathaIp, const int agathaPort, const bool multiThread = false);

    /**
     * Utility method, returns the Communicator instance if you have already called the Communicator::createCommunicatorInstance method.
     */
    static Communicator* getCommunicatorInstance();

    /**
     * Register callback objects to the lib.
     * 
     * Everytime the lib recieve a response by Agatha, it will give you the answer using your callback objects.
     * Obviously, if you don't call this function at least once, you will never receive a response.
     * Every call to this method overwrites the precedent ones.
     * @param callbackObjects list of all the callback objects.
     */
    void registerCallbacks(const std::vector<AgathaCallback *> &callbackObjects);

    /**
     * Tell Agatha to add given player to the database
     * @param player player object containing player info to send to Agatha
     * @param token the server's token
     */
    void add(Player *player, const std::string &token);

    /**
     * Tell Agatha to ban given player
     * @param player player object containing player info to send to Agatha
     * @param token the server's token
     */
    void ban(Player *player, const std::string &token);

    /**
     * Asks Agatha if given player is banned
     * @param player player object containing player info to send to Agatha
     * @param token the server's token
     */
    void isBanned(Player *player, const std::string &token);

    /**
     * If you're not using a multithread environment, use this method to give the control to the library and execute the callbacks.
     * This will work only if you have set the "multiThread" option as false (the default), else it will do nothing.
     * The method will return as he worked through all the answers (returns immediatly if there are no answers from Agatha.
     */
    ////TODO cambiare nome
    void doYourJob();

private:
    Communicator(const int localPort, const std::string &agathaIp, const int agathaPort, const bool multiThread = false);

    CommunicatorPrivate *const d;
    static Communicator *instance;
};

};

#endif  // COMMUNICATOR_H