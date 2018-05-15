
Debian
====================
This directory contains files used to package dripd/drip-qt
for Debian-based Linux systems. If you compile dripd/drip-qt yourself, there are some useful files here.

## drip: URI support ##


drip-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install drip-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dripqt binary to `/usr/bin`
and the `../../share/pixmaps/drip128.png` to `/usr/share/pixmaps`

drip-qt.protocol (KDE)

