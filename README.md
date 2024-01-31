
# Network Word Game

Welcome to the Network Word Game project! A simple client-server game involves the server randomly selecting a word, sending its letters to clients, and clients attempting to find the word. Let's get started!

## Prerequisites

Before running the project, make sure you have the following installed on your Ubuntu machine:

1. #### Install Visual Studio Code:
Download and install Visual Studio Code.

2. #### Install WSL:
Follow the instructions to install WSL on your Windows machine.

3. #### Install Ubuntu on WSL:

4. #### Install Ubuntu from Microsoft Store.

5. #### Install Git on WSL:
Open the WSL terminal and run:

    sudo apt update
    sudo apt install git
## Setting Up Visual Studio Code:
#### Install the Remote - WSL Extension:
1. Open VS Code, go to Extensions (click on the Extensions icon), search for "Remote - WSL," and install it.

2. Open Your Project Folder in VS Code:
Open VS Code, click "File" > "Open Folder," and select your project folder.

3. Connect to WSL:
In the bottom-right corner, click on the green icon, then "Remote - WSL: New Window."

## Installation

* #### Clone the repository:

   ```bash
   git clone https://github.com/your-username/network-word-game.git
Navigate to the project directory:

    cd network-word-game

## Running and Compiling

1. #### Compile the server and client programs:

   ```bash
   gcc SERVEUR.c -o Server
   gcc CLIENT.c -o Client

2. #### Running the Server
Start the server:

    ./Server

### The server will start listening for incoming connections.

3. #### Running the Client
Open a new terminal window.

Start the client:

    ./Client

The client will attempt to connect to the server.

Follow the on-screen instructions to play the game.

## Gameplay
* The server randomly chooses a word and sends its letters to the client.

* The client attempts to find the word and sends its answer to the server.

* The server compares the answers and sends the result to the client.

* The game ends when a client finds the word or after 10 attempts.

## Multiplayer
The game supports multiple clients.
The first client to find the word is the winner.
Other clients are defeated.
Notes
Make sure to check your firewall settings to allow connections.
Feel free to customize the game logic and expand the features.
Enjoy the game!
