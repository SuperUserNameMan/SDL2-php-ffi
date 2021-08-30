<?php

SDL::SDL(); // autoinit

class SDL
{
	//----------------------------------------------------------------------------------
	// Const Definition
	//----------------------------------------------------------------------------------

		const FALSE = 0;
		const TRUE  = 1;

		const MAX_SINT8 =  127 ;
		const MIN_SINT8 = -128 ;

		const MAX_UINT8 =  255 ;
		const MIN_UINT8 =    0 ;

		const MAX_SINT16 =  32767 ;
		const MIN_SINT16 = -32768 ;

		const MAX_UINT16 =  65535 ;
		const MIN_UINT16 =      0 ;

		const MAX_SINT32 =  2147483647 ;
		const MIN_SINT32 = -2147483648 ;

		const MAX_UINT32 =  4294967295 ;
		const MIN_UINT32 =           0 ;

		const MAX_SINT64 =   9223372036854775807 ;
		const MIN_SINT64 =  -9223372036854775808 ;

//		const MAX_UINT64 =  18446744073709551615 ; // will not work on PHP 8.0 64bits, because greater than PHP_INT_MAX
//		const MIN_UINT64 =                     0 ;

		const ICONV_ERROR  =  -1 ;
		const ICONV_E2BIG  =  -2 ;
		const ICONV_EILSEQ =  -3 ;
		const ICONV_EINVAL =  -4 ;

		public static function FOURCC( string $A , string $B , string $C , string $D ) : int
		{ 
			return ( ord($A)<<0 ) | ( ord($B)<<8 ) | ( ord($C)<<16 ) | ( ord($D)<<24 ) ; 
		}

		// ------------------------
		// from SDL.h :

		const INIT_TIMER         = 0x00000001 ;
		const INIT_AUDIO         = 0x00000010 ;
		const INIT_VIDEO         = 0x00000020 ; /**< SDL_INIT_VIDEO implies SDL_INIT_EVENTS */
		const INIT_JOYSTICK      = 0x00000200 ; /**< SDL_INIT_JOYSTICK implies SDL_INIT_EVENTS */
		const INIT_HAPTIC        = 0x00001000 ;
		const INIT_GAMECONTROLLER= 0x00002000 ; /**< SDL_INIT_GAMECONTROLLER implies SDL_INIT_JOYSTICK */
		const INIT_EVENTS        = 0x00004000 ;
		const INIT_SENSOR        = 0x00008000 ;
		const INIT_NOPARACHUTE   = 0x00100000 ; /**< compatibility; this flag is ignored. */
		const INIT_EVERYTHING    =
				( self::INIT_TIMER
				| self::INIT_AUDIO
				| self::INIT_VIDEO
				| self::INIT_EVENTS
				| self::INIT_JOYSTICK
				| self::INIT_HAPTIC
				| self::INIT_GAMECONTROLLER
				| self::INIT_SENSOR
				);

		// ------------------------
		// from SDL_hints.h :

		const HINT_FRAMEBUFFER_ACCELERATION
		    = "SDL_FRAMEBUFFER_ACCELERATION" ;
		const HINT_RENDER_DRIVER
		    = "SDL_RENDER_DRIVER" ;
		const HINT_RENDER_OPENGL_SHADERS
		    = "SDL_RENDER_OPENGL_SHADERS" ;
		const HINT_RENDER_DIRECT3D_THREADSAFE
		    = "SDL_RENDER_DIRECT3D_THREADSAFE" ;
		const HINT_RENDER_DIRECT3D11_DEBUG
		    = "SDL_RENDER_DIRECT3D11_DEBUG" ;
		const HINT_RENDER_LOGICAL_SIZE_MODE
		    = "SDL_RENDER_LOGICAL_SIZE_MODE" ;
		const HINT_RENDER_SCALE_QUALITY
		    = "SDL_RENDER_SCALE_QUALITY" ;
		const HINT_RENDER_VSYNC
		    = "SDL_RENDER_VSYNC" ;
		const HINT_VIDEO_ALLOW_SCREENSAVER
		    = "SDL_VIDEO_ALLOW_SCREENSAVER" ;
		const HINT_VIDEO_EXTERNAL_CONTEXT
		    = "SDL_VIDEO_EXTERNAL_CONTEXT" ;
		const HINT_VIDEO_X11_XVIDMODE
		    = "SDL_VIDEO_X11_XVIDMODE" ;
		const HINT_VIDEO_X11_XINERAMA
		    = "SDL_VIDEO_X11_XINERAMA" ;
		const HINT_VIDEO_X11_XRANDR
		    = "SDL_VIDEO_X11_XRANDR" ;
		const HINT_VIDEO_X11_WINDOW_VISUALID
		    = "SDL_VIDEO_X11_WINDOW_VISUALID" ;
		const HINT_VIDEO_X11_NET_WM_PING
		    = "SDL_VIDEO_X11_NET_WM_PING" ;
		const HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR
		    = "SDL_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR" ;
		const HINT_VIDEO_X11_FORCE_EGL
		    = "SDL_VIDEO_X11_FORCE_EGL" ;
		const HINT_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN
		    = "SDL_WINDOW_FRAME_USABLE_WHILE_CURSOR_HIDDEN" ;
		const HINT_WINDOWS_INTRESOURCE_ICON
		    = "SDL_WINDOWS_INTRESOURCE_ICON" ;
		const HINT_WINDOWS_INTRESOURCE_ICON_SMALL
		    = "SDL_WINDOWS_INTRESOURCE_ICON_SMALL" ;
		const HINT_WINDOWS_ENABLE_MESSAGELOOP
		    = "SDL_WINDOWS_ENABLE_MESSAGELOOP" ;
		const HINT_GRAB_KEYBOARD
		    = "SDL_GRAB_KEYBOARD" ;
		const HINT_MOUSE_DOUBLE_CLICK_TIME
		    = "SDL_MOUSE_DOUBLE_CLICK_TIME" ;
		const HINT_MOUSE_DOUBLE_CLICK_RADIUS
		    = "SDL_MOUSE_DOUBLE_CLICK_RADIUS" ;
		const HINT_MOUSE_NORMAL_SPEED_SCALE
		    = "SDL_MOUSE_NORMAL_SPEED_SCALE" ;
		const HINT_MOUSE_RELATIVE_SPEED_SCALE
		    = "SDL_MOUSE_RELATIVE_SPEED_SCALE" ;
		const HINT_MOUSE_RELATIVE_SCALING
		    = "SDL_MOUSE_RELATIVE_SCALING" ;
		const HINT_MOUSE_RELATIVE_MODE_WARP
		    = "SDL_MOUSE_RELATIVE_MODE_WARP" ;
		const HINT_MOUSE_FOCUS_CLICKTHROUGH
		    = "SDL_MOUSE_FOCUS_CLICKTHROUGH" ;
		const HINT_TOUCH_MOUSE_EVENTS
		    = "SDL_TOUCH_MOUSE_EVENTS" ;
		const HINT_MOUSE_TOUCH_EVENTS
		    = "SDL_MOUSE_TOUCH_EVENTS" ;
		const HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS
		    = "SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS" ;
		const HINT_IDLE_TIMER_DISABLED
		    = "SDL_IOS_IDLE_TIMER_DISABLED" ;
		const HINT_ORIENTATIONS
		    = "SDL_IOS_ORIENTATIONS" ;
		const HINT_APPLE_TV_CONTROLLER_UI_EVENTS
		    = "SDL_APPLE_TV_CONTROLLER_UI_EVENTS" ;
		const HINT_APPLE_TV_REMOTE_ALLOW_ROTATION
		    = "SDL_APPLE_TV_REMOTE_ALLOW_ROTATION" ;
		const HINT_IOS_HIDE_HOME_INDICATOR
		    = "SDL_IOS_HIDE_HOME_INDICATOR" ;
		const HINT_ACCELEROMETER_AS_JOYSTICK
		    = "SDL_ACCELEROMETER_AS_JOYSTICK" ;
		const HINT_TV_REMOTE_AS_JOYSTICK
		    = "SDL_TV_REMOTE_AS_JOYSTICK" ;
		const HINT_XINPUT_ENABLED
		    = "SDL_XINPUT_ENABLED" ;
		const HINT_XINPUT_USE_OLD_JOYSTICK_MAPPING
		    = "SDL_XINPUT_USE_OLD_JOYSTICK_MAPPING" ;
		const HINT_GAMECONTROLLERTYPE
		    = "SDL_GAMECONTROLLERTYPE" ;
		const HINT_GAMECONTROLLERCONFIG
		    = "SDL_GAMECONTROLLERCONFIG" ;
		const HINT_GAMECONTROLLERCONFIG_FILE
		    = "SDL_GAMECONTROLLERCONFIG_FILE" ;
		const HINT_GAMECONTROLLER_IGNORE_DEVICES
		    = "SDL_GAMECONTROLLER_IGNORE_DEVICES" ;
		const HINT_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT
		    = "SDL_GAMECONTROLLER_IGNORE_DEVICES_EXCEPT" ;
		const HINT_GAMECONTROLLER_USE_BUTTON_LABELS
		    = "SDL_GAMECONTROLLER_USE_BUTTON_LABELS" ;
		const HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS
		    = "SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS" ;
		const HINT_JOYSTICK_HIDAPI
		    = "SDL_JOYSTICK_HIDAPI" ;
		const HINT_JOYSTICK_HIDAPI_PS4
		    = "SDL_JOYSTICK_HIDAPI_PS4" ;
		const HINT_JOYSTICK_HIDAPI_PS5
		    = "SDL_JOYSTICK_HIDAPI_PS5" ;
		const HINT_JOYSTICK_HIDAPI_PS4_RUMBLE
		    = "SDL_JOYSTICK_HIDAPI_PS4_RUMBLE" ;
		const HINT_JOYSTICK_HIDAPI_STEAM
		    = "SDL_JOYSTICK_HIDAPI_STEAM" ;
		const HINT_JOYSTICK_HIDAPI_SWITCH
		    = "SDL_JOYSTICK_HIDAPI_SWITCH" ;
		const HINT_JOYSTICK_HIDAPI_XBOX
		    = "SDL_JOYSTICK_HIDAPI_XBOX" ;
		const HINT_JOYSTICK_HIDAPI_CORRELATE_XINPUT
		    = "SDL_JOYSTICK_HIDAPI_CORRELATE_XINPUT" ;
		const HINT_JOYSTICK_HIDAPI_GAMECUBE
		    = "SDL_JOYSTICK_HIDAPI_GAMECUBE" ;
		const HINT_ENABLE_STEAM_CONTROLLERS
		    = "SDL_ENABLE_STEAM_CONTROLLERS" ;
		const HINT_JOYSTICK_RAWINPUT
		    = "SDL_JOYSTICK_RAWINPUT" ;
		const HINT_JOYSTICK_THREAD
		    = "SDL_JOYSTICK_THREAD" ;
		const HINT_LINUX_JOYSTICK_DEADZONES
		    = "SDL_LINUX_JOYSTICK_DEADZONES" ;
		const HINT_ALLOW_TOPMOST
		    = "SDL_ALLOW_TOPMOST" ;
		const HINT_TIMER_RESOLUTION
		    = "SDL_TIMER_RESOLUTION" ;
		const HINT_QTWAYLAND_CONTENT_ORIENTATION
		    = "SDL_QTWAYLAND_CONTENT_ORIENTATION" ;
		const HINT_QTWAYLAND_WINDOW_FLAGS
		    = "SDL_QTWAYLAND_WINDOW_FLAGS" ;
		const HINT_THREAD_STACK_SIZE
		    = "SDL_THREAD_STACK_SIZE" ;
		const HINT_THREAD_PRIORITY_POLICY
		    = "SDL_THREAD_PRIORITY_POLICY" ;
		const HINT_THREAD_FORCE_REALTIME_TIME_CRITICAL
		    = "SDL_THREAD_FORCE_REALTIME_TIME_CRITICAL" ;
		const HINT_VIDEO_HIGHDPI_DISABLED
		    = "SDL_VIDEO_HIGHDPI_DISABLED" ;
		const HINT_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK
		    = "SDL_MAC_CTRL_CLICK_EMULATE_RIGHT_CLICK" ;
		const HINT_VIDEO_WIN_D3DCOMPILER
		    = "SDL_VIDEO_WIN_D3DCOMPILER" ;
		const HINT_VIDEO_WINDOW_SHARE_PIXEL_FORMAT
		    = "SDL_VIDEO_WINDOW_SHARE_PIXEL_FORMAT" ;
		const HINT_WINRT_PRIVACY_POLICY_URL
		    = "SDL_WINRT_PRIVACY_POLICY_URL" ;
		const HINT_WINRT_PRIVACY_POLICY_LABEL
		    = "SDL_WINRT_PRIVACY_POLICY_LABEL" ;
		const HINT_WINRT_HANDLE_BACK_BUTTON
		    = "SDL_WINRT_HANDLE_BACK_BUTTON" ;
		const HINT_VIDEO_MAC_FULLSCREEN_SPACES
		    = "SDL_VIDEO_MAC_FULLSCREEN_SPACES" ;
		const HINT_MAC_BACKGROUND_APP
		    = "SDL_MAC_BACKGROUND_APP" ;
		const HINT_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION
		    = "SDL_ANDROID_APK_EXPANSION_MAIN_FILE_VERSION" ;
		const HINT_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION
		    = "SDL_ANDROID_APK_EXPANSION_PATCH_FILE_VERSION" ;
		const HINT_IME_INTERNAL_EDITING
		    = "SDL_IME_INTERNAL_EDITING" ;
		const HINT_ANDROID_TRAP_BACK_BUTTON
		    = "SDL_ANDROID_TRAP_BACK_BUTTON" ;
		const HINT_ANDROID_BLOCK_ON_PAUSE
		    = "SDL_ANDROID_BLOCK_ON_PAUSE" ;
		const HINT_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO
		    = "SDL_ANDROID_BLOCK_ON_PAUSE_PAUSEAUDIO" ;
		const HINT_RETURN_KEY_HIDES_IME
		    = "SDL_RETURN_KEY_HIDES_IME" ;
		const HINT_EMSCRIPTEN_KEYBOARD_ELEMENT
		    = "SDL_EMSCRIPTEN_KEYBOARD_ELEMENT" ;
		const HINT_EMSCRIPTEN_ASYNCIFY
		    = "SDL_EMSCRIPTEN_ASYNCIFY" ;
		const HINT_NO_SIGNAL_HANDLERS
		    = "SDL_NO_SIGNAL_HANDLERS" ;
		const HINT_WINDOWS_NO_CLOSE_ON_ALT_F4
		    = "SDL_WINDOWS_NO_CLOSE_ON_ALT_F4" ;
		const HINT_BMP_SAVE_LEGACY_FORMAT
		    = "SDL_BMP_SAVE_LEGACY_FORMAT" ;
		const HINT_WINDOWS_DISABLE_THREAD_NAMING
		    = "SDL_WINDOWS_DISABLE_THREAD_NAMING" ;
		const HINT_RPI_VIDEO_LAYER
		    = "SDL_RPI_VIDEO_LAYER" ;
		const HINT_VIDEO_DOUBLE_BUFFER
		    = "SDL_VIDEO_DOUBLE_BUFFER" ;
		const HINT_OPENGL_ES_DRIVER
		    = "SDL_OPENGL_ES_DRIVER" ;
		const HINT_AUDIO_RESAMPLING_MODE
		    = "SDL_AUDIO_RESAMPLING_MODE" ;
		const HINT_AUDIO_CATEGORY
		    = "SDL_AUDIO_CATEGORY" ;
		const HINT_RENDER_BATCHING
		    = "SDL_RENDER_BATCHING" ;
		const HINT_AUTO_UPDATE_JOYSTICKS
		    = "SDL_AUTO_UPDATE_JOYSTICKS" ;
		const HINT_AUTO_UPDATE_SENSORS
		    = "SDL_AUTO_UPDATE_SENSORS" ;
		const HINT_EVENT_LOGGING
		    = "SDL_EVENT_LOGGING" ;
		const HINT_WAVE_RIFF_CHUNK_SIZE
		    = "SDL_WAVE_RIFF_CHUNK_SIZE" ;
		const HINT_WAVE_TRUNCATION
		    = "SDL_WAVE_TRUNCATION" ;
		const HINT_WAVE_FACT_CHUNK
		    = "SDL_WAVE_FACT_CHUNK" ;
		const HINT_DISPLAY_USABLE_BOUNDS
		    = "SDL_DISPLAY_USABLE_BOUNDS" ;
		const HINT_AUDIO_DEVICE_APP_NAME
		    = "SDL_AUDIO_DEVICE_APP_NAME" ;
		const HINT_AUDIO_DEVICE_STREAM_NAME
		    = "SDL_AUDIO_DEVICE_STREAM_NAME" ;
		const HINT_PREFERRED_LOCALES
		    = "SDL_PREFERRED_LOCALES" ;

