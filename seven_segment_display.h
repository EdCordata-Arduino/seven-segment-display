/*

  Seven-segment display library.
  https://github.com:EdCordata/arduino_seven_segment_display

*/

class SevenSegmentDisplay {


  private:

    int pins[8];
    int segment_pins[8];
    int decimal_state = 0;


  public:


    // SevenSegmentDisplay
    // -----------------------------------------------------------------
    SevenSegmentDisplay(int pin_1, int pin_2, int pin_3, int pin_4, int pin_5, int pin_6, int pin_7, int pin_8) {
      this->pins[0] = pin_1;
      this->pins[1] = pin_2;
      this->pins[2] = pin_3;
      this->pins[3] = pin_4;
      this->pins[4] = pin_5;
      this->pins[5] = pin_6;
      this->pins[6] = pin_7;
      this->pins[7] = pin_8;
    }
    // -----------------------------------------------------------------


    // SetupSegmentPinOrder
    // -----------------------------------------------------------------
    void SetupSegmentPinOrder(int seg_1, int seg_2, int seg_3, int seg_4, int seg_5, int seg_6, int seg_7, int seg_8) {
      this->segment_pins[0] = this->pins[seg_1 - 1];
      this->segment_pins[1] = this->pins[seg_2 - 1];
      this->segment_pins[2] = this->pins[seg_3 - 1];
      this->segment_pins[3] = this->pins[seg_4 - 1];
      this->segment_pins[4] = this->pins[seg_5 - 1];
      this->segment_pins[5] = this->pins[seg_6 - 1];
      this->segment_pins[6] = this->pins[seg_7 - 1];
      this->segment_pins[7] = this->pins[seg_8 - 1];
    }
    // -----------------------------------------------------------------


    // SetupPinMode
    // -----------------------------------------------------------------
    void SetupPinMode() {
      for (int i = 0; i < 8; i++) {
        pinMode(this->pins[i], OUTPUT);
      }
    }
    // -----------------------------------------------------------------


    // Clear
    // -----------------------------------------------------------------
    void Clear() {
      decimal_state = 0;

      for (int i = 0; i < 8; i++) {
        digitalWrite(this->segment_pins[i], LOW);
      }
    }
    // -----------------------------------------------------------------


    // SetSegmentState
    // -----------------------------------------------------------------
    void SetSegmentState(int i, int status) {
      digitalWrite(this->segment_pins[i - 1], status);
    }
    // -----------------------------------------------------------------


    // SetSegmentStates
    // -----------------------------------------------------------------
    void SetSegmentStates(int pins_states[8]) {
      for (int i = 0; i < 8; i++) {
        SetSegmentState(i + 1, pins_states[i]);
      }
    }
    // -----------------------------------------------------------------


    // SetDecimalState
    // -----------------------------------------------------------------
    void SetDecimalState(int state) {
      this->decimal_state = state;
      SetSegmentState(8, this->decimal_state);
    }
    // -----------------------------------------------------------------


