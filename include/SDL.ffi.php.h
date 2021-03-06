//#define FFI_LIB "./lib/libSDL2.so"


/////////////////////////////////////////////////////////////////
// SDL 2.0 API by Category
/////////////////////////////////////////////////////////////////


typedef      int SDL_bool;

typedef   int8_t Sint8;
typedef  uint8_t Uint8;

typedef  int16_t Sint16;
typedef uint16_t Uint16;

typedef  int32_t Sint32;
typedef uint32_t Uint32;

typedef  int64_t Sint64;
typedef uint64_t Uint64;

//==============================================================
// Basics
//==============================================================

//--------------------------------------------------------------
// Initialisation and Shutdown : SDL.h
//--------------------------------------------------------------

int    SDL_Init(Uint32 flags);
int    SDL_InitSubSystem(Uint32 flags);
void   SDL_QuitSubSystem(Uint32 flags);
Uint32 SDL_WasInit(Uint32 flags);
void   SDL_Quit(void);

//--------------------------------------------------------------
// Configuration Variables : SDL_hints.h
//--------------------------------------------------------------

typedef enum
{
	SDL_HINT_DEFAULT,
	SDL_HINT_NORMAL,
	SDL_HINT_OVERRIDE

} SDL_HintPriority;


SDL_bool SDL_SetHintWithPriority(const char *name, const char *value, SDL_HintPriority priority);
SDL_bool SDL_SetHint(const char *name, const char *value);
const char * SDL_GetHint(const char *name);
SDL_bool SDL_GetHintBoolean(const char *name, SDL_bool default_value);
typedef void (*SDL_HintCallback)(void *userdata, const char *name, const char *oldValue, const char *newValue);
void SDL_AddHintCallback(const char *name, SDL_HintCallback callback, void *userdata);
void SDL_DelHintCallback(const char *name, SDL_HintCallback callback, void *userdata);
void SDL_ClearHints(void);

//--------------------------------------------------------------
// Error Handling : SDL_error.h
//--------------------------------------------------------------

typedef enum
{
	SDL_ENOMEM,
	SDL_EFREAD,
	SDL_EFWRITE,
	SDL_EFSEEK,
	SDL_UNSUPPORTED,
	SDL_LASTERROR

} SDL_errorcode;

int          SDL_SetError(const char *fmt, ...);
const char * SDL_GetError(void);
char *       SDL_GetErrorMsg(char *errstr, int maxlen);
void         SDL_ClearError(void);
int          SDL_Error(SDL_errorcode code);

//#define SDL_OutOfMemory()   SDL_Error(SDL_ENOMEM) // TODO ?
//#define SDL_Unsupported()   SDL_Error(SDL_UNSUPPORTED) // TODO ?
//#define SDL_InvalidParamError(param)    SDL_SetError("Parameter '%s' is invalid", (param)) // TODO ?


//--------------------------------------------------------------
// Log Handling : SDL_log.h
//--------------------------------------------------------------

typedef enum
{
	SDL_LOG_CATEGORY_APPLICATION,
	SDL_LOG_CATEGORY_ERROR,
	SDL_LOG_CATEGORY_ASSERT,
	SDL_LOG_CATEGORY_SYSTEM,
	SDL_LOG_CATEGORY_AUDIO,
	SDL_LOG_CATEGORY_VIDEO,
	SDL_LOG_CATEGORY_RENDER,
	SDL_LOG_CATEGORY_INPUT,
	SDL_LOG_CATEGORY_TEST,


	SDL_LOG_CATEGORY_RESERVED1,
	SDL_LOG_CATEGORY_RESERVED2,
	SDL_LOG_CATEGORY_RESERVED3,
	SDL_LOG_CATEGORY_RESERVED4,
	SDL_LOG_CATEGORY_RESERVED5,
	SDL_LOG_CATEGORY_RESERVED6,
	SDL_LOG_CATEGORY_RESERVED7,
	SDL_LOG_CATEGORY_RESERVED8,
	SDL_LOG_CATEGORY_RESERVED9,
	SDL_LOG_CATEGORY_RESERVED10,


	SDL_LOG_CATEGORY_CUSTOM
} SDL_LogCategory;


typedef enum
{
	SDL_LOG_PRIORITY_VERBOSE = 1,
	SDL_LOG_PRIORITY_DEBUG,
	SDL_LOG_PRIORITY_INFO,
	SDL_LOG_PRIORITY_WARN,
	SDL_LOG_PRIORITY_ERROR,
	SDL_LOG_PRIORITY_CRITICAL,
	SDL_NUM_LOG_PRIORITIES
} SDL_LogPriority;


void SDL_LogSetAllPriority(SDL_LogPriority priority);
void SDL_LogSetPriority(int category, SDL_LogPriority priority);
SDL_LogPriority SDL_LogGetPriority(int category);
void SDL_LogResetPriorities(void);
void SDL_Log(const char *fmt, ...);
void SDL_LogVerbose(int category, const char *fmt, ...);
void SDL_LogDebug(int category, const char *fmt, ...);
void SDL_LogInfo(int category, const char *fmt, ...);
void SDL_LogWarn(int category, const char *fmt, ...);
void SDL_LogError(int category, const char *fmt, ...);
void SDL_LogCritical(int category, const char *fmt, ...);
void SDL_LogMessage(int category, SDL_LogPriority priority, const char *fmt, ...);
void SDL_LogMessageV(int category, SDL_LogPriority priority, const char *fmt, va_list ap);

typedef void (*SDL_LogOutputFunction)(void *userdata, int category, SDL_LogPriority priority, const char *message);

void SDL_LogGetOutputFunction(SDL_LogOutputFunction *callback, void **userdata);
void SDL_LogSetOutputFunction(SDL_LogOutputFunction  callback, void  *userdata);

//--------------------------------------------------------------
// Assertions : SDL_assert.h
//--------------------------------------------------------------

 // TODO ?

//--------------------------------------------------------------
// Querying SDL Version : SDL_version.h
//--------------------------------------------------------------

typedef struct SDL_version
{
	Uint8 major;
	Uint8 minor;
	Uint8 patch;
} SDL_version;


#define SDL_MAJOR_VERSION   2
#define SDL_MINOR_VERSION   0
#define SDL_PATCHLEVEL      14


//#define SDL_VERSION(x)                          \
//{                                   \
//	(x)->major = SDL_MAJOR_VERSION;                 \
//	(x)->minor = SDL_MINOR_VERSION;                 \
//	(x)->patch = SDL_PATCHLEVEL;                    \
//} // TODO ?
//
//
//#define SDL_VERSIONNUM(X, Y, Z)                     \
//	((X)*1000 + (Y)*100 + (Z)) // TODO ?
//
//
//#define SDL_COMPILEDVERSION \
//	SDL_VERSIONNUM(SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL) // TODO ?
//
//
//#define SDL_VERSION_ATLEAST(X, Y, Z) \
//	(SDL_COMPILEDVERSION >= SDL_VERSIONNUM(X, Y, Z)) // TODO ?
//

void SDL_GetVersion(SDL_version * ver);
const char * SDL_GetRevision(void);
int SDL_GetRevisionNumber(void);


//==============================================================
// Video
//==============================================================


//--------------------------------------------------------------
// Rectangle Functions : SDL_rect.h
//--------------------------------------------------------------

typedef struct SDL_Point
{
	int x;
	int y;
} SDL_Point;


typedef struct SDL_FPoint
{
	float x;
	float y;
} SDL_FPoint;



typedef struct SDL_Rect
{
	int x, y;
	int w, h;
} SDL_Rect;



typedef struct SDL_FRect
{
	float x;
	float y;
	float w;
	float h;
} SDL_FRect;



//SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point *p, const SDL_Rect *r) // TODO ?
//{
//	return ( (p->x >= r->x) && (p->x < (r->x + r->w)) &&
//	         (p->y >= r->y) && (p->y < (r->y + r->h)) ) ? SDL_TRUE : SDL_FALSE;
//}
//
//
//SDL_FORCE_INLINE SDL_bool SDL_RectEmpty(const SDL_Rect *r) // TODO ?
//{
//	return ((!r) || (r->w <= 0) || (r->h <= 0)) ? SDL_TRUE : SDL_FALSE;
//}
//
//
//SDL_FORCE_INLINE SDL_bool SDL_RectEquals(const SDL_Rect *a, const SDL_Rect *b) // TODO ?
//{
//	return (a && b && (a->x == b->x) && (a->y == b->y) &&
//	        (a->w == b->w) && (a->h == b->h)) ? SDL_TRUE : SDL_FALSE;
//}
//

SDL_bool SDL_HasIntersection(const SDL_Rect * A, const SDL_Rect * B);
SDL_bool SDL_IntersectRect(const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result);
void SDL_UnionRect(const SDL_Rect * A, const SDL_Rect * B, SDL_Rect * result);
SDL_bool SDL_EnclosePoints(const SDL_Point * points, int count, const SDL_Rect * clip, SDL_Rect * result);
SDL_bool SDL_IntersectRectAndLine(const SDL_Rect * rect, int *X1, int *Y1, int *X2, int *Y2);

//--------------------------------------------------------------
// Pixel Formats and Conversion Routines : SDL_pixels.h
//--------------------------------------------------------------

#define SDL_ALPHA_OPAQUE 255
#define SDL_ALPHA_TRANSPARENT 0

typedef enum
{
	SDL_PIXELTYPE_UNKNOWN,
	SDL_PIXELTYPE_INDEX1,
	SDL_PIXELTYPE_INDEX4,
	SDL_PIXELTYPE_INDEX8,
	SDL_PIXELTYPE_PACKED8,
	SDL_PIXELTYPE_PACKED16,
	SDL_PIXELTYPE_PACKED32,
	SDL_PIXELTYPE_ARRAYU8,
	SDL_PIXELTYPE_ARRAYU16,
	SDL_PIXELTYPE_ARRAYU32,
	SDL_PIXELTYPE_ARRAYF16,
	SDL_PIXELTYPE_ARRAYF32
} SDL_PixelType;


typedef enum
{
	SDL_BITMAPORDER_NONE,
	SDL_BITMAPORDER_4321,
	SDL_BITMAPORDER_1234
} SDL_BitmapOrder;


typedef enum
{
	SDL_PACKEDORDER_NONE,
	SDL_PACKEDORDER_XRGB,
	SDL_PACKEDORDER_RGBX,
	SDL_PACKEDORDER_ARGB,
	SDL_PACKEDORDER_RGBA,
	SDL_PACKEDORDER_XBGR,
	SDL_PACKEDORDER_BGRX,
	SDL_PACKEDORDER_ABGR,
	SDL_PACKEDORDER_BGRA
} SDL_PackedOrder;



typedef enum
{
	SDL_ARRAYORDER_NONE,
	SDL_ARRAYORDER_RGB,
	SDL_ARRAYORDER_RGBA,
	SDL_ARRAYORDER_ARGB,
	SDL_ARRAYORDER_BGR,
	SDL_ARRAYORDER_BGRA,
	SDL_ARRAYORDER_ABGR
} SDL_ArrayOrder;


typedef enum
{
	SDL_PACKEDLAYOUT_NONE,
	SDL_PACKEDLAYOUT_332,
	SDL_PACKEDLAYOUT_4444,
	SDL_PACKEDLAYOUT_1555,
	SDL_PACKEDLAYOUT_5551,
	SDL_PACKEDLAYOUT_565,
	SDL_PACKEDLAYOUT_8888,
	SDL_PACKEDLAYOUT_2101010,
	SDL_PACKEDLAYOUT_1010102
} SDL_PackedLayout;

//#define SDL_DEFINE_PIXELFOURCC(A, B, C, D) SDL_FOURCC(A, B, C, D)
//
//#define SDL_DEFINE_PIXELFORMAT(type, order, layout, bits, bytes) \
//	((1 << 28) | ((type) << 24) | ((order) << 20) | ((layout) << 16) | \
//	 ((bits) << 8) | ((bytes) << 0))
//
//#define SDL_PIXELFLAG(X)    (((X) >> 28) & 0x0F)
//#define SDL_PIXELTYPE(X)    (((X) >> 24) & 0x0F)
//#define SDL_PIXELORDER(X)   (((X) >> 20) & 0x0F)
//#define SDL_PIXELLAYOUT(X)  (((X) >> 16) & 0x0F)
//#define SDL_BITSPERPIXEL(X) (((X) >> 8) & 0xFF)
//#define SDL_BYTESPERPIXEL(X) \
//	(SDL_ISPIXELFORMAT_FOURCC(X) ? \
//	    ((((X) == SDL_PIXELFORMAT_YUY2) || \
//	      ((X) == SDL_PIXELFORMAT_UYVY) || \
//	      ((X) == SDL_PIXELFORMAT_YVYU)) ? 2 : 1) : (((X) >> 0) & 0xFF))
//
//#define SDL_ISPIXELFORMAT_INDEXED(format)   \
//	(!SDL_ISPIXELFORMAT_FOURCC(format) && \
//	 ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX1) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX4) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_INDEX8)))
//
//#define SDL_ISPIXELFORMAT_PACKED(format) \
//	(!SDL_ISPIXELFORMAT_FOURCC(format) && \
//	 ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED8) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED16) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_PACKED32)))
//
//#define SDL_ISPIXELFORMAT_ARRAY(format) \
//	(!SDL_ISPIXELFORMAT_FOURCC(format) && \
//	 ((SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU8) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU16) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYU32) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYF16) || \
//	  (SDL_PIXELTYPE(format) == SDL_PIXELTYPE_ARRAYF32)))
//
//#define SDL_ISPIXELFORMAT_ALPHA(format)   \
//	((SDL_ISPIXELFORMAT_PACKED(format) && \
//	 ((SDL_PIXELORDER(format) == SDL_PACKEDORDER_ARGB) || \
//	  (SDL_PIXELORDER(format) == SDL_PACKEDORDER_RGBA) || \
//	  (SDL_PIXELORDER(format) == SDL_PACKEDORDER_ABGR) || \
//	  (SDL_PIXELORDER(format) == SDL_PACKEDORDER_BGRA))) || \
//	(SDL_ISPIXELFORMAT_ARRAY(format) && \
//	 ((SDL_PIXELORDER(format) == SDL_ARRAYORDER_ARGB) || \
//	  (SDL_PIXELORDER(format) == SDL_ARRAYORDER_RGBA) || \
//	  (SDL_PIXELORDER(format) == SDL_ARRAYORDER_ABGR) || \
//	  (SDL_PIXELORDER(format) == SDL_ARRAYORDER_BGRA))))
//
//
//#define SDL_ISPIXELFORMAT_FOURCC(format)    \
//	((format) && (SDL_PIXELFLAG(format) != 1))
//

typedef enum SDL_PixelFormatEnum;

typedef struct SDL_Color
{
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
} SDL_Color;

//#define SDL_Colour SDL_Color // TODO ?

typedef struct SDL_Palette
{
	int ncolors;
	SDL_Color *colors;
	Uint32 version;
	int refcount;
} SDL_Palette;


typedef struct SDL_PixelFormat
{
	Uint32 format;
	SDL_Palette *palette;
	Uint8 BitsPerPixel;
	Uint8 BytesPerPixel;
	Uint8 padding[2];
	Uint32 Rmask;
	Uint32 Gmask;
	Uint32 Bmask;
	Uint32 Amask;
	Uint8 Rloss;
	Uint8 Gloss;
	Uint8 Bloss;
	Uint8 Aloss;
	Uint8 Rshift;
	Uint8 Gshift;
	Uint8 Bshift;
	Uint8 Ashift;
	int refcount;
	struct SDL_PixelFormat *next;
} SDL_PixelFormat;


