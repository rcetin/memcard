#!/bin/sh

build()
{
    meson .build/debug
    ninja -C .build/debug
}

clean()
{
    rm -rf .build
}

build