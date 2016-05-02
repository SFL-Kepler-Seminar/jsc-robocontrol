#include <JSCRoboControl.h>

JSCRoboControl myControl(7, 6, aPressed, wPressed, sPressed, dPressed, spacePressed,
  aRelease, wRelease, sRelease, dRelease, spaceRelease
);


void setup() { // Alle benutzten Pins einrichten
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  myControl.poll();
}

void wPressed() { // W ist gedrueckt.
    digitalWrite(11, HIGH);
}
void sPressed() { // A ist gedrueckt.
    digitalWrite(10, HIGH);
}
void sPressed() { // S ist gedrueckt.
    digitalWrite(9, HIGH);
}
void dPressed() { // D ist gedrueckt.
    digitalWrite(8, HIGH);
}
void spacePressed() { // Leertaste ist gedrueckt.
    digitalWrite(12, HIGH);
}
void aRelease() {
    digitalWrite(11, LOW); // A ist losgelassen (z.b. Anhalten)
}
void wRelease() { // W ist losgelassen (z.b. Anhalten)
    digitalWrite(10, LOW);
}
void sRelease() {  // S ist losgelassen (z.b. Anhalten)
    digitalWrite(9, LOW);
}
void dRelease() {  // D ist losgelassen (z.b. Anhalten)
    digitalWrite(8, LOW);
}
void spaceRelease() {  // Leertaste ist losgelassen (z.b. Anhalten)
    digitalWrite(12, LOW);
}