const char* SDL_GetPixelFormatName(Uint32 format);
SDL_bool SDL_PixelFormatEnumToMasks(Uint32 format, int *bpp, Uint32 * Rmask, Uint32 * Gmask, Uint32 * Bmask, Uint32 * Amask);
Uint32 SDL_MasksToPixelFormatEnum(int bpp, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
SDL_PixelFormat * SDL_AllocFormat(Uint32 pixel_format);
void SDL_FreeFormat(SDL_PixelFormat *format);
SDL_Palette *SDL_AllocPalette(int ncolors);
int SDL_SetPixelFormatPalette(SDL_PixelFormat * format, SDL_Palette *palette);
int SDL_SetPaletteColors(SDL_Palette * palette, const SDL_Color * colors, int firstcolor, int ncolors);
void SDL_FreePalette(SDL_Palette * palette);
Uint32 SDL_MapRGB(const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b);
Uint32 SDL_MapRGBA(const SDL_PixelFormat * format, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void SDL_GetRGB(Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b);
void SDL_GetRGBA(Uint32 pixel, const SDL_PixelFormat * format, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a);
void SDL_CalculateGammaRamp(float gamma, Uint16 * ramp);

//--------------------------------------------------------------
// Surface Creation andSimple Drawing : SDL_surface.h
//--------------------------------------------------------------


typedef enum
{
	SDL_BLENDMODE_NONE    = 0x00000000,
	SDL_BLENDMODE_BLEND   = 0x00000001,
	SDL_BLENDMODE_ADD     = 0x00000002,
	SDL_BLENDMODE_MOD     = 0x00000004,
	SDL_BLENDMODE_MUL     = 0x00000008,
	SDL_BLENDMODE_INVALID = 0x7FFFFFFF

} SDL_BlendMode;


typedef enum
{
	SDL_BLENDOPERATION_ADD              = 0x1,
	SDL_BLENDOPERATION_SUBTRACT         = 0x2,
	SDL_BLENDOPERATION_REV_SUBTRACT     = 0x3,
	SDL_BLENDOPERATION_MINIMUM          = 0x4,
	SDL_BLENDOPERATION_MAXIMUM          = 0x5

} SDL_BlendOperation;


typedef enum
{
	SDL_BLENDFACTOR_ZERO                = 0x1,
	SDL_BLENDFACTOR_ONE                 = 0x2,
	SDL_BLENDFACTOR_SRC_COLOR           = 0x3,
	SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR = 0x4,
	SDL_BLENDFACTOR_SRC_ALPHA           = 0x5,
	SDL_BLENDFACTOR_ONE_MINUS_SRC_ALPHA = 0x6,
	SDL_BLENDFACTOR_DST_COLOR           = 0x7,
	SDL_BLENDFACTOR_ONE_MINUS_DST_COLOR = 0x8,
	SDL_BLENDFACTOR_DST_ALPHA           = 0x9,
	SDL_BLENDFACTOR_ONE_MINUS_DST_ALPHA = 0xA

} SDL_BlendFactor;


SDL_BlendMode SDL_ComposeCustomBlendMode(
		SDL_BlendFactor srcColorFactor    ,
		SDL_BlendFactor dstColorFactor    ,
		SDL_BlendOperation colorOperation ,
		SDL_BlendFactor srcAlphaFactor    ,
		SDL_BlendFactor dstAlphaFactor    ,
	 	SDL_BlendOperation alphaOperation );


#define SDL_SWSURFACE       0
#define SDL_PREALLOC        0x00000001
#define SDL_RLEACCEL        0x00000002
#define SDL_DONTFREE        0x00000004
#define SDL_SIMD_ALIGNED    0x00000008

#define SDL_MUSTLOCK(S) (((S)->flags & SDL_RLEACCEL) != 0)


typedef struct SDL_Surface
{
	Uint32 flags;
	SDL_PixelFormat *format;
	int w, h;
	int pitch;
	void *pixels;
	void *userdata;
	int locked;
	void *list_blitmap;
	SDL_Rect clip_rect;
	struct SDL_BlitMap *map;
	int refcount;
} SDL_Surface;


typedef int (*SDL_blit) (struct SDL_Surface * src, SDL_Rect * srcrect, struct SDL_Surface * dst, SDL_Rect * dstrect);

typedef enum
{
	SDL_YUV_CONVERSION_JPEG,
	SDL_YUV_CONVERSION_BT601,
	SDL_YUV_CONVERSION_BT709,
	SDL_YUV_CONVERSION_AUTOMATIC
} SDL_YUV_CONVERSION_MODE;


SDL_Surface *SDL_CreateRGBSurface( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
SDL_Surface *SDL_CreateRGBSurfaceWithFormat(Uint32 flags, int width, int height, int depth, Uint32 format);
SDL_Surface *SDL_CreateRGBSurfaceFrom(void *pixels,int width,int height,int depth,int pitch,Uint32 Rmask,Uint32 Gmask,Uint32 Bmask,Uint32 Amask);
SDL_Surface *SDL_CreateRGBSurfaceWithFormatFrom(void *pixels, int width, int height, int depth, int pitch, Uint32 format);
void SDL_FreeSurface(SDL_Surface * surface);
int SDL_SetSurfacePalette(SDL_Surface * surface,SDL_Palette * palette);
int SDL_LockSurface(SDL_Surface * surface);
void SDL_UnlockSurface(SDL_Surface * surface);
//SDL_Surface *SDL_LoadBMP_RW(SDL_RWops * src,int freesrc); // TODO ?
//#define SDL_LoadBMP(file)   SDL_LoadBMP_RW(SDL_RWFromFile(file, "rb"), 1) // TODO ?
//int SDL_SaveBMP_RW(SDL_Surface * surface, SDL_RWops * dst, int freedst); // TODO ?
//#define SDL_SaveBMP(surface, file) SDL_SaveBMP_RW(surface, SDL_RWFromFile(file, "wb"), 1) // TODO ?
int SDL_SetSurfaceRLE(SDL_Surface * surface,int flag);
SDL_bool SDL_HasSurfaceRLE(SDL_Surface * surface);
int SDL_SetColorKey(SDL_Surface * surface,int flag, Uint32 key);
SDL_bool SDL_HasColorKey(SDL_Surface * surface);
int SDL_GetColorKey(SDL_Surface * surface,Uint32 * key);
int SDL_SetSurfaceColorMod(SDL_Surface * surface,Uint8 r, Uint8 g, Uint8 b);
int SDL_GetSurfaceColorMod(SDL_Surface * surface,Uint8 * r, Uint8 * g,Uint8 * b);
int SDL_SetSurfaceAlphaMod(SDL_Surface * surface,Uint8 alpha);
int SDL_GetSurfaceAlphaMod(SDL_Surface * surface,Uint8 * alpha);
int SDL_SetSurfaceBlendMode(SDL_Surface * surface,SDL_BlendMode blendMode);
int SDL_GetSurfaceBlendMode(SDL_Surface * surface,SDL_BlendMode *blendMode);
SDL_bool SDL_SetClipRect(SDL_Surface * surface,const SDL_Rect * rect);
void SDL_GetClipRect(SDL_Surface * surface,SDL_Rect * rect);
SDL_Surface *SDL_DuplicateSurface(SDL_Surface * surface);
SDL_Surface *SDL_ConvertSurface(SDL_Surface * src, const SDL_PixelFormat * fmt, Uint32 flags);
SDL_Surface *SDL_ConvertSurfaceFormat(SDL_Surface * src, Uint32 pixel_format, Uint32 flags);
int SDL_ConvertPixels(int width, int height,Uint32 src_format,const void * src, int src_pitch,Uint32 dst_format,void * dst, int dst_pitch);
int SDL_FillRect(SDL_Surface * dst, const SDL_Rect * rect, Uint32 color);
int SDL_FillRects(SDL_Surface * dst, const SDL_Rect * rects, int count, Uint32 color);
#define SDL_BlitSurface SDL_UpperBlit
int SDL_UpperBlit(SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect);
int SDL_LowerBlit(SDL_Surface * src, SDL_Rect * srcrect,SDL_Surface * dst, SDL_Rect * dstrect);
int SDL_SoftStretch(SDL_Surface * src,const SDL_Rect * srcrect,SDL_Surface * dst,const SDL_Rect * dstrect);
#define SDL_BlitScaled SDL_UpperBlitScaled
int SDL_UpperBlitScaled(SDL_Surface * src, const SDL_Rect * srcrect, SDL_Surface * dst, SDL_Rect * dstrect);
int SDL_LowerBlitScaled(SDL_Surface * src, SDL_Rect * srcrect,SDL_Surface * dst, SDL_Rect * dstrect);
void SDL_SetYUVConversionMode(SDL_YUV_CONVERSION_MODE mode);
SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionMode(void);
SDL_YUV_CONVERSION_MODE SDL_GetYUVConversionModeForResolution(int width, int height);


//--------------------------------------------------------------
// Display and Window Management : SDL_video.h
//--------------------------------------------------------------

typedef struct
{
	Uint32 format;
	int w;
	int h;
	int refresh_rate;
	void *driverdata;
} SDL_DisplayMode;

typedef struct SDL_Window SDL_Window;

typedef enum
{
	SDL_WINDOW_FULLSCREEN = 0x00000001,
	SDL_WINDOW_OPENGL = 0x00000002,
	SDL_WINDOW_SHOWN = 0x00000004,
	SDL_WINDOW_HIDDEN = 0x00000008,
	SDL_WINDOW_BORDERLESS = 0x00000010,
	SDL_WINDOW_RESIZABLE = 0x00000020,
	SDL_WINDOW_MINIMIZED = 0x00000040,
	SDL_WINDOW_MAXIMIZED = 0x00000080,
	SDL_WINDOW_INPUT_GRABBED = 0x00000100,
	SDL_WINDOW_INPUT_FOCUS = 0x00000200,
	SDL_WINDOW_MOUSE_FOCUS = 0x00000400,
	SDL_WINDOW_FULLSCREEN_DESKTOP = ( SDL_WINDOW_FULLSCREEN | 0x00001000 ),
	SDL_WINDOW_FOREIGN = 0x00000800,
	SDL_WINDOW_ALLOW_HIGHDPI = 0x00002000,
	SDL_WINDOW_MOUSE_CAPTURE = 0x00004000,
	SDL_WINDOW_ALWAYS_ON_TOP = 0x00008000,
	SDL_WINDOW_SKIP_TASKBAR  = 0x00010000,
	SDL_WINDOW_UTILITY       = 0x00020000,
	SDL_WINDOW_TOOLTIP       = 0x00040000,
	SDL_WINDOW_POPUP_MENU    = 0x00080000,
	SDL_WINDOW_VULKAN        = 0x10000000,
	SDL_WINDOW_METAL         = 0x20000000
} SDL_WindowFlags;


//#define SDL_WINDOWPOS_UNDEFINED_MASK    0x1FFF0000u
//#define SDL_WINDOWPOS_UNDEFINED_DISPLAY(X)  (SDL_WINDOWPOS_UNDEFINED_MASK|(X))
//#define SDL_WINDOWPOS_UNDEFINED         SDL_WINDOWPOS_UNDEFINED_DISPLAY(0)
//#define SDL_WINDOWPOS_ISUNDEFINED(X)    \
//	        (((X)&0xFFFF0000) == SDL_WINDOWPOS_UNDEFINED_MASK)
//
//
//#define SDL_WINDOWPOS_CENTERED_MASK    0x2FFF0000u
//#define SDL_WINDOWPOS_CENTERED_DISPLAY(X)  (SDL_WINDOWPOS_CENTERED_MASK|(X))
//#define SDL_WINDOWPOS_CENTERED         SDL_WINDOWPOS_CENTERED_DISPLAY(0)
//#define SDL_WINDOWPOS_ISCENTERED(X)    \
//	        (((X)&0xFFFF0000) == SDL_WINDOWPOS_CENTERED_MASK)


typedef enum
{
	SDL_WINDOWEVENT_NONE,
	SDL_WINDOWEVENT_SHOWN,
	SDL_WINDOWEVENT_HIDDEN,
	SDL_WINDOWEVENT_EXPOSED,
	SDL_WINDOWEVENT_MOVED,
	SDL_WINDOWEVENT_RESIZED,
	SDL_WINDOWEVENT_SIZE_CHANGED,
	SDL_WINDOWEVENT_MINIMIZED,
	SDL_WINDOWEVENT_MAXIMIZED,
	SDL_WINDOWEVENT_RESTORED,
	SDL_WINDOWEVENT_ENTER,
	SDL_WINDOWEVENT_LEAVE,
	SDL_WINDOWEVENT_FOCUS_GAINED,
	SDL_WINDOWEVENT_FOCUS_LOST,
	SDL_WINDOWEVENT_CLOSE,
	SDL_WINDOWEVENT_TAKE_FOCUS,
	SDL_WINDOWEVENT_HIT_TEST
} SDL_WindowEventID;


typedef enum
{
	SDL_DISPLAYEVENT_NONE,
	SDL_DISPLAYEVENT_ORIENTATION,
	SDL_DISPLAYEVENT_CONNECTED,
	SDL_DISPLAYEVENT_DISCONNECTED
} SDL_DisplayEventID;

typedef enum
{
	SDL_ORIENTATION_UNKNOWN,
	SDL_ORIENTATION_LANDSCAPE,
	SDL_ORIENTATION_LANDSCAPE_FLIPPED,
	SDL_ORIENTATION_PORTRAIT,
	SDL_ORIENTATION_PORTRAIT_FLIPPED
} SDL_DisplayOrientation;


typedef void *SDL_GLContext;


typedef enum
{
	SDL_GL_RED_SIZE,
	SDL_GL_GREEN_SIZE,
	SDL_GL_BLUE_SIZE,
	SDL_GL_ALPHA_SIZE,
	SDL_GL_BUFFER_SIZE,
	SDL_GL_DOUBLEBUFFER,
	SDL_GL_DEPTH_SIZE,
	SDL_GL_STENCIL_SIZE,
	SDL_GL_ACCUM_RED_SIZE,
	SDL_GL_ACCUM_GREEN_SIZE,
	SDL_GL_ACCUM_BLUE_SIZE,
	SDL_GL_ACCUM_ALPHA_SIZE,
	SDL_GL_STEREO,
	SDL_GL_MULTISAMPLEBUFFERS,
	SDL_GL_MULTISAMPLESAMPLES,
	SDL_GL_ACCELERATED_VISUAL,
	SDL_GL_RETAINED_BACKING,
	SDL_GL_CONTEXT_MAJOR_VERSION,
	SDL_GL_CONTEXT_MINOR_VERSION,
	SDL_GL_CONTEXT_EGL,
	SDL_GL_CONTEXT_FLAGS,
	SDL_GL_CONTEXT_PROFILE_MASK,
	SDL_GL_SHARE_WITH_CURRENT_CONTEXT,
	SDL_GL_FRAMEBUFFER_SRGB_CAPABLE,
	SDL_GL_CONTEXT_RELEASE_BEHAVIOR,
	SDL_GL_CONTEXT_RESET_NOTIFICATION,
	SDL_GL_CONTEXT_NO_ERROR
} SDL_GLattr;

typedef enum
{
	SDL_GL_CONTEXT_PROFILE_CORE           = 0x0001,
	SDL_GL_CONTEXT_PROFILE_COMPATIBILITY  = 0x0002,
	SDL_GL_CONTEXT_PROFILE_ES             = 0x0004
} SDL_GLprofile;

typedef enum
{
	SDL_GL_CONTEXT_DEBUG_FLAG              = 0x0001,
	SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG = 0x0002,
	SDL_GL_CONTEXT_ROBUST_ACCESS_FLAG      = 0x0004,
	SDL_GL_CONTEXT_RESET_ISOLATION_FLAG    = 0x0008
} SDL_GLcontextFlag;

typedef enum
{
	SDL_GL_CONTEXT_RELEASE_BEHAVIOR_NONE   = 0x0000,
	SDL_GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH  = 0x0001
} SDL_GLcontextReleaseFlag;

typedef enum
{
	SDL_GL_CONTEXT_RESET_NO_NOTIFICATION = 0x0000,
	SDL_GL_CONTEXT_RESET_LOSE_CONTEXT    = 0x0001
} SDL_GLContextResetNotification;


int SDL_GetNumVideoDrivers(void);
const char *SDL_GetVideoDriver(int index);
int SDL_VideoInit(const char *driver_name);
void SDL_VideoQuit(void);
const char *SDL_GetCurrentVideoDriver(void);
int SDL_GetNumVideoDisplays(void);
const char * SDL_GetDisplayName(int displayIndex);
int SDL_GetDisplayBounds(int displayIndex, SDL_Rect * rect);
int SDL_GetDisplayUsableBounds(int displayIndex, SDL_Rect * rect);
int SDL_GetDisplayDPI(int displayIndex, float * ddpi, float * hdpi, float * vdpi);
SDL_DisplayOrientation SDL_GetDisplayOrientation(int displayIndex);
int SDL_GetNumDisplayModes(int displayIndex);
int SDL_GetDisplayMode(int displayIndex, int modeIndex, SDL_DisplayMode * mode);
int SDL_GetDesktopDisplayMode(int displayIndex, SDL_DisplayMode * mode);
int SDL_GetCurrentDisplayMode(int displayIndex, SDL_DisplayMode * mode);
SDL_DisplayMode * SDL_GetClosestDisplayMode(int displayIndex, const SDL_DisplayMode * mode, SDL_DisplayMode * closest);
int SDL_GetWindowDisplayIndex(SDL_Window * window);
int SDL_SetWindowDisplayMode(SDL_Window * window, const SDL_DisplayMode* mode);
int SDL_GetWindowDisplayMode(SDL_Window * window, SDL_DisplayMode * mode);
Uint32 SDL_GetWindowPixelFormat(SDL_Window * window);
SDL_Window * SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
SDL_Window * SDL_CreateWindowFrom(const void *data);
Uint32 SDL_GetWindowID(SDL_Window * window);
SDL_Window * SDL_GetWindowFromID(Uint32 id);
Uint32 SDL_GetWindowFlags(SDL_Window * window);
void SDL_SetWindowTitle(SDL_Window * window, const char *title);
const char *SDL_GetWindowTitle(SDL_Window * window);
void SDL_SetWindowIcon(SDL_Window * window, SDL_Surface * icon);
void* SDL_SetWindowData(SDL_Window * window, const char *name, void *userdata);
void *SDL_GetWindowData(SDL_Window * window, const char *name);
void SDL_SetWindowPosition(SDL_Window * window, int x, int y);
void SDL_GetWindowPosition(SDL_Window * window, int *x, int *y);
void SDL_SetWindowSize(SDL_Window * window, int w, int h);
void SDL_GetWindowSize(SDL_Window * window, int *w, int *h);
int SDL_GetWindowBordersSize(SDL_Window * window, int *top, int *left, int *bottom, int *right);
void SDL_SetWindowMinimumSize(SDL_Window * window, int min_w, int min_h);
void SDL_GetWindowMinimumSize(SDL_Window * window, int *w, int *h);
void SDL_SetWindowMaximumSize(SDL_Window * window, int max_w, int max_h);
void SDL_GetWindowMaximumSize(SDL_Window * window, int *w, int *h);
void SDL_SetWindowBordered(SDL_Window * window, SDL_bool bordered);
void SDL_SetWindowResizable(SDL_Window * window, SDL_bool resizable);
void SDL_ShowWindow(SDL_Window * window);
void SDL_HideWindow(SDL_Window * window);
void SDL_RaiseWindow(SDL_Window * window);
void SDL_MaximizeWindow(SDL_Window * window);
void SDL_MinimizeWindow(SDL_Window * window);
void SDL_RestoreWindow(SDL_Window * window);
int SDL_SetWindowFullscreen(SDL_Window * window, Uint32 flags);
SDL_Surface * SDL_GetWindowSurface(SDL_Window * window);
int SDL_UpdateWindowSurface(SDL_Window * window);
int SDL_UpdateWindowSurfaceRects(SDL_Window * window, const SDL_Rect * rects, int numrects);
void SDL_SetWindowGrab(SDL_Window * window, SDL_bool grabbed);
SDL_bool SDL_GetWindowGrab(SDL_Window * window);
SDL_Window * SDL_GetGrabbedWindow(void);
int SDL_SetWindowBrightness(SDL_Window * window, float brightness);
float SDL_GetWindowBrightness(SDL_Window * window);
int SDL_SetWindowOpacity(SDL_Window * window, float opacity);
int SDL_GetWindowOpacity(SDL_Window * window, float * out_opacity);
int SDL_SetWindowModalFor(SDL_Window * modal_window, SDL_Window * parent_window);
int SDL_SetWindowInputFocus(SDL_Window * window);
int SDL_SetWindowGammaRamp(SDL_Window * window, const Uint16 * red, const Uint16 * green, const Uint16 * blue);
int SDL_GetWindowGammaRamp(SDL_Window * window, Uint16 * red, Uint16 * green, Uint16 * blue);

typedef enum
{
	SDL_HITTEST_NORMAL,
	SDL_HITTEST_DRAGGABLE,
	SDL_HITTEST_RESIZE_TOPLEFT,
	SDL_HITTEST_RESIZE_TOP,
	SDL_HITTEST_RESIZE_TOPRIGHT,
	SDL_HITTEST_RESIZE_RIGHT,
	SDL_HITTEST_RESIZE_BOTTOMRIGHT,
	SDL_HITTEST_RESIZE_BOTTOM,
	SDL_HITTEST_RESIZE_BOTTOMLEFT,
	SDL_HITTEST_RESIZE_LEFT
} SDL_HitTestResult;


typedef SDL_HitTestResult (*SDL_HitTest)(SDL_Window *win, const SDL_Point *area, void *data);


int SDL_SetWindowHitTest(SDL_Window * window, SDL_HitTest callback, void *callback_data);
void SDL_DestroyWindow(SDL_Window * window);
SDL_bool SDL_IsScreenSaverEnabled(void);
void SDL_EnableScreenSaver(void);
void SDL_DisableScreenSaver(void);
int SDL_GL_LoadLibrary(const char *path);
void *SDL_GL_GetProcAddress(const char *proc);
void SDL_GL_UnloadLibrary(void);
SDL_bool SDL_GL_ExtensionSupported(const char *extension);
void SDL_GL_ResetAttributes(void);
int SDL_GL_SetAttribute(SDL_GLattr attr, int value);
int SDL_GL_GetAttribute(SDL_GLattr attr, int *value);
SDL_GLContext SDL_GL_CreateContext(SDL_Window * window);
int SDL_GL_MakeCurrent(SDL_Window * window, SDL_GLContext context);
SDL_Window* SDL_GL_GetCurrentWindow(void);
SDL_GLContext SDL_GL_GetCurrentContext(void);
void SDL_GL_GetDrawableSize(SDL_Window * window, int *w, int *h);
int SDL_GL_SetSwapInterval(int interval);
int SDL_GL_GetSwapInterval(void);
void SDL_GL_SwapWindow(SDL_Window * window);
void SDL_GL_DeleteContext(SDL_GLContext context);


//--------------------------------------------------------------
// Message box : SDL_messagebox.h
//--------------------------------------------------------------

typedef enum
{
    SDL_MESSAGEBOX_ERROR                 = 0x00000010,   /**< error dialog */
    SDL_MESSAGEBOX_WARNING               = 0x00000020,   /**< warning dialog */
    SDL_MESSAGEBOX_INFORMATION           = 0x00000040,   /**< informational dialog */
    SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT = 0x00000080,   /**< buttons placed left to right */
    SDL_MESSAGEBOX_BUTTONS_RIGHT_TO_LEFT = 0x00000100    /**< buttons placed right to left */
} SDL_MessageBoxFlags;

typedef enum
{
    SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT = 0x00000001,  /**< Marks the default button when return is hit */
    SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT = 0x00000002   /**< Marks the default button when escape is hit */
} SDL_MessageBoxButtonFlags;

typedef struct
{
    Uint32 flags;       /**< ::SDL_MessageBoxButtonFlags */
    int buttonid;       /**< User defined button id (value returned via SDL_ShowMessageBox) */
    const char * text;  /**< The UTF-8 button text */
} SDL_MessageBoxButtonData;

typedef struct
{
    Uint8 r, g, b;
} SDL_MessageBoxColor;

typedef enum
{
    SDL_MESSAGEBOX_COLOR_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_TEXT,
    SDL_MESSAGEBOX_COLOR_BUTTON_BORDER,
    SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND,
    SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED,
    SDL_MESSAGEBOX_COLOR_MAX
} SDL_MessageBoxColorType;

typedef struct
{
    SDL_MessageBoxColor colors[SDL_MESSAGEBOX_COLOR_MAX];
} SDL_MessageBoxColorScheme;

typedef struct
{
    Uint32 flags;                       /**< ::SDL_MessageBoxFlags */
    SDL_Window *window;                 /**< Parent window, can be NULL */
    const char *title;                  /**< UTF-8 title */
    const char *message;                /**< UTF-8 message text */

    int numbuttons;
    const SDL_MessageBoxButtonData *buttons;

    const SDL_MessageBoxColorScheme *colorScheme;   /**< ::SDL_MessageBoxColorScheme, can be NULL to use system settings */
} SDL_MessageBoxData;


int SDL_ShowMessageBox(const SDL_MessageBoxData *messageboxdata, int *buttonid);

int SDL_ShowSimpleMessageBox(Uint32 flags, const char *title, const char *message, SDL_Window *window);


//--------------------------------------------------------------
// 2D accelerated Rendering : SDL_render.h
//--------------------------------------------------------------


typedef enum
{
	SDL_RENDERER_SOFTWARE = 0x00000001,
	SDL_RENDERER_ACCELERATED = 0x00000002,
	SDL_RENDERER_PRESENTVSYNC = 0x00000004,
	SDL_RENDERER_TARGETTEXTURE = 0x00000008
} SDL_RendererFlags;


typedef struct SDL_RendererInfo
{
	const char *name;
	Uint32 flags;
	Uint32 num_texture_formats;
	Uint32 texture_formats[16];
	int max_texture_width;
	int max_texture_height;
} SDL_RendererInfo;


typedef enum
{
	SDL_ScaleModeNearest,
	SDL_ScaleModeLinear,
	SDL_ScaleModeBest
} SDL_ScaleMode;


typedef enum
{
	SDL_TEXTUREACCESS_STATIC,
	SDL_TEXTUREACCESS_STREAMING,
	SDL_TEXTUREACCESS_TARGET
} SDL_TextureAccess;


typedef enum
{
	SDL_TEXTUREMODULATE_NONE = 0x00000000,
	SDL_TEXTUREMODULATE_COLOR = 0x00000001,
	SDL_TEXTUREMODULATE_ALPHA = 0x00000002
} SDL_TextureModulate;


typedef enum
{
	SDL_FLIP_NONE       = 0x00000000,
	SDL_FLIP_HORIZONTAL = 0x00000001,
	SDL_FLIP_VERTICAL   = 0x00000002
} SDL_RendererFlip;


struct SDL_Renderer;
typedef struct SDL_Renderer SDL_Renderer;


struct SDL_Texture;
typedef struct SDL_Texture SDL_Texture;

struct SDL_SW_YUVTexture
{
    Uint32 format;
    Uint32 target_format;
    int w, h;
    Uint8 *pixels;

    /* These are just so we don't have to allocate them separately */
    Uint16 pitches[3];
    Uint8 *planes[3];

    /* This is a temporary surface in case we have to stretch copy */
    SDL_Surface *stretch;
    SDL_Surface *display;
};

typedef struct SDL_SW_YUVTexture SDL_SW_YUVTexture;

struct SDL_Texture
{
    const void *magic;
    Uint32 format;              /**< The pixel format of the texture */
    int access;                 /**< SDL_TextureAccess */
    int w;                      /**< The width of the texture */
    int h;                      /**< The height of the texture */
    int modMode;                /**< The texture modulation mode */
    SDL_BlendMode blendMode;    /**< The texture blend mode */
    SDL_ScaleMode scaleMode;    /**< The texture scale mode */
    SDL_Color color;            /**< Texture modulation values */

    SDL_Renderer *renderer;

    /* Support for formats not supported directly by the renderer */
    SDL_Texture *native;
    SDL_SW_YUVTexture *yuv;
    void *pixels;
    int pitch;
    SDL_Rect locked_rect;
    SDL_Surface *locked_surface;  /**< Locked region exposed as a SDL surface */

    Uint32 last_command_generation; /* last command queue generation this texture was in. */

    void *driverdata;           /**< Driver specific texture representation */
    void *userdata;

    SDL_Texture *prev;
    SDL_Texture *next;
};


int SDL_GetNumRenderDrivers(void);
int SDL_GetRenderDriverInfo(int index, SDL_RendererInfo * info);
int SDL_CreateWindowAndRenderer(int width, int height, Uint32 window_flags, SDL_Window **window, SDL_Renderer **renderer);
SDL_Renderer * SDL_CreateRenderer(SDL_Window * window,int index, Uint32 flags);
SDL_Renderer * SDL_CreateSoftwareRenderer(SDL_Surface * surface);
SDL_Renderer * SDL_GetRenderer(SDL_Window * window);
int SDL_GetRendererInfo(SDL_Renderer * renderer, SDL_RendererInfo * info);
int SDL_GetRendererOutputSize(SDL_Renderer * renderer, int *w, int *h);
SDL_Texture * SDL_CreateTexture(SDL_Renderer * renderer, Uint32 format, int access, int w, int h);
SDL_Texture * SDL_CreateTextureFromSurface(SDL_Renderer * renderer, SDL_Surface * surface);
int SDL_QueryTexture(SDL_Texture * texture, Uint32 * format, int *access, int *w, int *h);
int SDL_SetTextureColorMod(SDL_Texture * texture, Uint8 r, Uint8 g, Uint8 b);
int SDL_GetTextureColorMod(SDL_Texture * texture, Uint8 * r, Uint8 * g, Uint8 * b);
int SDL_SetTextureAlphaMod(SDL_Texture * texture, Uint8 alpha);
int SDL_GetTextureAlphaMod(SDL_Texture * texture, Uint8 * alpha);
int SDL_SetTextureBlendMode(SDL_Texture * texture, SDL_BlendMode blendMode);
int SDL_GetTextureBlendMode(SDL_Texture * texture, SDL_BlendMode *blendMode);
int SDL_SetTextureScaleMode(SDL_Texture * texture, SDL_ScaleMode scaleMode);
int SDL_GetTextureScaleMode(SDL_Texture * texture, SDL_ScaleMode *scaleMode);
int SDL_UpdateTexture(SDL_Texture * texture, const SDL_Rect * rect, const void *pixels, int pitch);
int SDL_UpdateYUVTexture(SDL_Texture * texture, const SDL_Rect * rect, const Uint8 *Yplane, int Ypitch, const Uint8 *Uplane, int Upitch, const Uint8 *Vplane, int Vpitch);
int SDL_LockTexture(SDL_Texture * texture, const SDL_Rect * rect, void **pixels, int *pitch);
int SDL_LockTextureToSurface(SDL_Texture *texture, const SDL_Rect *rect, SDL_Surface **surface);
void SDL_UnlockTexture(SDL_Texture * texture);
SDL_bool SDL_RenderTargetSupported(SDL_Renderer *renderer);
int SDL_SetRenderTarget(SDL_Renderer *renderer, SDL_Texture *texture);
SDL_Texture * SDL_GetRenderTarget(SDL_Renderer *renderer);
int SDL_RenderSetLogicalSize(SDL_Renderer * renderer, int w, int h);
void SDL_RenderGetLogicalSize(SDL_Renderer * renderer, int *w, int *h);
int SDL_RenderSetIntegerScale(SDL_Renderer * renderer, SDL_bool enable);
SDL_bool SDL_RenderGetIntegerScale(SDL_Renderer * renderer);
int SDL_RenderSetViewport(SDL_Renderer * renderer, const SDL_Rect * rect);
void SDL_RenderGetViewport(SDL_Renderer * renderer, SDL_Rect * rect);
int SDL_RenderSetClipRect(SDL_Renderer * renderer, const SDL_Rect * rect);
void SDL_RenderGetClipRect(SDL_Renderer * renderer, SDL_Rect * rect);
SDL_bool SDL_RenderIsClipEnabled(SDL_Renderer * renderer);
int SDL_RenderSetScale(SDL_Renderer * renderer, float scaleX, float scaleY);
void SDL_RenderGetScale(SDL_Renderer * renderer, float *scaleX, float *scaleY);
int SDL_SetRenderDrawColor(SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
int SDL_GetRenderDrawColor(SDL_Renderer * renderer, Uint8 * r, Uint8 * g, Uint8 * b, Uint8 * a);
int SDL_SetRenderDrawBlendMode(SDL_Renderer * renderer, SDL_BlendMode blendMode);
int SDL_GetRenderDrawBlendMode(SDL_Renderer * renderer, SDL_BlendMode *blendMode);
int SDL_RenderClear(SDL_Renderer * renderer);
int SDL_RenderDrawPoint(SDL_Renderer * renderer, int x, int y);
int SDL_RenderDrawPoints(SDL_Renderer * renderer, const SDL_Point * points, int count);
int SDL_RenderDrawLine(SDL_Renderer * renderer, int x1, int y1, int x2, int y2);
int SDL_RenderDrawLines(SDL_Renderer * renderer, const SDL_Point * points, int count);
int SDL_RenderDrawRect(SDL_Renderer * renderer, const SDL_Rect * rect);
int SDL_RenderDrawRects(SDL_Renderer * renderer, const SDL_Rect * rects, int count);
int SDL_RenderFillRect(SDL_Renderer * renderer, const SDL_Rect * rect);
int SDL_RenderFillRects(SDL_Renderer * renderer, const SDL_Rect * rects, int count);
int SDL_RenderCopy(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect);
int SDL_RenderCopyEx(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect, const double angle, const SDL_Point *center, const SDL_RendererFlip flip);
int SDL_RenderDrawPointF(SDL_Renderer * renderer, float x, float y);
int SDL_RenderDrawPointsF(SDL_Renderer * renderer, const SDL_FPoint * points, int count);
int SDL_RenderDrawLineF(SDL_Renderer * renderer, float x1, float y1, float x2, float y2);
int SDL_RenderDrawLinesF(SDL_Renderer * renderer, const SDL_FPoint * points, int count);
int SDL_RenderDrawRectF(SDL_Renderer * renderer, const SDL_FRect * rect);
int SDL_RenderDrawRectsF(SDL_Renderer * renderer, const SDL_FRect * rects, int count);
int SDL_RenderFillRectF(SDL_Renderer * renderer, const SDL_FRect * rect);
int SDL_RenderFillRectsF(SDL_Renderer * renderer, const SDL_FRect * rects, int count);
int SDL_RenderCopyF(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_FRect * dstrect);
int SDL_RenderCopyExF(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_FRect * dstrect, const double angle, const SDL_FPoint *center, const SDL_RendererFlip flip);
int SDL_RenderReadPixels(SDL_Renderer * renderer, const SDL_Rect * rect, Uint32 format, void *pixels, int pitch);
void SDL_RenderPresent(SDL_Renderer * renderer);
void SDL_DestroyTexture(SDL_Texture * texture);
void SDL_DestroyRenderer(SDL_Renderer * renderer);
int SDL_RenderFlush(SDL_Renderer * renderer);
int SDL_GL_BindTexture(SDL_Texture *texture, float *texw, float *texh);
int SDL_GL_UnbindTexture(SDL_Texture *texture);
void *SDL_RenderGetMetalLayer(SDL_Renderer * renderer);
void *SDL_RenderGetMetalCommandEncoder(SDL_Renderer * renderer);


//--------------------------------------------------------------
// Platform-specific Window Management : SDL_syswm.h
//--------------------------------------------------------------

 // TODO ?

//--------------------------------------------------------------
// Clipboard Handling : SDL_clipboard.h
//--------------------------------------------------------------

 // TODO ?

//--------------------------------------------------------------
// Vulkan Support : SDL_vulkan.h
//--------------------------------------------------------------

 // TODO ?



//==============================================================
// Input Events
//==============================================================

//--------------------------------------------------------------
// Keyboard Support : SDL_keyboard.h
//--------------------------------------------------------------

typedef enum
{
	SDL_SCANCODE_UNKNOWN = 0,

	SDL_SCANCODE_A = 4,
	SDL_SCANCODE_B = 5,
	SDL_SCANCODE_C = 6,
	SDL_SCANCODE_D = 7,
	SDL_SCANCODE_E = 8,
	SDL_SCANCODE_F = 9,
	SDL_SCANCODE_G = 10,
	SDL_SCANCODE_H = 11,
	SDL_SCANCODE_I = 12,
	SDL_SCANCODE_J = 13,
	SDL_SCANCODE_K = 14,
	SDL_SCANCODE_L = 15,
	SDL_SCANCODE_M = 16,
	SDL_SCANCODE_N = 17,
	SDL_SCANCODE_O = 18,
	SDL_SCANCODE_P = 19,
	SDL_SCANCODE_Q = 20,
	SDL_SCANCODE_R = 21,
	SDL_SCANCODE_S = 22,
	SDL_SCANCODE_T = 23,
	SDL_SCANCODE_U = 24,
	SDL_SCANCODE_V = 25,
	SDL_SCANCODE_W = 26,
	SDL_SCANCODE_X = 27,
	SDL_SCANCODE_Y = 28,
	SDL_SCANCODE_Z = 29,

	SDL_SCANCODE_1 = 30,
	SDL_SCANCODE_2 = 31,
	SDL_SCANCODE_3 = 32,
	SDL_SCANCODE_4 = 33,
	SDL_SCANCODE_5 = 34,
	SDL_SCANCODE_6 = 35,
	SDL_SCANCODE_7 = 36,
	SDL_SCANCODE_8 = 37,
	SDL_SCANCODE_9 = 38,
	SDL_SCANCODE_0 = 39,

	SDL_SCANCODE_RETURN = 40,
	SDL_SCANCODE_ESCAPE = 41,
	SDL_SCANCODE_BACKSPACE = 42,
	SDL_SCANCODE_TAB = 43,
	SDL_SCANCODE_SPACE = 44,

	SDL_SCANCODE_MINUS = 45,
	SDL_SCANCODE_EQUALS = 46,
	SDL_SCANCODE_LEFTBRACKET = 47,
	SDL_SCANCODE_RIGHTBRACKET = 48,
	SDL_SCANCODE_BACKSLASH = 49,
	SDL_SCANCODE_NONUSHASH = 50,
	SDL_SCANCODE_SEMICOLON = 51,
	SDL_SCANCODE_APOSTROPHE = 52,
	SDL_SCANCODE_GRAVE = 53,
	SDL_SCANCODE_COMMA = 54,
	SDL_SCANCODE_PERIOD = 55,
	SDL_SCANCODE_SLASH = 56,

	SDL_SCANCODE_CAPSLOCK = 57,

	SDL_SCANCODE_F1 = 58,
	SDL_SCANCODE_F2 = 59,
	SDL_SCANCODE_F3 = 60,
	SDL_SCANCODE_F4 = 61,
	SDL_SCANCODE_F5 = 62,
	SDL_SCANCODE_F6 = 63,
	SDL_SCANCODE_F7 = 64,
	SDL_SCANCODE_F8 = 65,
	SDL_SCANCODE_F9 = 66,
	SDL_SCANCODE_F10 = 67,
	SDL_SCANCODE_F11 = 68,
	SDL_SCANCODE_F12 = 69,

	SDL_SCANCODE_PRINTSCREEN = 70,
	SDL_SCANCODE_SCROLLLOCK = 71,
	SDL_SCANCODE_PAUSE = 72,
	SDL_SCANCODE_INSERT = 73,
	SDL_SCANCODE_HOME = 74,
	SDL_SCANCODE_PAGEUP = 75,
	SDL_SCANCODE_DELETE = 76,
	SDL_SCANCODE_END = 77,
	SDL_SCANCODE_PAGEDOWN = 78,
	SDL_SCANCODE_RIGHT = 79,
	SDL_SCANCODE_LEFT = 80,
	SDL_SCANCODE_DOWN = 81,
	SDL_SCANCODE_UP = 82,

	SDL_SCANCODE_NUMLOCKCLEAR = 83,
	SDL_SCANCODE_KP_DIVIDE = 84,
	SDL_SCANCODE_KP_MULTIPLY = 85,
	SDL_SCANCODE_KP_MINUS = 86,
	SDL_SCANCODE_KP_PLUS = 87,
	SDL_SCANCODE_KP_ENTER = 88,
	SDL_SCANCODE_KP_1 = 89,
	SDL_SCANCODE_KP_2 = 90,
	SDL_SCANCODE_KP_3 = 91,
	SDL_SCANCODE_KP_4 = 92,
	SDL_SCANCODE_KP_5 = 93,
	SDL_SCANCODE_KP_6 = 94,
	SDL_SCANCODE_KP_7 = 95,
	SDL_SCANCODE_KP_8 = 96,
	SDL_SCANCODE_KP_9 = 97,
	SDL_SCANCODE_KP_0 = 98,
	SDL_SCANCODE_KP_PERIOD = 99,

	SDL_SCANCODE_NONUSBACKSLASH = 100,
	SDL_SCANCODE_APPLICATION = 101,
	SDL_SCANCODE_POWER = 102,
	SDL_SCANCODE_KP_EQUALS = 103,
	SDL_SCANCODE_F13 = 104,
	SDL_SCANCODE_F14 = 105,
	SDL_SCANCODE_F15 = 106,
	SDL_SCANCODE_F16 = 107,
	SDL_SCANCODE_F17 = 108,
	SDL_SCANCODE_F18 = 109,
	SDL_SCANCODE_F19 = 110,
	SDL_SCANCODE_F20 = 111,
	SDL_SCANCODE_F21 = 112,
	SDL_SCANCODE_F22 = 113,
	SDL_SCANCODE_F23 = 114,
	SDL_SCANCODE_F24 = 115,
	SDL_SCANCODE_EXECUTE = 116,
	SDL_SCANCODE_HELP = 117,
	SDL_SCANCODE_MENU = 118,
	SDL_SCANCODE_SELECT = 119,
	SDL_SCANCODE_STOP = 120,
	SDL_SCANCODE_AGAIN = 121,
	SDL_SCANCODE_UNDO = 122,
	SDL_SCANCODE_CUT = 123,
	SDL_SCANCODE_COPY = 124,
	SDL_SCANCODE_PASTE = 125,
	SDL_SCANCODE_FIND = 126,
	SDL_SCANCODE_MUTE = 127,
	SDL_SCANCODE_VOLUMEUP = 128,
	SDL_SCANCODE_VOLUMEDOWN = 129,

	SDL_SCANCODE_KP_COMMA = 133,
	SDL_SCANCODE_KP_EQUALSAS400 = 134,

	SDL_SCANCODE_INTERNATIONAL1 = 135,
	SDL_SCANCODE_INTERNATIONAL2 = 136,
	SDL_SCANCODE_INTERNATIONAL3 = 137,
	SDL_SCANCODE_INTERNATIONAL4 = 138,
	SDL_SCANCODE_INTERNATIONAL5 = 139,
	SDL_SCANCODE_INTERNATIONAL6 = 140,
	SDL_SCANCODE_INTERNATIONAL7 = 141,
	SDL_SCANCODE_INTERNATIONAL8 = 142,
	SDL_SCANCODE_INTERNATIONAL9 = 143,
	SDL_SCANCODE_LANG1 = 144,
	SDL_SCANCODE_LANG2 = 145,
	SDL_SCANCODE_LANG3 = 146,
	SDL_SCANCODE_LANG4 = 147,
	SDL_SCANCODE_LANG5 = 148,
	SDL_SCANCODE_LANG6 = 149,
	SDL_SCANCODE_LANG7 = 150,
	SDL_SCANCODE_LANG8 = 151,
	SDL_SCANCODE_LANG9 = 152,

	SDL_SCANCODE_ALTERASE = 153,
	SDL_SCANCODE_SYSREQ = 154,
	SDL_SCANCODE_CANCEL = 155,
	SDL_SCANCODE_CLEAR = 156,
	SDL_SCANCODE_PRIOR = 157,
	SDL_SCANCODE_RETURN2 = 158,
	SDL_SCANCODE_SEPARATOR = 159,
	SDL_SCANCODE_OUT = 160,
	SDL_SCANCODE_OPER = 161,
	SDL_SCANCODE_CLEARAGAIN = 162,
	SDL_SCANCODE_CRSEL = 163,
	SDL_SCANCODE_EXSEL = 164,

	SDL_SCANCODE_KP_00 = 176,
	SDL_SCANCODE_KP_000 = 177,
	SDL_SCANCODE_THOUSANDSSEPARATOR = 178,
	SDL_SCANCODE_DECIMALSEPARATOR = 179,
	SDL_SCANCODE_CURRENCYUNIT = 180,
	SDL_SCANCODE_CURRENCYSUBUNIT = 181,
	SDL_SCANCODE_KP_LEFTPAREN = 182,
	SDL_SCANCODE_KP_RIGHTPAREN = 183,
	SDL_SCANCODE_KP_LEFTBRACE = 184,
	SDL_SCANCODE_KP_RIGHTBRACE = 185,
	SDL_SCANCODE_KP_TAB = 186,
	SDL_SCANCODE_KP_BACKSPACE = 187,
	SDL_SCANCODE_KP_A = 188,
	SDL_SCANCODE_KP_B = 189,
	SDL_SCANCODE_KP_C = 190,
	SDL_SCANCODE_KP_D = 191,
	SDL_SCANCODE_KP_E = 192,
	SDL_SCANCODE_KP_F = 193,
	SDL_SCANCODE_KP_XOR = 194,
	SDL_SCANCODE_KP_POWER = 195,
	SDL_SCANCODE_KP_PERCENT = 196,
	SDL_SCANCODE_KP_LESS = 197,
	SDL_SCANCODE_KP_GREATER = 198,
	SDL_SCANCODE_KP_AMPERSAND = 199,
	SDL_SCANCODE_KP_DBLAMPERSAND = 200,
	SDL_SCANCODE_KP_VERTICALBAR = 201,
	SDL_SCANCODE_KP_DBLVERTICALBAR = 202,
	SDL_SCANCODE_KP_COLON = 203,
	SDL_SCANCODE_KP_HASH = 204,
	SDL_SCANCODE_KP_SPACE = 205,
	SDL_SCANCODE_KP_AT = 206,
	SDL_SCANCODE_KP_EXCLAM = 207,
	SDL_SCANCODE_KP_MEMSTORE = 208,
	SDL_SCANCODE_KP_MEMRECALL = 209,
	SDL_SCANCODE_KP_MEMCLEAR = 210,
	SDL_SCANCODE_KP_MEMADD = 211,
	SDL_SCANCODE_KP_MEMSUBTRACT = 212,
	SDL_SCANCODE_KP_MEMMULTIPLY = 213,
	SDL_SCANCODE_KP_MEMDIVIDE = 214,
	SDL_SCANCODE_KP_PLUSMINUS = 215,
	SDL_SCANCODE_KP_CLEAR = 216,
	SDL_SCANCODE_KP_CLEARENTRY = 217,
	SDL_SCANCODE_KP_BINARY = 218,
	SDL_SCANCODE_KP_OCTAL = 219,
	SDL_SCANCODE_KP_DECIMAL = 220,
	SDL_SCANCODE_KP_HEXADECIMAL = 221,

	SDL_SCANCODE_LCTRL = 224,
	SDL_SCANCODE_LSHIFT = 225,
	SDL_SCANCODE_LALT = 226,
	SDL_SCANCODE_LGUI = 227,
	SDL_SCANCODE_RCTRL = 228,
	SDL_SCANCODE_RSHIFT = 229,
	SDL_SCANCODE_RALT = 230,
	SDL_SCANCODE_RGUI = 231,

	SDL_SCANCODE_MODE = 257,

	SDL_SCANCODE_AUDIONEXT = 258,
	SDL_SCANCODE_AUDIOPREV = 259,
	SDL_SCANCODE_AUDIOSTOP = 260,
	SDL_SCANCODE_AUDIOPLAY = 261,
	SDL_SCANCODE_AUDIOMUTE = 262,
	SDL_SCANCODE_MEDIASELECT = 263,
	SDL_SCANCODE_WWW = 264,
	SDL_SCANCODE_MAIL = 265,
	SDL_SCANCODE_CALCULATOR = 266,
	SDL_SCANCODE_COMPUTER = 267,
	SDL_SCANCODE_AC_SEARCH = 268,
	SDL_SCANCODE_AC_HOME = 269,
	SDL_SCANCODE_AC_BACK = 270,
	SDL_SCANCODE_AC_FORWARD = 271,
	SDL_SCANCODE_AC_STOP = 272,
	SDL_SCANCODE_AC_REFRESH = 273,
	SDL_SCANCODE_AC_BOOKMARKS = 274,

	SDL_SCANCODE_BRIGHTNESSDOWN = 275,
	SDL_SCANCODE_BRIGHTNESSUP = 276,
	SDL_SCANCODE_DISPLAYSWITCH = 277,
	SDL_SCANCODE_KBDILLUMTOGGLE = 278,
	SDL_SCANCODE_KBDILLUMDOWN = 279,
	SDL_SCANCODE_KBDILLUMUP = 280,
	SDL_SCANCODE_EJECT = 281,
	SDL_SCANCODE_SLEEP = 282,

	SDL_SCANCODE_APP1 = 283,
	SDL_SCANCODE_APP2 = 284,

	SDL_SCANCODE_AUDIOREWIND = 285,
	SDL_SCANCODE_AUDIOFASTFORWARD = 286,

	SDL_NUM_SCANCODES = 512
} SDL_Scancode;


typedef Sint32 SDL_Keycode;

//#define SDLK_SCANCODE_MASK (1<<30)
//#define SDL_SCANCODE_TO_KEYCODE(X)  (X | SDLK_SCANCODE_MASK)

typedef enum
{
	SDLK_UNKNOWN = 0,

	SDLK_RETURN = '\r',
	SDLK_ESCAPE = '\033',
	SDLK_BACKSPACE = '\b',
	SDLK_TAB = '\t',
	SDLK_SPACE = ' ',
	SDLK_EXCLAIM = '!',
	SDLK_QUOTEDBL = '"',
	SDLK_HASH = '#',
	SDLK_PERCENT = '%',
	SDLK_DOLLAR = '$',
	SDLK_AMPERSAND = '&',
	SDLK_QUOTE = '\'',
	SDLK_LEFTPAREN = '(',
	SDLK_RIGHTPAREN = ')',
	SDLK_ASTERISK = '*',
	SDLK_PLUS = '+',
	SDLK_COMMA = ',',
	SDLK_MINUS = '-',
	SDLK_PERIOD = '.',
	SDLK_SLASH = '/',
	SDLK_0 = '0',
	SDLK_1 = '1',
	SDLK_2 = '2',
	SDLK_3 = '3',
	SDLK_4 = '4',
	SDLK_5 = '5',
	SDLK_6 = '6',
	SDLK_7 = '7',
	SDLK_8 = '8',
	SDLK_9 = '9',
	SDLK_COLON = ':',
	SDLK_SEMICOLON = ';',
	SDLK_LESS = '<',
	SDLK_EQUALS = '=',
	SDLK_GREATER = '>',
	SDLK_QUESTION = '?',
	SDLK_AT = '@',



	SDLK_LEFTBRACKET = '[',
	SDLK_BACKSLASH = '\\',
	SDLK_RIGHTBRACKET = ']',
	SDLK_CARET = '^',
	SDLK_UNDERSCORE = '_',
	SDLK_BACKQUOTE = '`',
	SDLK_a = 'a',
	SDLK_b = 'b',
	SDLK_c = 'c',
	SDLK_d = 'd',
	SDLK_e = 'e',
	SDLK_f = 'f',
	SDLK_g = 'g',
	SDLK_h = 'h',
	SDLK_i = 'i',
	SDLK_j = 'j',
	SDLK_k = 'k',
	SDLK_l = 'l',
	SDLK_m = 'm',
	SDLK_n = 'n',
	SDLK_o = 'o',
	SDLK_p = 'p',
	SDLK_q = 'q',
	SDLK_r = 'r',
	SDLK_s = 's',
	SDLK_t = 't',
	SDLK_u = 'u',
	SDLK_v = 'v',
	SDLK_w = 'w',
	SDLK_x = 'x',
	SDLK_y = 'y',
	SDLK_z = 'z',

//	SDLK_CAPSLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK),
//
//	SDLK_F1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1),
//	SDLK_F2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2),
//	SDLK_F3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3),
//	SDLK_F4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4),
//	SDLK_F5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5),
//	SDLK_F6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6),
//	SDLK_F7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7),
//	SDLK_F8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8),
//	SDLK_F9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9),
//	SDLK_F10 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10),
//	SDLK_F11 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11),
//	SDLK_F12 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12),
//
//	SDLK_PRINTSCREEN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN),
//	SDLK_SCROLLLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK),
//	SDLK_PAUSE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE),
//	SDLK_INSERT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT),
//	SDLK_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME),
//	SDLK_PAGEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP),
//	SDLK_DELETE = '\177',
//	SDLK_END = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END),
//	SDLK_PAGEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN),
//	SDLK_RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT),
//	SDLK_LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT),
//	SDLK_DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN),
//	SDLK_UP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP),
//
//	SDLK_NUMLOCKCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR),
//	SDLK_KP_DIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE),
//	SDLK_KP_MULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY),
//	SDLK_KP_MINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS),
//	SDLK_KP_PLUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS),
//	SDLK_KP_ENTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER),
//	SDLK_KP_1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1),
//	SDLK_KP_2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2),
//	SDLK_KP_3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3),
//	SDLK_KP_4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4),
//	SDLK_KP_5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5),
//	SDLK_KP_6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6),
//	SDLK_KP_7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7),
//	SDLK_KP_8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8),
//	SDLK_KP_9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9),
//	SDLK_KP_0 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0),
//	SDLK_KP_PERIOD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD),
//
//	SDLK_APPLICATION = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION),
//	SDLK_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER),
//	SDLK_KP_EQUALS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS),
//	SDLK_F13 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13),
//	SDLK_F14 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14),
//	SDLK_F15 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15),
//	SDLK_F16 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16),
//	SDLK_F17 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17),
//	SDLK_F18 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18),
//	SDLK_F19 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19),
//	SDLK_F20 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20),
//	SDLK_F21 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21),
//	SDLK_F22 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22),
//	SDLK_F23 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23),
//	SDLK_F24 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24),
//	SDLK_EXECUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE),
//	SDLK_HELP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP),
//	SDLK_MENU = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU),
//	SDLK_SELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT),
//	SDLK_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP),
//	SDLK_AGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN),
//	SDLK_UNDO = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO),
//	SDLK_CUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT),
//	SDLK_COPY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY),
//	SDLK_PASTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE),
//	SDLK_FIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND),
//	SDLK_MUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE),
//	SDLK_VOLUMEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP),
//	SDLK_VOLUMEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN),
//	SDLK_KP_COMMA = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA),
//	SDLK_KP_EQUALSAS400 =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400),
//
//	SDLK_ALTERASE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE),
//	SDLK_SYSREQ = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ),
//	SDLK_CANCEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL),
//	SDLK_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR),
//	SDLK_PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR),
//	SDLK_RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2),
//	SDLK_SEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR),
//	SDLK_OUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT),
//	SDLK_OPER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER),
//	SDLK_CLEARAGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN),
//	SDLK_CRSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL),
//	SDLK_EXSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL),
//
//	SDLK_KP_00 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00),
//	SDLK_KP_000 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000),
//	SDLK_THOUSANDSSEPARATOR =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR),
//	SDLK_DECIMALSEPARATOR =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR),
//	SDLK_CURRENCYUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT),
//	SDLK_CURRENCYSUBUNIT =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT),
//	SDLK_KP_LEFTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN),
//	SDLK_KP_RIGHTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN),
//	SDLK_KP_LEFTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE),
//	SDLK_KP_RIGHTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE),
//	SDLK_KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB),
//	SDLK_KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE),
//	SDLK_KP_A = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A),
//	SDLK_KP_B = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B),
//	SDLK_KP_C = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C),
//	SDLK_KP_D = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D),
//	SDLK_KP_E = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E),
//	SDLK_KP_F = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F),
//	SDLK_KP_XOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR),
//	SDLK_KP_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER),
//	SDLK_KP_PERCENT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT),
//	SDLK_KP_LESS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS),
//	SDLK_KP_GREATER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER),
//	SDLK_KP_AMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND),
//	SDLK_KP_DBLAMPERSAND =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND),
//	SDLK_KP_VERTICALBAR =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR),
//	SDLK_KP_DBLVERTICALBAR =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR),
//	SDLK_KP_COLON = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON),
//	SDLK_KP_HASH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH),
//	SDLK_KP_SPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE),
//	SDLK_KP_AT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT),
//	SDLK_KP_EXCLAM = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM),
//	SDLK_KP_MEMSTORE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE),
//	SDLK_KP_MEMRECALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL),
//	SDLK_KP_MEMCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR),
//	SDLK_KP_MEMADD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD),
//	SDLK_KP_MEMSUBTRACT =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT),
//	SDLK_KP_MEMMULTIPLY =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY),
//	SDLK_KP_MEMDIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE),
//	SDLK_KP_PLUSMINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS),
//	SDLK_KP_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR),
//	SDLK_KP_CLEARENTRY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY),
//	SDLK_KP_BINARY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY),
//	SDLK_KP_OCTAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL),
//	SDLK_KP_DECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL),
//	SDLK_KP_HEXADECIMAL =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL),
//
//	SDLK_LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL),
//	SDLK_LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT),
//	SDLK_LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT),
//	SDLK_LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI),
//	SDLK_RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL),
//	SDLK_RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT),
//	SDLK_RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT),
//	SDLK_RGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI),
//
//	SDLK_MODE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE),
//
//	SDLK_AUDIONEXT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT),
//	SDLK_AUDIOPREV = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV),
//	SDLK_AUDIOSTOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP),
//	SDLK_AUDIOPLAY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY),
//	SDLK_AUDIOMUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE),
//	SDLK_MEDIASELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT),
//	SDLK_WWW = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW),
//	SDLK_MAIL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL),
//	SDLK_CALCULATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR),
//	SDLK_COMPUTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER),
//	SDLK_AC_SEARCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH),
//	SDLK_AC_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME),
//	SDLK_AC_BACK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK),
//	SDLK_AC_FORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD),
//	SDLK_AC_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP),
//	SDLK_AC_REFRESH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH),
//	SDLK_AC_BOOKMARKS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS),
//
//	SDLK_BRIGHTNESSDOWN =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN),
//	SDLK_BRIGHTNESSUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP),
//	SDLK_DISPLAYSWITCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH),
//	SDLK_KBDILLUMTOGGLE =
//	    SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE),
//	SDLK_KBDILLUMDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN),
//	SDLK_KBDILLUMUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP),
//	SDLK_EJECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT),
//	SDLK_SLEEP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP),
//	SDLK_APP1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1),
//	SDLK_APP2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2),
//
//	SDLK_AUDIOREWIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND),
//	SDLK_AUDIOFASTFORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD)
} SDL_KeyCode;


typedef enum
{
	KMOD_NONE = 0x0000,
	KMOD_LSHIFT = 0x0001,
	KMOD_RSHIFT = 0x0002,
	KMOD_LCTRL = 0x0040,
	KMOD_RCTRL = 0x0080,
	KMOD_LALT = 0x0100,
	KMOD_RALT = 0x0200,
	KMOD_LGUI = 0x0400,
	KMOD_RGUI = 0x0800,
	KMOD_NUM = 0x1000,
	KMOD_CAPS = 0x2000,
	KMOD_MODE = 0x4000,
	KMOD_RESERVED = 0x8000,

	KMOD_CTRL = KMOD_LCTRL | KMOD_RCTRL,
	KMOD_SHIFT = KMOD_LSHIFT | KMOD_RSHIFT,
	KMOD_ALT = KMOD_LALT | KMOD_RALT,
	KMOD_GUI = KMOD_LGUI | KMOD_RGUI
} SDL_Keymod;



typedef struct SDL_Keysym
{
	SDL_Scancode scancode;
	SDL_Keycode sym;
	Uint16 mod;
	Uint32 unused;
} SDL_Keysym;


SDL_Window * SDL_GetKeyboardFocus(void);
const Uint8 *SDL_GetKeyboardState(int *numkeys);
SDL_Keymod SDL_GetModState(void);
void SDL_SetModState(SDL_Keymod modstate);
SDL_Keycode SDL_GetKeyFromScancode(SDL_Scancode scancode);
SDL_Scancode SDL_GetScancodeFromKey(SDL_Keycode key);
const char *SDL_GetScancodeName(SDL_Scancode scancode);
SDL_Scancode SDL_GetScancodeFromName(const char *name);
const char *SDL_GetKeyName(SDL_Keycode key);
SDL_Keycode SDL_GetKeyFromName(const char *name);
void SDL_StartTextInput(void);
SDL_bool SDL_IsTextInputActive(void);
void SDL_StopTextInput(void);
void SDL_SetTextInputRect(SDL_Rect *rect);
SDL_bool SDL_HasScreenKeyboardSupport(void);
SDL_bool SDL_IsScreenKeyboardShown(SDL_Window *window);


//--------------------------------------------------------------
// Mouse Support : SDL_mouse.h
//--------------------------------------------------------------



typedef struct SDL_Cursor SDL_Cursor;


typedef enum
{
	SDL_SYSTEM_CURSOR_ARROW,
	SDL_SYSTEM_CURSOR_IBEAM,
	SDL_SYSTEM_CURSOR_WAIT,
	SDL_SYSTEM_CURSOR_CROSSHAIR,
	SDL_SYSTEM_CURSOR_WAITARROW,
	SDL_SYSTEM_CURSOR_SIZENWSE,
	SDL_SYSTEM_CURSOR_SIZENESW,
	SDL_SYSTEM_CURSOR_SIZEWE,
	SDL_SYSTEM_CURSOR_SIZENS,
	SDL_SYSTEM_CURSOR_SIZEALL,
	SDL_SYSTEM_CURSOR_NO,
	SDL_SYSTEM_CURSOR_HAND,
	SDL_NUM_SYSTEM_CURSORS
} SDL_SystemCursor;


typedef enum
{
	SDL_MOUSEWHEEL_NORMAL,
	SDL_MOUSEWHEEL_FLIPPED
} SDL_MouseWheelDirection;


SDL_Window * SDL_GetMouseFocus(void);
Uint32 SDL_GetMouseState(int *x, int *y);
Uint32 SDL_GetGlobalMouseState(int *x, int *y);
Uint32 SDL_GetRelativeMouseState(int *x, int *y);
void SDL_WarpMouseInWindow(SDL_Window * window, int x, int y);
int SDL_WarpMouseGlobal(int x, int y);
int SDL_SetRelativeMouseMode(SDL_bool enabled);
int SDL_CaptureMouse(SDL_bool enabled);
SDL_bool SDL_GetRelativeMouseMode(void);
SDL_Cursor *SDL_CreateCursor(const Uint8 * data, const Uint8 * mask, int w, int h, int hot_x, int hot_y);
SDL_Cursor *SDL_CreateColorCursor(SDL_Surface *surface, int hot_x, int hot_y);
SDL_Cursor *SDL_CreateSystemCursor(SDL_SystemCursor id);
void SDL_SetCursor(SDL_Cursor * cursor);
SDL_Cursor *SDL_GetCursor(void);
SDL_Cursor *SDL_GetDefaultCursor(void);
void SDL_FreeCursor(SDL_Cursor * cursor);
int SDL_ShowCursor(int toggle);


//--------------------------------------------------------------
// Joystick Support : SDL_joystick.h
//--------------------------------------------------------------


struct _SDL_Joystick;
typedef struct _SDL_Joystick SDL_Joystick;

typedef struct {
	Uint8 data[16];
} SDL_JoystickGUID;

typedef Sint32 SDL_JoystickID;

typedef enum
{
	SDL_JOYSTICK_TYPE_UNKNOWN,
	SDL_JOYSTICK_TYPE_GAMECONTROLLER,
	SDL_JOYSTICK_TYPE_WHEEL,
	SDL_JOYSTICK_TYPE_ARCADE_STICK,
	SDL_JOYSTICK_TYPE_FLIGHT_STICK,
	SDL_JOYSTICK_TYPE_DANCE_PAD,
	SDL_JOYSTICK_TYPE_GUITAR,
	SDL_JOYSTICK_TYPE_DRUM_KIT,
	SDL_JOYSTICK_TYPE_ARCADE_PAD,
	SDL_JOYSTICK_TYPE_THROTTLE
} SDL_JoystickType;

typedef enum
{
	SDL_JOYSTICK_POWER_UNKNOWN = -1,
	SDL_JOYSTICK_POWER_EMPTY,
	SDL_JOYSTICK_POWER_LOW,
	SDL_JOYSTICK_POWER_MEDIUM,
	SDL_JOYSTICK_POWER_FULL,
	SDL_JOYSTICK_POWER_WIRED,
	SDL_JOYSTICK_POWER_MAX
} SDL_JoystickPowerLevel;


#define SDL_IPHONE_MAX_GFORCE 5.0

void SDL_LockJoysticks(void);
void SDL_UnlockJoysticks(void);
int SDL_NumJoysticks(void);
const char *SDL_JoystickNameForIndex(int device_index);
int SDL_JoystickGetDevicePlayerIndex(int device_index);
SDL_JoystickGUID SDL_JoystickGetDeviceGUID(int device_index);
Uint16 SDL_JoystickGetDeviceVendor(int device_index);
Uint16 SDL_JoystickGetDeviceProduct(int device_index);
Uint16 SDL_JoystickGetDeviceProductVersion(int device_index);
SDL_JoystickType SDL_JoystickGetDeviceType(int device_index);
SDL_JoystickID SDL_JoystickGetDeviceInstanceID(int device_index);
SDL_Joystick *SDL_JoystickOpen(int device_index);
SDL_Joystick *SDL_JoystickFromInstanceID(SDL_JoystickID instance_id);
SDL_Joystick *SDL_JoystickFromPlayerIndex(int player_index);
int SDL_JoystickAttachVirtual(SDL_JoystickType type, int naxes, int nbuttons, int nhats);
int SDL_JoystickDetachVirtual(int device_index);
SDL_bool SDL_JoystickIsVirtual(int device_index);
int SDL_JoystickSetVirtualAxis(SDL_Joystick *joystick, int axis, Sint16 value);
int SDL_JoystickSetVirtualButton(SDL_Joystick *joystick, int button, Uint8 value);
int SDL_JoystickSetVirtualHat(SDL_Joystick *joystick, int hat, Uint8 value);
const char *SDL_JoystickName(SDL_Joystick *joystick);
int SDL_JoystickGetPlayerIndex(SDL_Joystick *joystick);
void SDL_JoystickSetPlayerIndex(SDL_Joystick *joystick, int player_index);
SDL_JoystickGUID SDL_JoystickGetGUID(SDL_Joystick *joystick);
Uint16 SDL_JoystickGetVendor(SDL_Joystick *joystick);
Uint16 SDL_JoystickGetProduct(SDL_Joystick *joystick);
Uint16 SDL_JoystickGetProductVersion(SDL_Joystick *joystick);
const char * SDL_JoystickGetSerial(SDL_Joystick *joystick);
SDL_JoystickType SDL_JoystickGetType(SDL_Joystick *joystick);
void SDL_JoystickGetGUIDString(SDL_JoystickGUID guid, char *pszGUID, int cbGUID);
SDL_JoystickGUID SDL_JoystickGetGUIDFromString(const char *pchGUID);
SDL_bool SDL_JoystickGetAttached(SDL_Joystick *joystick);
SDL_JoystickID SDL_JoystickInstanceID(SDL_Joystick *joystick);
int SDL_JoystickNumAxes(SDL_Joystick *joystick);
int SDL_JoystickNumBalls(SDL_Joystick *joystick);
int SDL_JoystickNumHats(SDL_Joystick *joystick);
int SDL_JoystickNumButtons(SDL_Joystick *joystick);
void SDL_JoystickUpdate(void);
int SDL_JoystickEventState(int state);

#define SDL_JOYSTICK_AXIS_MAX   32767
#define SDL_JOYSTICK_AXIS_MIN   -32768

Sint16 SDL_JoystickGetAxis(SDL_Joystick *joystick, int axis);
SDL_bool SDL_JoystickGetAxisInitialState(SDL_Joystick *joystick, int axis, Sint16 *state);

#define SDL_HAT_CENTERED    0x00
#define SDL_HAT_UP          0x01
#define SDL_HAT_RIGHT       0x02
#define SDL_HAT_DOWN        0x04
#define SDL_HAT_LEFT        0x08
#define SDL_HAT_RIGHTUP     (SDL_HAT_RIGHT|SDL_HAT_UP)
#define SDL_HAT_RIGHTDOWN   (SDL_HAT_RIGHT|SDL_HAT_DOWN)
#define SDL_HAT_LEFTUP      (SDL_HAT_LEFT|SDL_HAT_UP)
#define SDL_HAT_LEFTDOWN    (SDL_HAT_LEFT|SDL_HAT_DOWN)

Uint8 SDL_JoystickGetHat(SDL_Joystick *joystick, int hat);
int SDL_JoystickGetBall(SDL_Joystick *joystick, int ball, int *dx, int *dy);
Uint8 SDL_JoystickGetButton(SDL_Joystick *joystick, int button);
int SDL_JoystickRumble(SDL_Joystick *joystick, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms);
int SDL_JoystickRumbleTriggers(SDL_Joystick *joystick, Uint16 left_rumble, Uint16 right_rumble, Uint32 duration_ms);
SDL_bool SDL_JoystickHasLED(SDL_Joystick *joystick);
int SDL_JoystickSetLED(SDL_Joystick *joystick, Uint8 red, Uint8 green, Uint8 blue);
void SDL_JoystickClose(SDL_Joystick *joystick);
SDL_JoystickPowerLevel SDL_JoystickCurrentPowerLevel(SDL_Joystick *joystick);

//--------------------------------------------------------------
// Sensors : SDL_sensor.h
//--------------------------------------------------------------

struct _SDL_Sensor;
typedef struct _SDL_Sensor SDL_Sensor;


typedef Sint32 SDL_SensorID;

typedef enum
{
	SDL_SENSOR_INVALID = -1,
	SDL_SENSOR_UNKNOWN,
	SDL_SENSOR_ACCEL,
	SDL_SENSOR_GYRO
} SDL_SensorType;


#define SDL_STANDARD_GRAVITY    9.80665f

void SDL_LockSensors(void);
void SDL_UnlockSensors(void);
int SDL_NumSensors(void);
const char *SDL_SensorGetDeviceName(int device_index);
SDL_SensorType SDL_SensorGetDeviceType(int device_index);
int SDL_SensorGetDeviceNonPortableType(int device_index);
SDL_SensorID SDL_SensorGetDeviceInstanceID(int device_index);
SDL_Sensor *SDL_SensorOpen(int device_index);
SDL_Sensor *SDL_SensorFromInstanceID(SDL_SensorID instance_id);
const char *SDL_SensorGetName(SDL_Sensor *sensor);
SDL_SensorType SDL_SensorGetType(SDL_Sensor *sensor);
int SDL_SensorGetNonPortableType(SDL_Sensor *sensor);
SDL_SensorID SDL_SensorGetInstanceID(SDL_Sensor *sensor);
int SDL_SensorGetData(SDL_Sensor * sensor, float *data, int num_values);
void SDL_SensorClose(SDL_Sensor * sensor);
void SDL_SensorUpdate(void);


//--------------------------------------------------------------
// Game Controller Support : SDL_gamecontroller.h
//--------------------------------------------------------------


struct _SDL_GameController;
typedef struct _SDL_GameController SDL_GameController;

typedef enum
{
	SDL_CONTROLLER_TYPE_UNKNOWN = 0,
	SDL_CONTROLLER_TYPE_XBOX360,
	SDL_CONTROLLER_TYPE_XBOXONE,
	SDL_CONTROLLER_TYPE_PS3,
	SDL_CONTROLLER_TYPE_PS4,
	SDL_CONTROLLER_TYPE_NINTENDO_SWITCH_PRO,
	SDL_CONTROLLER_TYPE_VIRTUAL,
	SDL_CONTROLLER_TYPE_PS5
} SDL_GameControllerType;

typedef enum
{
	SDL_CONTROLLER_BINDTYPE_NONE = 0,
	SDL_CONTROLLER_BINDTYPE_BUTTON,
	SDL_CONTROLLER_BINDTYPE_AXIS,
	SDL_CONTROLLER_BINDTYPE_HAT
} SDL_GameControllerBindType;


typedef struct SDL_GameControllerButtonBind
{
	SDL_GameControllerBindType bindType;
	union
	{
		int button;
		int axis;
		struct {
			int hat;
			int hat_mask;
		} hat;
	} value;
} SDL_GameControllerButtonBind;

//int SDL_GameControllerAddMappingsFromRW(SDL_RWops * rw, int freerw); // TODO ?
//#define SDL_GameControllerAddMappingsFromFile(file)   SDL_GameControllerAddMappingsFromRW(SDL_RWFromFile(file, "rb"), 1) // TODO ?
int SDL_GameControllerAddMapping(const char* mappingString);
int SDL_GameControllerNumMappings(void);
char * SDL_GameControllerMappingForIndex(int mapping_index);
char * SDL_GameControllerMappingForGUID(SDL_JoystickGUID guid);
char * SDL_GameControllerMapping(SDL_GameController *gamecontroller);
SDL_bool SDL_IsGameController(int joystick_index);
const char *SDL_GameControllerNameForIndex(int joystick_index);
SDL_GameControllerType SDL_GameControllerTypeForIndex(int joystick_index);
char *SDL_GameControllerMappingForDeviceIndex(int joystick_index);
SDL_GameController *SDL_GameControllerOpen(int joystick_index);
SDL_GameController *SDL_GameControllerFromInstanceID(SDL_JoystickID joyid);
SDL_GameController *SDL_GameControllerFromPlayerIndex(int player_index);
const char *SDL_GameControllerName(SDL_GameController *gamecontroller);
SDL_GameControllerType SDL_GameControllerGetType(SDL_GameController *gamecontroller);
int SDL_GameControllerGetPlayerIndex(SDL_GameController *gamecontroller);
void SDL_GameControllerSetPlayerIndex(SDL_GameController *gamecontroller, int player_index);
Uint16 SDL_GameControllerGetVendor(SDL_GameController *gamecontroller);
Uint16 SDL_GameControllerGetProduct(SDL_GameController *gamecontroller);
Uint16 SDL_GameControllerGetProductVersion(SDL_GameController *gamecontroller);
const char * SDL_GameControllerGetSerial(SDL_GameController *gamecontroller);
SDL_bool SDL_GameControllerGetAttached(SDL_GameController *gamecontroller);
SDL_Joystick *SDL_GameControllerGetJoystick(SDL_GameController *gamecontroller);
int SDL_GameControllerEventState(int state);
void SDL_GameControllerUpdate(void);



typedef enum
{
	SDL_CONTROLLER_AXIS_INVALID = -1,
	SDL_CONTROLLER_AXIS_LEFTX,
	SDL_CONTROLLER_AXIS_LEFTY,
	SDL_CONTROLLER_AXIS_RIGHTX,
	SDL_CONTROLLER_AXIS_RIGHTY,
	SDL_CONTROLLER_AXIS_TRIGGERLEFT,
	SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
	SDL_CONTROLLER_AXIS_MAX
} SDL_GameControllerAxis;


SDL_GameControllerAxis SDL_GameControllerGetAxisFromString(const char *pchString);
const char* SDL_GameControllerGetStringForAxis(SDL_GameControllerAxis axis);
SDL_GameControllerButtonBind SDL_GameControllerGetBindForAxis(SDL_GameController *gamecontroller, SDL_GameControllerAxis axis);
SDL_bool SDL_GameControllerHasAxis(SDL_GameController *gamecontroller, SDL_GameControllerAxis axis);
Sint16 SDL_GameControllerGetAxis(SDL_GameController *gamecontroller, SDL_GameControllerAxis axis);

typedef enum
{
	SDL_CONTROLLER_BUTTON_INVALID = -1,
	SDL_CONTROLLER_BUTTON_A,
	SDL_CONTROLLER_BUTTON_B,
	SDL_CONTROLLER_BUTTON_X,
	SDL_CONTROLLER_BUTTON_Y,
	SDL_CONTROLLER_BUTTON_BACK,
	SDL_CONTROLLER_BUTTON_GUIDE,
	SDL_CONTROLLER_BUTTON_START,
	SDL_CONTROLLER_BUTTON_LEFTSTICK,
	SDL_CONTROLLER_BUTTON_RIGHTSTICK,
	SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
	SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
	SDL_CONTROLLER_BUTTON_DPAD_UP,
	SDL_CONTROLLER_BUTTON_DPAD_DOWN,
	SDL_CONTROLLER_BUTTON_DPAD_LEFT,
	SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
	SDL_CONTROLLER_BUTTON_MISC1,
	SDL_CONTROLLER_BUTTON_PADDLE1,
	SDL_CONTROLLER_BUTTON_PADDLE2,
	SDL_CONTROLLER_BUTTON_PADDLE3,
	SDL_CONTROLLER_BUTTON_PADDLE4,
	SDL_CONTROLLER_BUTTON_TOUCHPAD,
	SDL_CONTROLLER_BUTTON_MAX
} SDL_GameControllerButton;


SDL_GameControllerButton SDL_GameControllerGetButtonFromString(const char *pchString);
const char* SDL_GameControllerGetStringForButton(SDL_GameControllerButton button);
SDL_GameControllerButtonBind SDL_GameControllerGetBindForButton(SDL_GameController *gamecontroller, SDL_GameControllerButton button);
SDL_bool SDL_GameControllerHasButton(SDL_GameController *gamecontroller, SDL_GameControllerButton button);
Uint8 SDL_GameControllerGetButton(SDL_GameController *gamecontroller, SDL_GameControllerButton button);
int SDL_GameControllerGetNumTouchpads(SDL_GameController *gamecontroller);
int SDL_GameControllerGetNumTouchpadFingers(SDL_GameController *gamecontroller, int touchpad);
int SDL_GameControllerGetTouchpadFinger(SDL_GameController *gamecontroller, int touchpad, int finger, Uint8 *state, float *x, float *y, float *pressure);
SDL_bool SDL_GameControllerHasSensor(SDL_GameController *gamecontroller, SDL_SensorType type);
int SDL_GameControllerSetSensorEnabled(SDL_GameController *gamecontroller, SDL_SensorType type, SDL_bool enabled);
SDL_bool SDL_GameControllerIsSensorEnabled(SDL_GameController *gamecontroller, SDL_SensorType type);
int SDL_GameControllerGetSensorData(SDL_GameController *gamecontroller, SDL_SensorType type, float *data, int num_values);
int SDL_GameControllerRumble(SDL_GameController *gamecontroller, Uint16 low_frequency_rumble, Uint16 high_frequency_rumble, Uint32 duration_ms);
int SDL_GameControllerRumbleTriggers(SDL_GameController *gamecontroller, Uint16 left_rumble, Uint16 right_rumble, Uint32 duration_ms);
SDL_bool SDL_GameControllerHasLED(SDL_GameController *gamecontroller);
int SDL_GameControllerSetLED(SDL_GameController *gamecontroller, Uint8 red, Uint8 green, Uint8 blue);
void SDL_GameControllerClose(SDL_GameController *gamecontroller);


//--------------------------------------------------------------
// Events Handling : SDL_events.h
//--------------------------------------------------------------

#define SDL_RELEASED    0
#define SDL_PRESSED 1


typedef enum
{
	SDL_FIRSTEVENT     = 0,

	SDL_QUIT           = 0x100,

	SDL_APP_TERMINATING,
	SDL_APP_LOWMEMORY,
	SDL_APP_WILLENTERBACKGROUND,
	SDL_APP_DIDENTERBACKGROUND,
	SDL_APP_WILLENTERFOREGROUND,
	SDL_APP_DIDENTERFOREGROUND,

	SDL_LOCALECHANGED,

	SDL_DISPLAYEVENT   = 0x150,

	SDL_WINDOWEVENT    = 0x200,
	SDL_SYSWMEVENT,

	SDL_KEYDOWN        = 0x300,
	SDL_KEYUP,
	SDL_TEXTEDITING,
	SDL_TEXTINPUT,
	SDL_KEYMAPCHANGED,

	SDL_MOUSEMOTION    = 0x400,
	SDL_MOUSEBUTTONDOWN,
	SDL_MOUSEBUTTONUP,
	SDL_MOUSEWHEEL,

	SDL_JOYAXISMOTION  = 0x600,
	SDL_JOYBALLMOTION,
	SDL_JOYHATMOTION,
	SDL_JOYBUTTONDOWN,
	SDL_JOYBUTTONUP,
	SDL_JOYDEVICEADDED,
	SDL_JOYDEVICEREMOVED,

	SDL_CONTROLLERAXISMOTION  = 0x650,
	SDL_CONTROLLERBUTTONDOWN,
	SDL_CONTROLLERBUTTONUP,
	SDL_CONTROLLERDEVICEADDED,
	SDL_CONTROLLERDEVICEREMOVED,
	SDL_CONTROLLERDEVICEREMAPPED,
	SDL_CONTROLLERTOUCHPADDOWN,
	SDL_CONTROLLERTOUCHPADMOTION,
	SDL_CONTROLLERTOUCHPADUP,
	SDL_CONTROLLERSENSORUPDATE,

	SDL_FINGERDOWN      = 0x700,
	SDL_FINGERUP,
	SDL_FINGERMOTION,

	SDL_DOLLARGESTURE   = 0x800,
	SDL_DOLLARRECORD,
	SDL_MULTIGESTURE,

	SDL_CLIPBOARDUPDATE = 0x900,

	SDL_DROPFILE        = 0x1000,
	SDL_DROPTEXT,
	SDL_DROPBEGIN,
	SDL_DROPCOMPLETE,

	SDL_AUDIODEVICEADDED = 0x1100,
	SDL_AUDIODEVICEREMOVED,

	SDL_SENSORUPDATE = 0x1200,

	SDL_RENDER_TARGETS_RESET = 0x2000,
	SDL_RENDER_DEVICE_RESET,

	SDL_USEREVENT    = 0x8000,
	SDL_LASTEVENT    = 0xFFFF
} SDL_EventType;


typedef struct SDL_CommonEvent
{
	Uint32 type;
	Uint32 timestamp;
} SDL_CommonEvent;


typedef struct SDL_DisplayEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 display;
	Uint8 event;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
	Sint32 data1;
} SDL_DisplayEvent;


typedef struct SDL_WindowEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Uint8 event;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
	Sint32 data1;
	Sint32 data2;
} SDL_WindowEvent;


typedef struct SDL_KeyboardEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Uint8 state;
	Uint8 repeat;
	Uint8 padding2;
	Uint8 padding3;
	SDL_Keysym keysym;
} SDL_KeyboardEvent;

#define SDL_TEXTEDITINGEVENT_TEXT_SIZE (32)

typedef struct SDL_TextEditingEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	char text[32]; //SDL_TEXTEDITINGEVENT_TEXT_SIZE];
	Sint32 start;
	Sint32 length;
} SDL_TextEditingEvent;


