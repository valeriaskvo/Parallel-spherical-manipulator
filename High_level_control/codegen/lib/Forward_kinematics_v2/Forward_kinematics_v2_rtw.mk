###########################################################################
## Makefile generated for MATLAB file/project 'Forward_kinematics_v2'. 
## 
## Makefile     : Forward_kinematics_v2_rtw.mk
## Generated on : Wed Apr 01 16:27:26 2020
## MATLAB Coder version: 4.3 (R2019b)
## 
## Build Info:
## 
## Final product: ./Forward_kinematics_v2.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = Forward_kinematics_v2
MAKEFILE                  = Forward_kinematics_v2_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2019b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2019b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
MASTER_ANCHOR_DIR         = 
START_DIR                 = C:/Users/valer/DOCUME~1/INNOPO~1/DIPLOM~1/PSMGIT~1/FORWAR~1/codegen/lib/FORWAR~2
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = Forward_kinematics_v2_rtw_comp.rsp
CMD_FILE                  = Forward_kinematics_v2_rtw.rsp
C_STANDARD_OPTS           = -fwrapv
CPP_STANDARD_OPTS         = -fwrapv
MODELLIB                  = Forward_kinematics_v2.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          MinGW64 | gmake (64-bit Windows)
# Supported Version(s):    6.x
# ToolchainInfo Version:   2019b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS
# MINGW_ROOT
# MINGW_C_STANDARD_OPTS

#-----------
# MACROS
#-----------

WARN_FLAGS            = -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes -Wnested-externs -Wpointer-arith -Wcast-align
WARN_FLAGS_MAX        = $(WARN_FLAGS) -Wcast-qual -Wshadow
CPP_WARN_FLAGS        = -Wall -W -Wwrite-strings -Winline -Wpointer-arith -Wcast-align
CPP_WARN_FLAGS_MAX    = $(CPP_WARN_FLAGS) -Wcast-qual -Wshadow
MW_EXTERNLIB_DIR      = $(MATLAB_ROOT)/extern/lib/win64/mingw64
SHELL                 = %SystemRoot%/system32/cmd.exe

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lws2_32

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: GNU C Compiler
CC_PATH = $(MINGW_ROOT)
CC = "$(CC_PATH)/gcc"

# Linker: GNU Linker
LD_PATH = $(MINGW_ROOT)
LD = "$(LD_PATH)/g++"

# C++ Compiler: GNU C++ Compiler
CPP_PATH = $(MINGW_ROOT)
CPP = "$(CPP_PATH)/g++"

# C++ Linker: GNU C++ Linker
CPP_LD_PATH = $(MINGW_ROOT)
CPP_LD = "$(CPP_LD_PATH)/g++"

# Archiver: GNU Archiver
AR_PATH = $(MINGW_ROOT)
AR = "$(AR_PATH)/ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @move
RUN                 =

#----------------------------------------
# "Faster Builds" Build Configuration
#----------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c $(MINGW_C_STANDARD_OPTS) -m64 \
                       -O0
CPPFLAGS             = -c $(CPP_STANDARD_OPTS) -m64 \
                       -O0
CPP_LDFLAGS          = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
CPP_SHAREDLIB_LDFLAGS  = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                         -Wl,--out-implib,$(basename $(PRODUCT)).lib
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -static -m64
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -shared -Wl,-rpath,"$(MATLAB_ARCH_BIN)",-L"$(MATLAB_ARCH_BIN)" -Wl,--no-undefined \
                       -Wl,--out-implib,$(basename $(PRODUCT)).lib



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./Forward_kinematics_v2.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__USE_MINGW_ANSI_STDIO=1 -DMODEL=Forward_kinematics_v2 -DHAVESTDIO -DUSE_RTMODEL
DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=Forward_kinematics_v2 -DHAVESTDIO -DUSE_RTMODEL

