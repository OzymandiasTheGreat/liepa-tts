#!/usr/bin/env python3

from distutils.core import Extension
import numpy


extension_mod = Extension(
	"liepa_tts._liepa",
	include_dirs=[
		numpy.get_include(),
	],
	libraries=[
		"LithUSS",
	],
	sources=[
		"liepa_tts/liepa.c",
		"liepa_tts/liepa_wrap.c",
	],
)


def build(setup_kwargs):

	setup_kwargs.update({
		'ext_modules': [extension_mod],
	})
