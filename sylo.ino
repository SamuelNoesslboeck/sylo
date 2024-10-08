// ######################################
// #    SYLO - Testing and demo file    # 
// ######################################
//
// > Helper file with all the snippets used so the correct use of the library can be verified

# include "logging.hpp"

// Components
    # include "components/rotary_encoder.hpp"
//  

// Timing
    # include "timing/toff.hpp"
    # include "timing/ton.hpp"
// 

// Triggers
    # include "triggers/rtrig.hpp"
// 

// Code snippets
namespace contents {
    namespace _1_Timers {
        namespace _1_1_TOff {
            # include "timing/toff.hpp"

            // Create new TOff timer with 1000ms phase
            static TOff timer (1000);

            void loop() {
                bool input = digitalRead(8);        // Example reading of input on PIN 8
                bool output = timer.exec(input);
            }
        }

        namespace _1_2_TOn {
            # include "timing/ton.hpp"

            // Create new TOn timer with 1000ms phase
            static TOn timer (1000);

            void loop() {
                bool input = digitalRead(8);        // Example reading of input on PIN 8
                bool output = timer.exec(input);
            }
        }
    }

    namespace _2_Triggers {
        namespace _2_1_RTrig {
            # include "triggers/rtrig.hpp"

            static RTrig trigger;

            void loop() {
                bool input = digitalRead(8);        // Example reading of input on PIN 8
                bool output = trigger.exec(input);
            }
        }

        namespace _2_2_FTrig {
            # include "triggers/ftrig.hpp"

            static FTrig trigger;

            void loop() {
                bool input = digitalRead(8);        // Example reading of input on PIN 8
                bool output = trigger.exec(input);
            }
        }
    }
}

namespace examples {
    namespace _1 {
        namespace _1_1_snippet {
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
        }

        namespace _1_2_snippet {
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
        }

        namespace _1_3_snippet {
            # include "timing/toff.hpp"
            # include "triggers/rtrig.hpp"

            # define SWITCH_PIN 8

            // We initialize our trigger here
            static RTrig trigger;
            // And the timer here, forcing a minimum time between inputs of 200ms
            static TOff timer;

            void setup() {
                // Set up our serial interface
                Serial.begin(9600);

                // Set up our input switch
                pinMode(SWITCH_PIN, INPUT);
            }

            void loop() {
                // Process the input signal through the timer, then the trigger
                if (trigger.exec(timer.exec(digitalRead(SWITCH_PIN)))) {
                    // Print the event message to our serial monitor
                    Serial.println("Button pressed!");
                }
            }
        }
    }
}

void setup() {

}

void loop() {

}