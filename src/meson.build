api_version = '0.1'

casilda_sources = [
  'casilda-compositor.c',
  'casilda-wayland-source.c',
]

casilda_headers = [
  'casilda.h',
  'casilda-compositor.h',
  'casilda-wayland-source.h',
]

version_conf = configuration_data()
version_conf.set('VERSION', meson.project_version())
version_conf.set('MAJOR_VERSION', version_split[0])
version_conf.set('MINOR_VERSION', version_split[1])
version_conf.set('MICRO_VERSION', version_split[2])

casilda_headers += configure_file(
  input: 'casilda-version.h.in',
  output: 'casilda-version.h',
  configuration: version_conf,
  install: true,
  install_dir: get_option('includedir') / 'casilda',
)

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

wl_protocols_dir = wayland_protocols_deps.get_variable('pkgdatadir')
wl_stable_protocols_dir = wl_protocols_dir / 'stable' / 'xdg-shell'

generated_protocols = [
  'xdg-shell',
]

wayland_protocol_sources = []

foreach proto_name: generated_protocols
  base_file = proto_name
  xml_path = '@0@.xml'.format(proto_name)

  foreach output_type: [ 'private-code', 'server-header' ]
    wayland_protocol_sources += custom_target(
      '@0@_@1@'.format(base_file, output_type),
      command: [ wayland_scanner, output_type, '@INPUT@', '@OUTPUT@' ],
      input: wl_stable_protocols_dir / 'xdg-shell' + '.xml',
      output: base_file + '-protocol.' + ('header' in output_type ? 'h' : 'c'),
    )
  endforeach
endforeach

lib_c_args = []
if xkbcommon_x11_dep.found() and x11_xcb_dep.found()
  casilda_deps += [xkbcommon_x11_dep, x11_xcb_dep]
  lib_c_args += ['-DHAVE_X11_XCB=1']
endif

casilda_lib = shared_library('casilda-' + api_version,
  sources: [
    casilda_sources,
    wayland_protocol_sources,
  ],
  dependencies: casilda_deps,
  c_args: lib_c_args,
  install: true,
)

casilda_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with: casilda_lib,
  dependencies: gtk4_dep,
)

install_headers(casilda_headers, subdir: 'casilda')

pkg.generate(
  description: 'A simple Gtk wayland compositor widget',
  libraries: casilda_lib,
  name: 'casilda',
  filebase: 'casilda-' + api_version,
  version: meson.project_version(),
  subdirs: 'casilda',
  requires: [ 'gtk4', 'wlroots-0.18' ],
  install_dir: get_option('libdir') / 'pkgconfig'
)

casilda_gir = gnome.generate_gir(casilda_lib,
  sources: [casilda_headers, casilda_sources],
  nsversion: api_version,
  namespace: 'Casilda',
  symbol_prefix: 'casilda',
  identifier_prefix: 'Casilda',
  includes: [ 'Gtk-4.0' ],
  install: true,
  extra_args: [ '--c-include=casilda.h' ]
)

if get_option('vapi')
    casilda_vapi = gnome.generate_vapi('casilda-' + api_version,
      sources: casilda_gir[0],
      install: true,
      packages: [ 'gtk4' ],
      install_dir: get_option('datadir') / 'vala' / 'vapi',
      metadata_dirs: [ meson.current_source_dir() ]
    )
endif
