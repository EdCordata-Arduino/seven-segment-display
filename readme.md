# Seven-segment Display Arduino Library

### Usage
```c++
#include "seven_segment_display.h"

SevenSegmentDisplay display = SevenSegmentDisplay(0, 1, 2, 3, 4, 5, 6, 7);

void setup() {
  display.SetupSegmentPinOrder( 3, 2, 4, 1, 5, 7, 6, 8 );
  display.SetupPinMode();
}

void loop() {
  display.SetChar("2");
}
```

Segments in this library are specified like so:
```
         1
     _________
    |         |
    |         |
  2 |    4    | 3
    |_________|
    |         |
    |         |
  5 |    7    | 6
    |_________|     *

                    8
```

So, if the pin-out for the display is connected like this
(like in display `Kingbright SC56-11EWA`):
```
    1 2 G 3 4
   _|_|_|_|_|_
  |   _____   |
  |  |     |  |
  |  |_____|  |
  |  |     |  |
  |  |_____|  |
  |_ _ _ _ _ _|
    | | | | |
    5 6 G 7 8
```
Then the `SetupSegmentPinOrder` should look like this:
```c++
display.SetupSegmentPinOrder( 3, 2, 4, 1, 5, 7, 6, 8 );
```

### Available functions


* `SetSegmentState(id, state)`

  * `id` - Segment ID as int
  * `state` - Segment state as boolean (on/off = true/false)
  
  Example:
    ```c++
    display.SetSegmentState(8, true);
    ```

<br/>

* `SetSegmentStates(segments)`
  Set multiple segments at once
  
  * `segments` - array of int's (or array's)
  
  Example:
  ```c++
  int segments[8] = {true, false, false, false, false, false, false, false};
  // or
  int segments[8] = {1, 0, 0, 0, 0, 0, 0, 0};
  
  display.SetSegmentStates(segments);
  ```

<br/>

* `Clear`
  Clears the display.
  
  ```c++
  display.Clear();
  ```

<br/>

* `SetDecimalState(state)`
  Sets decimal segments (eight segment) state. Note that decimal segment
  gets preserved when calling all functions bellow. Only functions that
  change the decimal segment state are `Clear`, `SetSegmentState`,
  and `SetSegmentStates`.
  
  * `state` - Segment state as boolean (on/off = true/false)
  
  Example:
  ```c++
  display.SetDecimalState(true);
  ```

<br/>

* `AnimateInfinity(delay, length, direction)`
  Start infinity-shaped animation. NOTE that this is code blocking animation,
  meaning, it uses `delay` and your code will pause until one animation
  cycle is finished.
  
  * `delay` - delay in milliseconds between each animation cycle.
  * `length` - length of the tail in animation as int (1-5)
  * `direction` - true for clockwise and false for counter-clockwise
  
  Example:
  ```c++
  display.AnimateInfinity(100, 1, true);
  ```

<br/>

* `AnimateLoopFull(delay, length, direction)`
  Start oval-shaped animation. NOTE that this is code blocking animation,
  meaning, it uses `delay` and your code will pause until one animation
  cycle is finished.
  
  * `delay` - delay in milliseconds between each animation cycle.
  * `length` - length of the tail in animation as int (1-5)
  * `direction` - true for clockwise and false for counter-clockwise
  
  Example:
  ```c++
  display.AnimateLoopFull(100, 1, true);
  ```

<br/>

* `AnimateLoopTop(delay, length, direction)`
  Start circle-shaped animation at the top of the screen. NOTE that
  this is code blocking animation, meaning, it uses `delay` and
  your code will pause until one animation cycle is finished.
  
  * `delay` - delay in milliseconds between each animation cycle.
  * `length` - length of the tail in animation as int (1-3)
  * `direction` - true for clockwise and false for counter-clockwise
  
  Example:
  ```c++
  display.AnimateLoopTop(100, 1, true);
  ```

<br/>

* `AnimateLoopBot(delay, length, direction)`
  Start circle-shaped animation at the bottom of the screen. NOTE that
  this is code blocking animation, meaning, it uses `delay` and
  your code will pause until one animation cycle is finished.
  
  * `delay` - delay in milliseconds between each animation cycle.
  * `length` - length of the tail in animation as int (1-3)
  * `direction` - true for clockwise and false for counter-clockwise
  
  Example:
  ```c++
  display.AnimateLoopBot(100, 1, true);
  ```

<br/>

* `SetChar(character)`
  Display specific character on the screen.
  
  * `character` - character or it's name as string.
  
  Examples:
  ```c++
  display.SetChar("A"); // A-Z
  display.SetChar("0"); // 0-9
  
  display.SetChar("dash");
  display.SetChar("underline");
  display.SetChar("overline");
  display.SetChar("equals");
  display.SetChar("single_quotes");
  display.SetChar("double_quotes");
  ```
