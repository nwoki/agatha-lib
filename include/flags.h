/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Simone Daminato <skyled@alice.it>
 *
 */

#ifndef FLAGS_H
#define FLAGS_H

namespace Agatha {

    /**
     * @file flags.h
     * @brief This file defines the common stuff for the Agatha library, like enums.
     */

    /**
     * @enum CallError
     * @brief specifies the error type when talking to Agatha
     * @author Daminato Simone
     *
     * Specifies the nature of the error that occurred while communicating with Agatha
     */
    enum CallError {
        SERVER_TIMEOUT,    /** a timeout occurred waiting for the Agatha server to respond */
        INVALID_TOKEN,     /** the given token is not valid */
    };

};

#endif  // FLAGS_H
