# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= CUBE
COMPRESSED  ?= NO
ICON        ?= iconc.png
DESCRIPTION ?= "A simple cube timer for the TI-84 Plus CE"

# ----------------------------

include $(CEDEV)/include/.makefile
