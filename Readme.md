# Introduction

Wana learn to write an emulator. I chose GameBoy for my first work.

To Nintendo: don't sue me, please hire me.

Warning: This implementation is only a simulator, not an emulator yet. I don't have the precise spec/doc of the CPU pipeline, clock and timing.

LotusGB: named from howntown "花蓮", reverse it "蓮花" -> Lotus.

# Progress
2023/2/12
1. Just strat.
2. Wrote an example to use GBIT. It calls GBIT and my library's interface.
3. Wrote an C/C++ wrapper. (Wana to implement my emulator in C++, but GBIT is C).
   1. I make a mistake. We can simply write a C++ program to call GBIT with providing extern "C" callbacks. We don't need to provide a fully C wrapper of C++. Let it go.

2023/2/15
1. Integrating GBIT, NOP is not passed.
2. I try to apply C++/OOP/DesignPattern, but my code is mixed up.
3. (TODO) get_state/set_state for GBIT


# Lisence (TODO)
maybe MIT license

# Acknowledgment (TODO)
## Introductions of GameBoy
https://wwssllabcd.github.io/2021/02/08/how-to-build-a-gameboy-emulator-1/
https://hackmd.io/@sysprog/BJvOWzFqv
https://thomas.spurden.name/gameboy
https://hackmd.io/@RinHizakura/BJ6HoW29v
https://media.ccc.de/v/33c3-8029-the_ultimate_game_boy_talk

## GBIT
https://github.com/koenk/gbit

## C wrapper to Call C++ with C++ objects
http://www.huoschen.idv.tw/blog/programming/c-calling-c++-functions/
## How to build linux shared libraries & write Makefiles
https://stackoverflow.com/questions/8096015/creating-a-simple-makefile-to-build-a-shared-library
https://jasonblog.github.io/note/gunmake/makefile_zhong_de_,_%5E,__,__fu_hao.html
https://gist.github.com/wenchy/64db1636845a3da0c4c7

## Game Boy: Complete Technical Reference
https://github.com/Gekkio/gb-ctr
