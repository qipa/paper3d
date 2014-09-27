// mycontext.h
// "Background" example. 
//
// Copyright 2012 - 2014 Future Interface. 
// This software is licensed under the terms of the MIT license.
//
// Hongwei Li lihw81@gmail.com
//

#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include <PFoundation/pcontext.h>
#include <PFoundation/pcontextproperties.h>
#include <PFoundation/pinterpolatedvalue.h>


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
    virtual void onPanBegin(pint32 x, pint32 y);
    virtual void onPan(pint32 x, pint32 y, pint32 dx, pint32 dy);
    virtual void onPanEnd(pint32 x, pint32 y, pint32 dx, pint32 dy);

private:
    MyScene *m_scene;
    PInterpolatedValue *m_value;
};

#endif
