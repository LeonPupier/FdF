# FdF - Fil de Fer
**42** project number 4 - *This project consists of graphically creating the schematic representation of raised terrain.*

### Important
This project is only compatible with a **macOS** environment for the moment. indeed, the ***Makefile*** and the ***MiniLibX*** is not currently planned for other platforms.

### Goal of the project
Create a program that can take a text file formatted as follows:
```c
0 0 0 0 0 0 0 0 0 0
0 9 0 0 0 9 9 9 0 0
0 9 0 0 0 9 9 9 0 0
0 9 9 9 0 9 0 0 0 0
0 0 0 0 0 0 0 0 0 0
```
To return its 3D representation of an isometric view in a graphics window at *1920x1080*.

### Features
* The map can be moved with the arrows.
* The terrain height can also be manually adjusted as needed during program execution with the keyboard:
  - Key 3 is used to increase the height of the relief.
  - Key 2 is used to decrease the height.
* Finally, it is possible to zoom in on the map at the desired location using the keyboard:
  - Key 1 is used to zoom.
  - Key 0 is used to zoom out.
* There is also a special mode, but you'll have to find it yourself!

### Runtime Arguments
The program compiled with the Makefile is called **fdf**.
When you run it through a command line call, you can pass it *an argument*.
This must be **the path of a map** you want it to represent.

Like this for example:
```shell
> ./fdf test_maps/france.fdf
```

### Gallery
An example with the map of France:
<img width="1915" alt="FdF_France" src="https://user-images.githubusercontent.com/100092382/206919437-f6914c56-7365-48ab-82c2-9867fd5c149d.png">

Similarly with a cliff by the sea:
<img width="1914" alt="FdF_Seaside" src="https://user-images.githubusercontent.com/100092382/206919430-8482016b-1052-40dc-9e41-022bf84962d9.png">

### Informations
- No memory leaks are present in the program.
  - ***leaks*** command and ***fsanitize*** with the compiler have been tested.
- The program consumes little RAM. Regardless of the size of the selected map, it affects insignificantly the memory used by the program.
  - RAM consumption is around 20MB.
- Rendering colors are based on the height of the point in question. The colors were chosen arbitrarily to work in priority with an earthly representation of a terrain such as a country.
- Rendering is completely frame-by-frame to prevent visual artifacts from progressive writing on the window.
- A badly formatted map will display no visual rendering. The program will not stop unexpectedly but will trigger a warning for you.

##### See you soon for new projects, Léon ;)
