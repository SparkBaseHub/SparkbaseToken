
Debian
====================
This directory contains files used to package based/base-qt
for Debian-based Linux systems. If you compile based/base-qt yourself, there are some useful files here.

## base: URI support ##


base-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install base-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your baseqt binary to `/usr/bin`
and the `../../share/pixmaps/base128.png` to `/usr/share/pixmaps`

base-qt.protocol (KDE)

