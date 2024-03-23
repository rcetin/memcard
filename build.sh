#!/bin/sh

build()
{
    meson .build
    ninja -C .build
}

clean()
{
    rm -rf .build
}

build