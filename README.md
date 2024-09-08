# Casilda

A simple Wayland compositor widget for Gtk 4 which can be used to embed other
processes windows in your Gtk 4 application.

It was originally created for Cambalache's workspace using wlroots,
a modular library to create Wayland compositors.

Following Wayland tradition, this library is named after my hometown in
Santa Fe, Argentina.

## License

Casilda is distributed under the [GNU Lesser General Public License](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html),
version 2.1 only (LGPL) as described in the COPYING file.

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

## How to use it

To add a Wayland compositor to your application all you have to do is create a
CasildaCompositor widget.

You can specify which UNIX socket the compositor will listen for clients
connections or let it will choose one automatically.

```
compositor = casilda_compositor_new ("/tmp/casilda-example.sock");
gtk_window_set_child (GTK_WINDOW (window), GTK_WIDGET (compositor));
```

Once the compositor is running you can connect to it by specifying the socket
in WAYLAND_DISPLAY environment variable.

```
export GDK_BACKEND=wayland
export WAYLAND_DISPLAY=/tmp/casilda-example.sock
gtk4-demo
```

## API

The api is pretty simple CasildaCompositor has two properties.

- socket: The unix socket file to connect to this compositor (string)
- bg-color: Compositor background color (GdkRGBA)

## Contributing

If you are interested in contributing you can open an issue [here](https://gitlab.gnome.org/jpu/casilda/-/issues)
and/or a merge request [here](https://gitlab.gnome.org/jpu/casilda/-/merge_requests)

## Contact

You can hang with us and ask us questions on Cambalache Matrix at #cambalache:gnome.org

[Matrix](https://matrix.to/#/#cambalache:gnome.org)