		//--------------------------------------------------------------
		// SDL_error.h

		// enum SDL_errorcode :

		const ENOMEM      = 0 ;
		const EFREAD      = 1 ;
		const EFWRITE     = 2 ;
		const EFSEEK      = 3 ;
		const UNSUPPORTED = 4 ;
		const LASTERROR   = 5 ;

		//--------------------------------------------------------------
		// SDL_log.h

		const MAX_LOG_MESSAGE = 4096 ;

		// typedef enum SDL_LogCategory :

		const LOG_CATEGORY_APPLICATION = 0 ;
		const LOG_CATEGORY_ERROR       = 1 ;
		const LOG_CATEGORY_ASSERT      = 2 ;
		const LOG_CATEGORY_SYSTEM      = 3 ;
		const LOG_CATEGORY_AUDIO       = 4 ;
		const LOG_CATEGORY_VIDEO       = 5 ;
		const LOG_CATEGORY_RENDER      = 6 ;
		const LOG_CATEGORY_INPUT       = 7 ;
		const LOG_CATEGORY_TEST        = 8 ;
		const LOG_CATEGORY_RESERVED1   = 9 ;
		const LOG_CATEGORY_RESERVED2   = 10 ;
		const LOG_CATEGORY_RESERVED3   = 11 ;
		const LOG_CATEGORY_RESERVED4   = 12 ;
		const LOG_CATEGORY_RESERVED5   = 13 ;
		const LOG_CATEGORY_RESERVED6   = 14 ;
		const LOG_CATEGORY_RESERVED7   = 15 ;
		const LOG_CATEGORY_RESERVED8   = 16 ;
		const LOG_CATEGORY_RESERVED9   = 17 ;
		const LOG_CATEGORY_RESERVED10  = 18 ;
		const LOG_CATEGORY_CUSTOM      = 19 ;

		// typedef enum SDL_LogPriority :

		const LOG_PRIORITY_VERBOSE  = 1 ;
		const LOG_PRIORITY_DEBUG    = 2 ;
		const LOG_PRIORITY_INFO     = 3 ;
		const LOG_PRIORITY_WARN     = 4 ;
		const LOG_PRIORITY_ERROR    = 5 ;
		const LOG_PRIORITY_CRITICAL = 6 ;
		const NUM_LOG_PRIORITIES    = 7 ;


		//--------------------------------------------------------------
		// SDL_version.h

		const MAJOR_VERSION   = 2  ;
		const MINOR_VERSION   = 0  ;
		const PATCHLEVEL      = 14 ;


		//--------------------------------------------------------------
		// SDL_messagebox.h

		// typedef enum SDL_MessageBoxFlags :
		const MESSAGEBOX_ERROR                 = 0x00000010 ;   /**< error dialog */
		const MESSAGEBOX_WARNING               = 0x00000020 ;   /**< warning dialog */
		const MESSAGEBOX_INFORMATION           = 0x00000040 ;   /**< informational dialog */
		const MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT = 0x00000080 ;   /**< buttons placed left to right */
		const MESSAGEBOX_BUTTONS_RIGHT_TO_LEFT = 0x00000100 ;   /**< buttons placed right to left */


		// typedef enum SDL_MessageBoxButtonFlags :
		const MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT = 0x00000001 ;  /**< Marks the default button when return is hit */
		const MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT = 0x00000002 ;  /**< Marks the default button when escape is hit */

		// typedef enum SDL_MessageBoxColorType :
		const MESSAGEBOX_COLOR_BACKGROUND         = 0 ;
		const MESSAGEBOX_COLOR_TEXT               = 1 ;
		const MESSAGEBOX_COLOR_BUTTON_BORDER      = 2 ;
		const MESSAGEBOX_COLOR_BUTTON_BACKGROUND  = 3 ;
		const MESSAGEBOX_COLOR_BUTTON_SELECTED    = 4 ;
		const MESSAGEBOX_COLOR_MAX                = 5 ;
		
		

		//--------------------------------------------------------------
		// SDL_video.h

		// typedef enum SDL_WindowFlags :
		const WINDOW_FULLSCREEN    = 0x00000001 ;
		const WINDOW_OPENGL        = 0x00000002 ;
		const WINDOW_SHOWN         = 0x00000004 ;
		const WINDOW_HIDDEN        = 0x00000008 ;
		const WINDOW_BORDERLESS    = 0x00000010 ;
		const WINDOW_RESIZABLE     = 0x00000020 ;
		const WINDOW_MINIMIZED     = 0x00000040 ;
		const WINDOW_MAXIMIZED     = 0x00000080 ;
		const WINDOW_INPUT_GRABBED = 0x00000100 ;
		const WINDOW_INPUT_FOCUS   = 0x00000200 ;
		const WINDOW_MOUSE_FOCUS   = 0x00000400 ;
		const WINDOW_FULLSCREEN_DESKTOP = ( self::WINDOW_FULLSCREEN | 0x00001000 ) ;
		const WINDOW_FOREIGN       = 0x00000800 ;
		const WINDOW_ALLOW_HIGHDPI = 0x00002000 ;
		const WINDOW_MOUSE_CAPTURE = 0x00004000 ;
		const WINDOW_ALWAYS_ON_TOP = 0x00008000 ;
		const WINDOW_SKIP_TASKBAR  = 0x00010000 ;
		const WINDOW_UTILITY       = 0x00020000 ;
		const WINDOW_TOOLTIP       = 0x00040000 ;
		const WINDOW_POPUP_MENU    = 0x00080000 ;
		const WINDOW_VULKAN        = 0x10000000 ;
		const WINDOW_METAL         = 0x20000000 ;

		const WINDOWPOS_UNDEFINED_MASK      = 0x1FFF0000 ;
		public static function WINDOWPOS_UNDEFINED_DISPLAY( $X ) { return self::WINDOWPOS_UNDEFINED_MASK | $X ; }
		const WINDOWPOS_UNDEFINED_DISPLAY_0 = self::WINDOWPOS_UNDEFINED_MASK | 0 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_1 = self::WINDOWPOS_UNDEFINED_MASK | 1 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_2 = self::WINDOWPOS_UNDEFINED_MASK | 2 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_3 = self::WINDOWPOS_UNDEFINED_MASK | 3 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_4 = self::WINDOWPOS_UNDEFINED_MASK | 4 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_5 = self::WINDOWPOS_UNDEFINED_MASK | 5 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_6 = self::WINDOWPOS_UNDEFINED_MASK | 6 ;
		const WINDOWPOS_UNDEFINED_DISPLAY_7 = self::WINDOWPOS_UNDEFINED_MASK | 7 ;
		const WINDOWPOS_UNDEFINED           = self::WINDOWPOS_UNDEFINED_DISPLAY_0 ;
		public static function WINDOWPOS_ISUNDEFINED( $X ) { return ( ( ($X) & 0xFFFF0000 ) == static::WINDOWPOS_UNDEFINED_MASK ); }

		const WINDOWPOS_CENTERED_MASK       = 0x2FFF0000 ;
		public static function WINDOWPOS_CENTERED_DISPLAY( $X ) { return self::WINDOWPOS_CENTERED_MASK | $X ; }
		const WINDOWPOS_CENTERED_DISPLAY_0  = self::WINDOWPOS_CENTERED_MASK | 0 ;
		const WINDOWPOS_CENTERED_DISPLAY_1  = self::WINDOWPOS_CENTERED_MASK | 1 ;
		const WINDOWPOS_CENTERED_DISPLAY_2  = self::WINDOWPOS_CENTERED_MASK | 2 ;
		const WINDOWPOS_CENTERED_DISPLAY_3  = self::WINDOWPOS_CENTERED_MASK | 3 ;
		const WINDOWPOS_CENTERED_DISPLAY_4  = self::WINDOWPOS_CENTERED_MASK | 4 ;
		const WINDOWPOS_CENTERED_DISPLAY_5  = self::WINDOWPOS_CENTERED_MASK | 5 ;
		const WINDOWPOS_CENTERED_DISPLAY_6  = self::WINDOWPOS_CENTERED_MASK | 6 ;
		const WINDOWPOS_CENTERED_DISPLAY_7  = self::WINDOWPOS_CENTERED_MASK | 7 ;
		const WINDOWPOS_CENTERED            = self::WINDOWPOS_CENTERED_DISPLAY_0 ;
		public static function WINDOWPOS_ISCENTERED( $X ) { return ( ( ( $X ) & 0xFFFF0000 ) == static::WINDOWPOS_CENTERED_MASK ); }

