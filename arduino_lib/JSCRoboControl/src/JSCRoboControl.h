#ifndef JSCRoboControl_h
#define JSCRoboControl_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class JSCRoboControl {
  public:
    JSCRoboControl(int rx, int tx, void (*a)(), void (*w)(), void (*s)(), void (*d)(), void (*space)(), void (*ar)(), void (*wr)(), void (*sr)(), void (*dr)(), void (*spacer)());
    void poll();
  private:
    void (*aPressed)();
    void (*sPressed)();
    void (*dPressed)();
    void (*wPressed)();
    void (*spacePressed)();
    void (*aRelease)();
    void (*sRelease)();
    void (*dRelease)();
    void (*wRelease)();
    void (*spaceRelease)();
    int wState;
    int aState;
    int sState;
    int dState;
    int spaceState;
    SoftwareSerial bt;
};
#endif

