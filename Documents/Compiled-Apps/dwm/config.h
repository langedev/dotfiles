/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$XDG_CONFIG_HOME/polybar/dwm.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "Cascadia Codes:size=10" };
//static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_foreground[]  = "#D9E0EE";
static const char col_background[]  = "#1E1D2F";
static const char col_primary[]     = "#F5C2E7";
static const char *colors[][3]      = {
	/*               fg              bg              border   */
	[SchemeNorm] = { col_foreground, col_background, col_background },
	[SchemeSel]  = { col_foreground, col_background, col_primary  },
};

static const char *const autostart[] = {
	"picom", NULL,
	"fcitx", "-d", NULL,
	"feh", "--no-fehbg", "--bg-center", "/home/pan/Pictures/bg.png", NULL,
	"sxhkd", "-c", "/home/pan/.config/sxhkd/sxhkdrc.dwm", NULL,
	"bluetoothctl", "power", "on", NULL,
	NULL /* terminate */
};

/* tagging */
static const char *tags[] = { "dev", "web", "chat", "note", "med", "etc" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,       NULL,       NULL,       0,            False,       -1 },
};

/* layout(s) */
static const float mfact     = 0.75; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "dk",      deck },   /* first entry is default */
	{ "mn",      monocle },
	{ "ms",      tile },
	{ "fl",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-n", "-p", "run", NULL };
//static const char *termcmd[]  = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "alacritty", "-t", scratchpadname, "-o", "font.size=12", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier            key        function        argument */
	{ MODKEY|ShiftMask,    XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,              XK_grave,  togglescratch,  {.v = scratchpadcmd } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click          event mask   button     function        argument */
	{ ClkClientWin,   MODKEY,      Button1,   movemouse,      {0} },
	{ ClkClientWin,   MODKEY,      Button2,   togglefloating, {0} },
	{ ClkClientWin,   MODKEY,      Button3,   resizemouse,    {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
 IPCCOMMAND( tag,                 1,  {ARG_TYPE_UINT}  ),
 IPCCOMMAND( toggleview,          1,  {ARG_TYPE_UINT}  ),
 IPCCOMMAND( view,                1,  {ARG_TYPE_UINT}  ),
 IPCCOMMAND( cyclelayout,         1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( focusmon,            1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( focusstack,          1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( incnmaster,          1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( killclient,          1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( movestack,           1,  {ARG_TYPE_SINT}  ),
 IPCCOMMAND( setmfact,            1,  {ARG_TYPE_FLOAT} ),
 IPCCOMMAND( togglebar,           1,  {ARG_TYPE_NONE}  ),
 IPCCOMMAND( togglefloating,      1,  {ARG_TYPE_NONE}  ),
 IPCCOMMAND( quit,                1,  {ARG_TYPE_NONE}  )
};