DEFINES = $(DEFINES_) $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/Forward_kinematics_v2_data.c $(START_DIR)/Forward_kinematics_v2_initialize.c $(START_DIR)/Forward_kinematics_v2_terminate.c $(START_DIR)/Forward_kinematics_v2.c $(START_DIR)/Inverse_kinematics.c $(START_DIR)/fmincon.c $(START_DIR)/factoryConstruct.c $(START_DIR)/finDiffEvalAndChkErr.c $(START_DIR)/computeFiniteDifferences.c $(START_DIR)/factorQRE.c $(START_DIR)/factorQR.c $(START_DIR)/squareQ_appendCol.c $(START_DIR)/deleteColMoveEnd.c $(START_DIR)/solve.c $(START_DIR)/computeGrad_StoreHx.c $(START_DIR)/computeFval_ReuseHx.c $(START_DIR)/computeFval.c $(START_DIR)/linearForm_.c $(START_DIR)/setProblemType.c $(START_DIR)/removeConstr.c $(START_DIR)/maxConstraintViolation.c $(START_DIR)/modifyOverheadPhaseOne_.c $(START_DIR)/addBoundToActiveSetMatrix_.c $(START_DIR)/Weighted_error.c $(START_DIR)/computeCentralDifferences.c $(START_DIR)/updateWorkingSetForNewQP.c $(START_DIR)/driver.c $(START_DIR)/test_exit.c $(START_DIR)/computeGradLag.c $(START_DIR)/xgemv.c $(START_DIR)/computeDualFeasError.c $(START_DIR)/computeLambdaLSQ.c $(START_DIR)/xgeqp3.c $(START_DIR)/xzgeqp3.c $(START_DIR)/xzlarfg.c $(START_DIR)/xzlarf.c $(START_DIR)/xnrm2.c $(START_DIR)/computeQ_.c $(START_DIR)/sortLambdaQP.c $(START_DIR)/step.c $(START_DIR)/driver1.c $(START_DIR)/PresolveWorkingSet.c $(START_DIR)/countsort.c $(START_DIR)/RemoveDependentIneq_.c $(START_DIR)/feasibleX0ForWorkingSet.c $(START_DIR)/xgemm.c $(START_DIR)/phaseone.c $(START_DIR)/iterate.c $(START_DIR)/xrotg.c $(START_DIR)/compute_deltax.c $(START_DIR)/xpotrf.c $(START_DIR)/relaxed.c $(START_DIR)/BFGSUpdate.c $(START_DIR)/H_leg.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj Forward_kinematics_v2_data.obj Forward_kinematics_v2_initialize.obj Forward_kinematics_v2_terminate.obj Forward_kinematics_v2.obj Inverse_kinematics.obj fmincon.obj factoryConstruct.obj finDiffEvalAndChkErr.obj computeFiniteDifferences.obj factorQRE.obj factorQR.obj squareQ_appendCol.obj deleteColMoveEnd.obj solve.obj computeGrad_StoreHx.obj computeFval_ReuseHx.obj computeFval.obj linearForm_.obj setProblemType.obj removeConstr.obj maxConstraintViolation.obj modifyOverheadPhaseOne_.obj addBoundToActiveSetMatrix_.obj Weighted_error.obj computeCentralDifferences.obj updateWorkingSetForNewQP.obj driver.obj test_exit.obj computeGradLag.obj xgemv.obj computeDualFeasError.obj computeLambdaLSQ.obj xgeqp3.obj xzgeqp3.obj xzlarfg.obj xzlarf.obj xnrm2.obj computeQ_.obj sortLambdaQP.obj step.obj driver1.obj PresolveWorkingSet.obj countsort.obj RemoveDependentIneq_.obj feasibleX0ForWorkingSet.obj xgemm.obj phaseone.obj iterate.obj xrotg.obj compute_deltax.obj xpotrf.obj relaxed.obj BFGSUpdate.obj H_leg.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS += $(CPPFLAGS_BASIC)

#---------------------
# MEX C++ Compiler
#---------------------

MEX_CPP_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CPPFLAGS += $(MEX_CPP_Compiler_BASIC)

#-----------------
# MEX Compiler
#-----------------

MEX_Compiler_BASIC =  @$(COMPILER_COMMAND_FILE)

