# General Overview

    - I want a text editor similar to vim

## Features
    - modal
        - Command mode, Insert mode
    - show lines at side of window
    - Input and delete text
        - use backspace and hjkl to move through text
    - working cursor
        - change colour 
    - undo using commands
    - Save file
    - move using mouse



## Order i should implement things
    - Make window
    - section window in two for lines and text box
    - add cursor to text box side


## Structure

Kamil.cpp - Main window (text window is used)
-Window (has the text box window and the line number)
-inupts (handles events like keyboard clicks and mouse events, state changes happen here)
-textdoc (handles the file like saving it)


window
    - Main Window
Editor
    - Where text is handled (same size as window)
    - Rectangle on left for margin
    - font
    - line info
    - drawn on main window
Input
    - mouse and keyboard window
TextDocument
