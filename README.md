

# ABALONE

This is a remake of the popular game abalone, it is a multiple-player game, the aime of the game To be the first player to push six of the opponent's marbles out of play, into the board's outer rim. 

## Table of contents

-   [Instructions for gameplay](#instructions-for-gameplay)
-   [Illustration](#Illustration)
-   [Built with](#Built-with)
-   [Technologies](#Technologies)
-   [Doxyfile](#Doxyfile)
-   [Decision](#Decision)
-   [Status](#Status)
-   [Author](#Author)
-   [Console version](#Console-version)

## Instructions for gameplay

On their turn, each player may move either a single marble or Column of marbles of their own color one space. A Column consists of two or three marbles of the same color directly adjacent to one another in a straight line. A marble or a column can move in any direction in an in-line move or side-step move.

## Illustration
- Illustration of abalone game : 

	![enter image description here](https://zupimages.net/up/21/06/crpw.jpg)

- abalone UML :

![enter image description here](https://zupimages.net/up/21/07/0vaq.png)

You can find this class diagram and the documentation of this diagram in /Analyse

- Structure of our depot : 

![Structure](https://zupimages.net/up/21/13/2ptd.png)
## Built with

-  C++17

## Technologies

- QT Creator

## Doxyfile 

#### Command to generate the documentation : 
- cd Abalone && doxygen .doxyfile

## Decision 

-  In the console version we use the MVC design pattern.
- We have decided not to keep class Position and Direction.
- We use the ABA-PRO move notation to write the moves.

## Status

#### Project in progress : 

- Analyse UML : Done
- Console version : Done
- Graphic version : In progress


## Authors 
- Zidi Billal 54637 mail :  [54637@etu.he2b.be](54637@etu.he2b.be)
- Bryan Grégoire  53735 mail :  [53735@etu.he2b.be](53735@etu.he2b.be)

## Console version 

- You can see the game in the  terminal:

![enter image description here](https://zupimages.net/up/21/13/9v73.png)

- You can see a line move :

![enter image description here](https://zupimages.net/up/21/13/e88x.png)

- You can see a laterally move :

![enter image description here](https://zupimages.net/up/21/13/4kvi.png)
