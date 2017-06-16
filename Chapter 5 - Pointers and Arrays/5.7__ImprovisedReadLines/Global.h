// MACROS

#define MAXLINES	100
#define MAXLENGTH	50
#define OVERFLOW	-
#define EOI		'%'
#define NEWLINE		'\n'

#define NEW_CHARACTER_EXISTS(character) (character=getchar())!=EOI&&(character!=NEWLINE)