MEX_CFLAGS += $(MEX_Compiler_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


MINGW_C_STANDARD_OPTS = $(C_STANDARD_OPTS)


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : C:/Users/valer/DOCUME~1/INNOPO~1/DIPLOM~1/PSMGIT~1/FORWAR~1/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : C:/Users/valer/DOCUME~1/INNOPO~1/DIPLOM~1/PSMGIT~1/FORWAR~1/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.obj : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


rt_nonfinite.obj : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.obj : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.obj : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Forward_kinematics_v2_data.obj : $(START_DIR)/Forward_kinematics_v2_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Forward_kinematics_v2_initialize.obj : $(START_DIR)/Forward_kinematics_v2_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Forward_kinematics_v2_terminate.obj : $(START_DIR)/Forward_kinematics_v2_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Forward_kinematics_v2.obj : $(START_DIR)/Forward_kinematics_v2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Inverse_kinematics.obj : $(START_DIR)/Inverse_kinematics.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fmincon.obj : $(START_DIR)/fmincon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factoryConstruct.obj : $(START_DIR)/factoryConstruct.c
	$(CC) $(CFLAGS) -o "$@" "$<"


finDiffEvalAndChkErr.obj : $(START_DIR)/finDiffEvalAndChkErr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeFiniteDifferences.obj : $(START_DIR)/computeFiniteDifferences.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factorQRE.obj : $(START_DIR)/factorQRE.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factorQR.obj : $(START_DIR)/factorQR.c
	$(CC) $(CFLAGS) -o "$@" "$<"


squareQ_appendCol.obj : $(START_DIR)/squareQ_appendCol.c
	$(CC) $(CFLAGS) -o "$@" "$<"


deleteColMoveEnd.obj : $(START_DIR)/deleteColMoveEnd.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solve.obj : $(START_DIR)/solve.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeGrad_StoreHx.obj : $(START_DIR)/computeGrad_StoreHx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeFval_ReuseHx.obj : $(START_DIR)/computeFval_ReuseHx.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeFval.obj : $(START_DIR)/computeFval.c
	$(CC) $(CFLAGS) -o "$@" "$<"


linearForm_.obj : $(START_DIR)/linearForm_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


setProblemType.obj : $(START_DIR)/setProblemType.c
	$(CC) $(CFLAGS) -o "$@" "$<"


removeConstr.obj : $(START_DIR)/removeConstr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


maxConstraintViolation.obj : $(START_DIR)/maxConstraintViolation.c
	$(CC) $(CFLAGS) -o "$@" "$<"


modifyOverheadPhaseOne_.obj : $(START_DIR)/modifyOverheadPhaseOne_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


addBoundToActiveSetMatrix_.obj : $(START_DIR)/addBoundToActiveSetMatrix_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


Weighted_error.obj : $(START_DIR)/Weighted_error.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeCentralDifferences.obj : $(START_DIR)/computeCentralDifferences.c
	$(CC) $(CFLAGS) -o "$@" "$<"


updateWorkingSetForNewQP.obj : $(START_DIR)/updateWorkingSetForNewQP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


driver.obj : $(START_DIR)/driver.c
	$(CC) $(CFLAGS) -o "$@" "$<"


test_exit.obj : $(START_DIR)/test_exit.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeGradLag.obj : $(START_DIR)/computeGradLag.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemv.obj : $(START_DIR)/xgemv.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeDualFeasError.obj : $(START_DIR)/computeDualFeasError.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeLambdaLSQ.obj : $(START_DIR)/computeLambdaLSQ.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgeqp3.obj : $(START_DIR)/xgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzgeqp3.obj : $(START_DIR)/xzgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarfg.obj : $(START_DIR)/xzlarfg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xzlarf.obj : $(START_DIR)/xzlarf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.obj : $(START_DIR)/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


computeQ_.obj : $(START_DIR)/computeQ_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sortLambdaQP.obj : $(START_DIR)/sortLambdaQP.c
	$(CC) $(CFLAGS) -o "$@" "$<"


step.obj : $(START_DIR)/step.c
	$(CC) $(CFLAGS) -o "$@" "$<"


driver1.obj : $(START_DIR)/driver1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


PresolveWorkingSet.obj : $(START_DIR)/PresolveWorkingSet.c
	$(CC) $(CFLAGS) -o "$@" "$<"


countsort.obj : $(START_DIR)/countsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


RemoveDependentIneq_.obj : $(START_DIR)/RemoveDependentIneq_.c
	$(CC) $(CFLAGS) -o "$@" "$<"


feasibleX0ForWorkingSet.obj : $(START_DIR)/feasibleX0ForWorkingSet.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgemm.obj : $(START_DIR)/xgemm.c
	$(CC) $(CFLAGS) -o "$@" "$<"


phaseone.obj : $(START_DIR)/phaseone.c
	$(CC) $(CFLAGS) -o "$@" "$<"


iterate.obj : $(START_DIR)/iterate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xrotg.obj : $(START_DIR)/xrotg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


compute_deltax.obj : $(START_DIR)/compute_deltax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xpotrf.obj : $(START_DIR)/xpotrf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


relaxed.obj : $(START_DIR)/relaxed.c
	$(CC) $(CFLAGS) -o "$@" "$<"


BFGSUpdate.obj : $(START_DIR)/BFGSUpdate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


H_leg.obj : $(START_DIR)/H_leg.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


