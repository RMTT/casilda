project('casilda','c',
  version: '0.1.0',
  meson_version: '>= 1.0.0',
  default_options: [
    'warning_level=2',
    'werror=false',
    'c_std=c11',
  ],
)

pkg = import('pkgconfig')
gnome = import('gnome')

version_split = meson.project_version().split('.')

epoxy_dep = dependency('epoxy', version: '>=1.5')
gtk4_dep = dependency('gtk4', version: '>= 4.14')
pixman_dep = dependency('pixman-1', version: '>=0.42.0')
wayland_protocols_deps = dependency('wayland-protocols',
  version: '>=1.32',
  fallback: 'wayland-protocols',
  default_options: ['tests=false'],
)
wayland_scanner_dep = dependency('wayland-scanner', native: true)
wayland_server_dep = dependency('wayland-server', version: '>=1.22')
wlroots_dep = dependency('wlroots-0.18', version: '>= 0.18')
x11_xcb_dep = dependency('x11-xcb', version: '>=1.8.7', required : false)
xkbcommon_x11_dep = dependency('xkbcommon-x11', version: '>=1.5', required : false)
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

config_h = configuration_data()
config_h.set_quoted('PACKAGE_VERSION', meson.project_version())
configure_file(output: 'config.h', configuration: config_h)
add_project_arguments(['-I' + meson.project_build_root()], language: 'c')

subdir('src')
