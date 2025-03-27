# Chord dictionary for Piano sheet music in C programming

My implementation of chord search using C. It is a command-line program that allows users to search for major and minor chords.

## Features
- Major chords
- Minor chords
- Displays notes

## How to run
1. Clone or download project files.
2. Open terminal in project directory.
3. Compile program: ```gcc main.c -o main```
4. Run program: ```./main```

## Usage
- Type in a chord you'd like to search
- Uses the format: note + type -> cmaj (c = notes, maj = type)
- Type `q` to quit

## File structure
- `chord_dictionary.c`: Holds the functions that displays the chords
- `chord_dictionary.h`: Declares functions
- `main.c`: Program loop for user to search and practice with chords

## Known issues
- Limited to only maj and min
- Doesn't have scales or other music theory
- Limited to just piano format

## License
This project is open-source and free to use.

## Author
Created by Andre Giske, for personal project, December 2024.