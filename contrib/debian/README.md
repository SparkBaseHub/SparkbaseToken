
Debian
====================
This directory contains files used to package sparkd/spark-qt
for Debian-based Linux systems. If you compile sparkd/spark-qt yourself, there are some useful files here.

## spark: URI support ##


spark-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install spark-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your spark-qt binary to `/usr/bin`
and the `../../share/pixmaps/spark128.png` to `/usr/share/pixmaps`

spark-qt.protocol (KDE)

