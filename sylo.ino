// ######################################
// #    SYLO - Testing and demo file    # 
// ######################################

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

// Code examples

namespace code_example_1 {
    namespace first_snippet {
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

    namespace second_snippet {
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
}

void setup() {

}

void loop() {

}