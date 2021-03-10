# Fractalkor
Fractalkor is a very small project that displays iterations of the Mandelbrot and Julia sets. The fractal implementation is done within glsl.

## Eye Candy
![pretty set](res/pretty_set.gif)
![oil mandelbrot](res/oil_mandelbrot.gif)
![julia motion](res/julia_motion.gif)

## Varkor Backend
This project uses some features from [Varkor](https://github.com/Underdisc/Varkor), my custom game engine, but it really only makes use of utilities from Varkor.

## Building
*Don't*. This is one of the first projects I have made where Varkor is treated as the backend. I may update this in the future to have some proper build instructions, but it is more likely that the Varkor readme will specify how to build Varkor subprojects like this. Additionally, the interface for interacting with Varkor is and will constantly be in flux. Even as a write this, I know this will not successfully build using the current master of Varkor because it only builds with my current modifications to Varkor. Hooray Software! Amiright?
