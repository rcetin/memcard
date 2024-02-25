project('memcard',
        'cpp',
        version: '0.0.0',
        default_options: ['cpp_std=c++17']
        )

src_files = []
inc_dir = include_directories(['.', 'src'])

deps = []
deps += dependency('wxwidgets', required: true)

subdir('src')

executable(meson.project_name(),
           sources: src_files,
           include_directories: inc_dir,
           dependencies: deps,
           install: false)
