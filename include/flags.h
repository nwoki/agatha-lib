/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#ifndef FLAGS_H
#define FLAGS_H

namespace agatha {

    /** 
     * @file flags.h
     * @brief This file defines the common stuffs of the library, like enums.
    */
    
    /**
    * @enum CallError
    * @brief specifies the error type
    * @author Daminato Simone
    *
    * Specifies the nature of the error occurred.
    */
    enum CallError {
        SERVER_TIMEOUT,    /** a timeout occurred waiting for the Agatha server. */
        INVALID_TOKEN,     /** the given token is not valid. */
    };

};

#endif  // FLAGS_H
