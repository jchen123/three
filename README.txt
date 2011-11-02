Compile with make.  Arguments are <t|e> <stepsize> <index of node you want to see springs for>.  All arguments are optional.

Press r to toggle movement.

No collaborations.  No references besides the lecture notes.

Constants are in the clothSystem.cpp file, you can easily change the number of nodes per line (set at 10 by default) and any of the constants.

The code runs horribly slow, and I can't find any particularly obvious optimizations.  I'm not really taking advantage of the cache or anything, but it seems weird to me that this few amount of calculations would be so slow.  Also it doesn't entirely act like the cloth in the a3soln demo, it's too springy.  Tried playing with constants with mot much help.

No extra credit.

Fun assignment.
