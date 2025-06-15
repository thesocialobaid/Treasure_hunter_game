# Treasure_hunter_game
Developed a Treasure hunter game in C++ using procedural programming 

###Overview of the Game: 
The game is set in a 100x100 grid representing a treasure map. The player navigates the grid to find the treasure while avoiding randomly placed explosives. The game has five levels, each with increasing difficulty ( more explosives). The player has 5 lives, and each collision with an explosive reduces one life. The game ends when the player completes all levels or their lives are lost. 

###Implementation 

The game is implemented using 2D pointers for the grid and procedural programming ( no classes or object-oriented programming). A scoreboard should display the score for each level. 

1. Game Grid: Uses a 100 x 100 2D matrix allocated using pointers. The position of treasures and explosives must be randomly initialized for each level.
2. Player Movement: The player starts at the top-left corner of the grid (position[0][0]). The player can move in four directions: Left, right, up, and down. The player cannot move outside the grid boundaries.
3. Lives and Collision: The player has 5 lives at the start of the game. If the player collides with an explosive (E), one life is lost. If the player finds a Treasure (T), their score increases by 10 points. The game ends if the player loses all lives or completes all 5 levels.
4. Levels: There are 5 levels, and with each level, the number of explosives increases by x10.
5.  Scoreboard displays a scoreboard at the end of each level showing the level number, score for the level, total score for all levels, and remaining lives.
6.  Dynamic Memory Management: Use a 2D pointer to dynamically allocate and deallocate memory for the grid. Ensure there are no memory leaks or dangling pointers.
7.  Procedural Programming: Functions and structures are utilized.
8.  Language: C++
9.  
