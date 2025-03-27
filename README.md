# Catch-coins-dodge-bullets-game-design
## Function Definitions:
* Define a player structure and a moving target (coin or bullet) structure.

* Define a coordinate function (used to control the position of the display on the screen) for future calls.

* Use the coordinate function to define the create map function (to create the map).

* Define global variables.

* Use the coordinate function and the player structure linked list to create a player (2×2 square) position linked list, stored in the create player linked list function.

* Use the player linked list and coordinate function to define the output player function.

* Use the coordinate function and the moving target structure to create the moving target position.

## Game flow
Call the start function to display the start screen.

Call the game entry and game operation function: Display the game mode selection screen, input the corresponding value, then execute the selection statement to enter the corresponding mode.

### 1.Bullet-Dodging Mode:

* Call the hide cursor function to hide the cursor.

* Call the create map function to create the map.

* Call the create player linked list function and output player function to display the player's initial position.

* Call the full operation function:
  * In the infinite loop, create a small loop for bullet movement. Each iteration of the small loop changes the bullet’s coordinates, clears the screen, and then calls the create map function again to refresh the map. The create player linked list function and output player function will be used to display the player’s position, and the bullet’s new position will be shown to complete the bullet's movement. In every large loop, there is a function to check if there is keyboard input (using C library functions). If keyboard input is detected, call the control function and player movement function, and based on the corresponding key press, update the player’s linked list data (i.e., the player’s position). Then clear the screen, call the create map function again to refresh the map, and call the create player linked list function and output player function to display the updated player position, completing the player’s movement. In each small loop, the game over detection function will be called to check if the player has been hit by a bullet. If hit, the game over function will be called to end the program.

### 2.Coin Catching Mode:

* Call the hide cursor function to hide the cursor.

* Call the create map function to create the map.

* Call the create player linked list function and output player function to display the player's initial position.

* Call the full operation function:
  * In the infinite loop, create a small loop for coin movement. Each iteration of the small loop changes the coin's coordinates, clears the screen, and calls the create map function again to refresh the map. The create player linked list function and output player function will be used to display the player’s position, and the new coin position will be shown to complete the coin’s movement. In each large loop, there is a function to check if there is keyboard input (using C library functions). If keyboard input is detected, call the control function and player movement function, and based on the corresponding key press, update the player’s linked list data (i.e., the player’s position). Then clear the screen, call the create map function again to refresh the map, and call the create player linked list function and output player function to display the updated player position, completing the player’s movement. In each small loop, the score-adding function will be called to check if the player has caught the coin. If the coin is caught, the global variable score will be incremented by 1, and the updated map will be displayed outside the map with real-time changes for every coin movement.

### 3.Game Instructions Mode:

* Call the game instructions function.

* Press any key to return to the game entry and game operation function.

