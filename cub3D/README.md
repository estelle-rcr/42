# Cub3D

### The project
We create a small 3D game inspired from Wolfenstein, a 90's game played in first-person view. We first make a parser to ensure the input file provided by the user is correct and that all the required data is provided in the right format. Then, we use the minilibX to display the game in 2D and then in 3D using the raycasting method.
  I added many bonuses: a HUD, fog and reliefs, points and victory, object pick-up, life, keys, a display/hide map, look up and down, textures on floor and ceiling...

In the bonus game, your mission is to find the 2 keys while staying alive:
![save](https://user-images.githubusercontent.com/25255182/116879212-ad382180-ac20-11eb-82e3-c0a6d190a477.jpg)

I added two small scripts in shell to compile and check leaks with valgrind.
  The first script is used as follow: `./leaks.sh cub3D map.cub` and check the program with one map in input, the result is in a log file.

  The second is used as follow: `./test_invalid_maps.sh cub3D invalid_maps/` and check multiple invalid map files and output the OK/KO from valgrind tests on the terminal and the log files for each map files in a dedicated directory.

### How to use it
The project runs only on a Linux distribution.
  Compile the mandatory project:
  `make`

  Compile the bonus version:
  `make bonus`

  Start the program:
  `./cub3D map_subject.cub` to play  
     OR `./cub3D map_subject.cub --save` to export a screenshot of the first view  

  To play the bonus version (with the HUD, etc.):
    `./cub3D_bonus map_bonus.cub` to play  
      OR `./cub3D_bonus map_bonus.cub --save` to export a screenshot of the first view 
  
#### Keyboard instructions:
  On a QWERTY keyboard, directionnal moves are done using: W-S-A-D.   
  
  Rotational moves: left and right arrows. 
    
  Bonus - Look up and down: up and down arrows.
  
  Show/hide map: press M. 
