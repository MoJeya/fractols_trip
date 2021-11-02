# Fract'ol

Fractol is a 42 School project. The purpose of this project is to create a fractal renderer.
**Note!!**
**Only macOS is supported**.

You can read the Details about this project in the Taskfile['en.subject.pdf'](/en.subject.pdf)

# Instalation
Clone the Repository and then go to the created directory and run the following command:

```
make
```
# How to run the programm?
You can run the programm with out any options, this will show you the man page

```
./fractols.a
```
to generate Mandelbrot-set
![Mandelbrot](/image/Mandelbrot-set.png)
```
./fractols.a 1
```
for julia set
![Julia-set](/image/julia-set-3.png)
```
./fractols.a 2
![Burningship-set](/image/burningship-set.png)
```
and for the Burningship-set
```
./fractols.a 3
```

# controls
**ESC** 			-> quit the programm
**SCROLL_UP** 		-> Zoom in
**SCROLL_DOWN**		-> Zoom out
**ARROWKEY_UP**		-> change to diffrent julia-set point
**ARROWKEY_DOWN**	-> change to diffrent julia-set point
**KEY_C**			-> change color and max_iteration

