

## Running Instructions

1. **Compiling:**
   To compile the project, run the following command in the root directory:
   ./build.sh


   This will compile the source code and create the executable `iron_dome_game`.

2. **Running the Game:**
   After compilation, you can run the game with:
   ./iron_dome_game


3. **Debug and Release Modes:**
   Alternatively, you can build and run the game in either debug or release mode by using the following scripts:

   - For **Debug Mode** (default):
     ./build_dbg.sh
     ./iron_dome_game_dbg


     In debug mode, the game will trigger asserts to check for any runtime issues.

   - For **Release Mode**:
     ./build_rel.sh
     ./iron_dome_game_rel

     In release mode, asserts are disabled for performance.

## OOP Principles

- **Encapsulation**: Each class, including the Entity and State classes, utilizes appropriate access specifiers to encapsulate internal details and protect the integrity of data. For example, private and protected members ensure that only authorized methods can access sensitive data.

- **Abstraction**: Abstraction is implemented through pure virtual methods in the `Entity` class. Since `Entity` has no direct instance (as it's a base class), its derived classes must implement the specific behavior required for their respective entities.

- **Polymorphism**: The game uses polymorphism to manage a collection of `Entity` objects. These objects are stored in a list, and mutual methods (such as `updatePosition()`, `drawOnGrid()`, etc.) are applied across all entities, allowing for diverse behavior based on their actual derived types.


