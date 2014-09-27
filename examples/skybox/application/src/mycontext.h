// mycontext.h
// "SkyBox" example. The first example.
//
// Copyright 2012 - 2014 Future Interface . All rights reserved.
//
// Hongwei Li lihw81@gmail.com
//

#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include <PFoundation/pcontext.h>
#include <PFoundation/pcontextproperties.h>

class MyScene;

class MyContext : public PContext
{
public:
    MyContext(const PContextProperties &properties);
    ~MyContext();
    
    virtual pbool onInitialized();
    virtual pbool onUpdate();
    virtual void onDestroy();
    
    virtual pbool onKeyboard(PEvent *event);

private:
    MyScene *m_scene;
};

#endif
