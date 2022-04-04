# About the project
This was one of my first bigger projects in which I tried using C++ and Qt. At the time of writing this, I wasn't really experienced with any of them. However, I still managed to produce a functional game of Shogi (even though it won't recognise a checkmate or let's you do moves that will bring your king in direct danger).
Apart from the rules that have something to do with "check" or "checkmate" it covers all the Shogi-rules I know about. Those being the following:

- correct movement patterns for each piece,
- promoting pieces when they move inside the promotion zone,
- dropping pieces you captured,
- not dropping a pawn in a column that already has an unpromoted pawn,
- only dropping pieces on field where they can perform at least one legal move (i.e. not dropping pawns or lances on the last row or dropping knights on one of the last two rows).