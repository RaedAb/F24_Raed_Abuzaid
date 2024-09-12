//
//  TomatoApplication.h
//  Tomato
//
//  Created by Game on 9/11/24.
//

#ifndef TomatoApplication_h
#define TomatoApplication_h

namespace Tmt
{
    class TomatoApplication
    {
    public:
        void Run();
        virtual void Initialize();
        virtual void Update();
        virtual void Shutdown();
        
    private:
        bool ShouldContinue{true};
    };
}

#endif /* TomatoApplication_h */
