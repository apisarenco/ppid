## Fast MacOS Parent PID Finder

This is a simple program that will find the parent PIDs of a process on MacOS.

### Why?

Because I want an easy way to test where my shell is running. Some terminal emulators support fonts and colors, while others do not. I want to know which one I'm using, and conditionally re-launch zsh with the correct $ZDOTDIR.

### Usage

```bash
ppid
```

```csv
57676 ppid
57144 zsh
79178 Code Helper (Re
79175 Code Helper (Re
79152 Electron
```
