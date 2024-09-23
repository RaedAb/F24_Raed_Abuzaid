//
//  TomatoUtilities.h
//  Tomato
//
//  Created by Game on 9/19/24.
//

#ifndef TomatoUtilities_h
#define TomatoUtilities_h

#ifdef TOMATO_MS_COMPILER
    #ifdef TOMATO_LIB
        #define TOMATO_API __declspec(dllexport)
    #else
        #define TOMATO_API __declspec(dllimport)
    #endif
#else
    #define TOMATO_API
#endif

#endif /* TomatoUtilities_h */
