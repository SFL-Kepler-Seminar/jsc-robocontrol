#include "Arduino.h"
#include "JSCRoboControl.h"

JSCRoboControl::JSCRoboControl(int rx, int tx, void (*a)(), void (*w)(), void (*s)(), void (*d)(), void (*space)(), void (*ar)(), void (*wr)(), void (*sr)(), void (*dr)(), void (*spacer)()):
        aPressed(a), sPressed(s), wPressed(w), dPressed(d), spacePressed(space), bt(rx, tx),
        aRelease(ar), sRelease(sr), wRelease(wr), dRelease(dr), spaceRelease(spacer){
      bt.begin(115200);
      wState = aState = sState = dState = spaceState = lastAction = 0;
}
void JSCRoboControl::poll() {
if(bt.available()) {
    lastAction = millis();
    switch(bt.read())  {
      case 'w':
        wState = 1;
        break;
      case 'a':
        aState = 1;
        break;
      case 's':
        sState = 1;
        break;
      case 'd':
        dState = 1;
        break;
      case 'x':
        spaceState = 1;
        break;
      case '1':
        wState = 0;
        break;
      case '2':
        aState = 0;
        break;
      case '3':
        sState = 0;
        break;
      case '4':
        dState = 0;
        break;
      case '0':
        spaceState = 0;
        break;
    }
  } else if(millis() - lastAction > 500) {
	wState = aState = sState = dState = spaceState = 0;
  }
  if(wState)
    wPressed();
  else
    wRelease();
  if(aState)
    aPressed();
  else
    aRelease();
  if(sState)
    sPressed();
  else
    sRelease();
  if(dState)
    dPressed();
  else
    dRelease();
  if(spaceState)
    spacePressed();
  else
    spaceRelease();
}
