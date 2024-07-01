<div align="center">
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/cub3d-light.png?raw=true#gh-light-mode-only" alt="Banner (claro)" />
    <img src="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/cub3d-dark.png?raw=true#gh-dark-mode-only" alt="Banner (oscuro)" />
    <br>
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.
    <br>
	<table>
	<tr><th>Albagar4 (Raycaster)</th>
		<td><a href='https://profile.intra.42.fr/users/albagar4' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/></td>
	</tr>
	<tr><th>Alvega-g (Parsing, MLX42)</th>
		<td><a href='https://profile.intra.42.fr/users/alvega-g' target="_blank">
        <img alt='42 (oscuro)' src='https://img.shields.io/badge/Málaga-black?style=flat&logo=42&logoColor=white'/><br></td>
	</tr>
	</table>    
    <img src="https://img.shields.io/badge/score- 120%20%2F%20100-success?color=%2312bab9&style=flat" />
    </a>
<div>
	<img src="https://s12.gifyu.com/images/SroGH.gif"/>
</div>
</div>

---

# Mandatory part

<table>
  <tr>
    <th>Program name</th>
    <td><em>cub3D</em></td>
  </tr>
  <tr>
    <th>Turn in files</th>
    <td>All your files</td>
  </tr>
  <tr>
    <th>Makefile</th>
    <td><code>all, clean, fclean, re, bonus</code></td>
  </tr>
  <tr>
	<th>Arguments</th>
	<td>a map in format <code>*.cub</code></td>
  </tr>
  <tr>
    <th>External functions</th>
    <td><code>open, close, read, write, printf, malloc, free, perror, strerror, exit</code><br>
		All functions of the math library (<code>-lm man man 3 math</code>)<br>
		All functions of the MLX42
	</td>
  </tr>
  <tr>
	<th>Libft authorized</th>
	<td>Yes</td>
  </tr>
  <tr>
    <th>Description</th>
    <td>You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.</td>
  </tr>
</table>

The constraints are as follows:

- You __must__ use the __MLX42__. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your __libft__ as those written above in __Common Instructions__ part.
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
- Your program must be able to set the floor and ceiling colors to two different ones.
- The program displays the image in a window and respects the following rules:
	- The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
	- The W, A, S, and D keys must allow you to move the point of view through the maze.
	- Pressing __ESC__ must close the window and quit the program cleanly.
	- Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
	- The use of __images__ of the __MLX42__ is strongly recommended.
- Your program must take as a first argument a scene description file with the __.cub__ extension.
	- The map must be composed of only 6 possible characters: __0__ for an empty space, __1__ for a wall, and __N__,__S__,__E__ or __W__ for the player’s start position and spawning orientation.
	This is a simple valid map:
```bash
111111
100101
101001
1100N1
111111
```
- The map must be closed/surrounded by walls, if not the program must return an error.
- Except for the map content, each type of element can be separated by one or more empty line(s).
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated by one or more space(s).
- The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.
- Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :
- North texture:
	- identifier: __NO__
	- path to the north texure
```bash
NO ./path_to_the_north_texture
```

- South texture:
	- identifier: __SO__
	- path to the south texure
```bash
SO ./path_to_the_south_texture
```
- West texture:
	- identifier: __WE__
	- path to the west texure
```bash
WE ./path_to_the_west_texture
```
- East texture:
	- identifier: __EA__
	- path to the east texure
```bash
EA ./path_to_the_east_texture
```
- Floor color:
	- identifier: __F__
	- R,G,B colors in range [0,255]: __0, 255, 255__
```bash
F 220,100,0
```
- Ceiling color:
	- identifier: __C__
	- R,G,B colors in range [0,255]: __0, 255, 255__
```bash
C 225,30,0
```

- Example of the mandatory part with a minimalist __.cub__ scene:
```bash
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

- If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

# Bonus part

Bonus list:
- Wall collisions.
- A minimap system.
- Doors which can open and close.
- animated sprite.
- Rotate the point of view with the mouse.

# How to run

Clone this repository and execute it by running the following commands:

```bash
git clone https://github.com/ColmiiK/cub3d.git
cd cub3d
make bonus
./cub3D_bonus maps/subject.cub
```

You can also compile the mandatory part only by running `make` instead of `make bonus`, but remember that the mandatory part doesn't have collisions, mouse movement, a minimap or animated sprites.

You can change the window size by modifying `W_HEIGHT` and `W_WIDTH` in `include/cub3D_bonus.h`.
### For instructions on how to build the dependencies needed, check out [Codam's MLX42](https://github.com/codam-coding-college/MLX42).
