#!/bin/sh

set -x
set -eu

clean()
{
    rm -rf .build
}

compile()
{
    meson .build
    ninja -C .build
}

run_tests()
{
    cd .build
    meson test -v
}

while [ $# -gt 0 ]; do
  case $1 in
    -c|--clean)
      clean
      shift
      ;;
    *)
      ;;
  esac
done

compile
run_tests
