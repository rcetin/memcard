
test_src_files = []
test_src_files += files('test_database.cpp')
test_src_files += files('../../src/database/sqlite_handler.cpp')

test_inc_dir = []

test_deps = []
test_deps += dependency('sqlite3', required : true)
test_deps += dependency('sqlitecpp', required : true)

database_exec = executable('test_database', sources: [test_src_files], include_directories: [common_inc, test_inc_dir] , dependencies : [common_test_deps, test_deps])


test('database', database_exec, suite: 'database', protocol : 'gtest')
