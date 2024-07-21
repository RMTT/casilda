api_version = '0.1'

casilda_sources = [
  'casilda_compositor.c',
  'casilda_wayland_source.c',
]

casilda_headers = [
  'casilda.h',
  'casilda_compositor.h',
  'casilda_wayland_source.h',
]

version_split = meson.project_version().split('.')
version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', version_split[0])
version_conf.set('MINOR_VERSION', version_split[1])
version_conf.set('MICRO_VERSION', version_split[2])

configure_file(
          input: 'casilda-version.h.in',
         output: 'casilda-version.h',
  configuration: version_conf,
        install: true,
    install_dir: get_option('includedir') / 'casilda'
)

gtk4_dep = dependency('gtk4', version: '>= 4.14')
wlroots_dep = dependency('wlroots', version: '>= 0.18')
wayland_server_dep = dependency('wayland-server', version: '>=1.22')
epoxy_dep = dependency('epoxy', version: '>=1.5')
xkbcommon = dependency(
    'xkbcommon',
    fallback: 'libxkbcommon',
    default_options: [
        'enable-tools=false',
        'enable-x11=false',
        'enable-docs=false',
        'enable-xkbregistry=false',
    ],
)

wayland_server_dep = dependency('wayland-server', version: '>=1.22')
pixman_dep = dependency('pixman-1', version: '>=0.42.0')
xkbcommon_x11_dep = dependency('xkbcommon-x11', version: '>=1.5', required : false)
x11_xcb_dep = dependency('x11-xcb', version: '>=1.8.7', required : false)

wayland_protos = dependency('wayland-protocols',
  version: '>=1.32',
  fallback: 'wayland-protocols',
  default_options: ['tests=false'],
)
wl_protocol_dir = wayland_protos.get_variable('pkgdatadir')

wayland_scanner_dep = dependency('wayland-scanner', native: true)
wayland_scanner = find_program(
  wayland_scanner_dep.get_variable('wayland_scanner'),
  native: true,
)

casilda_deps = [
  gtk4_dep,
  wlroots_dep,
  xkbcommon,
  wayland_server_dep,
  epoxy_dep,
  wayland_server_dep,
  pixman_dep
]

lib_c_args = []

if xkbcommon_x11_dep.found() and x11_xcb_dep.found()
  casilda_deps += [xkbcommon_x11_dep, x11_xcb_dep]
  lib_c_args += ['-DHAVE_X11_XCB=1']
endif

xdg_shell_c = custom_target(
  'xdg_shell_c',
  input: wl_protocol_dir / 'stable/xdg-shell/xdg-shell.xml',
  output: '@BASENAME@-protocol.c',
  command: [wayland_scanner, 'private-code', '@INPUT@', '@OUTPUT@'],
)

xdg_shell_server_h = custom_target(
  'xdg_shell_server_h',
  input: wl_protocol_dir / 'stable/xdg-shell/xdg-shell.xml',
  output: '@BASENAME@-protocol.h',
  command: [wayland_scanner, 'server-header', '@INPUT@', '@OUTPUT@'],
)

wayland_protocol_sources = [
  xdg_shell_c,
  xdg_shell_server_h,
 ]

casilda_lib = shared_library('casilda-' + api_version,
  casilda_sources + wayland_protocol_sources,
  dependencies: casilda_deps,
        c_args: lib_c_args,
       install: true,
)

install_headers(casilda_headers, subdir: 'casilda')

pkg = import('pkgconfig')
pkg.generate(
  description: 'A simple Gtk wayland compositor widget',
    libraries: casilda_lib,
         name: 'casilda',
     filebase: 'casilda-' + api_version,
      version: meson.project_version(),
      subdirs: 'casilda',
     requires: 'gtk-4.0',
  install_dir: get_option('libdir') / 'pkgconfig'
)

gnome = import('gnome')
casilda_gir = gnome.generate_gir(casilda_lib,
            nsversion: api_version,
            namespace: 'Casilda',
        symbol_prefix: 'casilda',
    identifier_prefix: 'Casilda',
             includes: [ 'Gtk-4.0' ],
              install: true,
)
