#!/bin/bash
GREEN='\033[1;32m'
CYAN='\033[1;36m'
LBLUE='\033[1;34m'
NC='\033[0m'

echo -e "${GREEN}Compiling every drill...${NC}\n\n"
for file in drill/week??/*.cpp
do
    # skip drill 16 later because it's easier to handle this way
    [[ -z "$(echo $file | grep week05)" ]] || continue
    echo -e "${LBLUE}`basename $file`${NC}"
    newname=`echo $file | sed "s|\.cpp\$|\.exe|g"`
    if [ -n "$(cat $file | grep -i window)" ] ; then
        # graphics drill, fltk compiling
        g++ gui/Graph.cpp gui/Window.cpp gui/GUI.cpp gui/Simple_window.cpp $file -o $newname -I ../libs -Wl,-subsystem,windows -mwindows ../libs/lib/libfltk_images.a ../libs/lib/libfltk_jpeg.a ../libs/lib/libfltk_png.a -lz ../libs/lib/libfltk.a -lole32 -luuid -lcomctl32 -lws2_32
    else
        # basic drill, default compiling
        g++ $file -o $newname
    fi
    echo -e "output: ${CYAN}$newname${NC}\n"
done

# do drill16
echo -e "${LBLUE}drill16.cpp${NC}"
g++ gui/Graph.cpp gui/Window.cpp gui/GUI.cpp drill/week05/Lines_window.cpp drill/week05/drill16.cpp -o drill/week05/drill16.exe -I ../libs -Wl,-subsystem,windows -mwindows ../libs/lib/libfltk_images.a ../libs/lib/libfltk_jpeg.a ../libs/lib/libfltk_png.a -lz ../libs/lib/libfltk.a -lole32 -luuid -lcomctl32 -lws2_32
echo -e "output: ${CYAN}drill/week05/drill16.exe\n\n"

echo -e "${GREEN}Done!"
