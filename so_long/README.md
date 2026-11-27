*This project has been created as part of the 42 curriculum by `<glicciar>`.*

# so_long

> A small 2D game built with MiniLibX.

## Description

so_long is a top-down 2D game: the player collects every collectible on the map, then reaches the exit. The map is read from a `.ber` file. The project covers textures, sprites, tiles, events and the render loop with MiniLibX.

**Key features**
- Moves with `W`, `A`, `S`, `D` and cannot walk through walls
- The goal is to collect everything, then reach the exit
- Number of moves displayed at every step
- Smooth window handling; `ESC` or closing the window quits cleanly
- Map validation: rectangular, enclosed by walls, exactly one start and one exit, at least one collectible, and a valid path to every collectible and the exit

**Map characters:** `0` empty, `1` wall, `C` collectible, `E` exit, `P` player start

**Bonus (implemented):** 
enemy patrols that make the player lose, sprite animation and move counter displayed on screen

## Instructions

**Requirements:** Linux with `cc`, `make` and MiniLibX (with X11 and Xext).

```bash
make
./so_long maps/map.ber
```

**Example map**
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Resources
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- Tutorials on flood fill for map validation

**Use of AI**
- Code assistence and debugging