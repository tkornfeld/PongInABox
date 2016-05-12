#include <Button.h>


/**
@class Button
    defines a button and a sampling method
@param pin
    the pin of this button. Please use Reference.
*/
Button::Button(uint8_t pin){
  this->pin = pin;
  this->lastDebounceTime = 0;
  this->lastButtonState = LOW;
  this->debounceDelay = 50;
  this->state = false;
}


/**
gets the current state of the button. Works like a toggle, not like a button
See https://www.arduino.cc/en/Tutorial/Debounce to learn about how this works.

@return the current state of the button

@test
*/
bool Button::get(){
  int reading = digitalRead(pin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        state = !state;
      }
    }
  }
  lastButtonState = reading;
  return state;
}