#define SDL_TEXTINPUTEVENT_TEXT_SIZE (32)

typedef struct SDL_TextInputEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	char text[32]; //SDL_TEXTINPUTEVENT_TEXT_SIZE];
} SDL_TextInputEvent;


typedef struct SDL_MouseMotionEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Uint32 which;
	Uint32 state;
	Sint32 x;
	Sint32 y;
	Sint32 xrel;
	Sint32 yrel;
} SDL_MouseMotionEvent;


typedef struct SDL_MouseButtonEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Uint32 which;
	Uint8 button;
	Uint8 state;
	Uint8 clicks;
	Uint8 padding1;
	Sint32 x;
	Sint32 y;
} SDL_MouseButtonEvent;


typedef struct SDL_MouseWheelEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Uint32 which;
	Sint32 x;
	Sint32 y;
	Uint32 direction;
} SDL_MouseWheelEvent;


typedef struct SDL_JoyAxisEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 axis;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
	Sint16 value;
	Uint16 padding4;
} SDL_JoyAxisEvent;


typedef struct SDL_JoyBallEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 ball;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
	Sint16 xrel;
	Sint16 yrel;
} SDL_JoyBallEvent;


typedef struct SDL_JoyHatEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 hat;
	Uint8 value;
	Uint8 padding1;
	Uint8 padding2;
} SDL_JoyHatEvent;