		// typedef enum SDL_WindowEventID;

		const WINDOWEVENT_NONE         = 0 ;
		const WINDOWEVENT_SHOWN        = 1 ;
		const WINDOWEVENT_HIDDEN       = 2 ;
		const WINDOWEVENT_EXPOSED      = 3 ;
		const WINDOWEVENT_MOVED        = 4 ;
		const WINDOWEVENT_RESIZED      = 5 ;
		const WINDOWEVENT_SIZE_CHANGED = 6 ;
		const WINDOWEVENT_MINIMIZED    = 7 ;
		const WINDOWEVENT_MAXIMIZED    = 8 ;
		const WINDOWEVENT_RESTORED     = 9 ;
		const WINDOWEVENT_ENTER        = 10 ;
		const WINDOWEVENT_LEAVE        = 11 ;
		const WINDOWEVENT_FOCUS_GAINED = 12 ;
		const WINDOWEVENT_FOCUS_LOST   = 13 ;
		const WINDOWEVENT_CLOSE        = 14 ;
		const WINDOWEVENT_TAKE_FOCUS   = 15 ;
		const WINDOWEVENT_HIT_TEST     = 16 ;

		//typedef enum SDL_DisplayEventID;

		const DISPLAYEVENT_NONE         = 0 ;
		const DISPLAYEVENT_ORIENTATION  = 1 ;
		const DISPLAYEVENT_CONNECTED    = 2 ;
		const DISPLAYEVENT_DISCONNECTED = 3 ;

		// typedef enum SDL_DisplayOrientation;

		const ORIENTATION_UNKNOWN            = 0 ;
		const ORIENTATION_LANDSCAPE          = 1 ;
		const ORIENTATION_LANDSCAPE_FLIPPED  = 2 ;
		const ORIENTATION_PORTRAIT           = 3 ;
		const ORIENTATION_PORTRAIT_FLIPPED   = 4 ;

		// typedef enum SDL_GLattr :

		const GL_RED_SIZE                   = 0 ;
		const GL_GREEN_SIZE                 = 1 ;
		const GL_BLUE_SIZE                  = 2 ;
		const GL_ALPHA_SIZE                 = 3 ;
		const GL_BUFFER_SIZE                = 4 ;
		const GL_DOUBLEBUFFER               = 5 ;
		const GL_DEPTH_SIZE                 = 6 ;
		const GL_STENCIL_SIZE               = 7 ;
		const GL_ACCUM_RED_SIZE             = 8 ;
		const GL_ACCUM_GREEN_SIZE           = 9 ;
		const GL_ACCUM_BLUE_SIZE            = 10 ;
		const GL_ACCUM_ALPHA_SIZE           = 11 ;
		const GL_STEREO                     = 12 ;
		const GL_MULTISAMPLEBUFFERS         = 13 ;
		const GL_MULTISAMPLESAMPLES         = 14 ;
		const GL_ACCELERATED_VISUAL         = 15 ;
		const GL_RETAINED_BACKING           = 16 ;
		const GL_CONTEXT_MAJOR_VERSION      = 17 ;
		const GL_CONTEXT_MINOR_VERSION      = 18 ;
		const GL_CONTEXT_EGL                = 19 ;
		const GL_CONTEXT_FLAGS              = 20 ;
		const GL_CONTEXT_PROFILE_MASK       = 21 ;
		const GL_SHARE_WITH_CURRENT_CONTEXT = 22 ;
		const GL_FRAMEBUFFER_SRGB_CAPABLE   = 23 ;
		const GL_CONTEXT_RELEASE_BEHAVIOR   = 24 ;
		const GL_CONTEXT_RESET_NOTIFICATION = 25 ;
		const GL_CONTEXT_NO_ERROR           = 26 ;


		// typedef enum SDL_GLprofile;

		const GL_CONTEXT_PROFILE_CORE           = 0x0001 ;
		const GL_CONTEXT_PROFILE_COMPATIBILITY  = 0x0002 ;
		const GL_CONTEXT_PROFILE_ES             = 0x0004 ;


		// typedef enum SDL_GLcontextFlag;

		const GL_CONTEXT_DEBUG_FLAG              = 0x0001 ;
		const GL_CONTEXT_FORWARD_COMPATIBLE_FLAG = 0x0002 ;
		const GL_CONTEXT_ROBUST_ACCESS_FLAG      = 0x0004 ;
		const GL_CONTEXT_RESET_ISOLATION_FLAG    = 0x0008 ;

		// typedef enum SDL_GLcontextReleaseFlag;

		const GL_CONTEXT_RELEASE_BEHAVIOR_NONE   = 0x0000 ;
		const GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH  = 0x0001 ;


		// typedef enum SDL_GLContextResetNotification;

		const GL_CONTEXT_RESET_NO_NOTIFICATION = 0x0000 ;
		const GL_CONTEXT_RESET_LOSE_CONTEXT    = 0x0001 ;

		// typedef enum SDL_HitTestResult;

		const HITTEST_NORMAL             = 0 ;
		const HITTEST_DRAGGABLE          = 1 ;
		const HITTEST_RESIZE_TOPLEFT     = 2 ;
		const HITTEST_RESIZE_TOP         = 3 ;
		const HITTEST_RESIZE_TOPRIGHT    = 4 ;
		const HITTEST_RESIZE_RIGHT       = 5 ;
		const HITTEST_RESIZE_BOTTOMRIGHT = 6 ;
		const HITTEST_RESIZE_BOTTOM      = 7 ;
		const HITTEST_RESIZE_BOTTOMLEFT  = 8 ;
		const HITTEST_RESIZE_LEFT        = 9 ;

		//-----------------------------------------------
		// SDL_surface.h :

		const SWSURFACE    = 0          ;
		const PREALLOC     = 0x00000001 ;
		const RLEACCEL     = 0x00000002 ;
		const DONTFREE     = 0x00000004 ;
		const SIMD_ALIGNED = 0x00000008 ;

		public static function  MUSTLOCK( $S ) { return ( ( $S->flags & static::RLEACCEL) != 0 ); }

		// typedef enum SDL_YUV_CONVERSION_MODE;

		const YUV_CONVERSION_JPEG      = 0 ;
		const YUV_CONVERSION_BT601     = 1 ;
		const YUV_CONVERSION_BT709     = 2 ;
		const YUV_CONVERSION_AUTOMATIC = 3 ;


//		public static function LoadBMP( $file ) { return static::LoadBMP_RW( static::RWFromFile( $file, "rb" ), 1 ); }
//		public static function SaveBMP( $surface , $file ) { return static::SaveBMP_RW( $surface, static::RWFromFile( $file, "wb" ) , 1 ); }


		//-----------------------------------------------
		// SDL_pixels.h

		const ALPHA_OPAQUE      = 255 ;
		const ALPHA_TRANSPARENT =   0 ;


		// typedef enum SDL_PixelType;

		const PIXELTYPE_UNKNOWN  = 0 ;
		const PIXELTYPE_INDEX1   = 1 ;
		const PIXELTYPE_INDEX4   = 2 ;
		const PIXELTYPE_INDEX8   = 3 ;
		const PIXELTYPE_PACKED8  = 4 ;
		const PIXELTYPE_PACKED16 = 5 ;
		const PIXELTYPE_PACKED32 = 6 ;
		const PIXELTYPE_ARRAYU8  = 7 ;
		const PIXELTYPE_ARRAYU16 = 8 ;
		const PIXELTYPE_ARRAYU32 = 9 ;
		const PIXELTYPE_ARRAYF16 = 10 ;
		const PIXELTYPE_ARRAYF32 = 11 ;

		// typedef enum SDL_BitmapOrder;

		const BITMAPORDER_NONE = 0 ;
		const BITMAPORDER_4321 = 1 ;
		const BITMAPORDER_1234 = 2 ;


		// typedef enum SDL_PackedOrder;

		const PACKEDORDER_NONE = 0 ;
		const PACKEDORDER_XRGB = 1 ;
		const PACKEDORDER_RGBX = 2 ;
		const PACKEDORDER_ARGB = 3 ;
		const PACKEDORDER_RGBA = 4 ;
		const PACKEDORDER_XBGR = 5 ;
		const PACKEDORDER_BGRX = 6 ;
		const PACKEDORDER_ABGR = 7 ;
		const PACKEDORDER_BGRA = 8 ;

		// typedef enum SDL_ArrayOrder;

		const ARRAYORDER_NONE = 0 ;
		const ARRAYORDER_RGB  = 1 ;
		const ARRAYORDER_RGBA = 2 ;
		const ARRAYORDER_ARGB = 3 ;
		const ARRAYORDER_BGR  = 4 ;
		const ARRAYORDER_BGRA = 5 ;
		const ARRAYORDER_ABGR = 6 ;

		// typedef enum SDL_PackedLayout;

		const PACKEDLAYOUT_NONE    = 0 ;
		const PACKEDLAYOUT_332     = 1 ;
		const PACKEDLAYOUT_4444    = 2 ;
		const PACKEDLAYOUT_1555    = 3 ;
		const PACKEDLAYOUT_5551    = 4 ;
		const PACKEDLAYOUT_565     = 5 ;
		const PACKEDLAYOUT_8888    = 6 ;
		const PACKEDLAYOUT_2101010 = 7 ;
		const PACKEDLAYOUT_1010102 = 8 ;


		public static function DEFINE_PIXELFOURCC( string $A , string $B , string $C , string $D ) : int
		{ 
			return static::FOURCC( $A , $B , $C , $D ); 
		}

		public static function DEFINE_PIXELFORMAT( int $type , int $order , int $layout , int $bits , int $bytes ) : int
		{
			return ( ( 1<<28 ) | ( $type<<24 ) | ( $order<<20 ) | ( $layout<<16 ) | ( $bits<<8 ) | ( $bytes<<0 ) ) ;
		}

		public static function PIXELFLAG    ( int $X ) : int { return ( ( $X>>28 ) & 0x0F ); }
		public static function PIXELTYPE    ( int $X ) : int { return ( ( $X>>24 ) & 0x0F ); }
		public static function PIXELORDER   ( int $X ) : int { return ( ( $X>>20 ) & 0x0F ); }
		public static function PIXELLAYOUT  ( int $X ) : int { return ( ( $X>>16 ) & 0x0F ); }
		public static function BITSPERPIXEL ( int $X ) : int { return ( ( $X>> 8 ) & 0xFF ); }
		public static function BYTESPERPIXEL( int $X )
		{
			if ( static::ISPIXELFORMAT_FOURCC( $X ) )
			{
				if (
					( $X == static::PIXELFORMAT_YUY2 )
					||
					( $X == static::PIXELFORMAT_UYVY )
					||
					( $X == static::PIXELFORMAT_YVYU )
				) {
					return 2;
				}

				return 1;
			}

			return ( $X>>0 ) & 0xFF ;
		}

