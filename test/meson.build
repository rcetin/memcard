
project('unit-test', 'cpp',default_options: ['cpp_std=c++17'])

common_test_deps = dependency('gtest', main : true, required : true)

common_inc = []
common_inc += ['../../src/']

subdir('database')
subdir('generator')