typedef struct SDL_JoyButtonEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 button;
	Uint8 state;
	Uint8 padding1;
	Uint8 padding2;
} SDL_JoyButtonEvent;


typedef struct SDL_JoyDeviceEvent
{
	Uint32 type;
	Uint32 timestamp;
	Sint32 which;
} SDL_JoyDeviceEvent;



typedef struct SDL_ControllerAxisEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 axis;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
	Sint16 value;
	Uint16 padding4;
} SDL_ControllerAxisEvent;



typedef struct SDL_ControllerButtonEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Uint8 button;
	Uint8 state;
	Uint8 padding1;
	Uint8 padding2;
} SDL_ControllerButtonEvent;



typedef struct SDL_ControllerDeviceEvent
{
	Uint32 type;
	Uint32 timestamp;
	Sint32 which;
} SDL_ControllerDeviceEvent;


typedef struct SDL_ControllerTouchpadEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Sint32 touchpad;
	Sint32 finger;
	float x;
	float y;
	float pressure;
} SDL_ControllerTouchpadEvent;


typedef struct SDL_ControllerSensorEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_JoystickID which;
	Sint32 sensor;
	float data[3];
} SDL_ControllerSensorEvent;


typedef struct SDL_AudioDeviceEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 which;
	Uint8 iscapture;
	Uint8 padding1;
	Uint8 padding2;
	Uint8 padding3;
} SDL_AudioDeviceEvent;