		public static function ISPIXELFORMAT_INDEXED( int $format ) : bool
		{
			return (
				! static::ISPIXELFORMAT_FOURCC( $format )
				&&
				(
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_INDEX1 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_INDEX4 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_INDEX8 )
				)
			);
		}

		public static function ISPIXELFORMAT_PACKED( int $format ) : bool
		{
			return (
				! static::ISPIXELFORMAT_FOURCC( $format )
				&&
				(
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_PACKED8 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_PACKED16 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_PACKED32 )
				)
			);
		}

		public static function ISPIXELFORMAT_ARRAY( int $format ) : bool
		{
			return (
				! static::ISPIXELFORMAT_FOURCC( $format )
				&&
				(
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_ARRAYU8 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_ARRAYU16 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_ARRAYU32 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_ARRAYF16 )
					||
					( static::PIXELTYPE( $format ) == static::PIXELTYPE_ARRAYF32 )
				)
			);
		}

		public static function ISPIXELFORMAT_ALPHA( int $format ) : bool
		{
			return (
				(
					static::ISPIXELFORMAT_PACKED( $format )
					&&
					(
						( static::PIXELORDER( $format ) == static::PACKEDORDER_ARGB )
						||
						( static::PIXELORDER( $format ) == static::PACKEDORDER_RGBA )
						||
						( static::PIXELORDER( $format ) == static::PACKEDORDER_ABGR )
						||
						( static::PIXELORDER( $format ) == static::PACKEDORDER_BGRA )
					)
				)
				||
				(
					static::ISPIXELFORMAT_ARRAY( $format )
					&&
					(
						( static::PIXELORDER( $format ) == static::ARRAYORDER_ARGB )
						||
						( static::PIXELORDER( $format ) == static::ARRAYORDER_RGBA )
						||
						( static::PIXELORDER( $format ) == static::ARRAYORDER_ABGR )
						||
						( static::PIXELORDER( $format ) == static::ARRAYORDER_BGRA )
					)
				)
			);
		}


		public static function ISPIXELFORMAT_FOURCC( int $format ) : bool
		{
			return ( $format && ( static::PIXELFLAG( $format ) != 1 ) );
		}


		public static $PIXELFORMAT = [];


		private static function _init_SDL_PixelFormatEnum()
		{
			static::$PIXELFORMAT['UNKNOWN'] = 0;

			static::$PIXELFORMAT['INDEX1LSB'  ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_INDEX1, static::BITMAPORDER_4321, 0, 1, 0);
			static::$PIXELFORMAT['INDEX1MSB'  ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_INDEX1, static::BITMAPORDER_1234, 0, 1, 0);
			static::$PIXELFORMAT['INDEX4LSB'  ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_INDEX4, static::BITMAPORDER_4321, 0, 4, 0);
			static::$PIXELFORMAT['INDEX4MSB'  ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_INDEX4, static::BITMAPORDER_1234, 0, 4, 0);
			static::$PIXELFORMAT['INDEX8'     ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_INDEX8, 0, 0, 8, 1);
			static::$PIXELFORMAT['RGB332'     ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED8, static::PACKEDORDER_XRGB, static::PACKEDLAYOUT_332, 8, 1);
			static::$PIXELFORMAT['XRGB4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XRGB, static::PACKEDLAYOUT_4444, 12, 2);
			static::$PIXELFORMAT['RGB444'     ] = static::$PIXELFORMAT['XRGB4444'];
			static::$PIXELFORMAT['XBGR4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XBGR, static::PACKEDLAYOUT_4444, 12, 2);
			static::$PIXELFORMAT['BGR444'     ] = static::$PIXELFORMAT['XBGR4444'];
			static::$PIXELFORMAT['XRGB1555'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XRGB, static::PACKEDLAYOUT_1555, 15, 2);
			static::$PIXELFORMAT['RGB555'     ] = static::$PIXELFORMAT['XRGB1555'];
			static::$PIXELFORMAT['XBGR1555'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XBGR, static::PACKEDLAYOUT_1555, 15, 2);
			static::$PIXELFORMAT['BGR555'     ] = static::$PIXELFORMAT['XBGR1555'];
			static::$PIXELFORMAT['ARGB4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_ARGB, static::PACKEDLAYOUT_4444, 16, 2);
			static::$PIXELFORMAT['RGBA4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_RGBA, static::PACKEDLAYOUT_4444, 16, 2);
			static::$PIXELFORMAT['ABGR4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_ABGR, static::PACKEDLAYOUT_4444, 16, 2);
			static::$PIXELFORMAT['BGRA4444'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_BGRA, static::PACKEDLAYOUT_4444, 16, 2);
			static::$PIXELFORMAT['ARGB1555'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_ARGB, static::PACKEDLAYOUT_1555, 16, 2);
			static::$PIXELFORMAT['RGBA5551'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_RGBA, static::PACKEDLAYOUT_5551, 16, 2);
			static::$PIXELFORMAT['ABGR1555'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_ABGR, static::PACKEDLAYOUT_1555, 16, 2);
			static::$PIXELFORMAT['BGRA5551'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_BGRA, static::PACKEDLAYOUT_5551, 16, 2);
			static::$PIXELFORMAT['RGB565'     ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XRGB, static::PACKEDLAYOUT_565, 16, 2);
			static::$PIXELFORMAT['BGR565'     ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED16, static::PACKEDORDER_XBGR, static::PACKEDLAYOUT_565, 16, 2);
			static::$PIXELFORMAT['RGB24'      ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_ARRAYU8, static::ARRAYORDER_RGB, 0, 24, 3);
			static::$PIXELFORMAT['BGR24'      ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_ARRAYU8, static::ARRAYORDER_BGR, 0, 24, 3);
			static::$PIXELFORMAT['XRGB8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_XRGB, static::PACKEDLAYOUT_8888, 24, 4);
			static::$PIXELFORMAT['RGB888'     ] = static::$PIXELFORMAT['XRGB8888'];
			static::$PIXELFORMAT['RGBX8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_RGBX, static::PACKEDLAYOUT_8888, 24, 4);
			static::$PIXELFORMAT['XBGR8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_XBGR, static::PACKEDLAYOUT_8888, 24, 4);
			static::$PIXELFORMAT['BGR888'     ] = static::$PIXELFORMAT['XBGR8888'];
			static::$PIXELFORMAT['BGRX8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_BGRX, static::PACKEDLAYOUT_8888, 24, 4);
			static::$PIXELFORMAT['ARGB8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_ARGB, static::PACKEDLAYOUT_8888, 32, 4);
			static::$PIXELFORMAT['RGBA8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_RGBA, static::PACKEDLAYOUT_8888, 32, 4);
			static::$PIXELFORMAT['ABGR8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_ABGR, static::PACKEDLAYOUT_8888, 32, 4);
			static::$PIXELFORMAT['BGRA8888'   ] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_BGRA, static::PACKEDLAYOUT_8888, 32, 4);
			static::$PIXELFORMAT['ARGB2101010'] = static::DEFINE_PIXELFORMAT( static::PIXELTYPE_PACKED32, static::PACKEDORDER_ARGB, static::PACKEDLAYOUT_2101010, 32, 4);

			if ( static::BYTEORDER() == static::BIG_ENDIAN )
			{
				static::$PIXELFORMAT['RGBA32' ] = static::$PIXELFORMAT['RGBA8888'];
				static::$PIXELFORMAT['ARGB32' ] = static::$PIXELFORMAT['ARGB8888'];
				static::$PIXELFORMAT['BGRA32' ] = static::$PIXELFORMAT['BGRA8888'];
				static::$PIXELFORMAT['ABGR32' ] = static::$PIXELFORMAT['ABGR8888'];
			}
			else
			{
				static::$PIXELFORMAT['RGBA32' ] = static::$PIXELFORMAT['ABGR8888'];
				static::$PIXELFORMAT['ARGB32' ] = static::$PIXELFORMAT['BGRA8888'];
				static::$PIXELFORMAT['BGRA32' ] = static::$PIXELFORMAT['ARGB8888'];
				static::$PIXELFORMAT['ABGR32' ] = static::$PIXELFORMAT['RGBA8888'];
			}

			static::$PIXELFORMAT['YV12'       ] = static::DEFINE_PIXELFOURCC('Y', 'V', '1', '2');
			static::$PIXELFORMAT['IYUV'       ] = static::DEFINE_PIXELFOURCC('I', 'Y', 'U', 'V');
			static::$PIXELFORMAT['YUY2'       ] = static::DEFINE_PIXELFOURCC('Y', 'U', 'Y', '2');
			static::$PIXELFORMAT['UYVY'       ] = static::DEFINE_PIXELFOURCC('U', 'Y', 'V', 'Y');
			static::$PIXELFORMAT['YVYU'       ] = static::DEFINE_PIXELFOURCC('Y', 'V', 'Y', 'U');
			static::$PIXELFORMAT['NV12'       ] = static::DEFINE_PIXELFOURCC('N', 'V', '1', '2');
			static::$PIXELFORMAT['NV21'       ] = static::DEFINE_PIXELFOURCC('N', 'V', '2', '1');
			static::$PIXELFORMAT['EXTERNAL_OES']= static::DEFINE_PIXELFOURCC('O', 'E', 'S', ' ');

		} // SDL_PixelFormatEnum;


		//-----------------------------------------------
		// SDL_blendmode.h

		// typedef enum SDL_BlendMode;

		const BLENDMODE_NONE    = 0x00000000 ;
		const BLENDMODE_BLEND   = 0x00000001 ;
		const BLENDMODE_ADD     = 0x00000002 ;
		const BLENDMODE_MOD     = 0x00000004 ;
		const BLENDMODE_MUL     = 0x00000008 ;
		const BLENDMODE_INVALID = 0x7FFFFFFF ;

		// typedef enum SDL_BlendOperation;

		const BLENDOPERATION_ADD              = 0x1 ;
		const BLENDOPERATION_SUBTRACT         = 0x2 ;
		const BLENDOPERATION_REV_SUBTRACT     = 0x3 ;
		const BLENDOPERATION_MINIMUM          = 0x4 ;
		const BLENDOPERATION_MAXIMUM          = 0x5 ;

		// typedef enum SDL_BlendFactor;

		const BLENDFACTOR_ZERO                = 0x1 ;
		const BLENDFACTOR_ONE                 = 0x2 ;
		const BLENDFACTOR_SRC_COLOR           = 0x3 ;
		const BLENDFACTOR_ONE_MINUS_SRC_COLOR = 0x4 ;
		const BLENDFACTOR_SRC_ALPHA           = 0x5 ;
		const BLENDFACTOR_ONE_MINUS_SRC_ALPHA = 0x6 ;
		const BLENDFACTOR_DST_COLOR           = 0x7 ;
		const BLENDFACTOR_ONE_MINUS_DST_COLOR = 0x8 ;
		const BLENDFACTOR_DST_ALPHA           = 0x9 ;
		const BLENDFACTOR_ONE_MINUS_DST_ALPHA = 0xA ;


		//---------------------------------------------------
		// SDL_endian.h

		const LIL_ENDIAN = 1234 ;
		const BIG_ENDIAN = 4321 ;

		private static function _isLittleEndian() : bool
		{ 
			// https://stackoverflow.com/questions/9744904/how-to-get-the-endianness-type-in-php
			return unpack('S',"\x01\x00")[1] === 1;
		}

		public static function BYTEORDER() : int
		{
			return static::_isLittleEndian() ? static::LIL_ENDIAN : static::BIG_ENDIAN ;
		}

		//---------------------------------------------------
		// SDL_render.h

		// typedef enum SDL_RendererFlags;

		const RENDERER_SOFTWARE      = 0x00000001 ;
		const RENDERER_ACCELERATED   = 0x00000002 ;
		const RENDERER_PRESENTVSYNC  = 0x00000004 ;
		const RENDERER_TARGETTEXTURE = 0x00000008 ;

		// typedef enum SDL_ScaleMode;

		const ScaleModeNearest = 0 ;
		const ScaleModeLinear  = 1 ;
		const ScaleModeBest    = 2 ;

		// typedef enum SDL_TextureAccess;

		const TEXTUREACCESS_STATIC    = 0 ;
		const TEXTUREACCESS_STREAMING = 1 ;
		const TEXTUREACCESS_TARGET    = 2 ;

		// typedef enum SDL_TextureModulate;

		const TEXTUREMODULATE_NONE  = 0x00000000 ;
		const TEXTUREMODULATE_COLOR = 0x00000001 ;
		const TEXTUREMODULATE_ALPHA = 0x00000002 ;

		// typedef enum SDL_RendererFlip;

		const FLIP_NONE       = 0x00000000 ;
		const FLIP_HORIZONTAL = 0x00000001 ;
		const FLIP_VERTICAL   = 0x00000002 ;

		//-------------------------------------------
		// SDL_scancode.h

		// typedef enum SDL_Scancode;

		const SCANCODE_UNKNOWN = 0 ;

		const SCANCODE_A = 4 ;
		const SCANCODE_B = 5 ;
		const SCANCODE_C = 6 ;
		const SCANCODE_D = 7 ;
		const SCANCODE_E = 8 ;
		const SCANCODE_F = 9 ;
		const SCANCODE_G = 10 ;
		const SCANCODE_H = 11 ;
		const SCANCODE_I = 12 ;
		const SCANCODE_J = 13 ;
		const SCANCODE_K = 14 ;
		const SCANCODE_L = 15 ;
		const SCANCODE_M = 16 ;
		const SCANCODE_N = 17 ;
		const SCANCODE_O = 18 ;
		const SCANCODE_P = 19 ;
		const SCANCODE_Q = 20 ;
		const SCANCODE_R = 21 ;
		const SCANCODE_S = 22 ;
		const SCANCODE_T = 23 ;
		const SCANCODE_U = 24 ;
		const SCANCODE_V = 25 ;
		const SCANCODE_W = 26 ;
		const SCANCODE_X = 27 ;
		const SCANCODE_Y = 28 ;
		const SCANCODE_Z = 29 ;

		const SCANCODE_1 = 30 ;
		const SCANCODE_2 = 31 ;
		const SCANCODE_3 = 32 ;
		const SCANCODE_4 = 33 ;
		const SCANCODE_5 = 34 ;
		const SCANCODE_6 = 35 ;
		const SCANCODE_7 = 36 ;
		const SCANCODE_8 = 37 ;
		const SCANCODE_9 = 38 ;
		const SCANCODE_0 = 39 ;

		const SCANCODE_RETURN = 40 ;
		const SCANCODE_ESCAPE = 41 ;
		const SCANCODE_BACKSPACE = 42 ;
		const SCANCODE_TAB = 43 ;
		const SCANCODE_SPACE = 44 ;

		const SCANCODE_MINUS = 45 ;
		const SCANCODE_EQUALS = 46 ;
		const SCANCODE_LEFTBRACKET = 47 ;
		const SCANCODE_RIGHTBRACKET = 48 ;
		const SCANCODE_BACKSLASH = 49 ;
		const SCANCODE_NONUSHASH = 50 ;
		const SCANCODE_SEMICOLON = 51 ;
		const SCANCODE_APOSTROPHE = 52 ;
		const SCANCODE_GRAVE = 53 ;
		const SCANCODE_COMMA = 54 ;
		const SCANCODE_PERIOD = 55 ;
		const SCANCODE_SLASH = 56 ;

		const SCANCODE_CAPSLOCK = 57 ;

		const SCANCODE_F1 = 58 ;
		const SCANCODE_F2 = 59 ;
		const SCANCODE_F3 = 60 ;
		const SCANCODE_F4 = 61 ;
		const SCANCODE_F5 = 62 ;
		const SCANCODE_F6 = 63 ;
		const SCANCODE_F7 = 64 ;
		const SCANCODE_F8 = 65 ;
		const SCANCODE_F9 = 66 ;
		const SCANCODE_F10 = 67 ;
		const SCANCODE_F11 = 68 ;
		const SCANCODE_F12 = 69 ;

		const SCANCODE_PRINTSCREEN = 70 ;
		const SCANCODE_SCROLLLOCK = 71 ;
		const SCANCODE_PAUSE = 72 ;
		const SCANCODE_INSERT = 73 ;
		const SCANCODE_HOME = 74 ;
		const SCANCODE_PAGEUP = 75 ;
		const SCANCODE_DELETE = 76 ;
		const SCANCODE_END = 77 ;
		const SCANCODE_PAGEDOWN = 78 ;
		const SCANCODE_RIGHT = 79 ;
		const SCANCODE_LEFT = 80 ;
		const SCANCODE_DOWN = 81 ;
		const SCANCODE_UP = 82 ;

		const SCANCODE_NUMLOCKCLEAR = 83 ;
		const SCANCODE_KP_DIVIDE = 84 ;
		const SCANCODE_KP_MULTIPLY = 85 ;
		const SCANCODE_KP_MINUS = 86 ;
		const SCANCODE_KP_PLUS = 87 ;
		const SCANCODE_KP_ENTER = 88 ;
		const SCANCODE_KP_1 = 89 ;
		const SCANCODE_KP_2 = 90 ;
		const SCANCODE_KP_3 = 91 ;
		const SCANCODE_KP_4 = 92 ;
		const SCANCODE_KP_5 = 93 ;
		const SCANCODE_KP_6 = 94 ;
		const SCANCODE_KP_7 = 95 ;
		const SCANCODE_KP_8 = 96 ;
		const SCANCODE_KP_9 = 97 ;
		const SCANCODE_KP_0 = 98 ;
		const SCANCODE_KP_PERIOD = 99 ;

		const SCANCODE_NONUSBACKSLASH = 100 ;
		const SCANCODE_APPLICATION = 101 ;
		const SCANCODE_POWER = 102 ;
		const SCANCODE_KP_EQUALS = 103 ;
		const SCANCODE_F13 = 104 ;
		const SCANCODE_F14 = 105 ;
		const SCANCODE_F15 = 106 ;
		const SCANCODE_F16 = 107 ;
		const SCANCODE_F17 = 108 ;
		const SCANCODE_F18 = 109 ;
		const SCANCODE_F19 = 110 ;
		const SCANCODE_F20 = 111 ;
		const SCANCODE_F21 = 112 ;
		const SCANCODE_F22 = 113 ;
		const SCANCODE_F23 = 114 ;
		const SCANCODE_F24 = 115 ;
		const SCANCODE_EXECUTE = 116 ;
		const SCANCODE_HELP = 117 ;
		const SCANCODE_MENU = 118 ;
		const SCANCODE_SELECT = 119 ;
		const SCANCODE_STOP = 120 ;
		const SCANCODE_AGAIN = 121 ;
		const SCANCODE_UNDO = 122 ;
		const SCANCODE_CUT = 123 ;
		const SCANCODE_COPY = 124 ;
		const SCANCODE_PASTE = 125 ;
		const SCANCODE_FIND = 126 ;
		const SCANCODE_MUTE = 127 ;
		const SCANCODE_VOLUMEUP = 128 ;
		const SCANCODE_VOLUMEDOWN = 129 ;

		const SCANCODE_KP_COMMA = 133 ;
		const SCANCODE_KP_EQUALSAS400 = 134 ;

		const SCANCODE_INTERNATIONAL1 = 135 ;
		const SCANCODE_INTERNATIONAL2 = 136 ;
		const SCANCODE_INTERNATIONAL3 = 137 ;
		const SCANCODE_INTERNATIONAL4 = 138 ;
		const SCANCODE_INTERNATIONAL5 = 139 ;
		const SCANCODE_INTERNATIONAL6 = 140 ;
		const SCANCODE_INTERNATIONAL7 = 141 ;
		const SCANCODE_INTERNATIONAL8 = 142 ;
		const SCANCODE_INTERNATIONAL9 = 143 ;
		const SCANCODE_LANG1 = 144 ;
		const SCANCODE_LANG2 = 145 ;
		const SCANCODE_LANG3 = 146 ;
		const SCANCODE_LANG4 = 147 ;
		const SCANCODE_LANG5 = 148 ;
		const SCANCODE_LANG6 = 149 ;
		const SCANCODE_LANG7 = 150 ;
		const SCANCODE_LANG8 = 151 ;
		const SCANCODE_LANG9 = 152 ;

		const SCANCODE_ALTERASE = 153 ;
		const SCANCODE_SYSREQ = 154 ;
		const SCANCODE_CANCEL = 155 ;
		const SCANCODE_CLEAR = 156 ;
		const SCANCODE_PRIOR = 157 ;
		const SCANCODE_RETURN2 = 158 ;
		const SCANCODE_SEPARATOR = 159 ;
		const SCANCODE_OUT = 160 ;
		const SCANCODE_OPER = 161 ;
		const SCANCODE_CLEARAGAIN = 162 ;
		const SCANCODE_CRSEL = 163 ;
		const SCANCODE_EXSEL = 164 ;

		const SCANCODE_KP_00 = 176 ;
		const SCANCODE_KP_000 = 177 ;
		const SCANCODE_THOUSANDSSEPARATOR = 178 ;
		const SCANCODE_DECIMALSEPARATOR = 179 ;
		const SCANCODE_CURRENCYUNIT = 180 ;
		const SCANCODE_CURRENCYSUBUNIT = 181 ;
		const SCANCODE_KP_LEFTPAREN = 182 ;
		const SCANCODE_KP_RIGHTPAREN = 183 ;
		const SCANCODE_KP_LEFTBRACE = 184 ;
		const SCANCODE_KP_RIGHTBRACE = 185 ;
		const SCANCODE_KP_TAB = 186 ;
		const SCANCODE_KP_BACKSPACE = 187 ;
		const SCANCODE_KP_A = 188 ;
		const SCANCODE_KP_B = 189 ;
		const SCANCODE_KP_C = 190 ;
		const SCANCODE_KP_D = 191 ;
		const SCANCODE_KP_E = 192 ;
		const SCANCODE_KP_F = 193 ;
		const SCANCODE_KP_XOR = 194 ;
		const SCANCODE_KP_POWER = 195 ;
		const SCANCODE_KP_PERCENT = 196 ;
		const SCANCODE_KP_LESS = 197 ;
		const SCANCODE_KP_GREATER = 198 ;
		const SCANCODE_KP_AMPERSAND = 199 ;
		const SCANCODE_KP_DBLAMPERSAND = 200 ;
		const SCANCODE_KP_VERTICALBAR = 201 ;
		const SCANCODE_KP_DBLVERTICALBAR = 202 ;
		const SCANCODE_KP_COLON = 203 ;
		const SCANCODE_KP_HASH = 204 ;
		const SCANCODE_KP_SPACE = 205 ;
		const SCANCODE_KP_AT = 206 ;
		const SCANCODE_KP_EXCLAM = 207 ;
		const SCANCODE_KP_MEMSTORE = 208 ;
		const SCANCODE_KP_MEMRECALL = 209 ;
		const SCANCODE_KP_MEMCLEAR = 210 ;
		const SCANCODE_KP_MEMADD = 211 ;
		const SCANCODE_KP_MEMSUBTRACT = 212 ;
		const SCANCODE_KP_MEMMULTIPLY = 213 ;
		const SCANCODE_KP_MEMDIVIDE = 214 ;
		const SCANCODE_KP_PLUSMINUS = 215 ;
		const SCANCODE_KP_CLEAR = 216 ;
		const SCANCODE_KP_CLEARENTRY = 217 ;
		const SCANCODE_KP_BINARY = 218 ;
		const SCANCODE_KP_OCTAL = 219 ;
		const SCANCODE_KP_DECIMAL = 220 ;
		const SCANCODE_KP_HEXADECIMAL = 221 ;

		const SCANCODE_LCTRL = 224 ;
		const SCANCODE_LSHIFT = 225 ;
		const SCANCODE_LALT = 226 ;
		const SCANCODE_LGUI = 227 ;
		const SCANCODE_RCTRL = 228 ;
		const SCANCODE_RSHIFT = 229 ;
		const SCANCODE_RALT = 230 ;
		const SCANCODE_RGUI = 231 ;

		const SCANCODE_MODE = 257 ;

		const SCANCODE_AUDIONEXT = 258 ;
		const SCANCODE_AUDIOPREV = 259 ;
		const SCANCODE_AUDIOSTOP = 260 ;
		const SCANCODE_AUDIOPLAY = 261 ;
		const SCANCODE_AUDIOMUTE = 262 ;
		const SCANCODE_MEDIASELECT = 263 ;
		const SCANCODE_WWW = 264 ;
		const SCANCODE_MAIL = 265 ;
		const SCANCODE_CALCULATOR = 266 ;
		const SCANCODE_COMPUTER = 267 ;
		const SCANCODE_AC_SEARCH = 268 ;
		const SCANCODE_AC_HOME = 269 ;
		const SCANCODE_AC_BACK = 270 ;
		const SCANCODE_AC_FORWARD = 271 ;
		const SCANCODE_AC_STOP = 272 ;
		const SCANCODE_AC_REFRESH = 273 ;
		const SCANCODE_AC_BOOKMARKS = 274 ;

		const SCANCODE_BRIGHTNESSDOWN = 275 ;
		const SCANCODE_BRIGHTNESSUP = 276 ;
		const SCANCODE_DISPLAYSWITCH = 277 ;
		const SCANCODE_KBDILLUMTOGGLE = 278 ;
		const SCANCODE_KBDILLUMDOWN = 279 ;
		const SCANCODE_KBDILLUMUP = 280 ;
		const SCANCODE_EJECT = 281 ;
		const SCANCODE_SLEEP = 282 ;

		const SCANCODE_APP1 = 283 ;
		const SCANCODE_APP2 = 284 ;

		const SCANCODE_AUDIOREWIND = 285 ;
		const SCANCODE_AUDIOFASTFORWARD = 286 ;

		const NUM_SCANCODES = 512 ;

	//--------------------------------------------------
	// SDL_keycode.h

	const K_SCANCODE_MASK = (1<<30) ;

	public static function SCANCODE_TO_KEYCODE( int $X ) : int { return ( $X | static::K_SCANCODE_MASK ); }

	static $K = [];

	private static function _init_SDL_KeyCode()
	{

		static::$K['UNKNOWN'   ] = 0 ;

		static::$K['RETURN'    ] = ord('\r' ) ;
		static::$K['ESCAPE'    ] = ord('\033' ) ;
		static::$K['BACKSPACE' ] = ord('\b' ) ;
		static::$K['TAB'       ] = ord('\t' ) ;
		static::$K['SPACE'     ] = ord(' ' ) ;
		static::$K['EXCLAIM'   ] = ord('!' ) ;
		static::$K['QUOTEDBL'  ] = ord('"' ) ;
		static::$K['HASH'      ] = ord('#' ) ;
		static::$K['PERCENT'   ] = ord('%' ) ;
		static::$K['DOLLAR'    ] = ord('$' ) ;
		static::$K['AMPERSAND' ] = ord('&' ) ;
		static::$K['QUOTE'     ] = ord('\'' ) ;
		static::$K['LEFTPAREN' ] = ord('(' ) ;
		static::$K['RIGHTPAREN'] = ord(')' ) ;
		static::$K['ASTERISK'  ] = ord('*' ) ;
		static::$K['PLUS'      ] = ord('+' ) ;
		static::$K['COMMA'     ] = ord(',' ) ;
		static::$K['MINUS'     ] = ord('-' ) ;
		static::$K['PERIOD'    ] = ord('.' ) ;
		static::$K['SLASH'     ] = ord('/' ) ;
		static::$K['0'         ] = ord('0' ) ;
		static::$K['1'         ] = ord('1' ) ;
		static::$K['2'         ] = ord('2' ) ;
		static::$K['3'         ] = ord('3' ) ;
		static::$K['4'         ] = ord('4' ) ;
		static::$K['5'         ] = ord('5' ) ;
		static::$K['6'         ] = ord('6' ) ;
		static::$K['7'         ] = ord('7' ) ;
		static::$K['8'         ] = ord('8' ) ;
		static::$K['9'         ] = ord('9' ) ;
		static::$K['COLON'     ] = ord(':' ) ;
		static::$K['SEMICOLON' ] = ord(';' ) ;
		static::$K['LESS'      ] = ord('<' ) ;
		static::$K['EQUALS'    ] = ord('=' ) ;
		static::$K['GREATER'   ] = ord('>' ) ;
		static::$K['QUESTION'  ] = ord('?' ) ;
		static::$K['AT'        ] = ord('@' ) ;

		static::$K['LEFTBRACKET' ] = ord('[' ) ;
		static::$K['BACKSLASH'   ] = ord('\\' ) ;
		static::$K['RIGHTBRACKET'] = ord(']' ) ;
		static::$K['CARET'       ] = ord('^' ) ;
		static::$K['UNDERSCORE'  ] = ord('_' ) ;
		static::$K['BACKQUOTE'   ] = ord('`' ) ;
		static::$K['a'           ] = ord('a' ) ;
		static::$K['b'           ] = ord('b' ) ;
		static::$K['c'           ] = ord('c' ) ;
		static::$K['d'           ] = ord('d' ) ;
		static::$K['e'           ] = ord('e' ) ;
		static::$K['f'           ] = ord('f' ) ;
		static::$K['g'           ] = ord('g' ) ;
		static::$K['h'           ] = ord('h' ) ;
		static::$K['i'           ] = ord('i' ) ;
		static::$K['j'           ] = ord('j' ) ;
		static::$K['k'           ] = ord('k' ) ;
		static::$K['l'           ] = ord('l' ) ;
		static::$K['m'           ] = ord('m' ) ;
		static::$K['n'           ] = ord('n' ) ;
		static::$K['o'           ] = ord('o' ) ;
		static::$K['p'           ] = ord('p' ) ;
		static::$K['q'           ] = ord('q' ) ;
		static::$K['r'           ] = ord('r' ) ;
		static::$K['s'           ] = ord('s' ) ;
		static::$K['t'           ] = ord('t' ) ;
		static::$K['u'           ] = ord('u' ) ;
		static::$K['v'           ] = ord('v' ) ;
		static::$K['w'           ] = ord('w' ) ;
		static::$K['x'           ] = ord('x' ) ;
		static::$K['y'           ] = ord('y' ) ;
		static::$K['z'           ] = ord('z' ) ;

		static::$K['CAPSLOCK'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CAPSLOCK ) ;

		static::$K['F1'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F1 ) ;
		static::$K['F2'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F2 ) ;
		static::$K['F3'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F3 ) ;
		static::$K['F4'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F4 ) ;
		static::$K['F5'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F5 ) ;
		static::$K['F6'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F6 ) ;
		static::$K['F7'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F7 ) ;
		static::$K['F8'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F8 ) ;
		static::$K['F9'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F9 ) ;
		static::$K['F10'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F10 ) ;
		static::$K['F11'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F11 ) ;
		static::$K['F12'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F12 ) ;

		static::$K['PRINTSCREEN' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PRINTSCREEN ) ;
		static::$K['SCROLLLOCK'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_SCROLLLOCK ) ;
		static::$K['PAUSE'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PAUSE ) ;
		static::$K['INSERT'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_INSERT ) ;
		static::$K['HOME'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_HOME ) ;
		static::$K['PAGEUP'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PAGEUP ) ;
		static::$K['DELETE'      ] = ord('\177' ) ;
		static::$K['END'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_END ) ;
		static::$K['PAGEDOWN'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PAGEDOWN ) ;
		static::$K['RIGHT'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RIGHT ) ;
		static::$K['LEFT'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_LEFT ) ;
		static::$K['DOWN'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_DOWN ) ;
		static::$K['UP'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_UP ) ;

		static::$K['NUMLOCKCLEAR'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_NUMLOCKCLEAR ) ;
		static::$K['KP_DIVIDE'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_DIVIDE ) ;
		static::$K['KP_MULTIPLY' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MULTIPLY ) ;
		static::$K['KP_MINUS'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MINUS ) ;
		static::$K['KP_PLUS'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_PLUS ) ;
		static::$K['KP_ENTER'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_ENTER ) ;
		static::$K['KP_1'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_1 ) ;
		static::$K['KP_2'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_2 ) ;
		static::$K['KP_3'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_3 ) ;
		static::$K['KP_4'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_4 ) ;
		static::$K['KP_5'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_5 ) ;
		static::$K['KP_6'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_6 ) ;
		static::$K['KP_7'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_7 ) ;
		static::$K['KP_8'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_8 ) ;
		static::$K['KP_9'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_9 ) ;
		static::$K['KP_0'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_0 ) ;
		static::$K['KP_PERIOD'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_PERIOD ) ;

		static::$K['APPLICATION' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_APPLICATION ) ;
		static::$K['POWER'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_POWER ) ;
		static::$K['KP_EQUALS'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_EQUALS ) ;
		static::$K['F13'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F13 ) ;
		static::$K['F14'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F14 ) ;
		static::$K['F15'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F15 ) ;
		static::$K['F16'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F16 ) ;
		static::$K['F17'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F17 ) ;
		static::$K['F18'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F18 ) ;
		static::$K['F19'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F19 ) ;
		static::$K['F20'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F20 ) ;
		static::$K['F21'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F21 ) ;
		static::$K['F22'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F22 ) ;
		static::$K['F23'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F23 ) ;
		static::$K['F24'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_F24 ) ;
		static::$K['EXECUTE'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_EXECUTE ) ;
		static::$K['HELP'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_HELP ) ;
		static::$K['MENU'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_MENU ) ;
		static::$K['SELECT'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_SELECT ) ;
		static::$K['STOP'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_STOP ) ;
		static::$K['AGAIN'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AGAIN ) ;
		static::$K['UNDO'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_UNDO ) ;
		static::$K['CUT'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CUT ) ;
		static::$K['COPY'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_COPY ) ;
		static::$K['PASTE'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PASTE ) ;
		static::$K['FIND'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_FIND ) ;
		static::$K['MUTE'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_MUTE ) ;
		static::$K['VOLUMEUP'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_VOLUMEUP ) ;
		static::$K['VOLUMEDOWN'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_VOLUMEDOWN ) ;
		static::$K['KP_COMMA'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_COMMA ) ;
		static::$K['KP_EQUALSAS400'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_EQUALSAS400 ) ;

		static::$K['ALTERASE'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_ALTERASE ) ;
		static::$K['SYSREQ'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_SYSREQ ) ;
		static::$K['CANCEL'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CANCEL ) ;
		static::$K['CLEAR'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CLEAR ) ;
		static::$K['PRIOR'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_PRIOR ) ;
		static::$K['RETURN2'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RETURN2 ) ;
		static::$K['SEPARATOR'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_SEPARATOR ) ;
		static::$K['OUT'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_OUT ) ;
		static::$K['OPER'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_OPER ) ;
		static::$K['CLEARAGAIN'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CLEARAGAIN ) ;
		static::$K['CRSEL'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CRSEL ) ;
		static::$K['EXSEL'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_EXSEL ) ;

		static::$K['KP_00'             ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_00 ) ;
		static::$K['KP_000'            ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_000 ) ;
		static::$K['THOUSANDSSEPARATOR'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_THOUSANDSSEPARATOR ) ;
		static::$K['DECIMALSEPARATOR'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_DECIMALSEPARATOR ) ;
		static::$K['CURRENCYUNIT'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CURRENCYUNIT ) ;
		static::$K['CURRENCYSUBUNIT'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CURRENCYSUBUNIT ) ;
		static::$K['KP_LEFTPAREN'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_LEFTPAREN ) ;
		static::$K['KP_RIGHTPAREN'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_RIGHTPAREN ) ;
		static::$K['KP_LEFTBRACE'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_LEFTBRACE ) ;
		static::$K['KP_RIGHTBRACE'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_RIGHTBRACE ) ;
		static::$K['KP_TAB'            ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_TAB ) ;
		static::$K['KP_BACKSPACE'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_BACKSPACE ) ;
		static::$K['KP_A'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_A ) ;
		static::$K['KP_B'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_B ) ;
		static::$K['KP_C'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_C ) ;
		static::$K['KP_D'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_D ) ;
		static::$K['KP_E'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_E ) ;
		static::$K['KP_F'              ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_F ) ;
		static::$K['KP_XOR'            ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_XOR ) ;
		static::$K['KP_POWER'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_POWER ) ;
		static::$K['KP_PERCENT'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_PERCENT ) ;
		static::$K['KP_LESS'           ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_LESS ) ;
		static::$K['KP_GREATER'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_GREATER ) ;
		static::$K['KP_AMPERSAND'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_AMPERSAND ) ;
		static::$K['KP_DBLAMPERSAND'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_DBLAMPERSAND ) ;
		static::$K['KP_VERTICALBAR'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_VERTICALBAR ) ;
		static::$K['KP_DBLVERTICALBAR' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_DBLVERTICALBAR ) ;
		static::$K['KP_COLON'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_COLON ) ;
		static::$K['KP_HASH'           ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_HASH ) ;
		static::$K['KP_SPACE'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_SPACE ) ;
		static::$K['KP_AT'             ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_AT ) ;
		static::$K['KP_EXCLAM'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_EXCLAM ) ;
		static::$K['KP_MEMSTORE'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMSTORE ) ;
		static::$K['KP_MEMRECALL'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMRECALL ) ;
		static::$K['KP_MEMCLEAR'       ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMCLEAR ) ;
		static::$K['KP_MEMADD'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMADD ) ;
		static::$K['KP_MEMSUBTRACT'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMSUBTRACT ) ;
		static::$K['KP_MEMMULTIPLY'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMMULTIPLY ) ;
		static::$K['KP_MEMDIVIDE'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_MEMDIVIDE ) ;
		static::$K['KP_PLUSMINUS'      ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_PLUSMINUS ) ;
		static::$K['KP_CLEAR'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_CLEAR ) ;
		static::$K['KP_CLEARENTRY'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_CLEARENTRY ) ;
		static::$K['KP_BINARY'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_BINARY ) ;
		static::$K['KP_OCTAL'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_OCTAL ) ;
		static::$K['KP_DECIMAL'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_DECIMAL ) ;
		static::$K['KP_HEXADECIMAL'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KP_HEXADECIMAL ) ;

		static::$K['LCTRL' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_LCTRL ) ;
		static::$K['LSHIFT'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_LSHIFT ) ;
		static::$K['LALT'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_LALT ) ;
		static::$K['LGUI'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_LGUI ) ;
		static::$K['RCTRL' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RCTRL ) ;
		static::$K['RSHIFT'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RSHIFT ) ;
		static::$K['RALT'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RALT ) ;
		static::$K['RGUI'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_RGUI ) ;

		static::$K['MODE'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_MODE ) ;

		static::$K['AUDIONEXT'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIONEXT ) ;
		static::$K['AUDIOPREV'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOPREV ) ;
		static::$K['AUDIOSTOP'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOSTOP ) ;
		static::$K['AUDIOPLAY'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOPLAY ) ;
		static::$K['AUDIOMUTE'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOMUTE ) ;
		static::$K['MEDIASELECT' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_MEDIASELECT ) ;
		static::$K['WWW'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_WWW ) ;
		static::$K['MAIL'        ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_MAIL ) ;
		static::$K['CALCULATOR'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_CALCULATOR ) ;
		static::$K['COMPUTER'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_COMPUTER ) ;
		static::$K['AC_SEARCH'   ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_SEARCH ) ;
		static::$K['AC_HOME'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_HOME ) ;
		static::$K['AC_BACK'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_BACK ) ;
		static::$K['AC_FORWARD'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_FORWARD ) ;
		static::$K['AC_STOP'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_STOP ) ;
		static::$K['AC_REFRESH'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_REFRESH ) ;
		static::$K['AC_BOOKMARKS'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AC_BOOKMARKS ) ;

		static::$K['BRIGHTNESSDOWN'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_BRIGHTNESSDOWN ) ;
		static::$K['BRIGHTNESSUP'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_BRIGHTNESSUP ) ;
		static::$K['DISPLAYSWITCH' ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_DISPLAYSWITCH ) ;
		static::$K['KBDILLUMTOGGLE'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KBDILLUMTOGGLE ) ;
		static::$K['KBDILLUMDOWN'  ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KBDILLUMDOWN ) ;
		static::$K['KBDILLUMUP'    ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_KBDILLUMUP ) ;
		static::$K['EJECT'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_EJECT ) ;
		static::$K['SLEEP'         ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_SLEEP ) ;
		static::$K['APP1'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_APP1 ) ;
		static::$K['APP2'          ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_APP2 ) ;

		static::$K['AUDIOREWIND'     ] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOREWIND ) ;
		static::$K['AUDIOFASTFORWARD'] = static::SCANCODE_TO_KEYCODE( static::SCANCODE_AUDIOFASTFORWARD ) ;
	}

	// typedef enum SDL_Keymod

	const KMOD_NONE     = 0x0000 ;
	const KMOD_LSHIFT   = 0x0001 ;
	const KMOD_RSHIFT   = 0x0002 ;
	const KMOD_LCTRL    = 0x0040 ;
	const KMOD_RCTRL    = 0x0080 ;
	const KMOD_LALT     = 0x0100 ;
	const KMOD_RALT     = 0x0200 ;
	const KMOD_LGUI     = 0x0400 ;
	const KMOD_RGUI     = 0x0800 ;
	const KMOD_NUM      = 0x1000 ;
	const KMOD_CAPS     = 0x2000 ;
	const KMOD_MODE     = 0x4000 ;
	const KMOD_RESERVED = 0x8000 ;

	const KMOD_CTRL  = self::KMOD_LCTRL  | self::KMOD_RCTRL ;
	const KMOD_SHIFT = self::KMOD_LSHIFT | self::KMOD_RSHIFT;
	const KMOD_ALT   = self::KMOD_LALT   | self::KMOD_RALT  ;
	const KMOD_GUI   = self::KMOD_LGUI   | self::KMOD_RGUI  ;


	//-------------------------------------
	// SDL_mouse.h

	// typedef enum SDL_SystemCursor;

	const SYSTEM_CURSOR_ARROW     = 0 ;
	const SYSTEM_CURSOR_IBEAM     = 1 ;
	const SYSTEM_CURSOR_WAIT      = 2 ;
	const SYSTEM_CURSOR_CROSSHAIR = 3 ;
	const SYSTEM_CURSOR_WAITARROW = 4 ;
	const SYSTEM_CURSOR_SIZENWSE  = 5 ;
	const SYSTEM_CURSOR_SIZENESW  = 6 ;
	const SYSTEM_CURSOR_SIZEWE    = 7 ;
	const SYSTEM_CURSOR_SIZENS    = 8 ;
	const SYSTEM_CURSOR_SIZEALL   = 9 ;
	const SYSTEM_CURSOR_NO        = 10 ;
	const SYSTEM_CURSOR_HAND      = 11 ;
	const NUM_SYSTEM_CURSORS      = 12 ;



	// typedef enum SDL_MouseWheelDirection;

	const MOUSEWHEEL_NORMAL    = 0 ;
	const MOUSEWHEEL_FLIPPED   = 1 ;

	public static function BUTTON( int $X ) : int { return ( 1 << ( $X - 1 ) ) ; }

	const BUTTON_LEFT   = 1 ;
	const BUTTON_MIDDLE = 2 ;
	const BUTTON_RIGHT  = 3 ;
	const BUTTON_X1     = 4 ;
	const BUTTON_X2     = 5 ;
	const BUTTON_LMASK  = 1 << 0 ;
	const BUTTON_MMASK  = 1 << 1 ;
	const BUTTON_RMASK  = 1 << 2 ;
	const BUTTON_X1MASK = 1 << 3 ;
	const BUTTON_X2MASK = 1 << 4 ;


	//-----------------------------------------
	// SDL_joystick.h

	// typedef enum SDL_JoystickType

	const JOYSTICK_TYPE_UNKNOWN        = 0 ;
	const JOYSTICK_TYPE_GAMECONTROLLER = 1 ;
	const JOYSTICK_TYPE_WHEEL          = 2 ;
	const JOYSTICK_TYPE_ARCADE_STICK   = 3 ;
	const JOYSTICK_TYPE_FLIGHT_STICK   = 4 ;
	const JOYSTICK_TYPE_DANCE_PAD      = 5 ;
	const JOYSTICK_TYPE_GUITAR         = 6 ;
	const JOYSTICK_TYPE_DRUM_KIT       = 7 ;
	const JOYSTICK_TYPE_ARCADE_PAD     = 8 ;
	const JOYSTICK_TYPE_THROTTLE       = 9 ;


	// typedef enum SDL_JoystickPowerLevel;

	const JOYSTICK_POWER_UNKNOWN = -1 ;
	const JOYSTICK_POWER_EMPTY   =  0 ;
	const JOYSTICK_POWER_LOW     =  1 ;
	const JOYSTICK_POWER_MEDIUM  =  2 ;
	const JOYSTICK_POWER_FULL    =  3 ;
	const JOYSTICK_POWER_WIRED   =  4 ;
	const JOYSTICK_POWER_MAX     =  5 ;


	const IPHONE_MAX_GFORCE = 5.0 ;

	const JOYSTICK_AXIS_MAX =  32767 ;
	const JOYSTICK_AXIS_MIN = -32768 ;

	const HAT_CENTERED   = 0x00 ;
	const HAT_UP         = 0x01 ;
	const HAT_RIGHT      = 0x02 ;
	const HAT_DOWN       = 0x04 ;
	const HAT_LEFT       = 0x08 ;
	const HAT_RIGHTUP    = ( self::HAT_RIGHT | self::HAT_UP   ) ;
	const HAT_RIGHTDOWN  = ( self::HAT_RIGHT | self::HAT_DOWN ) ;
	const HAT_LEFTUP     = ( self::HAT_LEFT  | self::HAT_UP   ) ;
	const HAT_LEFTDOWN   = ( self::HAT_LEFT  | self::HAT_DOWN ) ;


	//-----------------------------------
	// SDL_sensor.h

	// typedef enum SDL_SensorType;

	const SENSOR_INVALID = -1 ;
	const SENSOR_UNKNOWN =  0 ;
	const SENSOR_ACCEL   =  2 ;
	const SENSOR_GYRO    =  3 ;

	const STANDARD_GRAVITY = 9.80665 ;


	//------------------------------------
	// SDL_gamecontroller.h

	// typedef enum SDL_GameControllerType

	const CONTROLLER_TYPE_UNKNOWN = 0 ;
	const CONTROLLER_TYPE_XBOX360 = 1 ;
	const CONTROLLER_TYPE_XBOXONE = 2 ;
	const CONTROLLER_TYPE_PS3     = 3 ;
	const CONTROLLER_TYPE_PS4     = 4 ;
	const CONTROLLER_TYPE_NINTENDO_SWITCH_PRO = 5 ;
	const CONTROLLER_TYPE_VIRTUAL = 6 ;
	const CONTROLLER_TYPE_PS5     = 7 ;


	// typedef enum SDL_GameControllerBindType;

	const CONTROLLER_BINDTYPE_NONE   = 0 ;
	const CONTROLLER_BINDTYPE_BUTTON = 1 ;
	const CONTROLLER_BINDTYPE_AXIS   = 2 ;
	const CONTROLLER_BINDTYPE_HAT    = 3 ;


	// typedef enum SDL_GameControllerAxis;

	const CONTROLLER_AXIS_INVALID      = -1 ;
	const CONTROLLER_AXIS_LEFTX        =  0 ;
	const CONTROLLER_AXIS_LEFTY        =  1 ;
	const CONTROLLER_AXIS_RIGHTX       =  2 ;
	const CONTROLLER_AXIS_RIGHTY       =  3 ;
	const CONTROLLER_AXIS_TRIGGERLEFT  =  4 ;
	const CONTROLLER_AXIS_TRIGGERRIGHT =  5 ;
	const CONTROLLER_AXIS_MAX          =  6 ;


	// typedef enum SDL_GameControllerButton;

	const CONTROLLER_BUTTON_INVALID       = -1 ;
	const CONTROLLER_BUTTON_A             = 0 ;
	const CONTROLLER_BUTTON_B             = 1 ;
	const CONTROLLER_BUTTON_X             = 2 ;
	const CONTROLLER_BUTTON_Y             = 3 ;
	const CONTROLLER_BUTTON_BACK          = 4 ;
	const CONTROLLER_BUTTON_GUIDE         = 5 ;
	const CONTROLLER_BUTTON_START         = 6 ;
	const CONTROLLER_BUTTON_LEFTSTICK     = 7 ;
	const CONTROLLER_BUTTON_RIGHTSTICK    = 8 ;
	const CONTROLLER_BUTTON_LEFTSHOULDER  = 9 ;
	const CONTROLLER_BUTTON_RIGHTSHOULDER = 10 ;
	const CONTROLLER_BUTTON_DPAD_UP       = 11 ;
	const CONTROLLER_BUTTON_DPAD_DOWN     = 12 ;
	const CONTROLLER_BUTTON_DPAD_LEFT     = 13 ;
	const CONTROLLER_BUTTON_DPAD_RIGHT    = 14 ;
	const CONTROLLER_BUTTON_MISC1         = 15 ;
	const CONTROLLER_BUTTON_PADDLE1       = 16 ;
	const CONTROLLER_BUTTON_PADDLE2       = 17 ;
	const CONTROLLER_BUTTON_PADDLE3       = 18 ;
	const CONTROLLER_BUTTON_PADDLE4       = 19 ;
	const CONTROLLER_BUTTON_TOUCHPAD      = 20 ;
	const CONTROLLER_BUTTON_MAX           = 21 ;

	//--------------------------------------------
	// SDL_haptic.h

	const HAPTIC_CONSTANT     = (1<< 0) ;
	const HAPTIC_SINE         = (1<< 1) ;
	const HAPTIC_LEFTRIGHT    = (1<< 2) ;
	const HAPTIC_TRIANGLE     = (1<< 3) ;
	const HAPTIC_SAWTOOTHUP   = (1<< 4) ;
	const HAPTIC_SAWTOOTHDOWN = (1<< 5) ;
	const HAPTIC_RAMP         = (1<< 6) ;
	const HAPTIC_SPRING       = (1<< 7) ;
	const HAPTIC_DAMPER       = (1<< 8) ;
	const HAPTIC_INERTIA      = (1<< 9) ;
	const HAPTIC_FRICTION     = (1<<10) ;
	const HAPTIC_CUSTOM       = (1<<11) ;
	const HAPTIC_GAIN         = (1<<12) ;
	const HAPTIC_AUTOCENTER   = (1<<13) ;
	const HAPTIC_STATUS       = (1<<14) ;
	const HAPTIC_PAUSE        = (1<<15) ;

	const HAPTIC_POLAR         = 0 ;
	const HAPTIC_CARTESIAN     = 1 ;
	const HAPTIC_SPHERICAL     = 2 ;
	const HAPTIC_STEERING_AXIS = 3 ;

	const HAPTIC_INFINITY      = 4294967295 ;

	//---------------------------------------------
	// SDL_mutex.h

	const MUTEX_TIMEDOUT  = 1 ;
	const MUTEX_MAXWAIT   = 0xFFffFFff ; // (~(Uint32)0)


	//---------------------------------------------
	// SDL_audio.h

	const AUDIO_MASK_BITSIZE       = (0xFF) ;
	const AUDIO_MASK_DATATYPE      = (1<<8) ;
	const AUDIO_MASK_ENDIAN        = (1<<12);
	const AUDIO_MASK_SIGNED        = (1<<15);

	public static function AUDIO_BITSIZE       ( int $x ) : int { return ( $x & static::AUDIO_MASK_BITSIZE      ); }
	public static function AUDIO_ISFLOAT       ( int $x ) : int { return ( $x & static::AUDIO_MASK_DATATYPE     ); }
	public static function AUDIO_ISBIGENDIAN   ( int $x ) : int { return ( $x & static::AUDIO_MASK_ENDIAN       ); }
	public static function AUDIO_ISSIGNED      ( int $x ) : int { return ( $x & static::AUDIO_MASK_SIGNED       ); }
	public static function AUDIO_ISINT         ( int $x ) : int { return (    ! static::AUDIO_ISFLOAT    ( $x ) ); }
	public static function AUDIO_ISLITTLEENDIAN( int $x ) : int { return (    ! static::AUDIO_ISBIGENDIAN( $x ) ); }
	public static function AUDIO_ISUNSIGNED    ( int $x ) : int { return (    ! static::AUDIO_ISSIGNED   ( $x ) ); }

	static $AUDIO = [];

	private static function _init_AUDIO_formats()
	{
		static::$AUDIO['U8'    ] = 0x0008 ;
		static::$AUDIO['S8'    ] = 0x8008 ;
		static::$AUDIO['U16LSB'] = 0x0010 ;
		static::$AUDIO['S16LSB'] = 0x8010 ;
		static::$AUDIO['U16MSB'] = 0x1010 ;
		static::$AUDIO['S16MSB'] = 0x9010 ;
		static::$AUDIO['U16'   ] = static::$AUDIO['U16LSB'];
		static::$AUDIO['S16'   ] = static::$AUDIO['S16LSB'];

		static::$AUDIO['S32LSB'] = 0x8020 ;
		static::$AUDIO['S32MSB'] = 0x9020 ;
		static::$AUDIO['S32'   ] = static::$AUDIO['S32LSB'];

		static::$AUDIO['F32LSB'] = 0x8120 ;
		static::$AUDIO['F32MSB'] = 0x9120 ;
		static::$AUDIO['F32'   ] = static::$AUDIO['F32LSB'];

		if ( static::BYTEORDER() == SDL::LIL_ENDIAN )
		{
			static::$AUDIO['U16SYS'] = static::$AUDIO['U16LSB'];
			static::$AUDIO['S16SYS'] = static::$AUDIO['S16LSB'];
			static::$AUDIO['S32SYS'] = static::$AUDIO['S32LSB'];
			static::$AUDIO['F32SYS'] = static::$AUDIO['F32LSB'];
		}
		else
		{
			static::$AUDIO['U16SYS'] = static::$AUDIO['U16MSB'];
			static::$AUDIO['S16SYS'] = static::$AUDIO['S16MSB'];
			static::$AUDIO['S32SYS'] = static::$AUDIO['S32MSB'];
			static::$AUDIO['F32SYS'] = static::$AUDIO['F32MSB'];
		}
	}


	const AUDIO_ALLOW_FREQUENCY_CHANGE = 0x00000001 ;
	const AUDIO_ALLOW_FORMAT_CHANGE    = 0x00000002 ;
	const AUDIO_ALLOW_CHANNELS_CHANGE  = 0x00000004 ;
	const AUDIO_ALLOW_SAMPLES_CHANGE   = 0x00000008 ;
	const AUDIO_ALLOW_ANY_CHANGE       = ( self::AUDIO_ALLOW_FREQUENCY_CHANGE | self::AUDIO_ALLOW_FORMAT_CHANGE | self::AUDIO_ALLOW_CHANNELS_CHANGE | self::AUDIO_ALLOW_SAMPLES_CHANGE );


	//---------------------------------------
	// SDL_timer.h

	public static function TICKS_PASSED( int $A , int $B ) : int { return ( ( $B - $A ) <= 0 ); }


	//---------------------------------------
	// SDL_cpuinfo.h

	const CACHELINE_SIZE = 128 ;


	//---------------------------------------
	// SDL_power.h

	// typedef enum SDL_PowerState;

	const POWERSTATE_UNKNOWN    = 0 ;
	const POWERSTATE_ON_BATTERY = 1 ;
	const POWERSTATE_NO_BATTERY = 2 ;
	const POWERSTATE_CHARGING   = 3 ;
	const POWERSTATE_CHARGED    = 4 ;


	//---------------------------------------
	// SDL_events.h

	const RELEASED = 0 ;
	const PRESSED  = 1 ;

	const TEXTEDITINGEVENT_TEXT_SIZE = 32 ;
	const TEXTINPUTEVENT_TEXT_SIZE   = 32 ;

	// typedef enum SDL_EventType;

	const FIRSTEVENT              = 0 ;

	const QUIT                    = 0x100 ;
	const APP_TERMINATING         = 0x101 ;
	const APP_LOWMEMORY           = 0x102 ;
	const APP_WILLENTERBACKGROUND = 0x103 ;
	const APP_DIDENTERBACKGROUND  = 0x104 ;
	const APP_WILLENTERFOREGROUND = 0x105 ;
	const APP_DIDENTERFOREGROUND  = 0x106 ;
	const LOCALECHANGED           = 0x107 ;

	const DISPLAYEVENT            = 0x150 ;

	const WINDOWEVENT             = 0x200 ;
	const SYSWMEVENT              = 0x201 ;

	const KEYDOWN                 = 0x300 ;
	const KEYUP                   = 0x301 ;
	const TEXTEDITING             = 0x302 ;
	const TEXTINPUT               = 0x303 ;
	const KEYMAPCHANGED           = 0x304 ;

	const MOUSEMOTION             = 0x400 ;
	const MOUSEBUTTONDOWN         = 0x401 ;
	const MOUSEBUTTONUP           = 0x402 ;
	const MOUSEWHEEL              = 0x403 ;

	const JOYAXISMOTION           = 0x600 ;
	const JOYBALLMOTION           = 0x601 ;
	const JOYHATMOTION            = 0x602 ;
	const JOYBUTTONDOWN           = 0x603 ;
	const JOYBUTTONUP             = 0x604 ;
	const JOYDEVICEADDED          = 0x605 ;
	const JOYDEVICEREMOVED        = 0x606 ;

	const CONTROLLERAXISMOTION    = 0x650 ;
	const CONTROLLERBUTTONDOWN    = 0x651 ;
	const CONTROLLERBUTTONUP      = 0x652 ;
	const CONTROLLERDEVICEADDED   = 0x653 ;
	const CONTROLLERDEVICEREMOVED = 0x654 ;
	const CONTROLLERDEVICEREMAPPED= 0x655 ;
	const CONTROLLERTOUCHPADDOWN  = 0x656 ;
	const CONTROLLERTOUCHPADMOTION= 0x657 ;
	const CONTROLLERTOUCHPADUP    = 0x658 ;
	const CONTROLLERSENSORUPDATE  = 0x659 ;

	const FINGERDOWN              = 0x700 ;
	const FINGERUP                = 0x701 ;
	const FINGERMOTION            = 0x702 ;

	const DOLLARGESTURE           = 0x800 ;
	const DOLLARRECORD            = 0x801 ;
	const MULTIGESTURE            = 0x802 ;

	const CLIPBOARDUPDATE         = 0x900 ;

	const DROPFILE                = 0x1000 ;
	const DROPTEXT                = 0x1001 ;
	const DROPBEGIN               = 0x1002 ;
	const DROPCOMPLETE            = 0x1003 ;

	const AUDIODEVICEADDED        = 0x1100 ;
	const AUDIODEVICEREMOVED      = 0x1101 ;

	const SENSORUPDATE            = 0x1200 ;

	const RENDER_TARGETS_RESET    = 0x2000 ;
	const RENDER_DEVICE_RESET     = 0x2001 ;

	const USEREVENT               = 0x8000 ;

	const LASTEVENT               = 0xFFFF ;


	// typedef enum SDL_eventaction;

	const ADDEVENT = 0 ;
	const PEEKEVENT= 1 ;
	const GETEVENT = 2 ;


	// ---

	const QUERY   = -1 ;
	const IGNORE  =  0 ;
	const DISABLE =  0 ;
	const ENABLE  =  1 ;

	public static function GetEventState( int $type ) : int { return static::EventState( $type , static::QUERY ); }



	//----------------------------------------------------------------------------------
	// FFI initialisation
	//----------------------------------------------------------------------------------

	public static $ffi;

	public static function SDL()
	{
		if ( static::$ffi ) 
		{ 
			debug_print_backtrace();
			exit("SDL::SDL() already init".PHP_EOL); 
		}
		
		$cdef = __DIR__ . '/SDL.ffi.php.h';
		
		$lib_dir = defined('FFI_LIB_DIR') ? FFI_LIB_DIR : 'lib' ;
		
		$slib = "./$lib_dir/".match( PHP_OS_FAMILY ) 
		{
			'Linux'   => 'libSDL2.so',
			'Windows' => 'SDL2.dll',
		};
		
		static::$ffi = FFI::cdef( file_get_contents( $cdef ) , $slib );
		
		
		static::_init_SDL_PixelFormatEnum();
		static::_init_SDL_KeyCode();
		static::_init_AUDIO_formats();
	}


	public static function __callStatic( string $method , array $args ) : mixed
	{
		$callable = [static::$ffi, 'SDL_'.$method];
		return $callable(...$args);
	}


	//----------------------------------------------------------------------------------
	// Helpers
	//---------------------------------------------------------------------------------

	// void SDL_GetWindowSize(SDL_Window * window, int *w, int *h);
	public static function GetWindowSize( object $window ) : array
	{
		$w = FFI::new("int[1]");
		$h = FFI::new("int[1]");

		static::$ffi->SDL_GetWindowSize( $window , FFI::addr( $w[0] ) , FFI::addr( $h[0] ) );

		return [ $w[0] , $h[0] ];
	}

	// void SDL_GL_GetDrawableSize(SDL_Window * window, int *w, int *h);
	public static function GL_GetDrawableSize( object $window ) : array
	{
		$w = FFI::new("int[1]");
		$h = FFI::new("int[1]");

		static::$ffi->SDL_GL_GetDrawableSize( $window , FFI::addr( $w[0] ) , FFI::addr( $h[0] ) );

		return [ $w[0] , $h[0] ];
	}

	// Uint32 SDL_GetMouseState(int *x, int *y);
	public static function GetMouseState() : array
	{
		$x = FFI::new("int[1]");
		$y = FFI::new("int[1]");

		$state = static::$ffi->SDL_GetMouseState( FFI::addr( $x[0] ) , FFI::addr( $y[0] ) );

		return [ $state , $x[0] , $y[0] ];
	}

	// Uint32 SDL_GetGlobalMouseState(int *x, int *y);
	public static function GetGlobalMouseState() : array
	{
		$x = FFI::new("int[1]");
		$y = FFI::new("int[1]");

		$state = static::$ffi->SDL_GetGlobalMouseState( FFI::addr( $x[0] ) , FFI::addr( $y[0] ) );

		return [ $state , $x[0] , $y[0] ];
	}

	// Uint32 SDL_GetRelativeMouseState(int *x, int *y);
	public static function GetRelativeMouseState() : array
	{
		$x = FFI::new("int[1]");
		$y = FFI::new("int[1]");

		$state = static::$ffi->SDL_GetRelativeMouseState( FFI::addr( $x[0] ) , FFI::addr( $y[0] ) );

		return [ $state , $x[0] , $y[0] ];
	}

	// const Uint8 *SDL_GetKeyboardState(int *numkeys);
	public static function GetKeyboardState() : array
	{
		$len = FFI::new("int[1]");

		$state = static::$ffi->SDL_GetKeyboardState( FFI::addr( $len[0] ) );

		return [ $state , $len[0] ];
	}

};
