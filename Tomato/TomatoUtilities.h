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


    #if TOMATO_DEBUG==2
        #define TOMATO_LOG(x) std::cout << x << std::endl;
        #define TOMATO_ERROR(x) std::cout << x << std::endl;
    #elif defined TOMATO_DEBUG==1
        #define TOMATO_LOG(x)
        #define TOMATO_ERROR(x) std::cout << x << std::endl;
    #else
        #define TOMATO_LOG(x)
        #define TOMATO_ERROR(x)
    #endif

#endif /* TomatoUtilities_h */
