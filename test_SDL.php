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
