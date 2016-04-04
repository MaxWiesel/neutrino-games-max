/*
** initial coding by fx2
*/

#define __STDC_CONSTANT_MACROS

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

extern "C"
{
#include "draw.h"
#include "fx2math.h"
#include "pig.h"
//#include <plugin.h"
#include "rcinput.h"
}

#include "pnm_file.h"

#include "Table.h"
#define CONFIGDIR "."
#define GAMESDIR "."

extern	int				debug;
extern	int				doexit;
extern	unsigned short	actcode;
extern	unsigned short	realcode;

#define	RC_0			0
#define	RC_1			1
#define	RC_2			2
#define	RC_3			3
#define	RC_4			4
#define	RC_5			5
#define	RC_6			6
#define	RC_7			7
#define	RC_8			8
#define	RC_9			9

int main( )
{
	int 			rc = 0;

	CTable table;

	int fdfb = -1, fdrc = -1;
	if ( FBInitialize( 720, 576, 8, fdfb ) < 0 )
		return -1;

	Set_8Bit_Pal();
	FBFillRect( 0, 0, 1400, 800, BNR0 );

	if ( RcInitialize( fdrc ) < 0 )
		return -1;

	rc = table.Run();

	RcClose();

	FBClose();

	return rc;
}

//extern "C"
//{
//	int plugin_exec( PluginParam *par )
//	{
//		int		fd_fb=-1;
//		int		fd_rc=-1;
//
//		for( ; par; par=par->next )
//		{
//			if ( !strcmp(par->id,P_ID_FBUFFER) )
//				fd_fb=_atoi(par->val);
//			else if ( !strcmp(par->id,P_ID_RCINPUT) )
//				fd_rc=_atoi(par->val);
//			else if ( !strcmp(par->id,P_ID_NOPIG) )
//				fx2_use_pig=!_atoi(par->val);
//		}
//
//		return solitair_exec( fd_fb, fd_rc, -1, 0 );
//	}
//}
