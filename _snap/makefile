############################################################################
#
#  ========================================================================
#
#   Copyright (C) 1991-2004 SciTech Software, Inc. All rights reserved.
#
#   This file may be distributed and/or modified under the terms of the
#   GNU General Public License version 2.0 as published by the Free
#   Software Foundation and appearing in the file LICENSE.GPL included
#   in the packaging of this file.
#
#   Licensees holding a valid Commercial License for this product from
#   SciTech Software, Inc. may use this file in accordance with the
#   Commercial License Agreement provided with the Software.
#
#   This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING
#   THE WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#   PURPOSE.
#
#   See http://www.scitechsoft.com/license/ for information about
#   the licensing options available and how to purchase a Commercial
#   License Agreement.
#
#   Contact license@scitechsoft.com if any conditions of this licensing
#   are not clear to you, or you have questions about licensing options.
#
#  ========================================================================
#
# Descripton:   Makefile for the OpenGL demos.
#
#############################################################################

# Allow for linking with precompiled GLUT32 library instead of MGL GLUT library
.IMPORT .IGNORE: USE_GLUT32

# Link with standard MGL libraries

.INCLUDE: "../../../mgl.mak"

# Link with common libraries

.IF $(STKCALL)
BASELIBS         += $(LL)sglut$(LE)
.ELSE
BASELIBS         += $(LL)glut$(LE)
.ENDIF

.IF $(WIN32_GUI)
CFLAGS          += -DUSE_SNAP -DWIN32
.ELSE
CFLAGS          += -DUSE_SNAP -DUSE_DOS -UWIN32
.ENDIF

.IF $(USE_GLUT32)
CFLAGS          += -DNO_GL_MACROS -DNO_GLU_MACROS
CFLAGS		+= /Gz
LDENDFLAGS      += /SUBSYSTEM:console
.ENDIF

# Names of all executable files built
EXEFILES        = glex_snap$E

.IF $(USE_GLUT32)
EXELIBS         = $(LL)glut32$(LE) $(LL)opengl32$(LE) $(LL)glu32$(LE)
.ELSE
EXELIBS         = $(BASELIBS)
.ENDIF

.IF $(WIN32_GUI)
RCFILE          = demo$R
.ELSE
RCFILE          =
.ENDIF

all: $(EXEFILES)

GATST_OBJS  = glxsglut$O scene01$O scene02$O scene03$O scene04$O scene05$O scene06$O scene07$O scene08$O scene09$O scene10$O scene11$O scene12$O Texture$O utils$O

glex_snap$E:  $(GATST_OBJS) $(RCFILE)

#----------------------------------------------------------------------------
# Define the list of object files to create dependency information for
#----------------------------------------------------------------------------

DEPEND_OBJ      = $(GATST_OBJS)
DEPEND_SRC      = src;

.INCLUDE: "$(SCITECH)/makedefs/common.mk"

