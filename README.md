# Saggat
A Procedual Planetary Sytem Generator written in Qt3D

This is a side project, which will ever be work in progress. It can generate different planets, with moons and belts, adjustable with different parameters. Have Fun!

Written in C++ and QML, Shaders in GLSL and some JavaScript sprinkled in for the GUI, all with the Qt framework. Tested on Mac and Android (OpenGL ES3). For elevation and colours it is using 3D Simplex or Perlin Noise. It implements custom geometry, that generates a GeoSphere and modifies its polygons. The shader calculates colours based on the height of the mesh as input and additional also computes a noise based moisture map for varying vegetation.

It's a fun project, good for nothing.

<img src="https://github.com/Loxodromics/saggat/raw/master/screenshots/saggat2_0.gif">

## Images
<img src="https://github.com/Loxodromics/saggat/raw/master/screenshots/saggat2_1.jpg" width="638px">
<img src="https://github.com/Loxodromics/saggat/raw/master/screenshots/saggat2_2.jpg" width="654px">

## Build

### Perquisites
* Qt 5.13 (I only tested that version)
* OpenGL(ES) 3+ drivers

### Steps
* check out
* Open and build `saggat.pro` in QtCreator. Easy as that!

## Issues
* many, this is work in progress
* provides shaders for OpenGL 3 and ES 3
