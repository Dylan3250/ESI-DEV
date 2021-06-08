# Welcome to Abalone Game !

Project "Abalone" developed during the dev4 course by Akeche Chahed and Bricar Dylan with Mr Bettens.

This README allows you to better understand the project thanks to the following descriptions.

You will find :
- [The rules of the game and some notions to understand abaPro moves](#rules-of-the-game)
- [How to run the project ?](#how-to-run-the-game)
- [ABA-PRO notation](#aba-pro)
- [The structure of our project](#the-structure-of-our-project)
- [The analysis made for our project](#analysis-made-for-our-project)
- [Explanation of classes and methods](#explanation-of-classes-and-methods)
- [Change made since the first submission](#change-made-since-the-first-submission)

## Rules of the game

One player plays with white balls, the other with black balls. The object of the game is to be the first to push 6 opposing balls out of the playing area by pushing them with his own balls.

Constraint : to be able to push opposing balls, the player's balls must be larger than the opposing player's balls.
Ex: 
* Player 1 pushes with his two balls, a ball of the opposing player. The movement will be OK

Other Ex :
* Player 1 pushes with his two balls, two balls of the opposing player. The movement will not be OK.

## How to run the game

The project can be run with Qt Creator or on the command line.

## ABA-PRO

![Abalone](https://zupimages.net/up/21/13/z6bq.png)

Coordinates in ABA-PRO notation, X: G5, Y: C2, Z: H9

## The structure of our project
```
abalone
  ├──abalonecore
  │     ├── Headers
  │     │     ├── utils
  │     │     │      ├── consoleColor.h
  │     │     │      ├── observable.h
  │     │     │      └── observer.h 
  │     │     │
  │     │     ├── ActionStatus.h
  │     │     ├── ball.h
  │     │     ├── board.h
  │     │     ├── game.h
  │     │     ├── gameStatus.h
  │     │     ├── hexagon.h
  │     │     ├── model.h
  │     │     ├── player.h
  │     │     └── position.h
  │     │
  │     └── Sources
  │           ├── utils
  │           │      └──observable.cpp
  │           │
  │           └── board.cpp                           
  │──gui     
  │     ├── Headers
  │     │     ├──controller 
  │     │     │      └──controller.h   
  │     │     │
  │     │     ├──libs
  │     │     │      └──ghexacell.h
  │     │     │     
  │     │     └──view
  │     │            └──view.h│
  │     ├── Sources
  │     │     ├──controller 
  │     │     │      └──controller.cpp  
  │     │     │
  │     │     ├──libs
  │     │     │      └──ghexacell.cpp
  │     │     │     
  │     │     │──view
  │     │     │      └──view.cpp
  │     │     │    
  │     │     │ 
  │     │     └──main.cpp
  │     │ 
  │     └── Forms 
  │           └──view.ui│
  └──tui
        ├── Headers
        │     ├── controller
        │     │       └──controller.h
        │     └── view
        │             └──view.h
        └── Sources
              ├── controller  
              │       └──controller.cpp         
              ├── view
              │       └──view.cpp
              └── main.cpp
```

# Analysis made for our project

![Analysis](https://zupimages.net/up/21/13/8le4.png)


## Explanation of classes and methods

**Class Ball :** represents the player's ball. The ball is characterized by a color (black or white) and by the player's id.
- *Attribute :*
    - Color color : the color of the ball (black or white)
    - int PlayerId : the unique players'id
- *Method :*
    - Ball (int playerId , Color color) -> constructor of Ball
    - Color color() -> getter of color ball
    - int playerId() -> getter of PlayerId  
    
**Class Hexagon :** represents the hexagon box of the game. In the game there are 61 hexagons. A hexagon can have a ball or not.
- *Attribute :*
    - Ball ball : the player's ball in a hexagon
- *Method :*
    - Ball ball() -> getter of ball
    - void ball(Ball ball) -> setter of ball 

**Class Player :** represents the players of the game. The player is characterized by his id, his name and the number of balls he owns.
- *Attribute :*
    - int id : the id of player
    - int nbBalls : the number of balls the player has
    - String name : the name of player
- *Method :*
    - Player (int id , String name) -> constructor of Player
    - int id -> getter of id 
    - String name -> getter of name
    - int nbBall() -> getter of number of ball
    - void decreaseNbBall -> reduces the amount of ball the player has

**Class Position :** represents the coordinates of the hexagon box. 
- *Attribute :*
    - int x : coordinates of the hexagon column 
    - int y : coordinates of the hexagon row 
- *Method :*
    - int x() -> getter of x
    - int y() -> getter of y

**Class Observable :** represents the Observable class. It's a class that respects the design pattern 'Observer/Observable'. 
- *Attribute :*
    -  Set<Observer \*> observers : list of observers
- *Method :*
    - void notify(propertyName: &String) -> responsible for warning observers of a change of state
    - void addObserver(Observer \*) -> adds an observer to the set of observers for this object.
    - void deleteObserver(Observer \*) -> deletes an observer to the set of observers for this object.

**Class Model :** the Model class is an interface for the Game class and is used like an Observable object.
-  *Method :*
    - Player currentPlayer() -> getter of currentPlayer
    - void togglePlayer() -> switch the Player to play
    - Board board() -> getter of Board
    - GameStatus gameStatus() -> getter of gameStatus
    - void gameStatus(GameStatus gameStatus) -> setter of gameStatus 
    - int totalMoves() -> getter of the total number of movements
    - void addPlayer (Player player) -> adds given Player to Player's array.
    - void addMove() -> increase the number of movement 
    - boolean isEnd() -> checks if the game is over and the game status is finish.
    - ActionStatus moveLine(Position posDepart, Position posDestination) -> moves the ball linearly according to the starting position of the given ball and the destination position of the given ball.
        - posDepart : the starting position of the ball
        - posDestination : the destination position of the ball
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - ActionStatus moveLateral(Position posStarted, Position posDestination, Position posLateral) -> literally moves the ball according to the starting position of the given and the destination position of the given.
        - posStarted : the starting position of the ball
        - posDestination : the destination position of the ball
        - posLateral : the lateral position you want to move
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - Position convertABAToCoord(String ABACoord) -> converts ABA-PRO notation to array position (x and y)

**Class Game :** assembles all the elements of the abalone game already codded and defines players, the mechanism of the game... This class is used with the Model interface.
- *Attribute :*
    - int currentPlayer : the current Player 
    - Player [] players : array to showing the players of the game 
    - Board board : the board of the game
    - GameStatus status : status of the game (not started - in progress - finish)
    - int totalMoves : the total number of movements
-  *Method :*
    - Player currentPlayer() -> getter of currentPlayer
    - void togglePlayer() -> switch the Player to play
    - Board board() -> getter of Board
    - GameStatus gameStatus() -> getter of gameStatus
    - void gameStatus(GameStatus gameStatus) -> setter of gameStatus 
    - int totalMoves() -> getter of the total number of movements
    - void addPlayer (Player player) -> adds given Player to Player's array.
    - void addMove() -> increase the number of movement 
    - boolean isEnd() -> checks if the game is over and the game status is finish.
    - ActionStatus moveLine(Position posDepart, Position posDestination) -> moves the ball linearly according to the starting position of the given ball and the destination position of the given ball.
        - posDepart : the starting position of the ball
        - posDestination : the destination position of the ball
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - ActionStatus moveLateral(Position posStarted, Position posDestination, Position posLateral) -> literally moves the ball according to the starting position of the given and the destination position of the given.
        - posStarted : the starting position of the ball
        - posDestination : the destination position of the ball
        - posLateral : the lateral position you want to move
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - Position convertABAToCoord(String ABACoord) -> converts ABA-PRO notation to array position (x and y)

**Class Board :** contains all hexagons to make the board and methods to update each hexagon.
- *Attribute :*
    - Hexagon[][] board : the board of hexagon
-  *Method :*
    - Hexagon[][] board() -> getter of the board of hexagon
    - void editBall (Hexagon hex, Ball ball) -> edits the ball in a hexagon.
    - ActionStatus moveLine(Position posDepart, Position posDestination) -> moves the ball linearly according to the starting position of the given ball and the destination position of the given ball.
        - posDepart : the starting position of the ball
        - posDestination : the destination position of the ball
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - ActionStatus moveLateral(Position posStarted, Position posDestination, Position posLateral) -> literally moves the ball according to the starting position of the given and the destination position of the given.
        - posStarted : the starting position of the ball
        - posDestination : the destination position of the ball
        - posLateral : the lateral position you want to move
        - return the actionStatus of the mouvement.
        - => There are 4 states : MOVED - FALLEN - PUSHED - BLOCKED
    - Position convertABAToCoord(String ABACoord) -> converts ABA-PRO notation to array position (x and y)
    - boolean isPossibleMoving(List<Position> positions) -> checks if the movement is correct with the positions given in a list (if blocked, If enemy balls block, ...).

## Change made since the first submission
**Class Ball :**

     => nothing has been changed.

**Class Hexagon :**
- we have added a new constructor that takes as parameter a ball of a player to build the board : Hexagon(Ball ball).

**Class Player :**
- we have removed the constructor : Player(int id, String name).
- we have added  :
    - a new constructor that takes as parameter the player's id : Player(int id).
    - a new constructor that takes as parameter the player : Player(Player player).
    - a new setter for name : void name(String name). 

 **Class Position :** 
 - we have added  :
    - a new method to calculate the next position according to the position of the direction given in parameter. It is mainly used in the movements : void next(Position position).              
    - a new constructor that takes as parameter the coordinates of the hexagon (x,y): Position(int x, int y).
- we have redefined the overload of an equality operator. This allows to test the equality of two positions: operateur==(pos1:Position, pos2:Position).
- we did the same thing with the different operator to test if the two positions are different: operateur =!(pos1:Position, pos2:Position).

**Class Observable :**

      => nothing has been changed.

**Class Observer :**
- we have added :
     - a new class wich represents the Observable class. It's a class that respects the design pattern 'Observer/Observable'.
     - a method that is called when an observer is notified of a change : void update(String propertyname).

**Class Game (Model) :**
- we have added :
    - a new attribute which allows to save the last status of the game : Actionstatus lastActionStatus.  
    - a getter of Player : Player players(). 
- we have removed the methods moveLine/moveLateral and we have combined them into one method : ActionStatus move(<Vector> Position).
- we have changed the name of the method void addMove() become void addMoves().

**Class Board :**
- we have added :
    - a method that allows to see if the position given in parameter is in the board: boolean isInside(Position pos).
    - a private method to see if the first letter given for the abapro coordinate is valid :boolean isnotValidFirstLetter(char c).
    - a private method to see if the  given abapro coordinate is valid : boolean isnotvalidAbaPro(String abaCoord).
    - a method that allows to know the direction in relation to the given position : Position direction(Position pos). 
    - a method that accesses the coordinate of the hexagon given in parameter : Hexagon at(int x, int y).
    - a method that gives access to the hexagon with the coordinates of the position given in parameter: Hexagon at(Position pos). 
- we removed the method isPossibleMoving(position list): boolean  because we did not use it.

**ActionStatus :**
- we have added 2 new status : SELF_FALEN (allows to see if the player has fallen his own balls) and NOT_STARTED.



