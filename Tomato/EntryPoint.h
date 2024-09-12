//
//  EntryPoint.h
//  Tomato
//
//  Created by Game on 9/12/24.
//

#ifndef EntryPoint_h
#define EntryPoint_h

#define TOMATO_GAME_START(ClassName) \
int main()\
{\
    ClassName game;\
    game.Run();\
    return 0;\
}\

#endif /* EntryPoint_h */
