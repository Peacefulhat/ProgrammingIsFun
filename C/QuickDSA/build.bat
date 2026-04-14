 @echo off

set CommonCompilerFlags=-MTd -Oi -GR -Gm- -W4 -wd4201 -wd4100 -FC -Z7
set CommonLinkerFlags=-incremental:no User32.lib Gdi32.lib Winmm.lib


IF NOT EXIST build mkdir build

pushd build

cl %CommonCompilerFlags% d:\ProgrammingIsFun\C\QuickDSA\main.c  /link %CommonLinkerFlags%
popd
