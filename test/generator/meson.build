
test_src_files = []
test_src_files += files('test_uuid.cpp')
test_src_files += files('../../src/generator/uuid.cpp')

test_inc_dir = []

test_deps = []

uuid_exec = executable('test_uuid', sources: [test_src_files], include_directories: [common_inc, test_inc_dir] , dependencies : [common_test_deps, test_deps])


test('generator', uuid_exec, suite: 'generator', protocol : 'gtest')
