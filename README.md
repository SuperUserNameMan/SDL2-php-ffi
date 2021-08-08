# SDL2-php-ffi
SDL2 binding for PHP using FFI

Tested with PHP-cli 8.0.x under Linux.


This binding reuses and tries to improve the encapsulating method from [oratoto/raylib-php-ffi](https://github.com/oraoto/raylib-php-ffi) applied to SDL2 :

- the SDL C API is encapsulated into a PHP class `SDL` which only contains `const` and `static` members ;
- basic C `#define SDL_XXXX` constants and basic C enums are converted into PHP as class `const` accessible using `SDL::MY_CONST_NAME` ;
- C preprocessor macros are converted into PHP as public static methods accessible using `SDL::MY_MACRO_NAME( $A , $B )` ;
- C processor const and C enums that use complex preprocessor macro are converted into PHP as public static arrays. Example : ` public static $PIXELFORMAT = []; `. They are initialised using a private static functions (ex: `_init_SDL_PixelFormatEnum()`) which are all called at once by ` SDL::SDL() `.
- a `__callStatic()` method is used to call C function using FFI. Example : `` SDL::Init( SDL::INIT_VIDEO ); `` ;
- it is possible to override a C function by adding a ` public static function ` with the same name into the class. This can be used to simply the C API and the usage of FFI. Example : ` SDL::GetWindowSize( $window ) ` will return a PHP array containing ` [ $w , $h ] `.

## How to use :

```` PHP
<?php
include("./include/SDL.php");

SDL::SDL();

if ( SDL::Init( SDL::INIT_VIDEO ) != 0 )
{
	echo "SDL::Init Error : ".SDL::GetError().PHP_EOL;
	return false;
}

$win = SDL::CreateWindow( "TEST", SDL::WINDOWPOS_CENTERED , SDL::WINDOWPOS_CENTERED , 640 , 480 , SDL::WINDOW_SHOWN );

if ( ! isset( $win ) )
{
	echo "SDL::CreateWindow Error : ".SDL::GetError().PHP_EOL;
	SDL::Quit();
	return false;
}

list( $w , $h ) = SDL::GetWindowSize( $win ); // <--- this function was overriden to simplify
echo "The size of the window is $w x $h".PHP_EOL;

$surface = SDL::GetWindowSurface( $win );
SDL::FillRect( $surface , null , SDL::MapRGB( $surface->format , 0xFF , 0xFF , 0xFF ) );

SDL::UpdateWindowSurface( $win );


sleep( 5 );

SDL::DestroyWindow( $win );

SDL::Quit();
````


## TODO :
- make it compatible with Windows
