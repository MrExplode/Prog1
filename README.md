# Prog1 alap repo

Ez a template repo a Prog1 GUI fejlesztés során használt framework Windowson történő használatát könnyíti meg.

## Ismert problémák

Szerény tudásommal nem tudtam megoldani a namespace collisiont a `Shape` subclassok és a MinGW rendszer classok között, ezért a fentebb említett classokat namespace jelöléssel kell használni.  
Pl.:

```c++
Graph_lib::Polygon poly;
Graph_lib::Rectangle r {Point{200, 200}, 100, 50};
```

## Előfeltételek

A gcc compiler használatához Windowson telepíteni kell az [MSYS2](https://www.msys2.org/)-t. A projekt weboldalán elég korrekt angol leírás található, de azért [itt](https://github.com/MrExplode/Prog1-template/blob/master/docs/msys2.md) van magyarul is.

## Használat

A megírt forráskódokat az `src` mappába helyezd el. Ajánlott könyvtárstruktúra:

```

src

├── gui

├── week2

│ └── drill12.cpp

├── week3

│ └── . . .

│ . . .

└── compile.sh

```

A forráskódot a `compile.sh` vagy a `compile.bat` script segítségével tudod futtatni.

```bash

./compile.sh <forrás>  <output>

Pl:

./compile.sh week2/drill12.cpp week2/drill12.out
compile.bat week2/drill12.cpp week2/drill12.exe

```

### VSCode extrák

A [VSCode](https://code.visualstudio.com/) minden egyéb konfigurálás nélkül is használható, viszont ha szeretnél többet a syntax highlightnál, (pl. debugging, error check, integrált taskok) akkor [itt](https://code.visualstudio.com/docs/cpp/config-mingw) találsz róla egy leírást a beállításról.

### Egyéb IDE használata

Ha olyan menő vagy hogy [CLiont](https://www.jetbrains.com/clion/) / [Visual Studiot](https://visualstudio.microsoft.com/) használsz, akkor szerintem sikerülni fog egyedül setupolni a workspacet :)

- [fltk build](https://github.com/MrExplode/Prog1-template/blob/master/docs/fltk.md)

- [official leírás cmake használatához](https://github.com/fltk/fltk/blob/master/README.CMake.txt)
