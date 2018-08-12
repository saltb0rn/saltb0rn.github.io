#! /usr/bin/env python3

from distutils.core import setup, Extension

setup(name="Extest", ext_modules=[Extension("Extest", sources=['Extest.c'])])
