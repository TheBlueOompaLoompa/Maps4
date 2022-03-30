maps4_sources = [
  'main.cpp',
  ]

maps4_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
  dependency('shumate-1.0'),
]

gnome = import('gnome')

maps4_sources += gnome.compile_resources('maps4-resources',
  'maps4.gresource.xml',
  c_name: 'maps4'
)

executable('maps4', maps4_sources,
  dependencies: maps4_deps,
  install: true,
)
