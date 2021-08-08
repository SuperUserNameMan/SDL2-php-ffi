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


## TODO and missing stuff :
- [ ] make it compatible with Windows
- [ ] macro ` SDL_OutOfMemory() `
- [ ] macro ` SDL_Unsupported() `
- [ ] macro ` SDL_InvalidParamError( param ) `
- [ ] API from ` SDL_assert.h `
- [ ] macro ` SDL_VERSION( x ) `
- [ ] macro ` SDL_VERSIONNUM( X , Y , Z ) `
- [ ] macro ` SDL_COMPILEDVERSION() `
- [ ] macro ` SDL_VERSION_ATLEAST( X , Y , Z ) `
- [ ] inline ` SDL_PointInRect( p , r ) `
- [ ] inline ` SDL_RectEmpty( r ) `
- [ ] inline ` SDL_RectEquals( a , b ) `
- [ ] alias ` SDL_Colour ` and ` SDL_Color `
- [ ] bind ` SDL_LoadBMP_RW( src, freesrc ) `
- [ ] macro ` SDL_LoadBMP( file ) `
- [ ] bind ` SDL_SaveBMP_RW( surface , dst , freedst ) `
- [ ] macro ` SDL_SaveBMP( surface , file ) `
- [ ] API from ` SDL_syswm.h `
- [ ] API from ` SDL_clipboard.h `
- [ ] API from ` SDL_vulkan.h `
- [ ] bind ` SDL_GameControllerAddMappingsFromRW( rw , freerw ) `
- [ ] macro ` SDL_GameControllerAddMappingsFrom( file ) `
- [ ] struct ` SDL_TouchFingerEvent ` and union into ` SDL_Event `
- [ ] struct ` SDL_MultiGestureEvent ` and union into ` SDL_Event `
- [ ] struct ` SDL_DollarGestureEvent ` and union into ` SDL_Event `
- [ ] API ` SDL_thread.h `
- [ ] macro ` SDL_mutexP( m ) `
- [ ] macro ` SDL_mutexV( m ) `
- [ ] bind ` SDL_LoadWAV_RW( src , freesrc , spec , audio_buf , audio_len ) `
- [ ] macro ` SDL_LoadWav( file , spec , audio_buf , audio_ len ) `
- [ ] bind ` SDL_FreeWAV( audio_buf ) `
- [ ] API ` SDL_filesystem.h `
- [ ] API ` SDL_rwops.h `
- [ ] API ` SDL_loadso.h `
- [ ] API ` SDL_endian.h `
- [ ] API ` SDL_bits.h `
- [ ] API ` SDL_system.h `
- [ ] macro ` SDL_zero( x ) `
- [ ] macro ` SDL_zerop( x ) `
- [ ] macro ` SDL_zeroa( x ) `
- [ ] bind to all functions related to string manipulation, coversion and UTF8 ...
- [ ] struct ` SDL_iconv_t `
- [ ] bind to all functions related to iconv 