//typedef struct SDL_TouchFingerEvent // TODO ?
//{
//	Uint32 type;
//	Uint32 timestamp;
//	SDL_TouchID touchId;
//	SDL_FingerID fingerId;
//	float x;
//	float y;
//	float dx;
//	float dy;
//	float pressure;
//	Uint32 windowID;
//} SDL_TouchFingerEvent;



//typedef struct SDL_MultiGestureEvent // TODO ?
//{
//	Uint32 type;
//	Uint32 timestamp;
//	SDL_TouchID touchId;
//	float dTheta;
//	float dDist;
//	float x;
//	float y;
//	Uint16 numFingers;
//	Uint16 padding;
//} SDL_MultiGestureEvent;



//typedef struct SDL_DollarGestureEvent // TODO ?
//{
//	Uint32 type;
//	Uint32 timestamp;
//	SDL_TouchID touchId;
//	SDL_GestureID gestureId;
//	Uint32 numFingers;
//	float error;
//	float x;
//	float y;
//} SDL_DollarGestureEvent;



typedef struct SDL_DropEvent
{
	Uint32 type;
	Uint32 timestamp;
	char *file;
	Uint32 windowID;
} SDL_DropEvent;



typedef struct SDL_SensorEvent
{
	Uint32 type;
	Uint32 timestamp;
	Sint32 which;
	float data[6];
} SDL_SensorEvent;


