/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int minwsz    = 20;       /* Minimal height of a client for smfact */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
// static const char *fonts[]          = { "monospace:size=10" };
static const char *fonts[]          = { "JetBrainsMono Nerd Font:medium:size=11" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:medium:size=11";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

static const char polar_night1[]    = "#181b21";
static const char polar_night2[]    = "#2E3440";
static const char polar_night3[]    = "#3B4252";
static const char polar_night4[]    = "#434C5E";
static const char polar_night5[]    = "#4C566A";

static const char snow_storm1[]     = "#D8DEE9";
static const char snow_storm2[]     = "#E5E9F0";
static const char snow_storm3[]     = "#ECEFF4";

static const char frost1[]          = "#8FBCBB";
static const char frost2[]          = "#88C0D0";
static const char frost3[]          = "#81A1C1";
static const char frost4[]          = "#5E81AC";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { snow_storm1, polar_night1, polar_night1 },
	[SchemeSel]  = { polar_night1, frost3, snow_storm1 },
	[SchemeStatus] = { col_gray3, col_gray1, "#000000" },  // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel] = { polar_night1, frost3, "#000000" },  // Tagbar left slected {text,background,not used but cannot be empty}
	[SchemeTagsNorm] = { snow_storm1, polar_night1, "#000000" },  // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel] = { snow_storm1, polar_night1, "#000000" },  // infobar middle selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm] = { snow_storm1, polar_night1, "#000000" },  // infobar middle unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const float smfact    = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", polar_night1, "-nf", snow_storm1, "-sb", frost3, "-sf", polar_night1, NULL };
static const char *termcmd[]  = { "kitty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* modifier = 0 means no modifier */ 
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,  					            XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_g,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_s,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      setsmfact,      {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_k,      setsmfact,      {.f = +0.05} },
	{ MODKEY,                       XK_f, 		 zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY, 				              XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_w,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_t,  		 setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_r,  		 togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/* Screenshots */
	{ 0,                       			XK_Print,  spawn,          SHCMD("flameshot gui") },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
