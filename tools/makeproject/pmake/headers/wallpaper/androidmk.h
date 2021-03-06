const char ANDROIDMK_STR[] = 
"LOCAL_PATH:= $(call my-dir)\n"
"\n"
"\n"
"TECH_ROOT := $(FITECH)\n"
"PAPER3D_ROOT := $(FIPAPER3D)\n"
"TECH_LIBRARY_PATH := $(TECH_ROOT)/lib/android\n"
"PAPER3D_LIBRARY_PATH := $(PAPER3D_ROOT)/lib/android\n"
"\n"
"APP_DEFINES := -DANDROID\n"
"\n"
"ifeq ($(USE_STL), 1) \n"
"APP_DEFINES := $(APP_DEFINES) -DP_USE_STL\n"
"$(info ...Use native STL...)\n"
"else\n"
"$(info ...No STL support...)\n"
"endif\n"
"\n"
"ifeq ($(ENABLE_LOGGING), 1) \n"
"APP_DEFINES := $(APP_DEFINES) -DP_ENABLE_LOGGING\n"
"$(info ...Enable logging...)\n"
"else\n"
"$(info ...Disable logging...)\n"
"endif\n"
"\n"
"ifeq ($(NDK_DEBUG), 1)\n"
"$(info ...Build debug version...)\n"
"CONF_FLAGS := -g -DDEBUG -D_DEBUG \n"
"TECH_LIBRARY_PATH := $(TECH_LIBRARY_PATH)/ES20_Debug\n"
"PAPER3D_LIBRARY_PATH := $(PAPER3D_LIBRARY_PATH)/Debug\n"
"CONFIGURATION := Debug\n"
"else\n"
"$(info ...Build release version...)\n"
"CONF_FLAGS :=\n"
"TECH_LIBRARY_PATH := $(TECH_LIBRARY_PATH)/ES20_Release\n"
"PAPER3D_LIBRARY_PATH := $(PAPER3D_LIBRARY_PATH)/Release\n"
"CONFIGURATION := Release\n"
"# CONF_FLAGS := -O2  # not a good idea, -O0 is generated by ndk-build\n"
"endif\n"
"\n"
"\n"
"EXT_LIBRARY_PATH := $(TECH_ROOT)/3rdparty/platforms/android\n"
"APP_PATH := ../../..\n"
"\n"
"########################################\n"
"# Pre-compiled libraries\n"
"########################################\n"
"# png\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := png # name it whatever\n"
"LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/libpng/lib/$(CONFIGURATION)/libpng.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"# z\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := z\n"
"LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/zlib/lib/$(CONFIGURATION)/libz.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"# tinyxml\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := tinyxml\n"
"LOCAL_SRC_FILES := $(EXT_LIBRARY_PATH)/tinyxml/lib/$(CONFIGURATION)/libtinyxml.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"# platform\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := platform\n"
"LOCAL_SRC_FILES := $(TECH_LIBRARY_PATH)/libplatform.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"# foundation\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := foundation\n"
"LOCAL_SRC_FILES := $(TECH_LIBRARY_PATH)/libfoundation.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"# paper3d\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := paper3d\n"
"LOCAL_SRC_FILES := $(PAPER3D_LIBRARY_PATH)/libpaper3d.a  \n"
"\n"
"include $(PREBUILT_STATIC_LIBRARY)    #or PREBUILT_SHARED_LIBRARY\n"
"\n"
"########################################\n"
"# Build the main module\n"
"########################################\n"
"\n"
"include $(CLEAR_VARS)\n"
"\n"
"LOCAL_MODULE := fi \n"
"LOCAL_CFLAGS := -O2 $(APP_DEFINES) $(CONF_FLAGS) -fexceptions -frtti\n"
"\n"
"APP_LIBRARY_INCLUDE_PATHS := \\\n"
"$(APP_PATH)/src \\\n"
"$(TECH_ROOT)/include \\\n"
"$(TECH_ROOT)/include/PPlatform \\\n"
"$(TECH_ROOT)/include/PFoundation \\\n"
"$(PAPER3D_ROOT)/include\n"
"\n"
"EXT_LIBRARY_INCLUDE_PATHS := \\\n"
"$(TECH_ROOT)/3rdparty/platforms/android/libpng/include/ \\\n"
"$(TECH_ROOT)/3rdparty/common/libpng/include \\\n"
"$(TECH_ROOT)/3rdparty/common/zlib/include \\\n"
"$(TECH_ROOT)/3rdparty/common/tinyxml/include \n"
"\n"
"LOCAL_C_INCLUDES := \\\n"
"	$(APP_LIBRARY_INCLUDE_PATHS) \\\n"
"	$(EXT_LIBRARY_INCLUDE_PATHS)\n"
"\n"
"LOCAL_SRC_FILES := \\\n"
"$(TECH_ROOT)/src/platform/android/main.cpp \\\n"
"$(APP_PATH)/src/pmain.cpp \\\n"
"$(APP_PATH)/src/mycontext.cpp \\\n"
"$(APP_PATH)/src/myscene.cpp \n"
"\n"
"LOCAL_LDLIBS := -llog -lgcc -lGLESv2 -ldl -landroid\n"
"\n"
"LOCAL_STATIC_LIBRARIES := paper3d platform foundation png z tinyxml\n"
"\n"
"#-L$(EXT_LIBRARY_PATH)/freetype/lib -lfreetype \n"
"\n"
"include $(BUILD_SHARED_LIBRARY)\n"
"\n"
;