typedef struct SDL_QuitEvent
{
	Uint32 type;
	Uint32 timestamp;
} SDL_QuitEvent;


typedef struct SDL_OSEvent
{
	Uint32 type;
	Uint32 timestamp;
} SDL_OSEvent;


typedef struct SDL_UserEvent
{
	Uint32 type;
	Uint32 timestamp;
	Uint32 windowID;
	Sint32 code;
	void *data1;
	void *data2;
} SDL_UserEvent;


struct SDL_SysWMmsg;
typedef struct SDL_SysWMmsg SDL_SysWMmsg;


typedef struct SDL_SysWMEvent
{
	Uint32 type;
	Uint32 timestamp;
	SDL_SysWMmsg *msg;
} SDL_SysWMEvent;


typedef union SDL_Event
{
	Uint32 type;
	SDL_CommonEvent common;
	SDL_DisplayEvent display;
	SDL_WindowEvent window;
	SDL_KeyboardEvent key;
	SDL_TextEditingEvent edit;
	SDL_TextInputEvent text;
	SDL_MouseMotionEvent motion;
	SDL_MouseButtonEvent button;
	SDL_MouseWheelEvent wheel;
	SDL_JoyAxisEvent jaxis;
	SDL_JoyBallEvent jball;
	SDL_JoyHatEvent jhat;
	SDL_JoyButtonEvent jbutton;
	SDL_JoyDeviceEvent jdevice;
	SDL_ControllerAxisEvent caxis;
	SDL_ControllerButtonEvent cbutton;
	SDL_ControllerDeviceEvent cdevice;
	SDL_ControllerTouchpadEvent ctouchpad;
	SDL_ControllerSensorEvent csensor;
	SDL_AudioDeviceEvent adevice;
	SDL_SensorEvent sensor;
	SDL_QuitEvent quit;
	SDL_UserEvent user;
	SDL_SysWMEvent syswm;
//	SDL_TouchFingerEvent tfinger; // TODO ?
//	SDL_MultiGestureEvent mgesture; // TODO ?
//	SDL_DollarGestureEvent dgesture; // TODO ?
	SDL_DropEvent drop;

	Uint8 padding[56];
} SDL_Event;


