# casilda

A simple wayland compositor widget for Gtk 4.
Originally created for [Cambalache](https://gitlab.gnome.org/jpu/cambalache)
workspace, it is useful for embedding other processes windows.

The name follows the tradition of naming Wayland related projects after towns.
My hometown in Santa Fe, Argentina.

## License

Casilda is distributed under the [GNU Lesser General Public License](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html),
version 2.1 (LGPL) as described in the COPYING file.

## Source code

Source code lives on GNOME gitlab [here](https://gitlab.gnome.org/jpu/casilda)

`git clone https://gitlab.gnome.org/jpu/casilda.git`

## Dependencies

* [Meson](http://mesonbuild.com) build system
* [GTK](http://www.gtk.org) Version 4
* wlroots - Library to create Wayland compositors


## Manual installation

This is a regular meson package and can be installed the usual way.

```
# Configure project in _build directory
meson setup --wipe --prefix=~/.local _build .

# Build and install in ~/.local
ninja -C _build install
```

## Contributing

If you are interested in contributing you can open an issue [here](https://gitlab.gnome.org/jpu/casilda/-/issues)
and/or a merge request [here](https://gitlab.gnome.org/jpu/casilda/-/merge_requests)

## Contact

You can hang with us and ask us questions on Cambalache Matrix at #cambalache:gnome.org

[Matrix](https://matrix.to/#/#cambalache:gnome.org)
