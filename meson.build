project('memcard',
        'cpp',
        version: '0.0.0',
        default_options: ['cpp_std=c++17']
        )

src_files = []
inc_dir = include_directories(['.',
                                'src',
                                './external/vcpkg/installed/x64-linux/include/'])

deps = []
deps += dependency('wxwidgets', required: true)
deps += dependency('sqlite3', required : true)
deps += dependency('sqlitecpp', required : true)

subdir('src')

executable(meson.project_name(),
           sources: src_files,
           include_directories: inc_dir,
           dependencies: deps,
           install: false)