void SDL_PumpEvents(void);

typedef enum
{
	SDL_ADDEVENT,
	SDL_PEEKEVENT,
	SDL_GETEVENT
} SDL_eventaction;

int SDL_PeepEvents(SDL_Event * events, int numevents, SDL_eventaction action, Uint32 minType, Uint32 maxType);
SDL_bool SDL_HasEvent(Uint32 type);
SDL_bool SDL_HasEvents(Uint32 minType, Uint32 maxType);
void SDL_FlushEvent(Uint32 type);
void SDL_FlushEvents(Uint32 minType, Uint32 maxType);
int SDL_PollEvent(SDL_Event * event);
int SDL_WaitEvent(SDL_Event * event);
int SDL_WaitEventTimeout(SDL_Event * event, int timeout);
int SDL_PushEvent(SDL_Event * event);
typedef int (* SDL_EventFilter) (void *userdata, SDL_Event * event);
void SDL_SetEventFilter(SDL_EventFilter filter, void *userdata);
SDL_bool SDL_GetEventFilter(SDL_EventFilter * filter, void **userdata);
void SDL_AddEventWatch(SDL_EventFilter filter, void *userdata);
void SDL_DelEventWatch(SDL_EventFilter filter, void *userdata);
void SDL_FilterEvents(SDL_EventFilter filter, void *userdata);

#define SDL_QUERY   -1
#define SDL_IGNORE   0
#define SDL_DISABLE  0
#define SDL_ENABLE   1

Uint8 SDL_EventState(Uint32 type, int state);

#define SDL_GetEventState(type) SDL_EventState(type, SDL_QUERY)

Uint32 SDL_RegisterEvents(int numevents);



//==============================================================
// Force Feedback
//==============================================================

//--------------------------------------------------------------
// Force Feedback Support : SDL_haptic.h
//--------------------------------------------------------------


struct _SDL_Haptic;
typedef struct _SDL_Haptic SDL_Haptic;


#define SDL_HAPTIC_CONSTANT   (1u<<0)
#define SDL_HAPTIC_SINE       (1u<<1)
#define SDL_HAPTIC_LEFTRIGHT     (1u<<2)
#define SDL_HAPTIC_TRIANGLE   (1u<<3)
#define SDL_HAPTIC_SAWTOOTHUP (1u<<4)
#define SDL_HAPTIC_SAWTOOTHDOWN (1u<<5)
#define SDL_HAPTIC_RAMP       (1u<<6)
#define SDL_HAPTIC_SPRING     (1u<<7)
#define SDL_HAPTIC_DAMPER     (1u<<8)
#define SDL_HAPTIC_INERTIA    (1u<<9)
#define SDL_HAPTIC_FRICTION   (1u<<10)
#define SDL_HAPTIC_CUSTOM     (1u<<11)
#define SDL_HAPTIC_GAIN       (1u<<12)
#define SDL_HAPTIC_AUTOCENTER (1u<<13)
#define SDL_HAPTIC_STATUS     (1u<<14)
#define SDL_HAPTIC_PAUSE      (1u<<15)

#define SDL_HAPTIC_POLAR      0
#define SDL_HAPTIC_CARTESIAN  1
#define SDL_HAPTIC_SPHERICAL  2
#define SDL_HAPTIC_STEERING_AXIS 3

#define SDL_HAPTIC_INFINITY   4294967295U


typedef struct SDL_HapticDirection
{
	Uint8 type;
	Sint32 dir[3];
} SDL_HapticDirection;

typedef struct SDL_HapticConstant
{
	Uint16 type;
	SDL_HapticDirection direction;
	Uint32 length;
	Uint16 delay;
	Uint16 button;
	Uint16 interval;
	Sint16 level;
	Uint16 attack_length;
	Uint16 attack_level;
	Uint16 fade_length;
	Uint16 fade_level;
} SDL_HapticConstant;


typedef struct SDL_HapticPeriodic
{
	Uint16 type;
	SDL_HapticDirection direction;
	Uint32 length;
	Uint16 delay;
	Uint16 button;
	Uint16 interval;
	Uint16 period;
	Sint16 magnitude;
	Sint16 offset;
	Uint16 phase;
	Uint16 attack_length;
	Uint16 attack_level;
	Uint16 fade_length;
	Uint16 fade_level;
} SDL_HapticPeriodic;


typedef struct SDL_HapticCondition
{
	Uint16 type;
	SDL_HapticDirection direction;
	Uint32 length;
	Uint16 delay;
	Uint16 button;
	Uint16 interval;
	Uint16 right_sat[3];
	Uint16 left_sat[3];
	Sint16 right_coeff[3];
	Sint16 left_coeff[3];
	Uint16 deadband[3];
	Sint16 center[3];
} SDL_HapticCondition;


typedef struct SDL_HapticRamp
{
	Uint16 type;
	SDL_HapticDirection direction;
	Uint32 length;
	Uint16 delay;
	Uint16 button;
	Uint16 interval;
	Sint16 start;
	Sint16 end;
	Uint16 attack_length;
	Uint16 attack_level;
	Uint16 fade_length;
	Uint16 fade_level;
} SDL_HapticRamp;


typedef struct SDL_HapticLeftRight
{
	Uint16 type;
	Uint32 length;
	Uint16 large_magnitude;
	Uint16 small_magnitude;
} SDL_HapticLeftRight;


typedef struct SDL_HapticCustom
{
	Uint16 type;
	SDL_HapticDirection direction;
	Uint32 length;
	Uint16 delay;
	Uint16 button;
	Uint16 interval;
	Uint8 channels;
	Uint16 period;
	Uint16 samples;
	Uint16 *data;
	Uint16 attack_length;
	Uint16 attack_level;
	Uint16 fade_length;
	Uint16 fade_level;
} SDL_HapticCustom;


typedef union SDL_HapticEffect
{
	Uint16 type;
	SDL_HapticConstant constant;
	SDL_HapticPeriodic periodic;
	SDL_HapticCondition condition;
	SDL_HapticRamp ramp;
	SDL_HapticLeftRight leftright;
	SDL_HapticCustom custom;
} SDL_HapticEffect;


int SDL_NumHaptics(void);
const char *SDL_HapticName(int device_index);
SDL_Haptic *SDL_HapticOpen(int device_index);
int SDL_HapticOpened(int device_index);
int SDL_HapticIndex(SDL_Haptic * haptic);
int SDL_MouseIsHaptic(void);
SDL_Haptic *SDL_HapticOpenFromMouse(void);
int SDL_JoystickIsHaptic(SDL_Joystick * joystick);
SDL_Haptic *SDL_HapticOpenFromJoystick(SDL_Joystick * joystick);
void SDL_HapticClose(SDL_Haptic * haptic);
int SDL_HapticNumEffects(SDL_Haptic * haptic);
int SDL_HapticNumEffectsPlaying(SDL_Haptic * haptic);
unsigned int SDL_HapticQuery(SDL_Haptic * haptic);
int SDL_HapticNumAxes(SDL_Haptic * haptic);
int SDL_HapticEffectSupported(SDL_Haptic * haptic, SDL_HapticEffect * effect);
int SDL_HapticNewEffect(SDL_Haptic * haptic, SDL_HapticEffect * effect);
int SDL_HapticUpdateEffect(SDL_Haptic * haptic, int effect, SDL_HapticEffect * data);
int SDL_HapticRunEffect(SDL_Haptic * haptic, int effect, Uint32 iterations);
int SDL_HapticStopEffect(SDL_Haptic * haptic, int effect);
void SDL_HapticDestroyEffect(SDL_Haptic * haptic, int effect);
int SDL_HapticGetEffectStatus(SDL_Haptic * haptic, int effect);
int SDL_HapticSetGain(SDL_Haptic * haptic, int gain);
int SDL_HapticSetAutocenter(SDL_Haptic * haptic, int autocenter);
int SDL_HapticPause(SDL_Haptic * haptic);
int SDL_HapticUnpause(SDL_Haptic * haptic);
int SDL_HapticStopAll(SDL_Haptic * haptic);
int SDL_HapticRumbleSupported(SDL_Haptic * haptic);
int SDL_HapticRumbleInit(SDL_Haptic * haptic);
int SDL_HapticRumblePlay(SDL_Haptic * haptic, float strength, Uint32 length );
int SDL_HapticRumbleStop(SDL_Haptic * haptic);


//==============================================================
// Threads
//==============================================================

//--------------------------------------------------------------
// Thread Management : SDL_thread.h
//--------------------------------------------------------------

// TODO ? Well ... if you manage to understand this header better
// than me, please, DOTO.


struct SDL_Thread;
typedef struct SDL_Thread SDL_Thread;

typedef unsigned long SDL_threadID;

typedef unsigned int SDL_TLSID;

typedef enum {
    SDL_THREAD_PRIORITY_LOW,
    SDL_THREAD_PRIORITY_NORMAL,
    SDL_THREAD_PRIORITY_HIGH,
    SDL_THREAD_PRIORITY_TIME_CRITICAL
} SDL_ThreadPriority;

typedef int (*SDL_ThreadFunction) (void *data);

SDL_threadID SDL_ThreadID(void);

//--------------------------------------------------------------
// Thread Synchronization Primitives : SDL_mutex.h
//--------------------------------------------------------------


//#define SDL_MUTEX_TIMEDOUT  1
//#define SDL_MUTEX_MAXWAIT   (~(Uint32)0)

struct SDL_mutex;
typedef struct SDL_mutex SDL_mutex;

SDL_mutex *SDL_CreateMutex(void);
//#define SDL_mutexP(m)   SDL_LockMutex(m) // TODO ?
int SDL_LockMutex(SDL_mutex * mutex);
int SDL_TryLockMutex(SDL_mutex * mutex);
//#define SDL_mutexV(m)   SDL_UnlockMutex(m) // TODO ?
int SDL_UnlockMutex(SDL_mutex * mutex);
void SDL_DestroyMutex(SDL_mutex * mutex);

struct SDL_semaphore;
typedef struct SDL_semaphore SDL_sem;

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value);
void SDL_DestroySemaphore(SDL_sem * sem);
int SDL_SemWait(SDL_sem * sem);
int SDL_SemTryWait(SDL_sem * sem);
int SDL_SemWaitTimeout(SDL_sem * sem, Uint32 ms);
int SDL_SemPost(SDL_sem * sem);
Uint32 SDL_SemValue(SDL_sem * sem);

struct SDL_cond;
typedef struct SDL_cond SDL_cond;

SDL_cond *SDL_CreateCond(void);
void SDL_DestroyCond(SDL_cond * cond);
int SDL_CondSignal(SDL_cond * cond);
int SDL_CondBroadcast(SDL_cond * cond);
int SDL_CondWait(SDL_cond * cond, SDL_mutex * mutex);
int SDL_CondWaitTimeout(SDL_cond * cond, SDL_mutex * mutex, Uint32 ms);


//--------------------------------------------------------------
// Atomic Operations : SDL_atomic.h
//--------------------------------------------------------------

typedef int SDL_SpinLock;

SDL_bool SDL_AtomicTryLock(SDL_SpinLock *lock);
void SDL_AtomicLock(SDL_SpinLock *lock);
void SDL_AtomicUnlock(SDL_SpinLock *lock);
void SDL_MemoryBarrierReleaseFunction(void);
void SDL_MemoryBarrierAcquireFunction(void);

typedef struct { int value; } SDL_atomic_t;

SDL_bool SDL_AtomicCAS(SDL_atomic_t *a, int oldval, int newval);
int SDL_AtomicSet(SDL_atomic_t *a, int v);
int SDL_AtomicGet(SDL_atomic_t *a);
int SDL_AtomicAdd(SDL_atomic_t *a, int v);

SDL_bool SDL_AtomicCASPtr(void **a, void *oldval, void *newval);
void* SDL_AtomicSetPtr(void **a, void* v);
void* SDL_AtomicGetPtr(void **a);


//==============================================================
// Audio
//==============================================================

//--------------------------------------------------------------
// Audio Device Management, Playing and Recording : SDL_audio.h
//--------------------------------------------------------------

typedef Uint16 SDL_AudioFormat;

#define SDL_AUDIO_MASK_BITSIZE       (0xFF)
#define SDL_AUDIO_MASK_DATATYPE      (1<<8)
#define SDL_AUDIO_MASK_ENDIAN        (1<<12)
#define SDL_AUDIO_MASK_SIGNED        (1<<15)
#define SDL_AUDIO_BITSIZE(x)         (x & SDL_AUDIO_MASK_BITSIZE)
#define SDL_AUDIO_ISFLOAT(x)         (x & SDL_AUDIO_MASK_DATATYPE)
#define SDL_AUDIO_ISBIGENDIAN(x)     (x & SDL_AUDIO_MASK_ENDIAN)
#define SDL_AUDIO_ISSIGNED(x)        (x & SDL_AUDIO_MASK_SIGNED)
#define SDL_AUDIO_ISINT(x)           (!SDL_AUDIO_ISFLOAT(x))
#define SDL_AUDIO_ISLITTLEENDIAN(x)  (!SDL_AUDIO_ISBIGENDIAN(x))
#define SDL_AUDIO_ISUNSIGNED(x)      (!SDL_AUDIO_ISSIGNED(x))

#define AUDIO_U8        0x0008
#define AUDIO_S8        0x8008
#define AUDIO_U16LSB    0x0010
#define AUDIO_S16LSB    0x8010
#define AUDIO_U16MSB    0x1010
#define AUDIO_S16MSB    0x9010
#define AUDIO_U16       AUDIO_U16LSB
#define AUDIO_S16       AUDIO_S16LSB

#define AUDIO_S32LSB    0x8020
#define AUDIO_S32MSB    0x9020
#define AUDIO_S32       AUDIO_S32LSB

#define AUDIO_F32LSB    0x8120
#define AUDIO_F32MSB    0x9120
#define AUDIO_F32       AUDIO_F32LSB

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
#define AUDIO_U16SYS    AUDIO_U16LSB
#define AUDIO_S16SYS    AUDIO_S16LSB
#define AUDIO_S32SYS    AUDIO_S32LSB
#define AUDIO_F32SYS    AUDIO_F32LSB
#else
#define AUDIO_U16SYS    AUDIO_U16MSB
#define AUDIO_S16SYS    AUDIO_S16MSB
#define AUDIO_S32SYS    AUDIO_S32MSB
#define AUDIO_F32SYS    AUDIO_F32MSB
#endif