    // AnimateInfinity
    // -----------------------------------------------------------------
    void AnimateInfinity(int delay_ms, int segments, bool clockwise) {
      bool a    = (segments > 1);
      bool b    = (segments > 2);
      bool x    = this->decimal_state;
      int steps = 8;

      if (clockwise == true) {
        int anim[steps][8] = {
          {0, 1, 0, a, 0, b, 0, x},
          {1, a, 0, b, 0, 0, 0, x},
          {a, b, 1, 0, 0, 0, 0, x},
          {b, 0, a, 1, 0, 0, 0, x},
          {0, 0, b, a, 1, 0, 0, x},
          {0, 0, 0, b, a, 0, 1, x},
          {0, 0, 0, 0, b, 1, a, x},
          {0, 0, 0, 1, 0, a, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      } else {
        int anim[steps][8] = {
          {a, 1, b, 0, 0, 0, 0, x},
          {b, a, 0, 1, 0, 0, 0, x},
          {0, b, 0, a, 0, 1, 0, x},
          {0, 0, 0, b, 0, a, 1, x},
          {0, 0, 0, 0, 1, b, a, x},
          {0, 0, 0, 1, a, 0, b, x},
          {0, 0, 1, a, b, 0, 0, x},
          {1, 0, a, b, 0, 0, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      }
    }
    // -----------------------------------------------------------------


    // AnimateLoopFull
    // -----------------------------------------------------------------
    void AnimateLoopFull(int delay_ms, int segments, bool clockwise) {
      bool a    = (segments > 1);
      bool b    = (segments > 2);
      bool c    = (segments > 3);
      bool d    = (segments > 4);
      bool x    = this->decimal_state;
      int steps = 6;

      if (clockwise == true) {
         int anim[steps][8] = {
          {0, 1, d, 0, a, c, b, x},
          {1, a, 0, 0, b, d, c, x},
          {a, b, 1, 0, c, 0, d, x},
          {b, c, a, 0, d, 1, 0, x},
          {c, d, b, 0, 0, a, 1, x},
          {d, 0, c, 0, 1, b, a, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      } else {
         int anim[steps][8] = {
          {0, 1, d, 0, a, c, b, x},
          {1, a, 0, 0, b, d, c, x},
          {a, b, 1, 0, c, 0, d, x},
          {b, c, a, 0, d, 1, 0, x},
          {c, d, b, 0, 0, a, 1, x},
          {d, 0, c, 0, 1, b, a, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      }
    }
    // -----------------------------------------------------------------


    // AnimateLoopTop
    // -----------------------------------------------------------------
    void AnimateLoopTop(int delay_ms, int segments, bool clockwise) {
      bool a    = (segments > 1);
      bool b    = (segments > 2);
      bool x    = this->decimal_state;
      int steps = 4;

      if (clockwise == true) {
         int anim[steps][8] = {
          {0, 1, b, a, 0, 0, 0, x},
          {1, a, 0, b, 0, 0, 0, x},
          {a, b, 1, 0, 0, 0, 0, x},
          {b, 0, a, 1, 0, 0, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      } else {
         int anim[steps][8] = {
          {0, 1, b, a, 0, 0, 0, x},
          {b, 0, a, 1, 0, 0, 0, x},
          {1, b, 1, 0, 0, 0, 0, x},
          {1, a, 0, b, 0, 0, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      }
    }
    // -----------------------------------------------------------------


    // AnimateLoopTop
    // -----------------------------------------------------------------
    void AnimateLoopBot(int delay_ms, int segments, bool clockwise) {
      bool a    = (segments > 1);
      bool b    = (segments > 2);
      bool x    = this->decimal_state;
      int steps = 4;

      if (clockwise == true) {
         int anim[steps][8] = {
          {0, 1, b, a, 0, 0, 0, x},
          {1, a, 0, b, 0, 0, 0, x},
          {a, b, 1, 0, 0, 0, 0, x},
          {b, 0, a, 1, 0, 0, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      } else {
         int anim[steps][8] = {
          {0, 1, b, a, 0, 0, 0, x},
          {b, 0, a, 1, 0, 0, 0, x},
          {1, b, 1, 0, 0, 0, 0, x},
          {1, a, 0, b, 0, 0, 0, x}
        };

        for (int i = 0; i < steps; i++) {
          SetSegmentStates(anim[i]);
          delay(delay_ms);
        }
      }
    }
    // -----------------------------------------------------------------


    // SetChar
    // -----------------------------------------------------------------
    void SetChar(String ch) {
      bool x = this->decimal_state;

      if (ch == "0") {
        int segments[8] = {1, 1, 1, 0, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "1") {
        int segments[8] = {0, 0, 1, 0, 0, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "2") {
        int segments[8] = {1, 0, 1, 1, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "3") {
        int segments[8] = {1, 0, 1, 1, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "4") {
        int segments[8] = {0, 1, 1, 1, 0, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "5") {
        int segments[8] = {1, 1, 0, 1, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "6") {
        int segments[8] = {1, 1, 0, 1, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "7") {
        int segments[8] = {1, 0, 1, 0, 0, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "8") {
        int segments[8] = {1, 1, 1, 1, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "9") {
        int segments[8] = {1, 1, 1, 1, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "A") {
        int segments[8] = {1, 1, 1, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "B") {
        int segments[8] = {0, 1, 0, 1, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "C") {
        int segments[8] = {1, 1, 0, 0, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "D") {
        int segments[8] = {0, 0, 1, 1, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "E") {
        int segments[8] = {1, 1, 0, 1, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "F") {
        int segments[8] = {1, 1, 0, 1, 1, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "G") {
        int segments[8] = {1, 1, 0, 0, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "H") {
        int segments[8] = {0, 1, 0, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "I") {
        int segments[8] = {0, 1, 0, 0, 1, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "J") {
        int segments[8] = {0, 0, 1, 0, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "K") {
        int segments[8] = {1, 1, 0, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "L") {
        int segments[8] = {0, 1, 0, 0, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "M") {
        int segments[8] = {1, 0, 0, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "N") {
        int segments[8] = {0, 0, 0, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "O") {
        int segments[8] = {0, 0, 0, 1, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "P") {
        int segments[8] = {1, 1, 1, 1, 1, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "Q") {
        int segments[8] = {1, 1, 1, 1, 0, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "R") {
        int segments[8] = {0, 0, 0, 1, 1, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "S") {
        int segments[8] = {1, 1, 0, 0, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "T") {
        int segments[8] = {0, 1, 0, 1, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "U") {
        int segments[8] = {0, 1, 1, 0, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "V") {
        int segments[8] = {0, 0, 0, 0, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "W") {
        int segments[8] = {1, 0, 0, 0, 1, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "X") {
        int segments[8] = {0, 1, 1, 1, 1, 1, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "Y") {
        int segments[8] = {0, 1, 1, 1, 0, 1, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "Z") {
        int segments[8] = {1, 0, 1, 0, 1, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "dash") {
        int segments[8] = {0, 0, 0, 1, 0, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "underline") {
        int segments[8] = {0, 0, 0, 0, 0, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "overline") {
        int segments[8] = {1, 0, 0, 0, 0, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "equals") {
        int segments[8] = {0, 0, 0, 1, 0, 0, 1, x};
        SetSegmentStates(segments);
      }

      if (ch == "single_quotes") {
        int segments[8] = {0, 1, 0, 0, 0, 0, 0, x};
        SetSegmentStates(segments);
      }

      if (ch == "double_quotes") {
        int segments[8] = {0, 1, 1, 0, 0, 0, 0, x};
        SetSegmentStates(segments);
      }

    }
    // -----------------------------------------------------------------


};
