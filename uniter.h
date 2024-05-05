/* \33[ = <CSI> \33 = <ESC> */
#define vt220
#ifdef  vt220
#define BELL "\7"
#define HOME "\033[H"
#define CLR  "\033[J"
#define REVERSEON "\33[7m"
#define REVERSEOFF "\33[27m"
#define BLINKING   "\33[5m"
#define NOBLINKING "\33[25m"
#define UNDERLINE  "\33[4m"
#define NOUNDERLINE "\33[24m"
#define INCREAS "\33[1m"
#define NOINCREAS "\33[22m"
#define CURSORUP "\33M"
#define CURSORDOWN "\33D"
#define CURSORRIGHT "\33[1C"
#define CURSORLEFT  "\33[1D"
#define SAVECURSOR  "\0337"
#define RESTORECURSOR "\0338"
#define GRAFIC "\33)0\33~"
#define SELCAR "\33[1\042q"
#define SELDCAR "\33[2\042q"
#define ENDSEL "\33[042q"
#define DELCHARS "\33[?2J"
#define SINGLE_WIDTH "\33#5"
#define DOUBLE_WIDTH "\33#6"
#define HALF_TOP "\33#3"
#define HALF_BOTTOM "\33#4"
#define FORWARD "\33[%dC"
#define BACHWARD "\33[%dD"
#define DELCH "\33[%dP"
#define ERACH "\33[%dX"
#define CURSOR "\33[%d;%dH"
#define SETSCROLL "\33[%d;%dr"
#endif
#define RED 31
#define GREEN 32
#define BLUE 34
#define terminal printf
#define pcolor(col, str) printf("\033[%dm%s\033[0m", col, str)
//#define cursor(l,c) printf("\033[%d;%dH",l,c)
#define cursor(l,c) printf("\033[%d;%dH",l,c)