#define SDL_AUDIO_ALLOW_FREQUENCY_CHANGE    0x00000001
#define SDL_AUDIO_ALLOW_FORMAT_CHANGE       0x00000002
#define SDL_AUDIO_ALLOW_CHANNELS_CHANGE     0x00000004
#define SDL_AUDIO_ALLOW_SAMPLES_CHANGE      0x00000008
#define SDL_AUDIO_ALLOW_ANY_CHANGE          (SDL_AUDIO_ALLOW_FREQUENCY_CHANGE|SDL_AUDIO_ALLOW_FORMAT_CHANGE|SDL_AUDIO_ALLOW_CHANNELS_CHANGE|SDL_AUDIO_ALLOW_SAMPLES_CHANGE)

typedef void (* SDL_AudioCallback) (void *userdata, Uint8 * stream, int len);

typedef struct SDL_AudioSpec
{
	int freq;
	SDL_AudioFormat format;
	Uint8 channels;
	Uint8 silence;
	Uint16 samples;
	Uint16 padding;
	Uint32 size;
	SDL_AudioCallback callback;
	void *userdata;
} SDL_AudioSpec;


struct SDL_AudioCVT;
typedef void (* SDL_AudioFilter) (struct SDL_AudioCVT * cvt, SDL_AudioFormat format);

#define SDL_AUDIOCVT_MAX_FILTERS 9
#define SDL_AUDIOCVT_PACKED __attribute__((packed))

typedef struct SDL_AudioCVT
{
	int needed;
	SDL_AudioFormat src_format;
	SDL_AudioFormat dst_format;
	double rate_incr;
	Uint8 *buf;
	int len;
	int len_cvt;
	int len_mult;
	double len_ratio;
	SDL_AudioFilter filters[10]; //SDL_AUDIOCVT_MAX_FILTERS + 1];
	int filter_index;
} /* SDL_AUDIOCVT_PACKED */ SDL_AudioCVT; // FIXME ???

int SDL_GetNumAudioDrivers(void);
const char *SDL_GetAudioDriver(int index);
int SDL_AudioInit(const char *driver_name);
void SDL_AudioQuit(void);
const char *SDL_GetCurrentAudioDriver(void);
int SDL_OpenAudio(SDL_AudioSpec * desired, SDL_AudioSpec * obtained);

typedef Uint32 SDL_AudioDeviceID;

int SDL_GetNumAudioDevices(int iscapture);
const char *SDL_GetAudioDeviceName(int index, int iscapture);
SDL_AudioDeviceID SDL_OpenAudioDevice(const char *device, int iscapture, const SDL_AudioSpec * desired, SDL_AudioSpec * obtained, int allowed_changes);

typedef enum
{
	SDL_AUDIO_STOPPED = 0,
	SDL_AUDIO_PLAYING,
	SDL_AUDIO_PAUSED
} SDL_AudioStatus;

SDL_AudioStatus SDL_GetAudioStatus(void);
SDL_AudioStatus SDL_GetAudioDeviceStatus(SDL_AudioDeviceID dev);
void SDL_PauseAudio(int pause_on);
void SDL_PauseAudioDevice(SDL_AudioDeviceID dev, int pause_on);

//SDL_AudioSpec *SDL_LoadWAV_RW(SDL_RWops * src, int freesrc, SDL_AudioSpec * spec, Uint8 ** audio_buf, Uint32 * audio_len); // TODO ?
//#define SDL_LoadWAV(file, spec, audio_buf, audio_len) SDL_LoadWAV_RW(SDL_RWFromFile(file, "rb"),1, spec,audio_buf,audio_len) // TODO ?

//void SDL_FreeWAV(Uint8 * audio_buf); // TODO ?

int SDL_BuildAudioCVT(SDL_AudioCVT * cvt, SDL_AudioFormat src_format, Uint8 src_channels, int src_rate, SDL_AudioFormat dst_format, Uint8 dst_channels, int dst_rate);
int SDL_ConvertAudio(SDL_AudioCVT * cvt);

struct _SDL_AudioStream;
typedef struct _SDL_AudioStream SDL_AudioStream;

SDL_AudioStream * SDL_NewAudioStream(const SDL_AudioFormat src_format, const Uint8 src_channels, const int src_rate, const SDL_AudioFormat dst_format, const Uint8 dst_channels, const int dst_rate);
int SDL_AudioStreamPut(SDL_AudioStream *stream, const void *buf, int len);
int SDL_AudioStreamGet(SDL_AudioStream *stream, void *buf, int len);
int SDL_AudioStreamAvailable(SDL_AudioStream *stream);
int SDL_AudioStreamFlush(SDL_AudioStream *stream);
void SDL_AudioStreamClear(SDL_AudioStream *stream);
void SDL_FreeAudioStream(SDL_AudioStream *stream);

#define SDL_MIX_MAXVOLUME 128

void SDL_MixAudio(Uint8 * dst, const Uint8 * src, Uint32 len, int volume);
void SDL_MixAudioFormat(Uint8 * dst, const Uint8 * src, SDL_AudioFormat format, Uint32 len, int volume);
int SDL_QueueAudio(SDL_AudioDeviceID dev, const void *data, Uint32 len);
Uint32 SDL_DequeueAudio(SDL_AudioDeviceID dev, void *data, Uint32 len);
Uint32 SDL_GetQueuedAudioSize(SDL_AudioDeviceID dev);
void SDL_ClearQueuedAudio(SDL_AudioDeviceID dev);

void SDL_LockAudio(void);
void SDL_LockAudioDevice(SDL_AudioDeviceID dev);
void SDL_UnlockAudio(void);
void SDL_UnlockAudioDevice(SDL_AudioDeviceID dev);

void SDL_CloseAudio(void);
void SDL_CloseAudioDevice(SDL_AudioDeviceID dev);



//==============================================================
// Timers
//==============================================================

//--------------------------------------------------------------
// Timer Support : SDL_timer.h
//--------------------------------------------------------------

Uint32 SDL_GetTicks(void);

#define SDL_TICKS_PASSED(A, B)  ((Sint32)((B) - (A)) <= 0)

Uint64 SDL_GetPerformanceCounter(void);
Uint64 SDL_GetPerformanceFrequency(void);
void SDL_Delay(Uint32 ms);

typedef Uint32 (* SDL_TimerCallback) (Uint32 interval, void *param);

typedef int SDL_TimerID;

SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_TimerCallback callback, void *param);
SDL_bool SDL_RemoveTimer(SDL_TimerID id);


//==============================================================
// File Abstraction
//==============================================================

//--------------------------------------------------------------
// Filesystem Paths : SDL_filesystem.h
//--------------------------------------------------------------

// TODO or not TODO ? ... that is the question

//--------------------------------------------------------------
// File I/O Abstraction : SDL_rwops.h
//--------------------------------------------------------------

// TODO or not TODO ? ... that is another same question

//==============================================================
// Shared Object Support
//==============================================================

//--------------------------------------------------------------
// Shared Object Loading and Function Lookup : SDL_loadso.h
//--------------------------------------------------------------

// TODO or FFI ? ... that is a different similar question


//==============================================================
// Platform and CPU information
//==============================================================

//--------------------------------------------------------------
// Platform Detection : SDL_platform.h
//--------------------------------------------------------------

const char * SDL_GetPlatform (void);

//--------------------------------------------------------------
// CPU Feature Detection : SDL_cpuinfo.h
//--------------------------------------------------------------

#define SDL_CACHELINE_SIZE  128

int      SDL_GetCPUCount(void);
int      SDL_GetCPUCacheLineSize(void);
SDL_bool SDL_HasRDTSC(void);
SDL_bool SDL_HasAltiVec(void);
SDL_bool SDL_HasMMX(void);
SDL_bool SDL_Has3DNow(void);
SDL_bool SDL_HasSSE(void);
SDL_bool SDL_HasSSE2(void);
SDL_bool SDL_HasSSE3(void);
SDL_bool SDL_HasSSE41(void);
SDL_bool SDL_HasSSE42(void);
SDL_bool SDL_HasAVX(void);
SDL_bool SDL_HasAVX2(void);
SDL_bool SDL_HasAVX512F(void);
SDL_bool SDL_HasARMSIMD(void);
SDL_bool SDL_HasNEON(void);
int      SDL_GetSystemRAM(void);
size_t   SDL_SIMDGetAlignment(void);
void *   SDL_SIMDAlloc(const size_t len);
void *   SDL_SIMDRealloc(void *mem, const size_t len);
void     SDL_SIMDFree(void *ptr);


//--------------------------------------------------------------
// Byte Order and Byte Swapping : SDL_endian.h
//--------------------------------------------------------------

// TODO or PHP is ennough ?


//--------------------------------------------------------------
// Bit Manipulation : SDL_bits.h
//--------------------------------------------------------------

// TODO or you think i'm getting lazzy ?


//==============================================================
// Power Management
//==============================================================

//--------------------------------------------------------------
// Power Management Status : SDL_power.h
//--------------------------------------------------------------

typedef enum
{
	SDL_POWERSTATE_UNKNOWN,
	SDL_POWERSTATE_ON_BATTERY,
	SDL_POWERSTATE_NO_BATTERY,
	SDL_POWERSTATE_CHARGING,
	SDL_POWERSTATE_CHARGED
} SDL_PowerState;


SDL_PowerState SDL_GetPowerInfo(int *secs, int *pct);




//==============================================================
// Additional Functionality
//==============================================================

//--------------------------------------------------------------
// Platform-specific Functionality : SDL_system.h
//--------------------------------------------------------------

// TODO ?

//--------------------------------------------------------------
// Standard Library Functionnality : SDL_stdinc.h
//--------------------------------------------------------------

// /!\  many SDL functions are ignored bellow ... !!
// TODO ? FIXME ? IGNORE ?

void *SDL_malloc(size_t size);
void *SDL_calloc(size_t nmemb, size_t size);
void *SDL_realloc(void *mem, size_t size);
void SDL_free(void *mem);

typedef void *(*SDL_malloc_func)(size_t size);
typedef void *(*SDL_calloc_func)(size_t nmemb, size_t size);
typedef void *(*SDL_realloc_func)(void *mem, size_t size);
typedef void (*SDL_free_func)(void *mem);

void SDL_GetMemoryFunctions(SDL_malloc_func *malloc_func, SDL_calloc_func *calloc_func, SDL_realloc_func *realloc_func, SDL_free_func *free_func);
int  SDL_SetMemoryFunctions(SDL_malloc_func  malloc_func, SDL_calloc_func  calloc_func, SDL_realloc_func  realloc_func, SDL_free_func  free_func);

int SDL_GetNumAllocations(void);

char *SDL_getenv(const char *name);
int SDL_setenv(const char *name, const char *value, int overwrite);

void SDL_qsort(void *base, size_t nmemb, size_t size, int (*compare) (const void *, const void *));

int SDL_abs(int x);

int SDL_isdigit(int x);
int SDL_isspace(int x);
int SDL_isupper(int x);
int SDL_islower(int x);
int SDL_toupper(int x);
int SDL_tolower(int x);

Uint32 SDL_crc32(Uint32 crc, const void *data, size_t len);

void *SDL_memset( void *dst, int c, size_t len);

//#define SDL_zero(x) SDL_memset(&(x), 0, sizeof((x))) // TODO ?
//#define SDL_zerop(x) SDL_memset((x), 0, sizeof(*(x))) // TODO ?
//#define SDL_zeroa(x) SDL_memset((x), 0, sizeof((x))) // TODO ?

void *SDL_memcpy( void *dst, const void *src, size_t len);

void *SDL_memmove( void *dst, const void *src, size_t len);
int SDL_memcmp(const void *s1, const void *s2, size_t len);

//size_t SDL_wcslen(const wchar_t *wstr); // TODO ?
//size_t SDL_wcslcpy(wchar_t *dst, const wchar_t *src, size_t maxlen); // TODO ?
//size_t SDL_wcslcat(wchar_t *dst, const wchar_t *src, size_t maxlen); // TODO ?
//wchar_t *SDL_wcsdup(const wchar_t *wstr); // TODO ?
//wchar_t *SDL_wcsstr(const wchar_t *haystack, const wchar_t *needle); // TODO ?

//int SDL_wcscmp(const wchar_t *str1, const wchar_t *str2); // TODO ?
//int SDL_wcsncmp(const wchar_t *str1, const wchar_t *str2, size_t maxlen); // TODO ?
//int SDL_wcscasecmp(const wchar_t *str1, const wchar_t *str2); // TODO ?
//int SDL_wcsncasecmp(const wchar_t *str1, const wchar_t *str2, size_t len); // TODO ?

//size_t SDL_strlen(const char *str); // TODO ?
//size_t SDL_strlcpy(char *dst, const char *src, size_t maxlen); // TODO ?
//size_t SDL_utf8strlcpy(char *dst, const char *src, size_t dst_bytes); // TODO ?
//size_t SDL_strlcat(char *dst, const char *src, size_t maxlen); // TODO ?
//char *SDL_strdup(const char *str); // TODO ?
//char *SDL_strrev(char *str); // TODO ?
//char *SDL_strupr(char *str); // TODO ?
//char *SDL_strlwr(char *str); // TODO ?
//char *SDL_strchr(const char *str, int c); // TODO ?
//char *SDL_strrchr(const char *str, int c); // TODO ?
//char *SDL_strstr(const char *haystack, const char *needle); // TODO ?
//char *SDL_strtokr(char *s1, const char *s2, char **saveptr); // TODO ?
//size_t SDL_utf8strlen(const char *str); // TODO ?

//char *SDL_itoa(int value, char *str, int radix); // TODO ?
//char *SDL_uitoa(unsigned int value, char *str, int radix); // TODO ?
//char *SDL_ltoa(long value, char *str, int radix); // TODO ?
//char *SDL_ultoa(unsigned long value, char *str, int radix); // TODO ?
//char *SDL_lltoa(Sint64 value, char *str, int radix); // TODO ?
//char *SDL_ulltoa(Uint64 value, char *str, int radix); // TODO ?

//int SDL_atoi(const char *str); // TODO ?
//double SDL_atof(const char *str); // TODO ?
//long SDL_strtol(const char *str, char **endp, int base); // TODO ?
//unsigned long SDL_strtoul(const char *str, char **endp, int base); // TODO ?
//Sint64 SDL_strtoll(const char *str, char **endp, int base); // TODO ?
//Uint64 SDL_strtoull(const char *str, char **endp, int base); // TODO ?
//double SDL_strtod(const char *str, char **endp); // TODO ?

//int SDL_strcmp(const char *str1, const char *str2); // TODO ?
//int SDL_strncmp(const char *str1, const char *str2, size_t maxlen); // TODO ?
//int SDL_strcasecmp(const char *str1, const char *str2); // TODO ?
//int SDL_strncasecmp(const char *str1, const char *str2, size_t len); // TODO ?

//int SDL_sscanf(const char *text, const char *fmt, ...); // TODO ?
//int SDL_vsscanf(const char *text, const char *fmt, va_list ap); // TODO ?
//int SDL_snprintf(char *text, size_t maxlen, const char *fmt, ... ); // TODO ?
//int SDL_vsnprintf(char *text, size_t maxlen, const char *fmt, va_list ap); // TODO ?

double SDL_acos(double x);
float SDL_acosf(float x);
double SDL_asin(double x);
float SDL_asinf(float x);
double SDL_atan(double x);
float SDL_atanf(float x);
double SDL_atan2(double x, double y);
float SDL_atan2f(float x, float y);
double SDL_ceil(double x);
float SDL_ceilf(float x);
double SDL_copysign(double x, double y);
float SDL_copysignf(float x, float y);
double SDL_cos(double x);
float SDL_cosf(float x);
double SDL_exp(double x);
float SDL_expf(float x);
double SDL_fabs(double x);
float SDL_fabsf(float x);
double SDL_floor(double x);
float SDL_floorf(float x);
double SDL_trunc(double x);
float SDL_truncf(float x);
double SDL_fmod(double x, double y);
float SDL_fmodf(float x, float y);
double SDL_log(double x);
float SDL_logf(float x);
double SDL_log10(double x);
float SDL_log10f(float x);
double SDL_pow(double x, double y);
float SDL_powf(float x, float y);
double SDL_scalbn(double x, int n);
float SDL_scalbnf(float x, int n);
double SDL_sin(double x);
float SDL_sinf(float x);
double SDL_sqrt(double x);
float SDL_sqrtf(float x);
double SDL_tan(double x);
float SDL_tanf(float x);

//typedef struct _SDL_iconv_t *SDL_iconv_t; // TODO ?
//
//SDL_iconv_t SDL_iconv_open(const char *tocode, const char *fromcode); // TODO ?
//int SDL_iconv_close(SDL_iconv_t cd); // TODO ?
//size_t SDL_iconv(SDL_iconv_t cd, const char **inbuf, size_t * inbytesleft, char **outbuf, size_t * outbytesleft); // TODO ?
//
//char *SDL_iconv_string(const char *tocode, const char *fromcode, const char *inbuf, size_t inbytesleft); // TODO ?
//
//#define SDL_iconv_utf8_locale(S)    SDL_iconv_string("", "UTF-8", S, SDL_strlen(S)+1) // TODO ?
//#define SDL_iconv_utf8_ucs2(S)      (Uint16 *)SDL_iconv_string("UCS-2-INTERNAL", "UTF-8", S, SDL_strlen(S)+1) // TODO ?
//#define SDL_iconv_utf8_ucs4(S)      (Uint32 *)SDL_iconv_string("UCS-4-INTERNAL", "UTF-8", S, SDL_strlen(S)+1) // TODO ?


// -------------------------------------------------
