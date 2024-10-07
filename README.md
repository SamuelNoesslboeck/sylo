<p align="center">
    <img src="design/logo/sylo_logo_titled.svg" width="50%" />
</p>

--------------------------------------------------------------

A small helper library with components and sturctures frequently used in low level programming, especially with the arduino framework. Feel free to use the whole library or just copy single header files to use in your ardunio and co. projects. The code is not something game-breaking just snippets and stuff I frequently use, nicely packed together, documented and explained as best as I could.

## Contents & Tutorials

The following topics provide some information about the contents of this library, including tutorials on how and when to use them!

### 1. Timing

Everything related to changing signals in a time based matter.

#### 1.1. TOff - Timer Off

A `TOff` timer class helps extending a signal for a set duration, here called the `phase`. It is also very handy to unite many smaller signals into one large signal, more on that in [this code tutorial](#1-clean-handling-of-an-input-button-with-serial-output). Here an input signal and the output signal of a `TOff` timer over time:

![A signal timeline of a TOff component](documentation/timing/toff_timeline.svg)

#### 1.2. TOn - Timer On

### 2. Triggers

Triggers help processing signals at the right time, pace or in the right context.

#### 2.1. RTrig - Rising Trigger

#### 2.2. FTrig - Falling Trigger

## Code examples & tutorials

### 1. Clean handling of an input button with serial output

Given that we have a small button at pin `8` and we want to print out a message each time we press our button, we might start with a code that looks like the following:

```cpp
# define SWITCH_PIN 8

void setup() {
    // Set up our serial interface
    Serial.begin(9600);

    // Set up our input switch
    pinMode(SWITCH_PIN, INPUT);
}

void loop() {
    if (digitalRead(SWITCH_PIN)) {
        // Print the event message to our serial monitor
        Serial.println("Button pressed!");
    }
}
```

If we press our button **once**, even if we only tap it, we will get something like this in our serial monitor:

```
Button pressed!
Button pressed!
Button pressed!
Button pressed!
Button pressed!
```

and when we hold the button, the microcontroller keeps printing our success message. Which is great, but what if we want to, just as an example, send a message over network to a server or do other stuff that we only want to do once? 

For this case, we use a *rising trigger* or short `RTrig`! It allows us to only fire an event once, right when the signal changes to `HIGH`. Or in other words, right when we start to press the button. (See the full explaination of the `RTrig` [here](#21-rtrig---rising-trigger))

Using such a trigger is simple, we just have to import, initialize and use it like in the following snippet:

```cpp
# include "triggers/rtrig.hpp"

# define SWITCH_PIN 8

// We initialize our trigger here
static RTrig trigger;

void setup() {
    // Set up our serial interface
    Serial.begin(9600);

    // Set up our input switch
    pinMode(SWITCH_PIN, INPUT);
}

void loop() {
    // Process the input signal through the trigger
    if (trigger.exec(digitalRead(SWITCH_PIN))) {
        // Print the event message to our serial monitor
        Serial.println("Button pressed!");
    }
}
```

Now it does not matter anymore if we tap or hold the button, the `if`-statement will only be executed once. However there can still be some issues:

1. **Our user is very angry and presses the button at a very high speed, which we do not like**  
    As mentioned before you might have the case that you bind something like sending a message over network or similar to this button. Such processes can be very intense in terms of calculation power so you do not want to handle a lot of them in a short period of time.